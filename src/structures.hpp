#include <GL/glut.h> /* glut graphics library */
#include <GLFW/glfw3.h>
// #include <glad/gl.h>
#include <stdio.h>

#include <fstream>
#include <iostream>
using namespace std;

struct Point {};
struct Triangle {
    /* data */
};
void readFile(ifstream& file, Point* point);
void createTriangle(Triangle& tr);