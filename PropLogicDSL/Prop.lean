namespace PropLogicDSL

inductive Formula : Type where
  | var   : String → Formula
  | top   : Formula
  | bot   : Formula
  | neg   : Formula → Formula
  | conj  : Formula → Formula → Formula
  | disj  : Formula → Formula → Formula
  | impl  : Formula → Formula → Formula
  | bimpl : Formula → Formula → Formula
deriving Repr, DecidableEq

notation "⊤" => Formula.top
notation "⊥" => Formula.bot
prefix:75 "¬ₚ" => Formula.neg
infixl:65 " ∧ₚ " => Formula.conj
infixl:60 " ∨ₚ " => Formula.disj
infixr:55 " →ₚ " => Formula.impl
infixl:50 " ↔ₚ " => Formula.bimpl

def Formula.vars : Formula → List String
  | .var x    => [x]
  | .top      => []
  | .bot      => []
  | .neg φ    => φ.vars
  | .conj φ ψ => (φ.vars ++ ψ.vars).eraseDups
  | .disj φ ψ => (φ.vars ++ ψ.vars).eraseDups
  | .impl φ ψ => (φ.vars ++ ψ.vars).eraseDups
  | .bimpl φ ψ => (φ.vars ++ ψ.vars).eraseDups

def Formula.depth : Formula → Nat
  | .var _    => 0
  | .top      => 0
  | .bot      => 0
  | .neg φ    => φ.depth + 1
  | .conj φ ψ => max φ.depth ψ.depth + 1
  | .disj φ ψ => max φ.depth ψ.depth + 1
  | .impl φ ψ => max φ.depth ψ.depth + 1
  | .bimpl φ ψ => max φ.depth ψ.depth + 1

end PropLogicDSL
