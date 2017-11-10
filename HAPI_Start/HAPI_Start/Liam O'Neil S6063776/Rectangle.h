#pragma once
class Rectangle
{
	
public:
	//Constructors
	Rectangle() = default;
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b){}
	Rectangle(int w, int h) : left(0), right(w), top(0), bottom(h) {}
	//Return width and height
	int Width() const { return right - left; }
	int Height() const { return bottom - top; }
	int left{ 0 }, right{ 0 }, top{ 0 }, bottom{ 0 };
	
	//Where rect is the rectangle you are clipping and other is the screen/base rectangle
	bool ContainsComplete(Rectangle const &other);
	//Where rect is the rectangle you are clipping and other is the screen/base rectangle
	bool OutsideOf(Rectangle const &other);
	//Where rect is the rectangle you are clipping and other is the screen/base rectangle
	bool ContainsPartial(Rectangle const &other);
	//Where rect is the rectangle you are clipping and other is the screen/base rectangle
	void ClipTo(Rectangle const &other);
	void Translate(int x, int y);

	void setLeft(int l);
	void setRight(int r);
	void setTop(int t);
	void setBot(int b);

	~Rectangle();
};

