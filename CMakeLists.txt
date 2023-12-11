cmake_minimum_required(VERSION 3.26)
project(FunctionCalculation)

set(CMAKE_CXX_STANDARD 20)

add_executable(FunctionCalculation main.cpp
        src/Function.h
        src/QuadraticFunction.cpp
        src/QuadraticFunction.h
        src/FunctionCalculation.cpp
        src/FunctionCalculation.h
        src/CsvWriter.cpp
        src/CsvWriter.h
        src/AbsFunction.cpp
        src/AbsFunction.h
        src/CosineFunction.cpp
        src/CosineFunction.h)
