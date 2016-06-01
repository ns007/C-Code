#pragma once
#include "IControl.h"
#include <iostream>
#include <string>

using namespace std;

class TextBox : public IControl
{

private:
	string text;
public:
	TextBox(int width);
	~TextBox();
	void setText(string value);
	void draw();
	void operateKeyboardEvents(KEY_EVENT_RECORD);
	void operateMouseEvents(MOUSE_EVENT_RECORD);

	
};

