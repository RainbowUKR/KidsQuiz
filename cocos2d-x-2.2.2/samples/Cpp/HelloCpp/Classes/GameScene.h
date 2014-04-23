#pragma once
#include "cocos2d.h"
#include <vector>

class LevelParser;
class QuizObject;

class GameScene : public cocos2d::CCLayer
{
public:
	GameScene(void);
	virtual ~GameScene(void);
	virtual bool init();  

    static cocos2d::CCScene* scene();

	CREATE_FUNC(GameScene);

private:
	LevelParser* levelParser;
	QuizObject* quiz;

	std::vector<cocos2d::CCImage*> letters;
};

