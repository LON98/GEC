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

	viz.CreateSprite("Data\\alphaThing.tga", "circle");
	viz.CreateSprite("Data\\background.tga", "background");
	
	BYTE* screen = HAPI.GetScreenPointer();
	Rectangle screenRect{ width,height };
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
		
		const HAPI_TControllerData& controller = HAPI.GetControllerData(0);
		
		if (controller.isAttached)
		{
			int xVal = controller.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X];
			int yVal = controller.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y];
			if (xVal >  HK_GAMEPAD_LEFT_THUMB_DEADZONE)
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
			if (xVal < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
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
			if (yVal < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
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
			if (yVal > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				isVert = true;
				if (isHor)
				{
					circlePosY -= sqrt((moveSpeed*moveSpeed) / 2);
				}
				else
				{
					circlePosY -= moveSpeed;
				}
			}
			if (yVal < HK_GAMEPAD_LEFT_THUMB_DEADZONE && yVal > -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				isVert = false;
			}
			if (xVal < HK_GAMEPAD_LEFT_THUMB_DEADZONE && xVal > -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				isHor = false;
			}
			if (circlePosX <= (width / 2) + 100 && circlePosX >= (width / 2) - 100 && circlePosY >= (height / 2) - 100 && circlePosY <= (height / 2) + 100)
			{
				HAPI.SetControllerRumble(0, 65000, 65000);
			}
			else
			{
				HAPI.SetControllerRumble(0, 0, 0);
			}

			
		}
		
		if (keyboard.scanCode[HK_ESCAPE])
		{
			HAPI.Close();
		}
		if (keyboard.scanCode['W'])
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
		if (keyboard.scanCode['S'])
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
		if (keyboard.scanCode['A'])
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
		if (keyboard.scanCode['D'])
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
		viz.ClipBlit(screen, screenRect, "circle", circlePosX, circlePosY);


	}
}

