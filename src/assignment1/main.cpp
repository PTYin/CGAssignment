//
// Created by Peter on 2020/12/28.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include "MatchStickMan.h"


void InitGL(int Width, int Height)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

void ReSizeGLScene(int Width, int Height)
{
    if (Height == 0)
        Height = 1;
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}


void keyPressed(unsigned char key, int x, int y)/* The function called whenever a key is pressed. */
{
    Sleep(2000);  //pause 2 seconds
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(1080, 768);
    glutInitWindowPosition(0, 0);
    int window = glutCreateWindow("Stick man");

    glutDisplayFunc(&DrawGLScene);/* Register the function to do all our OpenGL drawing. */
    glutIdleFunc(&DrawGLScene);/* Even if there are no events, redraw our gl scene. */
    glutReshapeFunc(&ReSizeGLScene);/* Register the function called when our window is resized. */
    glutKeyboardFunc(&keyPressed);
    InitGL(640, 480);
    glutMainLoop();
    return 1;
}