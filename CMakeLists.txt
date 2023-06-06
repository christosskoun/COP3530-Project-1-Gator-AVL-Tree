cmake_minimum_required(VERSION 3.25)
project(Project_1_Gator_AVL_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_1_Gator_AVL_Project
        AVL_Tree.h
        main.cpp)
