
add_mlir_dialect_library(MLIRTuto
  TutoDialect.cpp
  TutoOps.cpp
  TutoPass.cpp
  DEPENDS
    MLIRTutoOpsIncGen
  LINK_LIBS PUBLIC
    MLIRIR
)
