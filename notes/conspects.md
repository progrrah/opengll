# The collection of conspects of opengl progamming

## The features of opengl

## The graphics programming concepts

## The opengl programming step

### 1.create windows

```cpp
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#define WINDOW_TITLE_PREFIX "Chapter 1"

int
  CurrentWidth = 800,
  CurrentHeight = 600,
  WindowHandle = 0;

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);

int main(int argc, char* argv[])
{
  Initialize(argc, argv);

  glutMainLoop();
  
  exit(EXIT_SUCCESS);
}

void Initialize(int argc, char* argv[])
{
  InitWindow(argc, argv);
  
  fprintf(
    stdout,
    "INFO: OpenGL Version: %s\n",
    glGetString(GL_VERSION)
  );

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void InitWindow(int argc, char* argv[])
{
    // initialize glut library
  glutInit(&argc, argv);
  
  glutInitContextVersion(4, 0);
  glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
  glutInitContextProfile(GLUT_CORE_PROFILE);

  glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
  );
  
  glutInitWindowSize(CurrentWidth, CurrentHeight);

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

  WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

  if(WindowHandle < 1) {
    fprintf(
      stderr,
      "ERROR: Could not create a new rendering window.\n"
    );
    exit(EXIT_FAILURE);
  }

  glutReshapeFunc(ResizeFunction);
  glutDisplayFunc(RenderFunction);
}

void ResizeFunction(int Width, int Height)
{
  CurrentWidth = Width;
  CurrentHeight = Height;
  glViewport(0, 0, CurrentWidth, CurrentHeight);
}

void RenderFunction(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glutSwapBuffers();
  glutPostRedisplay();
}

```

#### the table of functions

1) glutInit(int argc, char** argv) - initialize glut library in programm
2) glGetString(GL_VERSION) -
3) glClearColor(0,0,0) - set a new color by background
4) glutInitWindowSize()
5) glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
6) glutCreateWindow(name of window)
7) glutReshapeFunc(ResizeFunc)
8) glutDisplayFunct(RederFunc)
9) glViewport()
10) glClear()
11) glutSwapBuffers()
12) glutPostRedisplay()
