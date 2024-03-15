// #include "include/glad/glad.h"
#include <GL/glut.h> /* glut graphics library */
#include <iostream>
#include <stdio.h>

int Elemes[2][3]{{1, 2, 3}, {1, 4, 3}};
double Ncoords[4][3]{
    {-0.5, -0.5, 0}, {-0.5, 0.5, 0}, {0.5, 0.5, 0}, {0.5, -0.5, 0}};
void myDisp() {
  int i{0};
  glBegin(GL_TRIANGLES);
  glColor3d(0.1, 0.6, 0.3);
  for (int j = 0; j < 3; j++) {
    glVertex3d(Ncoords[Elemes[i][j]][0], Ncoords[Elemes[i][j]][1],
               Ncoords[Elemes[i][j]][2]);
  }
  glEnd();
  glutSwapBuffers();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  glutCreateWindow("Hello world!");

  glutDisplayFunc(myDisp);

  glutMainLoop();

  return 0;
}