#pragma once
#include <vector>
#include "include\cocos2d.h"
USING_NS_CC;

class LevelParser
{
public:
	LevelParser(void);
	~LevelParser(void);

	void GetLevelFromJson(const char* fileName);
	void AddGroundToLayer(const CCLayer* layer);
	
private:
	std::vector<const char*> tileContainer;
	std::vector<CCSprite*> levelGround;
	int levelWidth;
	int levelHeight;
	
};

