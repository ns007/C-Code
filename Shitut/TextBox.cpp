#include "stdafx.h"
#include "TextBox.h"


TextBox::TextBox(int width)
{
	setWidth(width);
}

void TextBox::setText(string value)
{
	text = value;
}

void TextBox::draw() {
	cout << '\xDA';
	for (int i = 0; i < getWidth(); i++) {
		cout << '\xC4';
	}
	cout << '\xBF' << endl;
	cout << '\xB3';
	cout << text;
	for (int i = 0; i < getWidth() - text.length(); i++) {
		cout << ' ';
	}
	cout << '\xB3' << endl;
	cout << '\xC0';
	for (int i = 0; i < getWidth(); i++) {
		cout << '\xC4';
	}
	cout << '\xD9' << endl;
}

TextBox::~TextBox()
{

}

void TextBox::operateKeyboardEvents(KEY_EVENT_RECORD ker)
{
	cout << "keyboardEvent" << endl;
}

void TextBox::operateMouseEvents(MOUSE_EVENT_RECORD ker)
{
	cout << "mouseEvent" << endl;
}
