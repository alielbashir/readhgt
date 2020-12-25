cmake_minimum_required(VERSION 3.17)
project(readhgt)

set(CMAKE_CXX_STANDARD 14)
SET(OpenCV_DIR /home/ali/installation/OpenCV-master/lib/cmake/opencv4)
add_executable(readhgt main.cpp readhgt.cpp readhgt.h)