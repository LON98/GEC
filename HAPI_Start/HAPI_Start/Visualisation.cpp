#include "Visualisation.h"



Visualisation::Visualisation()
{

}



void Visualisation::ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height)
{
	for (int i = 0; i < width*height * 4; i += 4)
	{
		screen[i] = r;
		screen[i + 1] = g;
		screen[i + 2] = b;
	}
	
}

void Visualisation::FastBlit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth)
{
	for (int y = 0; y < textureHeight; y++)
	{
		memcpy(screenPointer, texturePointer, textureHeight * 4);
		screenPointer = screenPointer + screenWidth * 4;
		texturePointer = texturePointer + textureWidth * 4;
	}
}

void Visualisation::Blit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth, int x = 0, int y = 0)
{

	BYTE* scrPtr{ screenPointer };
	BYTE* texPtr{ texturePointer };

	scrPtr += (x + y*screenWidth) * 4;
	for (int j = 0; j < textureHeight; j++)
	{
		for (int i = 0; i < textureWidth; i++)
		{
			BYTE alpha = texPtr[3];
			if (alpha == 0)
			{

			}
			else if (alpha == 255)
			{
				scrPtr[0] = texPtr[0];
				scrPtr[1] = texPtr[1];
				scrPtr[2] = texPtr[2];
			}
			else
			{
				BYTE red = texPtr[0];
				BYTE green = texPtr[1];
				BYTE blue = texPtr[2];


				scrPtr[0] = scrPtr[0] + ((alpha*(blue - scrPtr[0])) >> 8);
				scrPtr[1] = scrPtr[1] + ((alpha*(green - scrPtr[1])) >> 8);
				scrPtr[2] = scrPtr[2] + ((alpha*(red - scrPtr[2])) >> 8);
			}
			scrPtr += 4;
			texPtr += 4;
		}

		scrPtr += (screenWidth - textureWidth) * 4;

	}
}

void Visualisation::CreateSprite(const std::string & filePath, std::string name)
{
	Sprite* sprt = new Sprite;
	sprt->LoadSprite(filePath);
	//HAPI.RenderText(400, 400, HAPI_TColour::BLUE, "CreateSprite");
	//sprites[name] = sprt;
	sprites.emplace(std::make_pair(name, sprt));
}

void Visualisation::DrawSprite(std::string name, BYTE* screenPointer, int screenHeight, int screenWidth, int x, int y)
{
	
	BYTE* scrPtr{ screenPointer };
	BYTE* texPtr{ sprites.at(name)->getPointer() };
	int textureHeight = sprites.at(name)->getHeight();
	int textureWidth = sprites.at(name)->getWidth();
	

	scrPtr += (x + y*screenWidth) * 4;
	for (int j = 0; j < textureHeight; j++)
	{
		for (int i = 0; i < textureWidth; i++)
		{
			BYTE alpha = texPtr[3];
			if (alpha == 0)
			{

			}
			else if (alpha == 255)
			{
				scrPtr[0] = texPtr[0];
				scrPtr[1] = texPtr[1];
				scrPtr[2] = texPtr[2];
			}
			else
			{
				BYTE red = texPtr[0];
				BYTE green = texPtr[1];
				BYTE blue = texPtr[2];


				scrPtr[0] = scrPtr[0] + ((alpha*(blue - scrPtr[0])) >> 8);
				scrPtr[1] = scrPtr[1] + ((alpha*(green - scrPtr[1])) >> 8);
				scrPtr[2] = scrPtr[2] + ((alpha*(red - scrPtr[2])) >> 8);
			}
			scrPtr += 4;
			texPtr += 4;
		}

		scrPtr += (screenWidth - textureWidth) * 4;

	}
	
}

void Visualisation::DrawSpriteNoAlpha(std::string name, BYTE * screenPointer, int screenHeight, int screenWidth, int x, int y)
{
	BYTE* texturePointer{ sprites.at(name)->getPointer() };
	int textureHeight = sprites.at(name)->getHeight();
	int textureWidth = sprites.at(name)->getWidth();
	
	/*HAPI.RenderText(400, 400, HAPI_TColour::BLUE, std::to_string(textureHeight));
	HAPI.RenderText(400, 300, HAPI_TColour::BLUE, std::to_string(textureWidth));*/

	/*HAPI.UserMessage(std::to_string(textureHeight), "Debug Height");
	HAPI.UserMessage(std::to_string(textureWidth), "Debug Width");*/

	for (int y = 0; y < textureHeight; y++)
	{
		memcpy(screenPointer, texturePointer, textureHeight * 4);
		screenPointer = screenPointer + screenWidth * 4;
		texturePointer = texturePointer + textureWidth * 4;
	}
}

Sprite Visualisation::getSprite(std::string name)
{
	return *sprites[name];
}





Visualisation::~Visualisation()
{
	
	for (auto& s : sprites)
	{
		delete s.second;
	}
}
