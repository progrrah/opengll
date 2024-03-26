#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#define WINDOW_TITLE_PREFIX "Start"
using namespace std;
size_t number_points = 4;
vector<vector<int>> points(number_points);
// for (auto& i : points) {
//   i.resize(3);
// };
void myDisp();
void myKeyboardMain(unsigned char, int, int);
void myKeyboardSpecial();
void myMouse(int, int, int, int);
void myRender();
void ResizeDisplay();
void myReshape(int, int);

/// @brief glut and glew init
void Init();
/// @brief window init, create, init display mode, color, size, position
void InitWindow();

void createPoints(GLuint number) {
  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(/**/ 2), points, GL_STATIC_DRAW);
}
