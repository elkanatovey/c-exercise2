cmake_minimum_required(VERSION 3.12)
project(cpp_exercise2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_exercise2 main.cpp fileParser.h signatureVector.h fileParser.cpp signatureVector.cpp)