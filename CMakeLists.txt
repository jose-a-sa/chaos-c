cmake_minimum_required(VERSION 3.2)
project(chaos_map)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

include_directories("/opt/homebrew/include")
include_directories("${CMAKE_BINARY_DIR}/../include")
link_directories("${CMAKE_BINARY_DIR}/../lib")

set(SOURCE_FILES
    src/logistic_map.c
    src/standard.c
    src/main.c
    )

add_executable(chaos_map ${SOURCE_FILES})