#pragma once
#include "IControl.h"
#include <vector>

using namespace std;

class Panel : public IControl
{
	private:
		std::vector<IControl *> controllers;

	public:
		Panel(int height,int width);
		void AddControl(IControl * control);
		void draw();
		~Panel();
};

