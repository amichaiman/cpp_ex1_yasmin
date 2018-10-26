cmake_minimum_required(VERSION 3.10)
project(cpp_ex1)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp_ex1 main.cpp Players.cpp Players.h Player.cpp Player.h)