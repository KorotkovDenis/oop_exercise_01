cmake_minimum_required(VERSION 3.2)

project(lab1)

add_executable(lab1
        main.cpp
        Money.cpp
)

set_property(TARGET lab1 PROPERTY CXX_STANDART 11)