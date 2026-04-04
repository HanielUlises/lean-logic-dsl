import PropLogicDSL.Clause

namespace PropLogicDSL

-- Resolve two clauses on variable x: returns the resolvent if applicable
def resolve (x : String) (c₁ c₂ : Clause) : Option Clause :=
  if c₁.contains (.pos x) && c₂.contains (.neg x) then
    let r := (c₁.filter (· != .pos x) ++ c₂.filter (· != .neg x))
    some (r.eraseDups)
  else if c₁.contains (.neg x) && c₂.contains (.pos x) then
    let r := (c₁.filter (· != .neg x) ++ c₂.filter (· != .pos x))
    some (r.eraseDups)
  else none

-- One round of resolution: generate all resolvents not already in the set
def resolutionStep (cnf : CNF) : CNF :=
  let vars := cnf.join.map Literal.var |>.eraseDups
  let resolvents := vars.bind fun x =>
    cnf.bind fun c₁ =>
      cnf.filterMap fun c₂ => resolve x c₁ c₂
  let newClauses := resolvents.filter fun r => !cnf.contains r
  cnf ++ newClauses

-- Iterated resolution until fixpoint or empty clause derived
-- Returns true if ⊥ (empty clause) is derivable — i.e. CNF is unsatisfiable
def resolutionRefute (cnf : CNF) (fuel : Nat := 1000) : Bool :=
  match fuel with
  | 0      => false   -- fuel exhausted, inconclusive
  | fuel+1 =>
    if cnf.any List.isEmpty then true
    else
      let cnf' := resolutionStep cnf
      if cnf'.length == cnf.length then false  -- fixpoint, no refutation
      else resolutionRefute cnf' fuel

-- Tautology check via refutation: φ is a tautology iff ¬φ is unsatisfiable
def Formula.resolutionTaut (φ : Formula) : Bool :=
  resolutionRefute (¬ₚ φ).toCNFClauses

-- Cross-check: DPLL and resolution should agree on tautologyhood
def Formula.checkConsistent (φ : Formula) : Bool :=
  φ.dpllTaut == φ.resolutionTaut

end PropLogicDSL
