cmake_minimum_required(VERSION 3.10)

project("Turnierbaum")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories(src)

add_subdirectory(src)

cmake_path(SET GITIGNORE_FILE NORMALIZE "${CMAKE_BINARY_DIR}/.gitignore")
file(WRITE ${GITIGNORE_FILE} "*")
