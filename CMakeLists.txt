cmake_minimum_required(VERSION 3.27)
project(opengl LANGUAGES C CXX)

# add_subdirectory(externel/glfw)
add_subdirectory(externel/glut)
add_subdirectory(externel/glew/build/cmake)

# add_executable(another_main src/another_main.cpp)
# target_include_directories(another_main PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
# target_link_directories(another_main PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
# target_link_libraries(another_main PRIVATE freeglut glew)

# add_library(other_genius_thing src/other_genius_thing.cpp)
# target_include_directories(other_genius_thing PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
# target_link_directories(other_genius_thing PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
# target_link_libraries(other_genius_thing PRIVATE freeglut glew)

# add_library(stuff src/stuff.cpp)
# target_include_directories(stuff PUBLIC
# src inlcude
# externel/glfw/include
# externel/glfw/deps
# externel/glut/include)
# target_link_directories(stuff PRIVATE
# externel/glfw/src
# externel/glfw/deps
# externel/glut/src)
# target_link_libraries(stuff PRIVATE freeglut glew)

# add_executable(clear src/clear.cpp)
# target_include_directories(clear PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
# target_link_directories(clear PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
# target_link_libraries(clear PRIVATE freeglut glew other_genius_thing stuff)
add_executable(temp src/temp.cpp)
target_include_directories(temp PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(temp PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(temp PRIVATE freeglut glew temp_lib)

add_library(temp_lib src/temp_lib.cpp)
target_include_directories(temp_lib PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(temp_lib PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(temp_lib PRIVATE freeglut glew)

add_executable(abr src/abr.cpp)
target_include_directories(abr PUBLIC src inlcude externel/glfw/include externel/glfw/deps externel/glut/include)
target_link_directories(abr PRIVATE externel/glfw/src externel/glfw/deps externel/glut/src)
target_link_libraries(abr PRIVATE freeglut glew)

set(GREAT_EXAMPLES_SRC GREAT_EXAMPLES/abgr.c GREAT_EXAMPLES/bitfont.c GREAT_EXAMPLES/cube.c)
set(GREAT_EXAMPLES_NAME abgr bitfont cube)

list(GET GREAT_EXAMPLES_SRC 0 EX1)
list(GET GREAT_EXAMPLES_NAME 0 EX1_NAME)

list(GET GREAT_EXAMPLES_SRC 1 EX2)
list(GET GREAT_EXAMPLES_NAME 1 EX2_NAME)

list(GET GREAT_EXAMPLES_SRC 2 EX3)
list(GET GREAT_EXAMPLES_NAME 2 EX3_NAME)

add_executable(${EX1_NAME} ${EX1})
target_include_directories(${EX1_NAME} PUBLIC externel/glut/include)
target_link_directories(${EX1_NAME} PUBLIC externel/glut/src)
target_link_libraries(${EX1_NAME} freeglut glew)

add_executable(${EX2_NAME} ${EX2})
target_include_directories(${EX2_NAME} PUBLIC externel/glut/include)
target_link_directories(${EX2_NAME} PUBLIC externel/glut/src)
target_link_libraries(${EX2_NAME} freeglut glew)

add_executable(${EX3_NAME} ${EX3})
target_include_directories(${EX3_NAME} PUBLIC externel/glut/include)
target_link_directories(${EX3_NAME} PUBLIC externel/glut/src)
target_link_libraries(${EX3_NAME} freeglut glew)
