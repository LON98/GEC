#include "Rectangle.h"
#include <algorithm>




Rectangle::~Rectangle()
{
}

bool Rectangle::ContainsComplete(Rectangle const & other)
{
	if (bottom < other.bottom && top > other.top || right < other.right && left > other.left)
	{
		return true;
	}
	
	return false;
}

bool Rectangle::OutsideOf(Rectangle const & other)
{
	if (bottom > other.bottom && top < other.top || right > other.right && left < other.left)
	{
		return true;
	}
	return false;
}
bool Rectangle::ContainsPartial(Rectangle const & other)
{
	if (bottom < other.bottom && bottom > other.top || right < other.right && right > other.left || top > other.top && top < other.bottom || left > other.left && left < other.right)
	{
		
		return true;
	}

	return false;
}

void Rectangle::ClipTo(Rectangle const & other)
{
	top = std::max(other.top, top);
	right = std::min(other.right, right);
	left = std::max(other.left, left);
	bottom = std::min(other.bottom, bottom);
}

void Rectangle::Translate(int x, int y)
{
	top += y;
	bottom += y;
	left += x;
	right += x;
}

void Rectangle::setLeft(int l)
{
	left = l;
}

void Rectangle::setRight(int r)
{
	right = r;
}

void Rectangle::setTop(int t)
{
	top = t;
}

void Rectangle::setBot(int b)
{
	bottom = b;
}
