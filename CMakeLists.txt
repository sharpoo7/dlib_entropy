cmake_minimum_required(VERSION 2.8)
project(entropy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(dlib REQUIRED)

set(SRC_LIST
    main.cpp)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)


add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${dlib_LIBS})

add_executable(txt2bin txt2bin.cpp)
add_executable(bin2txt bin2txt.cpp)

