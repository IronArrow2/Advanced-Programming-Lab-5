#pragma once
#include <string>

//simple struct modelled after the SDL_Rect struct type, Consists of the x and y coordinates of the top left of the rectangle and the rectangle's width and height
struct MyRect
{
	int x, y, w, h;

	friend ostream& operator<< (ostream& output, const MyRect& rect)
	{
		output << rect.x << " " << rect.y << " " << rect.w << " " << rect.h;
		return output;
	}
};