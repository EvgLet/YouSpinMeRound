#include <Symbol.h>

Symbol* Symbol::create(int id)
{
	Symbol *symbol = new (std::nothrow) Symbol();
	symbol->id = id;
	if (symbol && symbol->init())
	{
		symbol->autorelease();
		return symbol;
	}
	return nullptr;
}

bool Symbol::init()
{
	Node::init();
	symbol_img = Sprite::create("symbols/sym" + std::to_string(id) + ".png");
	addChild(symbol_img);
	return true;
}

Symbol::Symbol(void)
{
	//create here
}

Symbol::~Symbol()
{
	//clean here
}