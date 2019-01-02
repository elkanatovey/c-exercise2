cmake_minimum_required(VERSION 3.12)
project(cpp_exercise2)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost COMPONENTS filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})

add_executable(cpp_exercise2 main.cpp fileParser.h signatureVector.h fileParser.cpp signatureVector.cpp)


#target_link_libraries(cpp_exercise2 ${Boost_LIBRARIES})

