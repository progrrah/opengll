cmake_minimum_required(VERSION 3.27)
project(opengl LANGUAGES C CXX)
set(HEADERS src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
set(SOURCES src externel/glfw/src externel/glfw/deps externel/glut/src)

add_subdirectory(externel/glfw)
add_subdirectory(externel/glut)
add_subdirectory(externel/glew/build/cmake)

add_executable(another_main src/another_main.cpp)
target_include_directories(another_main PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(another_main PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(another_main PRIVATE freeglut glew)

add_library(other_genius_thing src/other_genius_thing.cpp)
target_include_directories(other_genius_thing PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(other_genius_thing PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(other_genius_thing PRIVATE freeglut glew)

add_library(stuff src/stuff.cpp)
target_include_directories(stuff PUBLIC
    src inlcude
    externel/glfw/include
    externel/glfw/deps
    externel/glut/include)
target_link_directories(stuff PRIVATE
    externel/glfw/src
    externel/glfw/deps
    externel/glut/src)
target_link_libraries(stuff PRIVATE freeglut glew)

add_executable(clear src/clear.cpp)
target_include_directories(clear PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(clear PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(clear PRIVATE freeglut glew other_genius_thing stuff)