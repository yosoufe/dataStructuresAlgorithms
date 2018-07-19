cmake_minimum_required(VERSION 2.8)

project(linkedList)

set(CMAKE_BUILD_TYPE DEBUG)

set(SRC_FILES
#    linkedlist.cpp
    linkedlist.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})

