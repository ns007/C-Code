#include <iostream>
#include "ConsoleEventsHandler.h"
#include "ComoboxInputEntry.h"
#include "IControl.h"
#include <vector>
#include <string>
#include "TextBox.h"

using namespace std;

int main(void) {
	int x;
	std::vector<IControl *> inputEntries;
	TextBox * t = new TextBox(50);
	//t->setText("Fuck the system");
	t->setLocationX(20);
	t->setLocationY(30);
	inputEntries.push_back(t);
	ConsoleEventsHandler * consoleEventsHandler = new ConsoleEventsHandler(inputEntries);
	t->draw();
	consoleEventsHandler->listenToEvents();

	cout << '\xB3' << endl;

	

	cin >> x;
	return 0;
}
