#include <HAPI_lib.h>


using namespace HAPISPACE;
void ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height);void FastBlit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth);

void HAPI_Main()
{
	int width(1280);
	int height(720);
	
	HAPI_TColour textfill(HAPI_TColour::CYAN);


	if (!HAPI.Initialise(width, height, "The little HAPI window that could"))
		return;

	BYTE *texPoint;
	int texWidth, texHeight;
	if (!HAPI.LoadTexture("Data\\alphaThing.tga", &texPoint, texWidth, texHeight))
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
		FastBlit(screen, texPoint, height, texHeight, width, texWidth);
		
	}
	delete[] texPoint;
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
void FastBlit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth){
	for (int y = 0; y < textureHeight; y++)
	{
		memcpy(screenPointer, texturePointer, textureHeight * 4);
		screenPointer = screenPointer + screenWidth * 4;
		texturePointer = texturePointer + textureWidth * 4;
	}}