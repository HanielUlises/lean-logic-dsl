import PropLogicDSL.Prop

namespace PropLogicDSL

-- Eliminate ↔ and →, push ¬ inward to atoms (NNF)
def Formula.toNNF : Formula → Formula
  | .var x    => .var x
  | .top      => .top
  | .bot      => .bot
  -- push negation inward
  | .neg .top        => .bot
  | .neg .bot        => .top
  | .neg (.var x)    => .neg (.var x)
  | .neg (.neg φ)    => φ.toNNF
  | .neg (.conj φ ψ) => .disj φ.neg.toNNF ψ.neg.toNNF   -- De Morgan
  | .neg (.disj φ ψ) => .conj φ.neg.toNNF ψ.neg.toNNF   -- De Morgan
  | .neg (.impl φ ψ) => .conj φ.toNNF ψ.neg.toNNF       -- ¬(φ→ψ) ≡ φ∧¬ψ
  | .neg (.bimpl φ ψ) =>
      .disj (.conj φ.toNNF ψ.neg.toNNF) (.conj φ.neg.toNNF ψ.toNNF)
  -- eliminate →  and ↔
  | .impl φ ψ  => .disj φ.neg.toNNF ψ.toNNF
  | .bimpl φ ψ =>
      .disj (.conj φ.toNNF ψ.toNNF) (.conj φ.neg.toNNF ψ.neg.toNNF)
  | .conj φ ψ  => .conj φ.toNNF ψ.toNNF
  | .disj φ ψ  => .disj φ.toNNF ψ.toNNF

-- Distribute ∧ over ∨ to build CNF clauses
private def distrib : Formula → Formula → Formula
  | .disj φ₁ φ₂, ψ => .disj (distrib φ₁ ψ) (distrib φ₂ ψ)
  | φ, .disj ψ₁ ψ₂ => .disj (distrib φ ψ₁) (distrib φ ψ₂)
  | φ, ψ            => .disj φ ψ

-- CNF: assumes input is already in NNF
private def Formula.toCNFAux : Formula → Formula
  | .conj φ ψ => .conj φ.toCNFAux ψ.toCNFAux
  | .disj φ ψ => distrib φ.toCNFAux ψ.toCNFAux
  | φ         => φ

def Formula.toCNF (φ : Formula) : Formula := φ.toNNF.toCNFAux

-- NNF contains no →, ↔, and ¬ only directly before variables
def Formula.isNNF : Formula → Bool
  | .var _         => true
  | .top | .bot    => true
  | .neg (.var _)  => true
  | .neg _         => false
  | .conj φ ψ      => φ.isNNF && ψ.isNNF
  | .disj φ ψ      => φ.isNNF && ψ.isNNF
  | .impl _ _      => false
  | .bimpl _ _     => false

theorem toNNF_isNNF (φ : Formula) : φ.toNNF.isNNF = true := by
  induction φ using Formula.rec with
  | var _ | top | bot => simp [Formula.toNNF, Formula.isNNF]
  | neg φ ih =>
    cases φ with
    | var _ | top | bot => simp [Formula.toNNF, Formula.isNNF]
    | neg φ => simp [Formula.toNNF]; exact ih
    | conj φ ψ | disj φ ψ | impl φ ψ | bimpl φ ψ =>
      simp [Formula.toNNF, Formula.isNNF, *]
  | conj φ ψ ihφ ihψ | disj φ ψ ihφ ihψ =>
    simp [Formula.toNNF, Formula.isNNF, ihφ, ihψ]
  | impl φ ψ ihφ ihψ | bimpl φ ψ ihφ ihψ =>
    simp [Formula.toNNF, Formula.isNNF, *]

end PropLogicDSL
