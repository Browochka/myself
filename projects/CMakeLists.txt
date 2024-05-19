cmake_minimum_required(VERSION 3.2...3.27.5)

project(myself)

enable_testing()

add_subdirectory(lib/googletest)

set(SCL_LIB "scl_lib")
add_subdirectory(scl)

add_subdirectory(treesort)


set(CMAKE_SUPPRESS_REGENERATION true)