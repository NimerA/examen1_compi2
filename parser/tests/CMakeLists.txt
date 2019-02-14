cmake_minimum_required (VERSION 2.6)
project (test_parser)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14" )

# We use a custom lemon version
add_executable(lemon ${PROJECT_SOURCE_DIR}/../tools/lemon.c)

# Run lemon to generate the parser
add_custom_command (
  OUTPUT expr_parser.cpp expr_parser.h
  COMMAND lemon -T${PROJECT_SOURCE_DIR}/../tools/lempar.c -dexpr_parser.h -oexpr_parser.cpp ${PROJECT_SOURCE_DIR}/../expr.y
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/../expr.y
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
  
add_executable(test_parser expr_parser.cpp
                          test_parser.cpp)

enable_testing()
add_test(NAME test_parser
         COMMAND test_parser)
