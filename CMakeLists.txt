cmake_minimum_required(VERSION 3.28)
project(opengl LANGUAGES C CXX)
# add_compile_options(-Wall -ggdb)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(GLAD REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtkmm-3.0)

# add_library(glad "${PROJECT_SOURCE_DIR}/src/glad.c")
# add_executable(glad "src/glad.c")
# add_executable(opengl src/main.cpp)
add_executable(another src/another_main.cpp)
add_subdirectory(externel/glfw)
# add_executable(clear src/clear.cpp)

# target_link_libraries(opengl OpenGL::GL GLUT::GLUT)
target_include_directories(another
PUBLIC src 
PUBLIC inlcude
PUBLIC externel/glfw/include
PUBLIC externel/glfw/deps
)
target_link_directories(another PRIVATE externel/glfw/src PRIVATE externel/glfw/deps)
target_link_libraries(another OpenGL::GL GLUT::GLUT glfw)



add_executable(boing externel/glfw/examples/boing.c)

target_include_directories(boing  
PUBLIC externel/glfw/include
PUBLIC externel/glfw/deps
PUBLIC externel/glfw/deps/glad 
PUBLIC usr/include)

target_link_directories(boing PRIVATE externel/glfw/src)
target_link_libraries(boing glfw)


add_executable(heightmap externel/glfw/examples/heightmap.c)
target_include_directories(heightmap PUBLIC externel/glfw/include
PUBLIC externel/glfw/deps
PUBLIC externel/glfw/deps/glad 
PUBLIC usr/include
${GTKMM_INCLUDE_DIRS})

target_link_directories(heightmap PRIVATE
externel/glfw/src
${GTKMM_LIBRARY_DIRS})

target_link_libraries(heightmap PRIVATE glfw  PRIVATE ${GTKMM_LIBRARIES})
target_compile_definitions(heightmap PRIVATE ${GTKMM_CFLAGS_OTHER})