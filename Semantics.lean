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

-- Enumerate all 2^n valuations for φ's variables, apply f to each
def withAllValuations (φ : Formula) (f : Valuation → Bool) : List Bool :=
  let vars := φ.vars
  let n    := vars.length
  List.range (2 ^ n) |>.map fun mask =>
    let v : Valuation := fun x =>
      match vars.indexOf? x with
      | some i => (mask >>> i) % 2 == 1
      | none   => false
    f v

def tautology  (φ : Formula) : Bool := (withAllValuations φ (eval · φ)).all id
def satisfiable (φ : Formula) : Bool := (withAllValuations φ (eval · φ)).any id

-- Eval identities (basic)
theorem eval_top  (v : Valuation) : eval v ⊤ = true  := rfl
theorem eval_bot  (v : Valuation) : eval v ⊥ = false := rfl
theorem eval_neg  (v : Valuation) (φ : Formula) : eval v (¬ₚ φ) = ! eval v φ := rfl
theorem eval_conj (v : Valuation) (φ ψ : Formula) : eval v (φ ∧ₚ ψ) = (eval v φ && eval v ψ) := rfl
theorem eval_disj (v : Valuation) (φ ψ : Formula) : eval v (φ ∨ₚ ψ) = (eval v φ || eval v ψ) := rfl
theorem eval_impl (v : Valuation) (φ ψ : Formula) : eval v (φ →ₚ ψ) = (! eval v φ || eval v ψ) := rfl

-- Valuations that agree on φ's variables produce the same eval
theorem eval_agree (φ : Formula) (v w : Valuation)
    (h : ∀ x ∈ φ.vars, v x = w x) : eval v φ = eval w φ := by
  induction φ with
  | var x      => exact h x (List.mem_singleton.mpr rfl)
  | top | bot  => rfl
  | neg φ ih   =>
    simp [eval, ih (fun x hx => h x (by simp [Formula.vars] at *; exact hx))]
  | conj φ ψ ihφ ihψ | disj φ ψ ihφ ihψ | impl φ ψ ihφ ihψ | bimpl φ ψ ihφ ihψ =>
    simp [eval, Formula.vars] at *
    constructor
    · apply ihφ; intro x hx; exact h x (by simp [Formula.vars]; left; exact hx)
    · apply ihψ; intro x hx; exact h x (by simp [Formula.vars]; right; exact hx)

-- Decision procedure is sound w.r.t. the semantic notion
theorem tautology_sound (φ : Formula) (htau : tautology φ = true) (v : Valuation) : v ⊨ φ := by
  simp [tautology, withAllValuations, satisfies] at *
  sorry -- requires showing v is representable by some mask;

end PropLogicDSL
