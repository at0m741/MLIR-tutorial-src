#ifndef TUTO_DIALECT
#define TUTO_DIALECT

include "mlir/IR/OpBase.td"

def Tuto_Dialect : Dialect {
    let name = "tuto";
    let summary = "A Tuto out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::tuto";
}


class Tuto_Op<string mnemonic, list<Trait> traits = []> :
        Op<Tuto_Dialect, mnemonic, traits>;

#endif // TUTO_DIALECT
