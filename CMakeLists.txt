cmake_minimum_required(VERSION 3.26)
project(credit)

set(CMAKE_CXX_STANDARD 17)

add_executable(credit main.cpp
        Credit.h
        Credit.cpp)
