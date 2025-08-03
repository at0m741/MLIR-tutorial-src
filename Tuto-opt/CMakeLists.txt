get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
		MLIRTuto
        MLIROptLib
        )
add_llvm_executable(Tuto-opt Tuto-opt.cpp)

llvm_update_compile_flags(Tuto-opt)
target_link_libraries(Tuto-opt PRIVATE ${LIBS})
