#include "Sprite.h"



Sprite::Sprite()
{
	
}

bool Sprite::LoadSprite(std::string filePath)
{
	
	if (!HAPI.LoadTexture(filePath, &pointer, width, height))
	{
		HAPI.UserMessage("Texture not found: " + filePath, "Error");
		
		return false;
	}
	
	rect.setBot(height);
	rect.setLeft(0);
	rect.setRight(width);
	rect.setTop(0);
	
	/*HAPI.UserMessage(std::to_string(rect.Height()), "Debug Height");
	HAPI.UserMessage(std::to_string(rect.Width()), "Debug Width");*/
	
	return true;
}

int Sprite::getHeight()
{
	return height;
}

int Sprite::getWidth()
{
	return width;
}

BYTE * Sprite::getPointer()
{
	return pointer;
}

void Sprite::setHeight(int newHeight)
{
	height = newHeight;
}

void Sprite::setWidth(int newWidth)
{
	width = newWidth;
}

Rectangle Sprite::getRect()
{
	return rect;
}



Sprite::~Sprite()
{
	delete[] pointer;
}
