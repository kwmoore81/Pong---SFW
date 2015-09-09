#include "sfwdraw.h"
#include <iostream>

using namespace std;
using namespace sfw;

const int windowWidth = 1000;
const int windowHeight = 720;

int main()
{

	initContext(windowWidth, windowHeight, "PONG!");

	float xpos = 300, ypos = 400; 
	float xacc = 0, yacc = 0;	  
	float xvel = 0, yvel = 0;	  
	float speed = 100;

	while (stepContext())
	{
		
		xpos += xvel * getDeltaTime();
		ypos += yvel * getDeltaTime();

		xvel += xacc * getDeltaTime();
		yvel += yacc * getDeltaTime();
		
		yacc = xacc = 0;
		
		
		drawCircle(xpos, ypos, 30);

		drawLine(5, 5, 5, windowHeight - 5);
		drawLine(5, 5, windowWidth - 5, 5);

		drawLine(windowWidth - 5, windowHeight - 5, 5, windowHeight - 5);
		drawLine(windowWidth - 5, windowHeight - 5, windowWidth - 5, 5);
	}





	sfw::termContext();
	system("pause");
	return 0;
}