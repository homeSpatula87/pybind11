project(cpp_proj)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../../ ../)

pybind11_add_module(cpp_tests wrappers.cpp)
