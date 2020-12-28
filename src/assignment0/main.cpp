//
// Created by Peter on 2020/12/28.
//

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <eigen3/Eigen/Core>
#include "camera.h"
#include "Loader.h"

using namespace std;
using namespace glm;

//Create the Camera
Camera camera;

Loader loader[2];

class Window
{
public:
    Window()
    {
        this->interval = 1000 / 60;        //60 FPS
        this->window_handle = -1;
    }

    int window_handle, interval;
    ivec2 size;
    float window_aspect;
} window;

//Invalidate the window handle when window is closed
void CloseFunc()
{
    window.window_handle = -1;
}

//Resize the window and properly update the camera viewport
void ReshapeFunc(int w, int h)
{
    if (h > 0)
    {
        window.size = ivec2(w, h);
        window.window_aspect = float(w) / float(h);
    }
    camera.SetViewport(0, 0, window.size.x, window.size.y);
}

//Keyboard input for camera, also handles exit case
void KeyboardFunc(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 'w':
            camera.Move(FORWARD);
            break;
        case 'a':
            camera.Move(LEFT);
            break;
        case 's':
            camera.Move(BACK);
            break;
        case 'd':
            camera.Move(RIGHT);
            break;
        case 'q':
            camera.Move(DOWN);
            break;
        case 'e':
            camera.Move(UP);
            break;
        case 'x':
        case 27:
            exit(0);
            return;
        default:
            break;
    }
}

void SpecialFunc(int c, int x, int y)
{}

void CallBackPassiveFunc(int x, int y)
{}

//Used when person clicks mouse
void CallBackMouseFunc(int button, int state, int x, int y)
{
    camera.SetPos(button, state, x, y);
}

//Used when person drags mouse around
void CallBackMotionFunc(int x, int y)
{
    camera.Move2D(x, y);
}

//Draw a wire cube! (nothing fancy here)
void DisplayFunc()
{

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glLoadIdentity();


//    glFlush();

    glEnable(GL_CULL_FACE);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window.size.x, window.size.y);


    glm::mat4 model, view, projection;
    camera.Update();
    camera.GetMatricies(projection, view, model);

    glm::mat4 mvp = projection * view * model;    //Compute the mvp matrix
    glLoadMatrixf(glm::value_ptr(mvp));
    loader[0].draw();
    glutSwapBuffers();
}

//Redraw based on fps set for window
void TimerFunc(int value)
{
    if (window.window_handle != -1)
    {
        glutTimerFunc(window.interval, TimerFunc, value);
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    //glut boilerplate
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 512);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    //Setup window and callbacks
    window.window_handle = glutCreateWindow("MODERN_GL_CAMERA");


    char a[40] = "../../resource/sample.obj", b[40] = "../../resource/teapot.obj";

    if (argc > 1)
    {
        strcpy(a, argv[1]);
        if (argc > 2)
            strcpy(a, argv[2]);
    }

    loader[0].load(a);
    loader[1].load(b);


    glutReshapeFunc(ReshapeFunc);
    glutDisplayFunc(DisplayFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(SpecialFunc);
    glutMouseFunc(CallBackMouseFunc);
    glutMotionFunc(CallBackMotionFunc);
    glutPassiveMotionFunc(CallBackPassiveFunc);
    glutTimerFunc(window.interval, TimerFunc, 0);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        cerr << "GLEW failed to initialize." << endl;
        return 0;
    }
    //Setup camera
    camera.SetMode(FREE);
    camera.SetPosition(glm::vec3(0, 0, -1));
    camera.SetLookAt(glm::vec3(0, 0, 0));
    camera.SetClipping(.1, 1000);
    camera.SetFOV(45);
    //Start the glut loop!
    glutMainLoop();
    return 0;
}
