/*
HAPI Start
----------
This solution contains an already set up HAPI project and this main file

The directory structure and main files are:

HAPI_Start - contains the Visual Studio solution file (.sln)
HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
HAPI - the directory with all the HAPI library files
Data - a place to put your data files with a few sample ones provided

Additionally in the top directory there are two batch files for creating a redistributable Demo folder
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>

// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;
void ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height);

struct Star
{
	float starX;
	float starY;
	float starZ;
};
void DrawStars(Star star, BYTE* screen, int width, int height, BYTE r, BYTE g, BYTE b, float eyeDist);
// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down
void HAPI_Main()
{
	//Star star;
	int width(1920*2);
	int height(1200);
//	int text_x;
//	int text_y;
	
	HAPI_TColour textfill(HAPI_TColour::CYAN);


	if (!HAPI.Initialise(width, height, "The little HAPI window that could"))
		return;

	BYTE* screen = HAPI.GetScreenPointer();
	const int numStar = 100000;
	HAPI.SetShowFPS(true);
	Star* stars = new Star[numStar]();

	
	for (int i = 0; i < numStar; i++)
	{
		stars[i].starX = rand() % width;
		stars[i].starY = rand() % height;
		stars[i].starZ = rand() % 100;
	}
	float eyeDist = 100.f;
	while (HAPI.Update())
	{
		/*HAPI_TMouseData mouse = HAPI.GetMouseData();
		text_x = mouse.x - 200;
		text_y = mouse.y - 100;
		if (mouse.leftButtonDown) textfill = HAPI_TColour::BLUE;
		if (mouse.rightButtonDown) textfill = HAPI_TColour::CYAN;
		HAPI.RenderText(text_x, text_y, textfill, HAPI_TColour::GREEN, 6.0f, "HAPI text", 128, eItalic);*/
		//HAPI.SetControllerRumble(0, 65535, 65535);
		
		HAPI_TKeyboardData keyboard = HAPI.GetKeyboardData();
		if (keyboard.scanCode['S'])
		{
			eyeDist += 1;
			if (eyeDist > 500)
			{
				eyeDist = 500;
			}
			
		}
		if (keyboard.scanCode['W'])
		{
			eyeDist -= 1;
			if (eyeDist < -50)
			{
				eyeDist = -50;
			}
		
		}
		if (keyboard.scanCode[HK_ESCAPE])
		{
			HAPI.Close();
		}
		ClearToColour(0, 0, 50, screen, width, height);
		for (int i = 0; i < numStar; i++)
		{
			int colourPick = std::rand() % 4;
			if (colourPick == 0)
			{
				DrawStars(stars[i], screen, width, height, 255, 255, 255, eyeDist);
			}
			else if(colourPick == 1)
			{
				DrawStars(stars[i], screen, width, height, 255, 255, 0, eyeDist);
			}
			else if (colourPick == 2)
			{
				DrawStars(stars[i], screen, width, height, 0, 0, 230, eyeDist);
			}
			else if (colourPick == 3)
			{
				DrawStars(stars[i], screen, width, height, 150, 80, 0, eyeDist);
			}
			
			stars[i].starZ -= 1;
			if (stars[i].starZ <= 0)
			{
				stars[i].starZ = 100;
			}
			
		}
		

		//memset(screen, 150, width*height * 4);
	}
	delete[] stars;
	//HAPI.SetControllerRumble(0, 0, 0);

}

void ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height)
{
	for (int i = 0; i < width*height * 4; i += 4)
	{
		screen[i] = r;
		screen[i + 1] = g;
		screen[i + 2] = b;
	}
}

//Sx = ((eyeDist * (Px - Cx)) / (eyeDist + Pz)) + Cx
//Sy = ((eyeDist * (Py - Cy)) / (eyeDist + Pz)) + Cy

void DrawStars(Star star, BYTE* screen, int width, int height, BYTE r, BYTE g, BYTE b, float eyeDist)
{
	//float eyeDist = 100;
	float Sx = ((eyeDist*(star.starX - width / 2)) / (eyeDist + star.starZ)) + width / 2;
	float Sy = ((eyeDist*(star.starY - height / 2)) / (eyeDist + star.starZ)) + height / 2;
	int i = ((int)Sx + ((int)Sy*width)) * 4;
	if (Sx >= width || Sy >= height || Sx <= 0 || Sy <= 0)
	{
		return;
	}
	screen[i] = r;
	screen[i + 1] = g;
	screen[i + 2] = b;




}