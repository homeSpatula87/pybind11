project(kf_code)
cmake_minimum_required(VERSION 3.10)

add_subdirectory(../../ ../)

pybind11_add_module(cpp_tests wrappers.cpp)