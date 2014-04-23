#include "GameScene.h"
#include "AppMacros.h"
#include "LevelParser.h"
#include "QuizObject.h"
USING_NS_CC;


GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
}

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameScene::init()
{
	 if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	levelParser = new LevelParser();
	levelParser->GetQuizesFromJson("test_level.json");

	if(levelParser->CountAvailableQuizes() > 0)
	{
		assert(0);
	}

	quiz = levelParser->GetRandomQuiz();
	
	CCSprite* background = CCSprite::create("game_background.png");
	background->setPosition(ccp(0,0));
	background->setContentSize(CCSize(visibleSize.width, visibleSize.height));
	this->addChild(background);

	CCLabelTTF* question = CCLabelTTF::create(quiz->GetQuestion().c_str(),"Arial",TITLE_FONT_SIZE);
	CCLabelTTF* answer = CCLabelTTF::create(quiz->GetAnswer().c_str(),"Arial",TITLE_FONT_SIZE);

	question->setPosition(ccp(50, 100));
	answer->setPosition(ccp(50, 400));

	this->addChild(question);
	this->addChild(answer);
}
