// main function for opengl init and other
#include <GL/glut.h>
float red = 1.0f, blue = 1.0f, green = 1.0f;
double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
void createbodies() {
  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 1.0, 0.5);
  glVertex3d(0.5, 0, 0);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3d(0, 1, 0);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3d(-0.5, 0, 0);

  glColor3f(1.0, 1.0, 0.0);
  glVertex3d(0.5, 0, 0);
  glColor3f(1.0, 1.0, 0.0);
  glVertex3d(0, 1, 0);
  glColor3f(1.0, 1.0, 0.0);
  glVertex3d(0, 0, 0.5);

  glColor3f(1.0, 0.0, 1.0);
  glVertex3d(0, 0, 0.5);
  glColor3f(1.0, 0.0, 1.0);
  glVertex3d(0, 1, 0);
  glColor3f(0.7, 0.0, 1.0);
  glVertex3d(-0.5, 0, 0);

  glColor3f(1.0, 0.5, 0.0);
  glVertex3d(0.5, 0, 0);
  glColor3f(1.0, 0.5, 0.0);
  glVertex3d(0, 0, 0.5);
  glColor3f(0.7, 0.5, 0.0);
  glVertex3d(-0.5, 0, 0);
  glEnd();
}
void changeSize(int w, int h) {
  // предотвращение деления на ноль
  if (h == 0) h = 1;
  float ratio = w * 1.0 / h;
  // используем матрицу проекции
  glMatrixMode(GL_PROJECTION);
  // обнуляем матрицу
  glLoadIdentity();
  // установить параметры вьюпорта
  glViewport(0, 0, w, h);
  // установить корректную перспективу
  gluPerspective(45.0f, ratio, 0.1f, 100.0f);
  // вернуться к матрице проекции
  glMatrixMode(GL_MODELVIEW);
}
void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  // TODO: РАЗОБРАТЬСЯ С КАМЕРОЙ
  gluLookAt(0.1f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  glRotatef(rotate_z, 0., 0., 1.);
  createbodies();
  glutSwapBuffers();
}
// TODO: WHY WE GIVE A TWO VARS
void specialKeys(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_RIGHT:
      rotate_y += 5;
      break;
    case GLUT_KEY_LEFT:
      rotate_y -= 5;
      break;
    case GLUT_KEY_UP:
      rotate_x += 5;
      break;
    case GLUT_KEY_DOWN:
      rotate_x -= 5;
  }
}
void normalKeys(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
      rotate_z += 5;
      break;
    case 's':
      rotate_z -= 5;
      break;
    case 27:
      exit(0);
      break;
  }
}