#include "ConsoleEventsHandler.h"
#include <Windows.h>
#include <iostream>
#include "IControl.h"
#include <vector>

#define BYTES_TO_READ 128

using namespace std;

HANDLE hStdin;
INPUT_RECORD irInBuf[128];
DWORD cNumRead;
std::vector<IControl *> controllers;

ConsoleEventsHandler::ConsoleEventsHandler(std::vector<IControl *> _controllers)
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	controllers = _controllers;
}

ConsoleEventsHandler::ConsoleEventsHandler()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
}

ConsoleEventsHandler::~ConsoleEventsHandler()
{
}


IControl * getInputEntryByCursorPosition()
{
	IControl * controllerToReturn = NULL;
	for (IControl * controller : controllers)
	{
		controllerToReturn = controller;
	}
	return controllerToReturn;
}

void ConsoleEventsHandler::listenToEvents(){
	
	while (true)
	{
		IControl * controller = getInputEntryByCursorPosition();
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			BYTES_TO_READ,         // size of read buffer 
			&cNumRead)) // number of records read 
			exit(-1);

		// Dispatch the events to the appropriate handler. 
		for (int i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				controller->operateKeyboardEvents(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				controller->operateMouseEvents(irInBuf[i].Event.MouseEvent);
				break;
			}
		}
	}
}

