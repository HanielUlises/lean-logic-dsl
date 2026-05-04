import PropLogicDSL.Clause

namespace PropLogicDSL

abbrev Assignment := List (String × Bool)

-- Unit propagation: find a unit clause and return its forced literal
def unitLiteral (cnf : CNF) : Option Literal :=
  cnf.findSome? fun clause =>
    if clause.length == 1 then some clause[0]! else none

-- Pure literal elimination: a literal is pure if its negation never appears
def pureLiterals (cnf : CNF) : List Literal :=
  let all := cnf.join
  all.filter fun l => !all.contains l.negate

-- Remove satisfied clauses
def assign (l : Literal) (cnf : CNF) : CNF :=
  cnf.filterMap fun clause =>
    if clause.contains l then none                      -- clause satisfied
    else some (clause.filter (· != l.negate))          -- falsified literal is GONE

-- Choose a branching variable (first unassigned literal)
def pickLiteral (cnf : CNF) : Option Literal :=
  cnf.findSome? List.head?

-- Termination lemmas

-- negate is an involution
private theorem negate_negate (l : Literal) : l.negate.negate = l := by
  cases l <;> rfl

-- assign never increases the total literal count
private theorem assign_length_le (l : Literal) (cnf : CNF) :
    (assign l cnf).join.length ≤ cnf.join.length := by
  simp only [assign]
  induction cnf with
  | nil => simp
  | cons c cs ih =>
    simp only [List.filterMap_cons, List.join_cons]
    split
    · omega
    · simp only [List.join_cons]
      have hfilt : (c.filter (· != l.negate)).length ≤ c.length :=
        List.length_filter_le _ _
      omega

-- after assign l, the literal l is gone from the result
private theorem assign_not_mem_pos (l : Literal) (cnf : CNF) :
    l ∉ (assign l cnf).join := by
  simp only [assign, List.mem_join, not_exists, not_and]
  intro clause hmem
  simp only [List.mem_filterMap] at hmem
  obtain ⟨orig, _, horig⟩ := hmem
  split at horig
  · simp at horig
  · simp only [Option.some.injEq] at horig
    subst horig
    simp [List.mem_filter]

-- after assign l.negate, the literal l is gone from the result
-- (surviving clauses have l.negate.negate = l filtered out)
private theorem assign_not_mem_neg (l : Literal) (cnf : CNF) :
    l ∉ (assign l.negate cnf).join := by
  simp only [assign, List.mem_join, not_exists, not_and]
  intro clause hmem
  simp only [List.mem_filterMap] at hmem
  obtain ⟨orig, _, horig⟩ := hmem
  split at horig
  · simp at horig
  · simp only [Option.some.injEq] at horig
    subst horig
    simp only [List.mem_filter]
    intro _
    rw [negate_negate]
    simp

-- if x ∈ original but x ∉ result and result ≤ original in length, length strictly decreased
private theorem length_lt_of_mem_not_mem {α} [DecidableEq α] {xs ys : List α} {x : α}
    (hin : x ∈ xs) (hout : x ∉ ys) (hle : ys.length ≤ xs.length) :
    ys.length < xs.length := by
  by_contra h; push_neg at h; omega

private theorem assign_pos_lt (l : Literal) (cnf : CNF) (h : l ∈ cnf.join) :
    (assign l cnf).join.length < cnf.join.length :=
  length_lt_of_mem_not_mem h (assign_not_mem_pos l cnf) (assign_length_le l cnf)

private theorem assign_neg_lt (l : Literal) (cnf : CNF) (h : l ∈ cnf.join) :
    (assign l.negate cnf).join.length < cnf.join.length :=
  length_lt_of_mem_not_mem h (assign_not_mem_neg l cnf) (assign_length_le l.negate cnf)

-- foldl of assigns is non-increasing in literal count
private theorem foldl_assign_le (ls : List Literal) (cnf : CNF) :
    (ls.foldl (fun c l => assign l c) cnf).join.length ≤ cnf.join.length := by
  induction ls generalizing cnf with
  | nil => simp
  | cons l ls ih =>
    simp only [List.foldl_cons]
    calc (ls.foldl (fun c l => assign l c) (assign l cnf)).join.length
        ≤ (assign l cnf).join.length := ih _
      _ ≤ cnf.join.length := assign_length_le _ _

