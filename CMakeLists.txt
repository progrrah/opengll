cmake_minimum_required(VERSION 3.27)
project(opengl LANGUAGES C CXX)
set(HEADERS src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
set(SOURCES src externel/glfw/src externel/glfw/deps externel/glut/src)

add_executable(clear src/clear.cpp)
add_subdirectory(externel/glfw)
add_subdirectory(externel/glut)
add_subdirectory(externel/glew/build/cmake)
target_include_directories(clear PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(clear PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)

target_link_libraries(clear PRIVATE glfw freeglut glew)

add_executable(boing externel/glfw/examples/boing.c)

target_include_directories(boing
    PUBLIC src
    PUBLIC inlcude
    PUBLIC externel/glfw/include
    PUBLIC externel/glfw/deps
    PUBLIC externel/glut/include
    PUBLIC usr/include)

target_link_directories(boing PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)

target_link_libraries(boing PRIVATE glfw glut glew)
