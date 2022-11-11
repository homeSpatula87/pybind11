**Requirements:**  <br>
python3 <br>
numpy (python package)<br>
CMake >= 3.10 <br>
A C++-17 compatible compiler from the supported compiler list on this page: https://pybind11.readthedocs.io/en/latest/. <br>



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
    |-- /cpp
     	|
     	|-- CMakesList.txt
     	|-- wrappers.cpp
     	|-- /build
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
    the generated library (it is python version and operating system dependent, probably will not work without building it yourself)


**IMPORTANT:**<br>  
As the generated library will be specific to your operating system
and python version, so I suggest you build it yourself (Extra details for Ubuntu and VisualStudio 2022 below).

This is done as follows: <br>
1) make sure you satisfy the requirements listed at the top of this directory. <br>
2) navigate to the build directory. <br>
3) run the command "cmake .." <br>
4) Depending on what operating system you are working and what compiler you are using this step will vary (cmake will automatically pick a build method based on what is available).
Step 3 will generate some files, which are then used to build the library.
Now the new library should be visible in the build folder, the name will probably by cpp_test._\<something relating to you python version and operating system\>_._\<some extension\>_. <br>
5) To test it, make sure that the library is in the build folder.
Whether this is the case or not will depend on what the ```cmake ..``` command generated. <br>
6) Then navigate to the `practice` folder and run ```python3 test.py```. <br>

It took me less than 1 min to perform the tests. If it seems to be taking
longer for you, you can edit the test.py file to be dealing with shorter
lists / arrays.

**Conclusion:** <br>
Not that hard to use.
Thew performance benefits might seem disappointing, but for these basic
operations it was as I expected.
(Also note, numpy is written in C, I don't think you should be using
pybind11 to compete with operations in-built in numpy)

**Detailed guide for Ubuntu:**<br><br>
The ```cmake ..``` command should generate a makefile, in which case you need need to run the command "make" to finish building the library.

**Detailed guide VisualStudio 2022:**<br><br>
The ```cmake ..``` command should generate a project file (.sln), which you then need to build by opening it as a project first.
Before you build it, you need to set the compiler version to C++17 or higher (default is C++14), via project properties.
When you build the file, depending on your CMake preferences, the library might not be in the ```build``` folder.
With default setting the library will be put in a new ```Debug``` folder.
The library should then be a .pyd file.
