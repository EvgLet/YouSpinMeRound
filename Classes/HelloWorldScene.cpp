#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Window.h"
#include <iostream>
#include <base/ccUtils.h>


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

	auto spinButton = MenuItemImage::create("Spin.png", "spinpressed.png", CC_CALLBACK_1(HelloWorld::menuSpinCallback, this));

	spinButton->setScaleY(0.3);
	spinButton->setScaleX(0.3);

	spinButton->setPosition(Vec2(origin.x + closeItem->getContentSize().width,
		origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
	menu->addChild(spinButton);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("YouSpinMeRound", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("background.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	Window* w = Window::create();
	auto rect = utils::getCascadeBoundingBox(w);
	w->setPosition(Vec2(visibleSize.width / 2 - rect.size.width / 2, visibleSize.height / 2 - rect.size.height / 2));
	addChild(w);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();   
}

void HelloWorld::menuSpinCallback(Ref* pSender)
{
	//make some magic after spin pressed
	std::cout << "For test" << std::endl;
}
