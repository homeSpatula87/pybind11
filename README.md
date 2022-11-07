**Requirements:**  <br>
python3 <br>
numpy <br>
time <br>
CMake >= 3.10 <br>
A C++-11 compatible compiler. <br>
(If you are on ubuntu, almost surely you will have g++ of a sufficient version)


**Info:** <br>
pybind11 is a library for binding c++ (11 and up) code to python.
This can be useful for recycling existing C++ code, and for trying to exploit
the performance benefits of C++.
(In particular I believe pybind11 is in pytorch, a frequently used python library
for deep learning applications)


All my code is in the "practice" folder.
the folder / file structure is as follows:
```
./practice
    |
    |-- test.py
    |-- tests.txt
    |-- cpp
     	|
     	|-- CMakesList.txt
     	|-- wrappers.cpp
     	|-- build
            |
            |-- cpp_tests.cpython-310-x86_64-linux-gnu.so
```
File descriptions:

*test.py:*
    the python file testing the library.
    
*tests.txt:*
    a text files with the output of test.py
    
*CMakesList.txt:*
    The CMake file used for building the library
    
*wrappers.cpp:*
    The cpp file containing the cpp code and using the pybind11
    code for linking cpp tp python
    
*cpp_tests.cpython-310-x86_64-linux-gnu.so:*
    the generated library


**IMPORTANT:**<br>  
The generated library will be specific to your operating system
and python version, so I suggest you build it yourself.

This is done as follows: <br>
1) make sure you satisfy the requirements in requirements.txt. <br>
2) navigate to the build directory. <br>
3) run the command "cmake .." <br>
4) run the command "make" <br>

Now the new library should be visible in the build folder.

To test it, navigate the the `practice` folder and run "python3 test.py".
It took me less than 1 min to perform the tests. If it seems to be taking
longer for you, you can edit the test.py file to be dealing with shorter
lists / arrays.

**Conclusion:** <br>
Not that hard to use.
Thew performance benefits might seem disappointing, but for these basic
operations it was as I expected.
(Also note, numpy is written in C, I don't think you should be using
pybind11 to compete with operations in-built in numpy)
