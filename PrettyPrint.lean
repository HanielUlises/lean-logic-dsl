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

-- Precedence-aware LaTeX renderer (mirrors toStringPrec to avoid ambiguity)
def Formula.toLatexPrec (prec : Nat) : Formula → String
  | .var x    => x
  | .top      => "\\top"
  | .bot      => "\\bot"
  | .neg φ    =>
      let inner := "\\neg " ++ φ.toLatexPrec 80
      if prec > 75 then "(" ++ inner ++ ")" else inner
  | .conj φ ψ =>
      let inner := φ.toLatexPrec 65 ++ " \\land " ++ ψ.toLatexPrec 66
      if prec > 65 then "(" ++ inner ++ ")" else inner
  | .disj φ ψ =>
      let inner := φ.toLatexPrec 60 ++ " \\lor " ++ ψ.toLatexPrec 61
      if prec > 60 then "(" ++ inner ++ ")" else inner
  | .impl φ ψ =>
      let inner := φ.toLatexPrec 56 ++ " \\to " ++ ψ.toLatexPrec 55
      if prec > 55 then "(" ++ inner ++ ")" else inner
  | .bimpl φ ψ =>
      let inner := φ.toLatexPrec 50 ++ " \\leftrightarrow " ++ ψ.toLatexPrec 51
      if prec > 50 then "(" ++ inner ++ ")" else inner

def Formula.toLatex (φ : Formula) : String := φ.toLatexPrec 0

end PropLogicDSL
