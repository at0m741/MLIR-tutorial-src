// RUN: mlir-opt %s | FileCheck %s

func.func @add_example(%arg0: f64, %arg1: f64) -> f64 {
  %res = tuto.add %arg0, %arg1 : f64
  return %res : f64
}

// CHECK: tuto.add
