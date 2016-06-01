#include "stdafx.h"
#include "Label.h"
#include <string>
#include <iostream>

using namespace std;

Label::Label(int width)
{
	setWidth(width);
}

void Label::setText(string value)
{
	text = value;
}

void Label::draw() {
	cout << text;
}

Label::~Label()
{

}

void Label::operateKeyboardEvents(KEY_EVENT_RECORD ker)
{
	cout << "keyboardEvent" << endl;
}

void Label::operateMouseEvents(MOUSE_EVENT_RECORD ker)
{
	cout << "mouseEvent" << endl;
}
