#include <HAPI_lib.h>


using namespace HAPISPACE;
void ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height);

void HAPI_Main()
{
	int width(1920*2);
	int height(1200);
	
	HAPI_TColour textfill(HAPI_TColour::CYAN);


	if (!HAPI.Initialise(width, height, "The little HAPI window that could"))
		return;

	BYTE* screen = HAPI.GetScreenPointer();
	HAPI.SetShowFPS(true);

	while (HAPI.Update())
	{

		HAPI_TKeyboardData keyboard = HAPI.GetKeyboardData();
		
		if (keyboard.scanCode[HK_ESCAPE])
		{
			HAPI.Close();
		}
		ClearToColour(0, 0, 50, screen, width, height);
	}
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
