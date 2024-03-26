// #include "include/glad/glad.h"
#include <GL/glut.h> /* glut graphics library */
#include <GLFW/glfw3.h>
// #include <glad/gl.h>
#include <stdio.h>

#include <iostream>

#include "objects.hpp"
using namespace std;
fstream file{"../objects/model1.inp"};
fstream file1{"../objects/model2.inp"};
fstream file2{"../objects/model3.inp"};
Body bd(file);
Body bd2(file1);
Body bd3(file2);
int tr_number = bd.Ntriangles;
int point_number = bd.NNcoords;
int tr_number2 = bd2.Ntriangles;
int point_number2 = bd2.NNcoords;
int tr_number3 = bd3.Ntriangles;
int point_number3 = bd3.NNcoords;
double phi = 0.;
double teta = 0.;

// угол поворота
float angle = 0.0f;
float red = 1.0f, blue = 1.0f, green = 1.0f;
void myKeyboard(unsigned char key, int x, int y);
void myKeyboard2(unsigned char key, int x, int y);
void changeSize(int w, int h);
void renderScene(void);
void myDisp();
void myDisp2();
void myTransform() {
    // glTranslated(-150, 0, 0);
    glScaled(1. / 2000, 1. / 2000, 0);
    double color_shifting{0.01};
    for (int tr_index{}; tr_index < tr_number;
         tr_index++, color_shifting += 0.025) {
        glBegin(GL_TRIANGLES);
        for (int vertex_index{}; vertex_index < 3; vertex_index++) {
            glColor3d(0.2 + color_shifting, 0.6 + color_shifting,
                      0.7 + color_shifting * 2);
            glVertex3d(bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][0],
                       bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][1],
                       bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][2]);
        }
        glEnd();
    }
    // color_shifting = 0.;
    // glTranslated(150, 0, 0);
    // for (int tr_index{}; tr_index < tr_number2;
    //      tr_index++, color_shifting += 0.025) {
    //     glBegin(GL_TRIANGLES);
    //     for (int vertex_index{}; vertex_index < 3; vertex_index++) {
    //         glColor3d(0.2 + color_shifting, 0.6 + color_shifting,
    //                   0.7 + color_shifting * 2);
    //         glVertex3d(bd2.Ncoords[bd2.Elemes[tr_index][vertex_index] -
    //         1][0],
    //                    bd2.Ncoords[bd2.Elemes[tr_index][vertex_index] -
    //                    1][1], bd2.Ncoords[bd2.Elemes[tr_index][vertex_index]
    //                    - 1][2]);
    //     }
    //     glEnd();
    // }
    // color_shifting = 0.;
    // glTranslated(1500, 0, 0);
    // for (int tr_index{}; tr_index < tr_number3;
    //      tr_index++, color_shifting += 0.025) {
    //     glBegin(GL_TRIANGLES);
    //     for (int vertex_index{}; vertex_index < 3; vertex_index++) {
    //         glColor3d(0.2 + color_shifting, 0.6 + color_shifting,
    //                   0.7 + color_shifting * 2);
    //         glVertex3d(bd3.Ncoords[bd3.Elemes[tr_index][vertex_index] -
    //         1][0],
    //                    bd3.Ncoords[bd3.Elemes[tr_index][vertex_index] -
    //                    1][1], bd3.Ncoords[bd3.Elemes[tr_index][vertex_index]
    //                    - 1][2]);
    //     }
    //     glEnd();
    // }

    // glScaled(2000, 200, 0);
}
void processSpecialKeys(int key, int x, int y);
// void Scale();
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
};
void renderScene(void) {
    // очистить буфер цвета и глубины.
    // Scale();
    // glScaled(1. / 2000, 1. / 2000, 1.);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // обнулить трансформацию
    // glLoadIdentity();
    // установить камеру
    // gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    // поворот на заданную величину
    glScaled(1. / 2000, 1. / 2000, 0);
    double color_shifting{0.01};
    for (int tr_index{}; tr_index < tr_number;
         tr_index++, color_shifting += 0.025) {
        glBegin(GL_TRIANGLES);
        for (int vertex_index{}; vertex_index < 3; vertex_index++) {
            glColor3d(0.2 + color_shifting, 0.6 + color_shifting,
                      0.7 + color_shifting * 2);
            glVertex3d(bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][0],
                       bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][1],
                       bd.Ncoords[bd.Elemes[tr_index][vertex_index] - 1][2]);
        }
        glEnd();
        myTransform();
        // angle += 0.1f;

        glutSwapBuffers();
    }
}
void myKeyboard(unsigned char key, int x, int y) {
    // how to implement changing coords
    switch (key) {
        case 'a':
            phi += 30;
            break;
        case 'd':
            phi -= 30;
            break;
        case 'w':
            teta += 30;
            break;
        case 's':
            teta -= 30;
            break;
        default:
            break;
    }
}
void processSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F2:
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F3:
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        case GLUT_KEY_UP:

            break;
        case GLUT_KEY_DOWN:
            break;
    }
}
void myDisp() {}
void myDisp2() {
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColor3d(0.1, 0.6, 0.3);
    glutSwapBuffers();
}
// void Scale() { glScaled(1 / 2000, 1 / 2000, 1); }

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Hello world!");

    glutDisplayFunc(renderScene);
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(changeSize);
    // glutIdleFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);
    // together run this function?
    // glutSpecialFunc(myKeyboard)
    glutMainLoop();

    return 0;
}