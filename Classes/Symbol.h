#include <cocos2d.h>

USING_NS_CC;

class Symbol : public  cocos2d::Node
{
	int id = 0;
	Sprite* symbol_img;
public:
	static Symbol* create(int id);
	bool init() override;
protected:
	Symbol();
	virtual ~Symbol();
};