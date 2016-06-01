#pragma once
#include "IControl.h"
#include <Windows.h>

class ComoboxInputEntry : public IControl
{

public:
	ComoboxInputEntry();
	~ComoboxInputEntry();
	void operateKeyboardEvents(KEY_EVENT_RECORD);
	void operateMouseEvents(MOUSE_EVENT_RECORD);
	void draw();
};

