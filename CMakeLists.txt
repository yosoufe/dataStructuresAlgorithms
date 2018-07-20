cmake_minimum_required(VERSION 2.8)

project(dataStructures)

set(CMAKE_BUILD_TYPE DEBUG)

# tree.h

add_executable(linkedlist_example mainLinkedList.cpp linkedlist.h)
add_executable(stack_example mainStack.cpp)
add_executable(queue_example queueExample.cpp)
add_executable(main main.cpp dynamicarray.h binaryheap.h)
