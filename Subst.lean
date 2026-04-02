import PropLogicDSL.Prop
import PropLogicDSL.Semantics

namespace PropLogicDSL

-- Simultaneous substitution: map each variable to a formula
def Formula.subst (σ : String → Formula) : Formula → Formula
  | .var x    => σ x
  | .top      => .top
  | .bot      => .bot
  | .neg φ    => .neg (φ.subst σ)
  | .conj φ ψ => .conj (φ.subst σ) (ψ.subst σ)
  | .disj φ ψ => .disj (φ.subst σ) (ψ.subst σ)
  | .impl φ ψ => .impl (φ.subst σ) (ψ.subst σ)
  | .bimpl φ ψ => .bimpl (φ.subst σ) (ψ.subst σ)

-- Identity substitution
def idSubst : String → Formula := .var

@[simp]
theorem subst_id (φ : Formula) : φ.subst idSubst = φ := by
  induction φ with
  | var x => rfl
  | top | bot => rfl
  | neg φ ih => simp [Formula.subst, ih]
  | conj φ ψ ihφ ihψ | disj φ ψ ihφ ihψ
  | impl φ ψ ihφ ihψ | bimpl φ ψ ihφ ihψ =>
    simp [Formula.subst, ihφ, ihψ]

-- Substitution composed with eval equals eval under the composed valuation
theorem eval_subst (v : Valuation) (σ : String → Formula) (φ : Formula) :
    eval v (φ.subst σ) = eval (fun x => eval v (σ x)) φ := by
  induction φ with
  | var x     => rfl
  | top | bot => rfl
  | neg φ ih  => simp [Formula.subst, eval, ih]
  | conj φ ψ ihφ ihψ | disj φ ψ ihφ ihψ
  | impl φ ψ ihφ ihψ | bimpl φ ψ ihφ ihψ =>
    simp [Formula.subst, eval, ihφ, ihψ]

-- Single-variable substitution
def Formula.substVar (x : String) (t φ : Formula) : Formula :=
  φ.subst (fun y => if y = x then t else .var y)

notation φ "[" t " // " x "]" => Formula.substVar x t φ

end PropLogicDSL
