
#ifndef TUTO_OPS_H
#define TUTO_OPS_H

include "TutoDialect.td"
include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/DialectBase.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def AddOp : Tuto_Op<"add", [Pure]> {
  let summary = "Addition";
  let description = [{
    Addition operation between two values.
  }];

  let arguments = (ins F64:$lhs, F64:$rhs);
  let results = (outs F64:$res);
  let assemblyFormat = [{
    $lhs `,` $rhs `:` type($lhs) attr-dict
  }];
}

#endif // TUTO_OPS_H
