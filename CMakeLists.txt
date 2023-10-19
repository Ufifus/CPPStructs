cmake_minimum_required(VERSION 3.27.0)

project(structs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

message("${PROJECT_NAME}: PATH = ${CMAKE_SOURCE_DIR}")

#---------Add libraries----------
#     Add and link libraries.
#--------------------------------

# Set paths to source code and includes .h files
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

# include .h dir
include_directories(${INCLUDE_PATH})

# include source libs
FILE(GLOB SRC_LIB "${SRC_PATH}/*.cpp")

message("${PROJECT_NAME}: INCLUDE FILES = ${SRC_LIB}")

add_library(${PROJECT_NAME} SHARED ${SRC_LIB})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${SRC_PATH}
)
