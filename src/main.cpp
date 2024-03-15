#include <GL/glut.h> /* glut graphics library */
#include <stdio.h>
void myDisp() {
  // glBegin(GL_LINES);
  // glVertex2s(-1, -1);
  // glVertex2s(1, 1);
  // glEnd();
  glBegin(GL_TRIANGLES);
  glColor3d(0.1, 0.1, 0.1);
  glVertex2s(-1, -1);
  glVertex2s(0, 0);
  glVertex2s(1, 1);
  glEnd();
  glBegin(GL_TRIANGLES);
  glColor3d(1.0, 0.2, 0.7);
  glVertex2s(-1, -1);
  glVertex2s(0, 1);
  glVertex2s(1, 1);
  glEnd();
  // glBegin()
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

  printf("Hello world!");
  return 0;
}