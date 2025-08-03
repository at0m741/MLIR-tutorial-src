
#ifndef TUTO_TUTOOPS_H
#define TUTO_TUTOOPS_H

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "TutoDialect/TutoOps.h.inc"

#endif // TUTO_TUTOOPS_H
