#include <Window.h>
#include <cstdlib>
#include <base/ccUtils.h>

Window * Window::create()
{
	Window *window = new (std::nothrow) Window();
	if (window && window->init())
	{
		window->autorelease();
		return window;
	}
	return nullptr;
}

bool Window::init()
{
	Node::init();
	for (int i = 0; i < REELS; ++i) {
		std::vector<Symbol*> reel;//baraban na anglijskom
		for (int j = 0; j < SYMBOLS; ++j) {
			Symbol* s = Symbol::create(1 + rand() % 10);//random ot 1 do 10 poka 4to, potom ot servaka polu4im dannie i zapolnim norm
			reel.push_back(s);//??? symonym, tolko uzaet semantiku peremesh4eniya c++11
		}
		symbols.push_back(reel);
	}

	int currentX = 0;
	
	for (std::vector<Symbol*> reel : symbols) {
		int currentY = 0;
		for (Symbol* sym : reel) {
			addChild(sym);
			sym->setPosition(currentX, currentY);
			currentY += utils::getCascadeBoundingBox(sym).size.height * 1.1f;
		}
		currentX += utils::getCascadeBoundingBox(reel.at(0)).size.width * 1.1f;
	}

	return true;
}

Window::Window()
{
}

Window::~Window()
{
}
