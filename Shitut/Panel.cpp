#include "stdafx.h"
#include "Panel.h"
#include <vector> 

Panel::Panel(int height,int width)
{
	setWidth(width);
	setHeight(height);
}

Panel::~Panel()
{

}

void Panel::AddControl(IControl * control)
{
	controllers.push_back(control);
}

void Panel::draw()
{

}