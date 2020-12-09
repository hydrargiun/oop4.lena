cmake_minimum_required(VERSION 3.17)
project(oop4_lena)

set(CMAKE_CXX_STANDARD 14)
add_library(Table Table.cpp Table.h)
link_libraries(Table)
add_executable(oop4_lena main.cpp)