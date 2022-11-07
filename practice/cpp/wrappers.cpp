#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include <vector>    // vectors
#include <numeric>   // transform_reduce
#include <iostream>

namespace py = pybind11;




                  // simple function test compare for-loop speeds,
                  // calculates the sum of squares for a python list as input:
void for_loop_squares(py::list lst)
{
    float total = 0;
    for (auto item : lst)
        total += (item * item).cast<float>();
    py::print(total);
}



                  // simple C++ class encapsulating pairs of strings:
class testClass
{
                  // declared as python strings:
    py::str d_first_name;
    py::str d_last_name;
    
    public:
                  // constructor:
        testClass(py::str const &first_name, py::str const &last_name)
        :
            d_first_name(first_name),
            d_last_name(last_name)
        {   
        }
                  // return a python tuple:
        py::tuple give_full_name() const
        {
            return py::make_tuple(d_first_name, d_last_name);
        }
};


                  // simple implementation of a dot-product:
template <typename T>
T dot_prod(std::vector<T> const &vec0, std::vector<T> const &vec1)
{
    return std::transform_reduce
            (
                vec0.begin(),
                vec0.end(),
                vec1.begin(),
                0
            );
}

                  // we let the previous function take std::vectors as input,
                  // thus python types need to be converted, we use the
                  // following function to be able to be able measure how long
                  // this conversion takes
template <typename T>
void does_nothing(std::vector<T> const &vec0, std::vector<T> const &vec1)
{
}


PYBIND11_MODULE(cpp_tests, m)
{
                  // optional module docstring
    m.doc() = "pybind11 tests"; 

                  // binding C++ code to python code, the structure is:
                  // m.def(<python_name>, <reference_to_func>, <description>) 
    m.def("squares", &for_loop_squares, "calc.'s sum of squares");
    
                  // binding the class:
    py::class_<testClass>(m, "testClass")
        .def(py::init<py::str const &, py::str const &>())
        .def("give_full_name", &testClass::give_full_name);

                  // More binding (It does not seem possible to bind to the
                  // template-ed function (without specifying a type), as
                  // without instantiating the template, the function will
                  // not have an address, so we can't pass a reference):
    m.def("dot_prod", &dot_prod<int>, "integer dot product (int)");
    m.def("does_nothing", &does_nothing<int>, "does absolutely nothing (int)");
    m.def("dot_prod", &dot_prod<float>, "integer dot product (float)");
    m.def("does_nothing", &does_nothing<float>, "does absolutely nothing (float)");

}