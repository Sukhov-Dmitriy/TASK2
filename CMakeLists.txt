cmake_minimum_required(VERSION 3.5)

project(Ex23 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ex23 main.cpp functions.cpp CRat.cpp CRatFactory.cpp CRat.h CRatFactory.h functions.h)
