#pragma once
#include <vector>
#include "IControl.h"

class ConsoleEventsHandler
{
public:
	ConsoleEventsHandler();
	ConsoleEventsHandler(std::vector<IControl *>);
	~ConsoleEventsHandler();
	void listenToEvents();
};

