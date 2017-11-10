#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
using namespace HAPISPACE;

class Sprite
{
public:
	Sprite();
	bool LoadSprite(std::string filePath);
	int getHeight();
	int getWidth();
	BYTE* getPointer();
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	Rectangle getRect();
	
	~Sprite();
private:
	int height{-1};
	int width{-1};
	BYTE* pointer;
	Rectangle rect;
	
};

