#pragma once
#include <HAPI_lib.h>
#include <unordered_map>
#include "Sprite.h"
using namespace HAPISPACE;
class Visualisation
{
	
public:
	Visualisation::Visualisation();
	void ClearToColour(BYTE r, BYTE g, BYTE b, BYTE* screen, int width, int height);
	void FastBlit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth);
	void Blit(BYTE* screenPointer, BYTE* texturePointer, int screenHeight, int textureHeight, int screenWidth, int textureWidth, int x, int y);
	void CreateSprite(const std::string & filePath, std::string name);
	void DrawSprite(std::string name, BYTE* screenPointer, int screenHeight, int screenWidth, int x, int y);
	void DrawSpriteNoAlpha(std::string name, BYTE* screenPointer, int screenHeight, int screenWidth, int x, int y);
	Visualisation::~Visualisation();
	void ClipBlit(BYTE *dest, const Rectangle &destRect, std::string name, int posX, int posY);
private:
	std::unordered_map<std::string, Sprite*> sprites;
};


