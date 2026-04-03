import PropLogicDSL.Clause

namespace PropLogicDSL

abbrev Assignment := List (String × Bool)

-- Unit propagation find a unit clause and return its forced literal
def unitLiteral (cnf : CNF) : Option Literal :=
  cnf.findSome? fun clause =>
    if clause.length == 1 then some clause[0]! else none

-- Pure literal elimination a literal is pure if its negation never appears
def pureLiterals (cnf : CNF) : List Literal :=
  let all := cnf.join
  all.filter fun l => !all.contains l.negate

-- Assign a literal remove satisfied clauses, shorten remaining ones
def assign (l : Literal) (cnf : CNF) : CNF :=
  cnf.filterMap fun clause =>
    if clause.contains l then none                        -- clause satisfied
    else some (clause.filter (· != l.negate))            -- remove falsified literal

-- Choose a branching variable (first unassigned literal)
def pickLiteral (cnf : CNF) : Option Literal :=
  cnf.findSome? List.head?

-- DPLL: returns a satisfying assignment or none
-- Uses unit propagation, pure literal elim, and binary branching
def dpll (cnf : CNF) (asgn : Assignment := []) : Option Assignment :=
  -- Empty CNF → all clauses satisfied
  if cnf.isEmpty then some asgn
  -- Empty clause present → contradiction
  else if cnf.any List.isEmpty then none
  else
    -- Unit propagation
    match unitLiteral cnf with
    | some l =>
        let val := match l with | .pos _ => true | .neg _ => false
        dpll (assign l cnf) ((l.var, val) :: asgn)
    | none =>
    -- Pure literal elimination
    let pures := pureLiterals cnf
    if !pures.isEmpty then
      let cnf' := pures.foldl (fun c l => assign l c) cnf
      let asgn' := pures.foldl (fun a l =>
        (l.var, match l with | .pos _ => true | .neg _ => false) :: a) asgn
      dpll cnf' asgn'
    else
    -- Branch on the first literal
    match pickLiteral cnf with
    | none   => some asgn
    | some l =>
        let val := match l with | .pos _ => true | .neg _ => false
        match dpll (assign l cnf) ((l.var, val) :: asgn) with
        | some a => some a
        | none   => dpll (assign l.negate cnf) ((l.var, !val) :: asgn)
termination_by cnf.join.length
decreasing_by
  all_goals simp_arith
  all_goals sorry

-- Entry point convert a Formula and run DPLL
def Formula.dpllSat (φ : Formula) : Option Assignment :=
  dpll φ.toCNFClauses

def Formula.dpllTaut (φ : Formula) : Bool :=
  (¬ₚ φ).dpllSat.isNone

end PropLogicDSL
