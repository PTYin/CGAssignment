//
// Created by Peter on 2020/12/28.
//

#ifndef CGASSIGNMENT_MATCHSTICKMAN_H
#define CGASSIGNMENT_MATCHSTICKMAN_H

#include <GL/glut.h>

static float angleoflarma, angleoflarmb, angleofrarma, angleofrarmb, angleofllegb, angleofrlegb, angleofllega, angleofrlega = 0;
static float la, ra, ll, rl = 0;
static float a = 0.2;
static float b = 0.1, angle = 0.1, c = 0.07;
static const float angle1 = 0.2;
static const float angle2 = 0.1;

void DrawBody();
void DrawShoulder();
void DrawHip();
void DrawArmA();
void DrawArmB();
void DrawLegB();
void DrawLegA();
void DrawHead();
void DrawNeck();
void DrawGLScene(); //The main drawing function.


#endif //CGASSIGNMENT_MATCHSTICKMAN_H
