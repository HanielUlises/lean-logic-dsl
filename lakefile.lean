import Lake
open Lake DSL

package «prop-logic-dsl» where

lean_lib «PropLogicDSL» where

@[default_target]
lean_exe «prop-logic-dsl» where
  root := `Main
