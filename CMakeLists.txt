cmake_minimum_required(VERSION 2.8)

project(dataStructures)

set(CMAKE_BUILD_TYPE DEBUG)

add_executable(linkedlist_example mainLinkedList.cpp linkedlist.h)
add_executable(stack_example mainStack.cpp)
add_executable(queue_example queueExample.cpp)
