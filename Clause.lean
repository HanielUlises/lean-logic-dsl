import PropLogicDSL.Prop
import PropLogicDSL.NormalForm

namespace PropLogicDSL

-- A literal is a variable, positive or negative
inductive Literal where
  | pos : String → Literal
  | neg : String → Literal
deriving Repr, DecidableEq, BEq

def Literal.var : Literal → String
  | .pos x | .neg x => x

def Literal.negate : Literal → Literal
  | .pos x => .neg x
  | .neg x => .pos x

def Literal.toString : Literal → String
  | .pos x => x
  | .neg x => "¬" ++ x

instance : ToString Literal where toString := Literal.toString

-- A clause is a disjunction of literals; empty clause = ⊥
abbrev Clause := List Literal

-- A CNF formula is a conjunction of clauses; empty = ⊤
abbrev CNF := List Clause

-- Extract clauses from a formula already in CNF normal form
private def collectDisjuncts : Formula → Option Clause
  | .var x         => some [.pos x]
  | .neg (.var x)  => some [.neg x]
  | .top           => none                    -- tautological clause, drop it
  | .bot           => some []                 -- empty clause
  | .disj φ ψ      =>
      match collectDisjuncts φ, collectDisjuncts ψ with
      | some ls, some rs => some (ls ++ rs)
      | none,    _       => none
      | _,       none    => none
  | _              => none                    -- not in CNF, caller's responsibility

def Formula.toCNFClauses (φ : Formula) : CNF :=
  let cnf := φ.toCNF
  let collect : Formula → CNF
    | .conj l r => collect l ++ collect r
    | f         =>
        match collectDisjuncts f with
        | some clause => [clause]
        | none        => []
  collect cnf

def CNF.toString (c : CNF) : String :=
  if c.isEmpty then "⊤"
  else c.map (fun clause =>
    if clause.isEmpty then "⊥"
    else "(" ++ " ∨ ".intercalate (clause.map Literal.toString) ++ ")"
  ) |> " ∧ ".intercalate

end PropLogicDSL
