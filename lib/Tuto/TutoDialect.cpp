
#include "TutoDialect/TutoDialect.h"
#include "TutoDialect/TutoOps.h"

#include "mlir/IR/DialectImplementation.h"

using namespace mlir;
using namespace mlir::tuto;


void TutoDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "TutoDialect/TutoOps.cpp.inc"
  >();
}

