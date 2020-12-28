cmake_minimum_required(VERSION 3.16)
project(CGAssignment)

set(CMAKE_CXX_STANDARD 14)

set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dependencies)
# Opengl Init

find_package(OpenGL REQUIRED)

# GLEW Init
add_subdirectory(${DEPENDENCIES_DIR}/glew)
include_directories(${DEPENDENCIES_DIR}/glew/include/ src/utils)

# GLFW Init
add_subdirectory(${DEPENDENCIES_DIR}/glfw)
include_directories(${DEPENDENCIES_DIR}/glfw/include/)

# FreeGLUT Init
add_subdirectory(${DEPENDENCIES_DIR}/freeglut)
include_directories(${DEPENDENCIES_DIR}/freeglut/include/)

# for header only libraries (eigen3, glm)
include_directories(${DEPENDENCIES_DIR}/include)

# add utils library
add_library(utils
        src/utils/LoadShaders.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_SOURCE_DIR src)
set(ASSIGNMENTS assignment0)

add_executable(assignment0 src/assignment0/main.cpp src/assignment0/Loader.h src/assignment0/Loader.cpp src/assignment0/camera.h src/assignment0/camera.cpp)

foreach(ASSIGNMENT ${ASSIGNMENTS})
    target_link_libraries(${ASSIGNMENT} utils ${OPENGL_LIBRARIES} glew freeglut freeglut_static glfw)
endforeach(ASSIGNMENT)
