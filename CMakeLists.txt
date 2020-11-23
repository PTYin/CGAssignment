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

# add utils library
add_library(utils
        src/utils/LoadShaders.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(ASSIGNMENTS assignment0)

foreach(ASSIGNMENT ${ASSIGNMENTS})
    add_executable(${ASSIGNMENT} src/${ASSIGNMENT}/main.cpp)
    target_link_libraries(${ASSIGNMENT} utils ${OPENGL_LIBRARIES} glew freeglut freeglut_static)

endforeach(ASSIGNMENT)



## FreeGLUT Init
#if (${FLAG} MATCHES "GLUT")
#    add_subdirectory(${DEPENDENCIES_DIR}/freeglut)
#    include_directories(${DEPENDENCIES_DIR}/freeglut/include/)
##    link_directories(${CMAKE_BINARY_DIR}/lib ${CMAKE_BINARY_DIR}/dependencies/freeglut/lib)
##    # GLUT + GLEW
#    target_link_libraries(CGAssignment ${OPENGL_LIBRARIES} glew freeglut)
##    set(LIBRARIES ${OPENGL_LIBRARIES}
##            debug freeglutd debug freeglut_staticd optimized freeglut optimized freeglut_static
##            debug libglew32d debug glew32d optimized libglew32 optimized glew32)
#endif (${FLAG} MATCHES "GLUT")
