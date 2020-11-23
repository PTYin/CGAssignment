//
// Created by Peter on 2020/11/23.
//

#include <iostream>
#include <cstdio>

#include <GL/glew.h>
#include <GL/freeglut.h>

void initWindow(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(512, 512);
    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutCreateWindow("Assignment 0");
}

int main(int argc, char** argv)
{
    // TODO read file

    initWindow(argc, argv);

    if (glewInit())
    {
        std::cerr << "Unable to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }


    return 0;
}