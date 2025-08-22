
#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <mlir/Dialect/Linalg/IR/Linalg.h>
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "TutoDialect/TutoDialect.h"
#include "TutoDialect/TutoOpsDialect.cpp.inc"
#include "mlir/Dialect/Func/IR/FuncOps.h"

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;
  registry.insert<mlir::tuto::TutoDialect>();
  registry.insert<mlir::arith::ArithDialect>();
  registry.insert<mlir::math::MathDialect>();
  registry.insert<mlir::tensor::TensorDialect>();
  registry.insert<mlir::affine::AffineDialect>();
  registry.insert<mlir::linalg::LinalgDialect>();
  registry.insert<mlir::memref::MemRefDialect>();
  registry.insert<mlir::LLVM::LLVMDialect>();
  registry.insert<mlir::func::FuncDialect>();
  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "Tuto optimizer driver\n", registry));
}
