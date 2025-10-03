
#include "TutoDialect/TutoPass.h"
#include "TutoDialect/TutoOps.h"

#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;
using namespace mlir::tuto;

namespace {

struct LowerPolyApplyPass
    : public PassWrapper<LowerPolyApplyPass, OperationPass<mlir::ModuleOp>> {
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(LowerPolyApplyPass)

  void runOnOperation() override {
    mlir::ModuleOp module = getOperation();

    module.walk([&](tuto::PolyApplyOp op) {
      Region &region = op.getBody();

      if (!region.empty()) {
        Block *parentBlock = op->getBlock();
        auto &ops = region.front().getOperations();
        parentBlock->getOperations().splice(op->getIterator(), ops);
      }

      op.erase(); 
    });
  }

  StringRef getArgument() const final { return "lower-polyapply"; }
  StringRef getDescription() const final {
    return "Inline the body of tuto.polyapply ops.";
  }
};

} // end anonymous namespace

std::unique_ptr<mlir::Pass> mlir::tuto::createLowerPolyApplyPass() {
  return std::make_unique<LowerPolyApplyPass>();
}

void mlir::tuto::registerTutoPasses() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return std::make_unique<LowerPolyApplyPass>();
  });
}
