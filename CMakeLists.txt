cmake_minimum_required(VERSION 3.3)
project(rpn_calculator)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lginac -lcln") # for ginac
#project(assembler C ASM) # this enables building the assembly part of the code
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lfltk -lfltk_images")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lginac -lcln") # for ginac

set(SOURCE_FILES main.cpp rpn_calc.cpp rpn_calc.h)
add_executable(rpn_calculator
        main.cpp
        rpn_calc.cpp
        expression_tree.cpp
        linenoise/linenoise.c
        linenoise/linenoise.h)
add_executable(test_rpn_calculator 
    test_rpn_calculator.cpp 
    rpn_calc.cpp)
add_executable(test_cln 
    test_cln.cpp)
add_executable(test_divide_by_zero 
    test_divide_by_zero.cpp)
add_executable(linenoise_example 
    linenoise/linenoise.c 
    linenoise/example.c)
add_executable(expression_tree
        expression_tree.cpp
        rpn_calc.cpp test_expression_tree.cpp)