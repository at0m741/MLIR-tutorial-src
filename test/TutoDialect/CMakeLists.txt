configure_lit_site_cfg(
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
  ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
)

set(TUTO_DIALECT_TEST_DEPENDS
  FileCheck count not
  TutoDialect
)

add_lit_testsuite(check-tuto-dialect "Running the TutoDialect tests"
  ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${TUTO_DIALECT_TEST_DEPENDS}
)
add_lit_testsuites(TUTO_DIALECT ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${TUTO_DIALECT_TEST_DEPENDS})
