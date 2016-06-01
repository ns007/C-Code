#pragma once
#include "IControl.h"
#include <iostream>

using namespace std;

class Label : public IControl
{
	private:
		string text;
	public:
		Label(int width);
		~Label();
		void setText(string value);
		void draw();
		void operateKeyboardEvents(KEY_EVENT_RECORD);
		void operateMouseEvents(MOUSE_EVENT_RECORD);
};

