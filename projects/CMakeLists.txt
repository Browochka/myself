cmake_minimum_required(VERSION 3.2...3.27.5)

project(myself)

enable_testing()

add_subdirectory(lib/googletest)

add_subdirectory(treesort)
add_subdirectory(unit_test_example)

set(CMAKE_SUPPRESS_REGENERATION true)