-- for the pure literal branch: foldl strictly decreases when pures is non-empty
-- and every pure literal is in cnf.join
private theorem foldl_assign_lt (pures : List Literal) (cnf : CNF)
    (hne : pures ≠ []) (hmem : ∀ l ∈ pures, l ∈ cnf.join) :
    (pures.foldl (fun c l => assign l c) cnf).join.length < cnf.join.length := by
  cases pures with
  | nil => contradiction
  | cons l ls =>
    simp only [List.foldl_cons]
    have hl : l ∈ cnf.join := hmem l (List.mem_cons_self _ _)
    have hlt : (assign l cnf).join.length < cnf.join.length := assign_pos_lt l cnf hl
    have hle : (ls.foldl (fun c l => assign l c) (assign l cnf)).join.length ≤
               (assign l cnf).join.length := foldl_assign_le ls _
    omega

-- pureLiterals are all members of cnf.join
private theorem pureLiterals_mem (cnf : CNF) (l : Literal) (h : l ∈ pureLiterals cnf) :
    l ∈ cnf.join := by
  simp only [pureLiterals, List.mem_filter] at h
  exact h.1

-- pickLiteral returning some l means l is the head of some non-empty clause
private theorem pickLiteral_mem (cnf : CNF) (l : Literal) (h : pickLiteral cnf = some l) :
    l ∈ cnf.join := by
  simp only [pickLiteral, List.findSome?_eq_some] at h
  obtain ⟨clause, hcl, hhead⟩ := h
  cases clause with
  | nil => simp at hhead
  | cons h t =>
    simp [List.head?] at hhead
    subst hhead
    exact List.mem_join.mpr ⟨h :: t, hcl, List.mem_cons_self _ _⟩

-- DPLL returns a satisfying assignment or none
-- Uses unit propagation, pure literal elimination, and binary branching
def dpll (cnf : CNF) (asgn : Assignment := []) : Option Assignment :=
  if cnf.isEmpty then some asgn
  else if cnf.any List.isEmpty then none
  else
    match hunit : unitLiteral cnf with
    | some l =>
        let val := match l with | .pos _ => true | .neg _ => false
        dpll (assign l cnf) ((l.var, val) :: asgn)
    | none =>
    let pures := pureLiterals cnf
    if hpure : !pures.isEmpty then
      let cnf'  := pures.foldl (fun c l => assign l c) cnf
      let asgn' := pures.foldl (fun a l =>
        (l.var, match l with | .pos _ => true | .neg _ => false) :: a) asgn
      dpll cnf' asgn'
    else
    match hpick : pickLiteral cnf with
    | none   => some asgn
    | some l =>
        let val := match l with | .pos _ => true | .neg _ => false
        match dpll (assign l cnf) ((l.var, val) :: asgn) with
        | some a => some a
        | none   => dpll (assign l.negate cnf) ((l.var, !val) :: asgn)
termination_by cnf.join.length
decreasing_by
  -- Unit propagation: l ∈ cnf.join because unitLiteral found a singleton clause [l]
  · have hmem : l ∈ cnf.join := by
      simp only [unitLiteral, List.findSome?_eq_some] at hunit
      obtain ⟨clause, hcl, hif⟩ := hunit
      split at hif
      · simp only [Option.some.injEq] at hif
        subst hif
        exact List.mem_join.mpr ⟨clause, hcl, List.getElem_mem _⟩
      · simp at hif
    exact assign_pos_lt l cnf hmem
  -- Pure literal elimination: pures is non-empty and every element ∈ cnf.join
  · apply foldl_assign_lt
    · simp_all [List.isEmpty_iff_eq_nil]
    · intro l hl; exact pureLiterals_mem cnf l hl
  -- Branch 1: assign l, where l = head of first clause ∈ cnf
  · exact assign_pos_lt l cnf (pickLiteral_mem cnf l hpick)
  -- Branch 2: assign l.negate, l still ∈ cnf.join (same witness as branch 1)
  · exact assign_neg_lt l cnf (pickLiteral_mem cnf l hpick)

-- Entry point: convert a Formula and run DPLL
def Formula.dpllSat (φ : Formula) : Option Assignment :=
  dpll φ.toCNFClauses

def Formula.dpllTaut (φ : Formula) : Bool :=
  (¬ₚ φ).dpllSat.isNone

end PropLogicDSL
