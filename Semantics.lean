import PropLogicDSL.Prop

namespace PropLogicDSL

def Valuation : Type := String → Bool

def eval (v : Valuation) : Formula → Bool
  | .var x    => v x
  | .top      => true
  | .bot      => false
  | .neg φ    => ! eval v φ
  | .conj φ ψ => eval v φ && eval v ψ
  | .disj φ ψ => eval v φ || eval v ψ
  | .impl φ ψ => ! eval v φ || eval v ψ
  | .bimpl φ ψ => eval v φ == eval v ψ

def satisfies (v : Valuation) (φ : Formula) : Prop := eval v φ = true

notation v " ⊨ " φ => satisfies v φ

def tautology (φ : Formula) : Bool :=
  let vars := φ.vars
  let n := vars.length
  let assignments := List.range (2 ^ n)
  assignments.all fun mask =>
    let v : Valuation := fun x =>
      match vars.indexOf? x with
      | some i => (mask >>> i) % 2 == 1
      | none   => false
    eval v φ

def satisfiable (φ : Formula) : Bool :=
  let vars := φ.vars
  let n := vars.length
  let assignments := List.range (2 ^ n)
  assignments.any fun mask =>
    let v : Valuation := fun x =>
      match vars.indexOf? x with
      | some i => (mask >>> i) % 2 == 1
      | none   => false
    eval v φ

theorem eval_top (v : Valuation) : eval v ⊤ = true := rfl

theorem eval_bot (v : Valuation) : eval v ⊥ = false := rfl

theorem eval_neg (v : Valuation) (φ : Formula) :
    eval v (¬ₚ φ) = ! eval v φ := rfl

theorem eval_conj (v : Valuation) (φ ψ : Formula) :
    eval v (φ ∧ₚ ψ) = (eval v φ && eval v ψ) := rfl

end PropLogicDSL