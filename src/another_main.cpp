// #include "include/glad/glad.h"
#include <GL/glut.h> /* glut graphics library */
#include <GLFW/glfw3.h>
// #include <glad/gl.h>
#include <stdio.h>

#include <iostream>

#include "structures.hpp"

int Elemes[2][3]{{1, 2, 3}, {1, 4, 3}};
double Ncoords[4][3]{
    {-0.5, -0.5, 0}, {-0.5, 0.5, 0}, {0.5, 0.5, 0}, {0.5, -0.5, 0}};
int tr_number = 2;
void myKeyboard(unsigned char key, int x, int y) {
    // how to implement changing coords
    switch (key) {
        case 'a':
            /* code */
            break;
        case 'd':
            // do stuff
            break;
        case 'w':
            // do other stuff
            break;
        case 's':
            break;

        default:
            break;
    }
}
void myDisp() {
    glBegin(GL_TRIANGLES);
    glColor3d(0.1, 0.6, 0.3);
    for (int tr_index{}; tr_index < tr_number; tr_index++) {
        for (int vertex_index{}; vertex_index < 3; vertex_index++) {
            glVertex3d(Ncoords[Elemes[tr_index][vertex_index] - 1][0],
                       Ncoords[Elemes[tr_index][vertex_index] - 1][1],
                       Ncoords[Elemes[tr_index][vertex_index] - 1][2]);
        }
    }
    glEnd();
    glutSwapBuffers();
}
void myDisp2() {
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColor3d(0.1, 0.6, 0.3);
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Hello world!");

    glutDisplayFunc(myDisp);
    // while we run in these moment, laater we run in myDisp
    // glutKeyboardFunc(myKeyboard);
    // together run this function?
    // glutSpecialFunc(myKeyboard)
    glutMainLoop();

    return 0;
}