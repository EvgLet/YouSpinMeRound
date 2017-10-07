#include <Symbol.h>

Symbol* Symbol::create()
{
	Symbol *symbol = new (std::nothrow) Symbol();
	if (symbol && symbol->init())
	{
		symbol->autorelease();
		return symbol;
	}
	return nullptr;
}

Symbol::Symbol(void)
{
	//create here
}

Symbol::~Symbol()
{
	//clean here
}