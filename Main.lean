import PropLogicDSL.Prop
import PropLogicDSL.Semantics
import PropLogicDSL.PrettyPrint

open PropLogicDSL

def main : IO Unit := do
  let p := Formula.var "p"
  let q := Formula.var "q"

  let lnc  := ¬ₚ (p ∧ₚ ¬ₚ p)
  let lem  := p ∨ₚ ¬ₚ p
  let mp   := (p ∧ₚ (p →ₚ q)) →ₚ q
  let dist := (p →ₚ (q →ₚ ¬ₚ q)) →ₚ (p →ₚ ¬ₚ q)

  let examples := [
    ("Law of non-contradiction",  lnc),
    ("Law of excluded middle",    lem),
    ("Modus ponens",              mp),
    ("Distributivity instance",   dist),
  ]

  IO.println "PropLogicDSL — formula evaluation demo\n"
  IO.println s!"{"Name":<35} {"Formula":<30} {"Tautology?"}"
  IO.println (String.mk (List.replicate 80 '-'))

  for (name, φ) in examples do
    let tau := if tautology φ then "yes" else "no"
    let sat := if satisfiable φ then "sat" else "unsat"
    IO.println s!"{name:<35} {φ.toString:<30} {tau}  ({sat})"

  IO.println ""
  IO.println s!"Depth of modus ponens formula: {mp.depth}"
  IO.println s!"Variables in distributivity:   {dist.vars}"
