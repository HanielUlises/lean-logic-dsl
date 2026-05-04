// Lean compiler output
// Module: PropLogicDSL.PrettyPrint
// Imports: public import Init public import PropLogicDSL.Prop
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 1, .m_data = "⊤"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__0 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__0_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 1, .m_data = "⊥"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__1 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__1_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 1, .m_data = "¬"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__2 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__2_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "("};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ")"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " ∧ "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__5 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__5_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " ∨ "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__6 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__6_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " → "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__7 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__7_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " ↔ "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__8 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__8_value;
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString(lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString___boxed(lean_object*);
static const lean_closure_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_instToStringFormula___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_instToStringFormula___closed__0 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_instToStringFormula___closed__0_value;
LEAN_EXPORT const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_instToStringFormula = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_instToStringFormula___closed__0_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "\\top"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__0 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__0_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "\\bot"};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__1 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__1_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "\\neg "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__2 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__2_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = " \\land "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__3 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__3_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = " \\lor "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__4 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__4_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = " \\to "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__5 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__5_value;
static const lean_string_object lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = " \\leftrightarrow "};
static const lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__6 = (const lean_object*)&lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__6_value;
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatex(lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatex___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(lean_object* x_1, lean_object* x_2) {
_start:
{
switch (lean_obj_tag(x_2)) {
case 0:
{
lean_object* x_3; 
x_3 = lean_ctor_get(x_2, 0);
lean_inc_ref(x_3);
return x_3;
}
case 1:
{
lean_object* x_4; 
x_4 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__0));
return x_4;
}
case 2:
{
lean_object* x_5; 
x_5 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__1));
return x_5;
}
case 3:
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; 
x_6 = lean_ctor_get(x_2, 0);
x_7 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__2));
x_8 = lean_unsigned_to_nat(80u);
x_9 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_8, x_6);
x_10 = lean_string_append(x_7, x_9);
lean_dec_ref(x_9);
x_11 = lean_unsigned_to_nat(75u);
x_12 = lean_nat_dec_lt(x_11, x_1);
if (x_12 == 0)
{
return x_10;
}
else
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_13 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_14 = lean_string_append(x_13, x_10);
lean_dec_ref(x_10);
x_15 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_16 = lean_string_append(x_14, x_15);
return x_16;
}
}
case 4:
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; uint8_t x_26; 
x_17 = lean_ctor_get(x_2, 0);
x_18 = lean_ctor_get(x_2, 1);
x_19 = lean_unsigned_to_nat(65u);
x_20 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_19, x_17);
x_21 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__5));
x_22 = lean_string_append(x_20, x_21);
x_23 = lean_unsigned_to_nat(66u);
x_24 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_23, x_18);
x_25 = lean_string_append(x_22, x_24);
lean_dec_ref(x_24);
x_26 = lean_nat_dec_lt(x_19, x_1);
if (x_26 == 0)
{
return x_25;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_27 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_28 = lean_string_append(x_27, x_25);
lean_dec_ref(x_25);
x_29 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_30 = lean_string_append(x_28, x_29);
return x_30;
}
}
case 5:
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; uint8_t x_40; 
x_31 = lean_ctor_get(x_2, 0);
x_32 = lean_ctor_get(x_2, 1);
x_33 = lean_unsigned_to_nat(60u);
x_34 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_33, x_31);
x_35 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__6));
x_36 = lean_string_append(x_34, x_35);
x_37 = lean_unsigned_to_nat(61u);
x_38 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_37, x_32);
x_39 = lean_string_append(x_36, x_38);
lean_dec_ref(x_38);
x_40 = lean_nat_dec_lt(x_33, x_1);
if (x_40 == 0)
{
return x_39;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; 
x_41 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_42 = lean_string_append(x_41, x_39);
lean_dec_ref(x_39);
x_43 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_44 = lean_string_append(x_42, x_43);
return x_44;
}
}
case 6:
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; uint8_t x_54; 
x_45 = lean_ctor_get(x_2, 0);
x_46 = lean_ctor_get(x_2, 1);
x_47 = lean_unsigned_to_nat(56u);
x_48 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_47, x_45);
x_49 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__7));
x_50 = lean_string_append(x_48, x_49);
x_51 = lean_unsigned_to_nat(55u);
x_52 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_51, x_46);
x_53 = lean_string_append(x_50, x_52);
lean_dec_ref(x_52);
x_54 = lean_nat_dec_lt(x_51, x_1);
if (x_54 == 0)
{
return x_53;
}
else
{
lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; 
x_55 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_56 = lean_string_append(x_55, x_53);
lean_dec_ref(x_53);
x_57 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_58 = lean_string_append(x_56, x_57);
return x_58;
}
}
default: 
{
lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; uint8_t x_68; 
x_59 = lean_ctor_get(x_2, 0);
x_60 = lean_ctor_get(x_2, 1);
x_61 = lean_unsigned_to_nat(50u);
x_62 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_61, x_59);
x_63 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__8));
x_64 = lean_string_append(x_62, x_63);
x_65 = lean_unsigned_to_nat(51u);
x_66 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_65, x_60);
x_67 = lean_string_append(x_64, x_66);
lean_dec_ref(x_66);
x_68 = lean_nat_dec_lt(x_61, x_1);
if (x_68 == 0)
{
return x_67;
}
else
{
lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; 
x_69 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_70 = lean_string_append(x_69, x_67);
lean_dec_ref(x_67);
x_71 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_72 = lean_string_append(x_70, x_71);
return x_72;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec(x_2, x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toString(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(lean_object* x_1, lean_object* x_2) {
_start:
{
switch (lean_obj_tag(x_2)) {
case 0:
{
lean_object* x_3; 
x_3 = lean_ctor_get(x_2, 0);
lean_inc_ref(x_3);
return x_3;
}
case 1:
{
lean_object* x_4; 
x_4 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__0));
return x_4;
}
case 2:
{
lean_object* x_5; 
x_5 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__1));
return x_5;
}
case 3:
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; 
x_6 = lean_ctor_get(x_2, 0);
x_7 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__2));
x_8 = lean_unsigned_to_nat(80u);
x_9 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_8, x_6);
x_10 = lean_string_append(x_7, x_9);
lean_dec_ref(x_9);
x_11 = lean_unsigned_to_nat(75u);
x_12 = lean_nat_dec_lt(x_11, x_1);
if (x_12 == 0)
{
return x_10;
}
else
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_13 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_14 = lean_string_append(x_13, x_10);
lean_dec_ref(x_10);
x_15 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_16 = lean_string_append(x_14, x_15);
return x_16;
}
}
case 4:
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; uint8_t x_26; 
x_17 = lean_ctor_get(x_2, 0);
x_18 = lean_ctor_get(x_2, 1);
x_19 = lean_unsigned_to_nat(65u);
x_20 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_19, x_17);
x_21 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__3));
x_22 = lean_string_append(x_20, x_21);
x_23 = lean_unsigned_to_nat(66u);
x_24 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_23, x_18);
x_25 = lean_string_append(x_22, x_24);
lean_dec_ref(x_24);
x_26 = lean_nat_dec_lt(x_19, x_1);
if (x_26 == 0)
{
return x_25;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_27 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_28 = lean_string_append(x_27, x_25);
lean_dec_ref(x_25);
x_29 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_30 = lean_string_append(x_28, x_29);
return x_30;
}
}
case 5:
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; uint8_t x_40; 
x_31 = lean_ctor_get(x_2, 0);
x_32 = lean_ctor_get(x_2, 1);
x_33 = lean_unsigned_to_nat(60u);
x_34 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_33, x_31);
x_35 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__4));
x_36 = lean_string_append(x_34, x_35);
x_37 = lean_unsigned_to_nat(61u);
x_38 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_37, x_32);
x_39 = lean_string_append(x_36, x_38);
lean_dec_ref(x_38);
x_40 = lean_nat_dec_lt(x_33, x_1);
if (x_40 == 0)
{
return x_39;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; 
x_41 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_42 = lean_string_append(x_41, x_39);
lean_dec_ref(x_39);
x_43 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_44 = lean_string_append(x_42, x_43);
return x_44;
}
}
case 6:
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; uint8_t x_54; 
x_45 = lean_ctor_get(x_2, 0);
x_46 = lean_ctor_get(x_2, 1);
x_47 = lean_unsigned_to_nat(56u);
x_48 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_47, x_45);
x_49 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__5));
x_50 = lean_string_append(x_48, x_49);
x_51 = lean_unsigned_to_nat(55u);
x_52 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_51, x_46);
x_53 = lean_string_append(x_50, x_52);
lean_dec_ref(x_52);
x_54 = lean_nat_dec_lt(x_51, x_1);
if (x_54 == 0)
{
return x_53;
}
else
{
lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; 
x_55 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_56 = lean_string_append(x_55, x_53);
lean_dec_ref(x_53);
x_57 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_58 = lean_string_append(x_56, x_57);
return x_58;
}
}
default: 
{
lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; uint8_t x_68; 
x_59 = lean_ctor_get(x_2, 0);
x_60 = lean_ctor_get(x_2, 1);
x_61 = lean_unsigned_to_nat(50u);
x_62 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_61, x_59);
x_63 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___closed__6));
x_64 = lean_string_append(x_62, x_63);
x_65 = lean_unsigned_to_nat(51u);
x_66 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_65, x_60);
x_67 = lean_string_append(x_64, x_66);
lean_dec_ref(x_66);
x_68 = lean_nat_dec_lt(x_61, x_1);
if (x_68 == 0)
{
return x_67;
}
else
{
lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; 
x_69 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__3));
x_70 = lean_string_append(x_69, x_67);
lean_dec_ref(x_67);
x_71 = ((lean_object*)(lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toStringPrec___closed__4));
x_72 = lean_string_append(x_70, x_71);
return x_72;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatex(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatexPrec(x_2, x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatex___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_prop_x2dlogic_x2ddsl_PropLogicDSL_Formula_toLatex(x_1);
lean_dec(x_1);
return x_2;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_prop_x2dlogic_x2ddsl_PropLogicDSL_Prop(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_prop_x2dlogic_x2ddsl_PropLogicDSL_PrettyPrint(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_prop_x2dlogic_x2ddsl_PropLogicDSL_Prop(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
