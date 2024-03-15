cmake_minimum_required(VERSION 3.28)
project(opengl VERSION 0.1.0 LANGUAGES C CXX)
add_compile_options(-Wall -ggdb)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(GLAD REQUIRED)

# add_library(glad "${PROJECT_SOURCE_DIR}/src/glad.c")
# add_executable(glad "src/glad.c")
# add_executable(opengl src/main.cpp)
add_subdirectory(externel/glfw)
add_executable(another another_main.cpp)
# add_executable(clear src/clear.cpp)

# target_link_libraries(opengl OpenGL::GL GLUT::GLUT)
target_link_libraries(another OpenGL::GL GLUT::GLUT)

