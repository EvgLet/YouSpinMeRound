#include <cocos2d.h>
#include <vector>
#include "Symbol.h"

USING_NS_CC;

class Window : public Node
{
	static const int REELS = 5;
	static const int SYMBOLS = 3;

	std::vector<std::vector<Symbol*>> symbols;
public:
	static Window* create();
	bool init() override;
protected:
	Window();
	virtual ~Window();
};