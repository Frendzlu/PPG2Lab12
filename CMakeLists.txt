cmake_minimum_required(VERSION 3.26)
project(PPG2Lab12)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/csg2d)

add_executable(PPG2Lab12
        src/csg2d/Circle.cpp
        src/csg2d/Circle.h
        src/csg2d/functions.cpp
        src/csg2d/functions.h
        src/csg2d/libincludes.h
        src/csg2d/main.cpp
        src/csg2d/operation.h
        src/csg2d/shape.cpp
        src/csg2d/shape.h
        src/csg2d/Rectangle.cpp
        src/csg2d/Rectangle.h
        src/csg2d/ComplexShape.cpp
        src/csg2d/ComplexShape.h)
