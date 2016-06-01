#include "ComoboxInputEntry.h"
#include <Windows.h>
#include <iostream>

using namespace std;


ComoboxInputEntry::ComoboxInputEntry()
{

}


ComoboxInputEntry::~ComoboxInputEntry()
{

}

void ComoboxInputEntry::operateKeyboardEvents(KEY_EVENT_RECORD ker)
{
	cout << "keyboardEvent" << endl;
}

void ComoboxInputEntry::operateMouseEvents(MOUSE_EVENT_RECORD ker)
{
	cout << "mouseEvent" << endl;
}

void ComoboxInputEntry::draw()
{

}