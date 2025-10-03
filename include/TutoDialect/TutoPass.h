
#ifndef TUTO_PASS_H
#define TUTO_PASS_H

#include "mlir/Pass/Pass.h"

namespace mlir {
namespace tuto {

std::unique_ptr<mlir::Pass> createLowerPolyApplyPass();

void registerTutoPasses();

} // namespace tuto
} // namespace mlir

#endif
