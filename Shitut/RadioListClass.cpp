//#include <Windows.h>
//#include <stdio.h>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//VOID KeyEventProc(KEY_EVENT_RECORD);
//VOID MouseEventProc(MOUSE_EVENT_RECORD);
//
//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE), h = GetStdHandle(STD_OUTPUT_HANDLE);
//DWORD genDW, wAttr = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
//
//short row = 1, column = 0, k = 0, check = 1;
//COORD c = { column, row };
//string values[10]; //array in size 10 that includes the radio buttons
//
//
//int main(void) {
//
//	DWORD cNumRead, fdwMode, i;
//	INPUT_RECORD irInBuf[128];
//
//	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
//	//SetConsoleMode(hStdin, fdwMode);
//	//if (!SetConsoleMode(hStdin, fdwMode))
//	//	cout << "Error\n";
//
//	//get radio's buttons name and enter into string array in size 10
//	cout << "Enter radio button's names or enter 'done':\n";
//	char nameBut[] = "";
//	int j = 0;
//	while (strcmp(nameBut, "done") != 0)
//	{
//		cin.getline(nameBut, 50);
//		string str(nameBut);
//		values[j++] = str;
//	}
//	system("CLS"); //clear screen after we get al the radio names
//
//	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
//	SetConsoleCursorInfo(h, &cci);
//
//	//print the radio buttons
//	j = j - 2;
//	printf("Use up and down key for choose the required option and press enter:\n");
//	while (k <= j)
//	{
//		cout << "[ ] " << values[k++] << "\n";
//	}
//
//	//save the current color and background console: background - black, font color: white
//	CONSOLE_SCREEN_BUFFER_INFO cbi;
//	GetConsoleScreenBufferInfo(h, &cbi);
//	genDW = cbi.wAttributes;
//
//	//print the first radio button in white background
//	SetConsoleCursorPosition(h, c);
//	SetConsoleTextAttribute(h, wAttr);
//	cout << "[X] " << values[0] << "\n";
//
//	c = { column, row };
//	SetConsoleCursorPosition(h, c);
//
//	//fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
//
//	while (1)
//	{
//		// Wait for the events. 
//		if (!ReadConsoleInput(
//			hStdin,      // input buffer handle 
//			irInBuf,     // buffer to read into 
//			128,         // size of read buffer 
//			&cNumRead)) // number of records read 
//			exit(-1);
//
//		// Dispatch the events to the appropriate handler. 
//		for (i = 0; i < cNumRead; i++)
//		{
//			switch (irInBuf[i].EventType)
//			{
//			case KEY_EVENT: // keyboard input 
//				KeyEventProc(irInBuf[i].Event.KeyEvent);
//				break;
//
//			case MOUSE_EVENT: // mouse input 
//				MouseEventProc(irInBuf[i].Event.MouseEvent);
//				break;
//			}
//		}
//	}
//
//	return 0;
//}
//
//VOID KeyEventProc(KEY_EVENT_RECORD ker)
//{
//	if (!ker.bKeyDown) return;
//
//	if (ker.wVirtualKeyCode == VK_DOWN) {
//		if (row<k) {
//			SetConsoleTextAttribute(h, genDW); //change to default background and font color
//			if (row == check) {
//				SetConsoleTextAttribute(h, wAttr);
//				cout << "[X] " << values[row - 1] << "\n";
//			}
//			else {
//				cout << "[ ] " << values[row - 1] << "\n";
//			}
//			row++;
//			c = { column, row };
//			SetConsoleCursorPosition(h, c);
//			SetConsoleTextAttribute(h, wAttr);
//			cout << "[ ] " << values[row - 1] << "\n";
//			SetConsoleCursorPosition(h, c);
//		}
//	}
//	if (ker.wVirtualKeyCode == VK_UP) {
//		if (row > 1) {
//			SetConsoleTextAttribute(h, genDW);
//			if (row == check) {
//				SetConsoleTextAttribute(h, wAttr);
//				cout << "[X] " << values[row - 1] << "\n";
//			}
//			else {
//				cout << "[ ] " << values[row - 1] << "\n";
//			}
//			row--;
//			c = { column, row };
//			SetConsoleCursorPosition(h, c);
//			SetConsoleTextAttribute(h, wAttr);
//			cout << "[ ] " << values[row - 1] << "\n";
//			SetConsoleCursorPosition(h, c);
//		}
//	}
//	if (ker.wVirtualKeyCode == VK_RETURN) {
//		SetConsoleTextAttribute(h, genDW);
//		c = { 0, check };
//		SetConsoleCursorPosition(h, c);
//		cout << "[ ] " << values[check - 1] << "\n";
//
//		c = { 0, row };
//		SetConsoleCursorPosition(h, c);
//		SetConsoleTextAttribute(h, wAttr);
//		check = row;
//		cout << "[X] " << values[check - 1] << "\n";
//		SetConsoleCursorPosition(h, c);
//	}
//}
//
//
//VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
//{
//#ifndef MOUSE_HWHEELED
//#define MOUSE_HWHEELED 0x0008
//#endif
//	printf("Mouse event: ");
//
//	switch (mer.dwEventFlags)
//	{
//	case 0:
//
//		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//		{
//			printf("left button press \n");
//		}
//		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
//		{
//			printf("right button press \n");
//		}
//		else
//		{
//			printf("button press\n");
//		}
//		break;
//	case DOUBLE_CLICK:
//		printf("double click\n");
//		break;
//	case MOUSE_HWHEELED:
//		printf("horizontal mouse wheel\n");
//		break;
//	case MOUSE_MOVED:
//		printf("mouse moved\n");
//		break;
//	case MOUSE_WHEELED:
//		printf("vertical mouse wheel\n");
//		break;
//	default:
//		printf("unknown\n");
//		break;
//	}
//}