#pragma once
#include "cocos2d.h"
USING_NS_CC;

class GroundSprite
{
public:
	GroundSprite(int i,int j, const char* spriteName);
	GroundSprite();
	~GroundSprite();

private:
	int i;
	int j;
	CCSprite* sprite;

};