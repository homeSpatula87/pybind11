import cpp.build.cpp_tests as cpp
import time
import numpy as np



                  # testing class:
print("Testing class:")

test_obj = cpp.testClass("first", "last")
print(test_obj.give_full_name(), '\n', '\n')
print("\n\n")




                  # comparing for loops:
print("comparing for loops:")
big_list = list(map( lambda x: float(x), range(20000000)))

                  # cpp:
t_for_start_cpp = time.time()
cpp.squares(big_list)
print('cpp for loop time:', time.time() - t_for_start_cpp, '\n')

                  # python:
t_for_start_py = time.time()
tot_sum = 0
for idx in big_list:
    tot_sum += idx * idx
print(tot_sum)
print('py for loop time:', time.time() - t_for_start_py, '\n', '\n')




                  # compare dot products:
print("comparing dot products")
vec_tens = np.ones(10000000) * 10

                  # cpp conversion only:
t_conversion_s = time.time()
cpp.does_nothing(vec_tens, vec_tens)
t_conversion = time.time() - t_conversion_s
print('cpp conversion time:', t_conversion)

                  # cpp full dot product:
t_dot_prod_cpp = time.time()
cpp_prod = cpp.dot_prod(vec_tens, vec_tens)
t_dot_prod_total_cpp = time.time()
print('cpp dot prod total time:', t_dot_prod_total_cpp - t_dot_prod_cpp)
print('cpp dot prod time without conversion:', time.time() - t_dot_prod_cpp - t_conversion, '\n')

                  # numpy:
t_dot_prod_np = time.time()
np_prod = np.dot(vec_tens, vec_tens)
print('np dot prod time:', time.time() - t_dot_prod_np, '\n')


print('results of the dot products:', cpp_prod, np_prod)




