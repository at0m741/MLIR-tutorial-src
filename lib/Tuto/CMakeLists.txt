
add_mlir_dialect_library(MLIRTuto
  TutoDialect.cpp
  TutoOps.cpp
  DEPENDS
    MLIRTutoOpsIncGen
  LINK_LIBS PUBLIC
    MLIRIR
)
