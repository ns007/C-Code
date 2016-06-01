#include "IControl.h"


int IControl::getLocationX(){
	return locationX;
}

int IControl::getLocationY(){
	return locationY;
}

void IControl::setLocationX(int _locationX){
	locationX = _locationX;
}

void IControl::setLocationY(int _locationY){
	locationY = _locationY;
}

int IControl::getWidth() {
	return width;
}

int IControl::getHeight() {
	return height;
}

void IControl::setWidth(int _width) {
	width = _width;
}

void IControl::setHeight(int _height) {
	height = _height;
}