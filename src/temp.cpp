#include <stdlib.h>
#include <GL/freeglut.h>
#include "temp_lib.hpp"

void createSierpinski() { float p{}; }

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Piramide");

  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutSpecialFunc(specialKeys);

  // наши новые функции
  glutKeyboardFunc(normalKeys);
  glutSpecialFunc(specialKeys);

  glutMainLoop();

  return 1;
}