#include <HAPI_lib.h>
#include "Visualisation.h"


using namespace HAPISPACE;


void HAPI_Main()
{
	Visualisation viz;
	int width(1280);
	int height(720);

	HAPI_TColour textfill(HAPI_TColour::CYAN);


	if (!HAPI.Initialise(width, height, "The little HAPI window that could"))
		return;

	/*BYTE *texPoint;
	int texWidth, texHeight;
	if (!HAPI.LoadTexture("Data\\alphaThing.tga", &texPoint, texWidth, texHeight))
	{
		HAPI.UserMessage("Texture not found: Data\\alphaThing.tga ", "Error");
		return;
	}*/
		
	
	//BYTE *backPoint;
	//int backWidth, backHeight;
	//if (!HAPI.LoadTexture("Data\\background.tga", &backPoint, backWidth, backHeight))
	//{
	//	HAPI.UserMessage("Texture not found: Data\\background.tga", "Error");
	//	return;
	//}
	viz.CreateSprite("Data\\alphaThing.tga", "circle");
	viz.CreateSprite("Data\\background.tga", "background");
	int texHeight = viz.getSprite("circle").getHeight();
	int texWidth = viz.getSprite("circle").getHeight();
	BYTE* screen = HAPI.GetScreenPointer();
	HAPI.SetShowFPS(true);
	float circlePosX = 0;
	float circlePosY = 0;
	bool isVert = false;
	bool isHor = false;
	int moveSpeed = 3;
	int hypot = moveSpeed*moveSpeed * 2;

	
	while (HAPI.Update())
	{

		HAPI_TKeyboardData keyboard = HAPI.GetKeyboardData();
		
		if (keyboard.scanCode[HK_ESCAPE])
		{
			HAPI.Close();
		}
		if (keyboard.scanCode['W'] && circlePosY > 0)
		{
			isVert = true;
			if (isHor)
			{
				circlePosY -= sqrt((moveSpeed*moveSpeed)/2);
			}
			else
			{
				circlePosY -= moveSpeed;
			}
		}
		if (keyboard.scanCode['S'] && circlePosY < height - texHeight - 1)
		{
			isVert = true;
			if (isHor)
			{
				circlePosY += sqrt((moveSpeed*moveSpeed) / 2);
			}
			else
			{
				circlePosY += moveSpeed;
			}
		}
		if (keyboard.scanCode['A'] && circlePosX > 0)
		{
			isHor = true;
			if (isVert)
			{
				circlePosX -= sqrt((moveSpeed*moveSpeed) / 2);
			}
			else
			{
				circlePosX -= moveSpeed;
			}
		}
		if (keyboard.scanCode['D'] && circlePosX < width - texWidth - 1)
		{
			isHor = true;
			if (isVert)
			{
				circlePosX += sqrt((moveSpeed*moveSpeed) / 2);
			}
			else
			{
				circlePosX += moveSpeed;
			}
		}
		if (!keyboard.scanCode['W'] && !keyboard.scanCode['S'])
		{
			isVert = false;
		}
		if (!keyboard.scanCode['A'] && !keyboard.scanCode['D'])
		{
			isHor = false;
		}
	
		viz.ClearToColour(100, 0, 0, screen, width, height);
		viz.DrawSpriteNoAlpha("background", screen, height, width, 0, 0);
		viz.DrawSprite("circle", screen, height, width, circlePosX, circlePosY);
		


	}
	/*delete[] texPoint;*/
	//delete[] backPoint;
}

