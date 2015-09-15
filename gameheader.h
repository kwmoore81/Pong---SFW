#pragma once
#include "sfwdraw.h"

bool menu = true;
char menuChoice[50] = "0";
float xBallPos = 500, yBallPos = 360;
float xBallAcc = 0, yBallAcc = 0;
float xBallVel = rand() % (500 - -500) + -500, yBallVel = rand() % (360 - -360) + -360;
float ballRad = 10;

float playerSpeed = 500;

float tableCenterRad = 80;
struct DrawPlayer
{

	float PlayerTopX = 30, PlayerTopY = 300;
	float PlayerBottomX = 30, PlayerBottomY = 430;
	float PlayerYacc = 0;
	float PlayerYvel = 0;
	float PlayerTopX2 = 50, PlayerTopY2 = 300;
	float PlayerBottomX2 = 50, PlayerBottomY2 = 430;
	float PlayerYacc2 = 0;
	float PlayerYvel2 = 0;
	float PlayerScore = 0;
	

	float RPlayerTopX = 970;
	float RPlayerBottomX = 30;
	float RPlayerYacc = 0;
	float RPlayerYvel = 0;
	float RPlayerTopX2 = 950;
	float RPlayerBottomX2 = 950;
	float RPlayerYacc2 = 0;
	float RPlayerYvel2 = 0;
	float RPlayerScore = 0;
	

};

struct DrawPlayer LeftPlayer;
struct DrawPlayer RightPlayer;


