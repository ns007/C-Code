#pragma once
#include <Windows.h>

class IControl
{

private:

	int locationX;
	int locationY;
	int width;
	int height;

public:
	
	virtual void operateKeyboardEvents(KEY_EVENT_RECORD) = 0;
	virtual void operateMouseEvents(MOUSE_EVENT_RECORD) = 0;
	virtual void draw() = 0;
	int getLocationX();
	int getLocationY();
	void setLocationX(int);
	void setLocationY(int);
	int getWidth();
	int getHeight();
	void setWidth(int);
	void setHeight(int);
};

