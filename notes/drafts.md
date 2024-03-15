# what

## 1.draft

### which steps we will be see

1) initialize freeglut
2) init display
3) init keyboard function
4) init mainloop

#### initialize freeglut - glutInit()

#### init display

1) specify the size of display( height and width and window handle)

### which process contains on opengl

1) track the button actions and take them in graphic rendering
2) graphic rendering
3) display init and drawing in there
4) read a big data from file example

Initialize(){
    Init();
    glClearColor()
    
}

Init()
{
    glutInit();
    glutReshapeFunction(Resizefunction);
    glutRenderFunction(Renderfunction);
    glInitDsiplayMode()
    glWindowCreate();
    exit(EXIT_FAILURE)
}
ResizeFunction()
{
    CurrentWindow_size -> give sizes;
    glViewport();
}
RenderFunction()
{
    glSwapBuffers();
    glClear();
    glPostRedisplay();
}
