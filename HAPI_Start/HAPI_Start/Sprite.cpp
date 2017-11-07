#include "Sprite.h"



Sprite::Sprite()
{
}

bool Sprite::LoadSprite(std::string filePath)
{
	//BYTE* texPoint;
	//int texWidth, texHeight;
	if (!HAPI.LoadTexture(filePath, &pointer, width, height))
	{
		HAPI.UserMessage("Texture not found: " + filePath, "Error");
		
		return false;
	}
	/*setHeight(texHeight);
	setWidth(texWidth);*/
	
	
	/*HAPI.UserMessage(std::to_string(height), "Debug Height");
	HAPI.UserMessage(std::to_string(width), "Debug Width");*/
	
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



Sprite::~Sprite()
{
	//THIS NEEDS FIXING
	//
	//
	//
	//
	//delete[] pointer;
}
