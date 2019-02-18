cmake_minimum_required(VERSION 3.0)
project(cls_2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}\
    -Wall\
    -Werror\
    -Wpedantic\
")

add_executable(task_1_test task_1/test.cpp)
add_executable(task_2_test task_2/test.cpp)
#add_executable(task_3_test task_3/test.cpp)

#add_executable(workshop workshop.cpp)
