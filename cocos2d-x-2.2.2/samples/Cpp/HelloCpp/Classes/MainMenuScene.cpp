#include "MainMenuScene.h"
#include "AppMacros.h"
USING_NS_CC;

CCScene* MainMenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenuScene *layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MainMenuScene::init()
{
	 if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MainMenuScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
	
	
	CCMenuItemImage* pStartItem = CCMenuItemImage::create(
										"OrdinaryQuad.png",
										"OrdinaryQuad.png",
										this,
										menu_selector(MainMenuScene::menuStartCallback)
													 );

	CCLabelTTF* startButtonLabel = CCLabelTTF::create("START","Arial", 12);
	startButtonLabel->setPosition(ccp(pStartItem->getContentSize().width / 2,
									pStartItem->getContentSize().height / 2));
	
	pStartItem->addChild(startButtonLabel);

	pStartItem->setPosition(ccp(origin.x + visibleSize.width / 2 - pStartItem->getContentSize().width / 2,
								origin.y + visibleSize.height / 2 - pStartItem->getContentSize().height / 2));

	CCMenu* menu = CCMenu::create(pStartItem,pCloseItem,NULL);
	menu->setPosition(CCPointZero);
    this->addChild(menu, 1);
}

void MainMenuScene::menuCloseCallback(CCObject* pSender)
{
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
		CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	#else


		CCDirector::sharedDirector()->end();

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);

	#endif
	#endif
}

void MainMenuScene::menuStartCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,newScene));
	//impliment function,that will open GameScene.
	//CCDirector::sharedDirector()->pushScene();
}