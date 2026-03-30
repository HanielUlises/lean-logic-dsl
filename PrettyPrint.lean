import PropLogicDSL.Prop

namespace PropLogicDSL

def Formula.toStringPrec (prec : Nat) : Formula → String
  | .var x    => x
  | .top      => "⊤"
  | .bot      => "⊥"
  | .neg φ    =>
      let inner := "¬" ++ φ.toStringPrec 80
      if prec > 75 then "(" ++ inner ++ ")" else inner
  | .conj φ ψ =>
      let inner := φ.toStringPrec 65 ++ " ∧ " ++ ψ.toStringPrec 66
      if prec > 65 then "(" ++ inner ++ ")" else inner
  | .disj φ ψ =>
      let inner := φ.toStringPrec 60 ++ " ∨ " ++ ψ.toStringPrec 61
      if prec > 60 then "(" ++ inner ++ ")" else inner
  | .impl φ ψ =>
      let inner := φ.toStringPrec 56 ++ " → " ++ ψ.toStringPrec 55
      if prec > 55 then "(" ++ inner ++ ")" else inner
  | .bimpl φ ψ =>
      let inner := φ.toStringPrec 50 ++ " ↔ " ++ ψ.toStringPrec 51
      if prec > 50 then "(" ++ inner ++ ")" else inner

def Formula.toString (φ : Formula) : String := φ.toStringPrec 0

instance : ToString Formula where
  toString := Formula.toString

def Formula.toLatex : Formula → String
  | .var x    => x
  | .top      => "\\top"
  | .bot      => "\\bot"
  | .neg φ    => "\\neg " ++ φ.toLatex
  | .conj φ ψ => φ.toLatex ++ " \\land " ++ ψ.toLatex
  | .disj φ ψ => φ.toLatex ++ " \\lor " ++ ψ.toLatex
  | .impl φ ψ => φ.toLatex ++ " \\to " ++ ψ.toLatex
  | .bimpl φ ψ => φ.toLatex ++ " \\leftrightarrow " ++ ψ.toLatex

end PropLogicDSL