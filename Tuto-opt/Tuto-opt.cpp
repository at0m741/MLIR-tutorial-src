#include "TutoDialect/TutoDialect.h"
#include "TutoDialect/TutoOpsDialect.cpp.inc"
#include "TutoDialect/TutoPass.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Linalg/IR/Linalg.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/CommandLine.h"

int main(int argc, char **argv) {
  mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
    return mlir::tuto::createLowerPolyApplyPass();
  });

  mlir::DialectRegistry registry;
  registry.insert<
      mlir::tuto::TutoDialect,
      mlir::arith::ArithDialect,
      mlir::math::MathDialect,
      mlir::tensor::TensorDialect,
      mlir::affine::AffineDialect,
      mlir::linalg::LinalgDialect,
      mlir::memref::MemRefDialect,
      mlir::LLVM::LLVMDialect,
      mlir::func::FuncDialect,
      mlir::scf::SCFDialect>();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "Tuto optimizer driver\n", registry));
}
