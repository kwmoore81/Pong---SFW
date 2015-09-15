#include "sfwdraw.h"
#include <iostream>
#include "gameheader.h"

using namespace std;
using namespace sfw;


const int windowWidth = 1000;
const int windowHeight = 720;


void runGame()
{
	initContext(windowWidth, windowHeight, "PONG!");

	while (stepContext())
	{
		//Ball Logic
		xBallPos += xBallVel * getDeltaTime();
		yBallPos += yBallVel * getDeltaTime();

		yBallVel += yBallAcc * getDeltaTime();
		yBallPos += xBallAcc * getDeltaTime();


		drawCircle(xBallPos, yBallPos, ballRad);

		if (yBallPos > windowHeight - ballRad - 8) { yBallVel += -yBallVel * 2; }
		if (yBallPos < 0 + ballRad + 8) { yBallVel += -yBallVel * 2; }

		if (xBallPos > windowWidth - ballRad - 8)
		{
			xBallPos = 945, yBallPos = 360;
			xBallAcc = 0, yBallAcc = 0;
			xBallVel = -500, yBallVel = rand() % (360 - -360) + -360;
			ballRad = 10;
			++LeftPlayer.PlayerScore;

		
			

			if (LeftPlayer.PlayerScore >= 4)
			{
				termContext();
				system("CLS");
				cout << "Left Player Wins!" << endl
					<< "Left Player Score: " << LeftPlayer.PlayerScore << endl
					<< "Right Player Score: " << RightPlayer.RPlayerScore << endl;

				menu = true;
				RightPlayer.RPlayerScore = 0; LeftPlayer.PlayerScore = 0;
				break;
			}

		}

		if (xBallPos < 0 + ballRad + 8)
		{
			xBallPos = 55, yBallPos = 360;
			xBallAcc = 0, yBallAcc = 0;
			xBallVel = 500, yBallVel = rand() % (360 - -360) + -360;
			ballRad = 10;
			++RightPlayer.RPlayerScore;

			if (RightPlayer.RPlayerScore >= 4)
			{
				termContext();
				system("CLS");
				cout << "Right Player Wins!" << endl
					<< "Left Player Score: " << LeftPlayer.PlayerScore << endl
					<< "Right Player Score: " << RightPlayer.RPlayerScore << endl;

				menu = true;
				RightPlayer.RPlayerScore = 0; LeftPlayer.PlayerScore = 0;
				break;
			}

		}

		if (yBallPos > LeftPlayer.PlayerTopY2 - ballRad &&
			yBallPos < LeftPlayer.PlayerBottomY2 + ballRad &&
			xBallPos < (LeftPlayer.PlayerTopX2 + 15) - ballRad) {
			xBallVel += -xBallVel * 2.1;
		}

		if (yBallPos > RightPlayer.PlayerTopY - ballRad &&
			yBallPos < RightPlayer.PlayerBottomY + ballRad &&
			xBallPos >(RightPlayer.RPlayerTopX2 - 15) + ballRad) {
			xBallVel += -xBallVel * 2.1;
		}

		//Left Player Logic

		LeftPlayer.PlayerTopY += LeftPlayer.PlayerYvel * getDeltaTime();
		LeftPlayer.PlayerBottomY += LeftPlayer.PlayerYvel * getDeltaTime();
		LeftPlayer.PlayerTopY2 += LeftPlayer.PlayerYvel2 * getDeltaTime();
		LeftPlayer.PlayerBottomY2 += LeftPlayer.PlayerYvel2 * getDeltaTime();
		LeftPlayer.PlayerYvel += LeftPlayer.PlayerYacc * getDeltaTime();
		LeftPlayer.PlayerYvel2 += LeftPlayer.PlayerYacc2 * getDeltaTime();

		drawLine(LeftPlayer.PlayerTopX, LeftPlayer.PlayerTopY, LeftPlayer.PlayerBottomX, LeftPlayer.PlayerBottomY);
		drawLine(LeftPlayer.PlayerTopX2, LeftPlayer.PlayerTopY2, LeftPlayer.PlayerBottomX2, LeftPlayer.PlayerBottomY2);
		drawLine(LeftPlayer.PlayerTopX, LeftPlayer.PlayerTopY, LeftPlayer.PlayerTopX2, LeftPlayer.PlayerTopY);
		drawLine(LeftPlayer.PlayerTopX, LeftPlayer.PlayerBottomY, LeftPlayer.PlayerBottomX2, LeftPlayer.PlayerBottomY);

		LeftPlayer.PlayerYacc = 0; LeftPlayer.PlayerYacc2 = 0;

		if (getKey('q'))  LeftPlayer.PlayerYvel = -playerSpeed; if (getKey('q')) LeftPlayer.PlayerYvel2 = -playerSpeed;
		if (getKey('a'))  LeftPlayer.PlayerYvel = playerSpeed; if (getKey('a')) LeftPlayer.PlayerYvel2 = playerSpeed;




		if (LeftPlayer.PlayerTopY < (windowHeight - windowHeight) + 15)
		{
			LeftPlayer.PlayerYvel = 0; LeftPlayer.PlayerYvel2 = 0;

			if (getKey('a')) { LeftPlayer.PlayerYvel = playerSpeed; LeftPlayer.PlayerYvel2 = playerSpeed; }
		}

		if (LeftPlayer.PlayerBottomY > windowHeight - 12)
		{

			LeftPlayer.PlayerYvel = 0; LeftPlayer.PlayerYvel2 = 0;

			if (getKey('q'))
			{
				LeftPlayer.PlayerYvel = -playerSpeed; LeftPlayer.PlayerYvel2 = -playerSpeed;

			}
		}
		
		switch (LeftPlayer.PlayerScore)
		{
		case 1:
			drawCircle(400, 25, 5);
			break;
		case 2:
			drawCircle(400, 25, 5);
			drawCircle(400, 25, 10);
			break;
		case 3:
			drawCircle(400, 25, 5);
			drawCircle(400, 25, 10);
			drawCircle(400, 25, 15);
			break;
		default:
			break;
		}
		
		//Right Player Logic
		
		RightPlayer.PlayerTopY += RightPlayer.RPlayerYvel * getDeltaTime();
		RightPlayer.PlayerBottomY += RightPlayer.RPlayerYvel * getDeltaTime();
		RightPlayer.PlayerTopY2 += RightPlayer.RPlayerYvel2 * getDeltaTime();
		RightPlayer.PlayerBottomY2 += RightPlayer.RPlayerYvel2 * getDeltaTime();
		RightPlayer.RPlayerYvel += RightPlayer.RPlayerYacc * getDeltaTime();
		RightPlayer.RPlayerYvel2 += RightPlayer.RPlayerYacc2 * getDeltaTime();

		drawLine(RightPlayer.RPlayerTopX, RightPlayer.PlayerTopY, RightPlayer.RPlayerTopX, RightPlayer.PlayerBottomY);
		drawLine(RightPlayer.RPlayerTopX2, RightPlayer.PlayerTopY, RightPlayer.RPlayerTopX2, RightPlayer.PlayerBottomY);
		drawLine(RightPlayer.RPlayerTopX, RightPlayer.PlayerTopY, RightPlayer.RPlayerTopX2, RightPlayer.PlayerTopY);
		drawLine(RightPlayer.RPlayerTopX, RightPlayer.PlayerBottomY, RightPlayer.RPlayerTopX2, RightPlayer.PlayerBottomY);

		if (getKey('o')) RightPlayer.RPlayerYvel = -playerSpeed; if (getKey('o')) RightPlayer.RPlayerYvel2 = -playerSpeed;
		if (getKey('l')) RightPlayer.RPlayerYvel = playerSpeed; if (getKey('l')) RightPlayer.RPlayerYvel2 = playerSpeed;

		if (RightPlayer.PlayerTopY < (windowHeight - windowHeight) + 15)
		{
			RightPlayer.RPlayerYvel = 0; RightPlayer.RPlayerYvel2 = 0;

			if (getKey('l'))
			{

				RightPlayer.RPlayerYvel = playerSpeed; RightPlayer.PlayerYvel2 = playerSpeed;

			}
		}
		if (RightPlayer.PlayerBottomY > windowHeight - 12)
		{

			RightPlayer.RPlayerYvel = 0; RightPlayer.RPlayerYvel2 = 0;

			if (getKey('o'))
			{

				RightPlayer.RPlayerYvel = -playerSpeed; RightPlayer.RPlayerYvel2 = -playerSpeed;

			}
		}

		switch (RightPlayer.RPlayerScore)
		{
		case 1:
			drawCircle(600, 25, 5);
			break;
		case 2:
			drawCircle(600, 25, 5);
			drawCircle(600, 25, 10);
			break;
		case 3:
			drawCircle(600, 25, 5);
			drawCircle(600, 25, 10);
			drawCircle(600, 25, 15);
			break;
		default:
			break;
		}

		//Draw Table

		drawLine(5, 5, 5, windowHeight - 5);
		drawLine(5, 5, windowWidth - 5, 5);

		drawLine(windowWidth - 5, windowHeight - 5, 5, windowHeight - 5);
		drawLine(windowWidth - 5, windowHeight - 5, windowWidth - 5, 5);
		drawLine(500, 5, 500, 360 - tableCenterRad);
		drawLine(500, windowHeight - 5, 500, 360 + tableCenterRad);
		drawCircle(500, 360, tableCenterRad);
	}
}


int main()
{
   while (menu = true)
	{
		cout << "                                Pong!"             << endl
			 << "                       First to 4 Points is Game!" << endl
		   	 << "                           Press P to Play!"   << endl			
			 << "                           Press Q to Exit."       << endl
			 << "                       Press I for instructions."  << endl;

		cin >> menuChoice;
		
		if (menuChoice[0] == 'p')
		{
			menu = false;
			runGame();
			
		}

		else if (menuChoice[0] == 'q')
		{
			menu = false;
			termContext();
			break;
		}

		else if (menuChoice[0] == 'i')
		{
			system("CLS");
			cout << "Left Player:" << endl
				<< "Paddle Up: Q" << endl
				<< "Paddle Down: A" << endl << endl
				<< "Right Player:" << endl
				<< "Paddle UP: O" << endl
				<< "Paddle Down: L" << endl << endl
				<< "First Player to 4 Points Wins!" << endl << endl
				<< "Press M to return to the Main Menu." << endl;

			cin >> menuChoice;

			if (menuChoice[0] == 'm')
			{
				system("CLS");
			}
		} 
		
		else
		{
			
			//Kevin Hunter showed me this (clears the console)
			system("CLS");

		}
	}
	

	termContext();
	
	return 0;
}

