#include "GroundSprite.h"

GroundSprite::GroundSprite()
{
	i = 0;
	j = 0;
	sprite = nullptr;
}

GroundSprite::GroundSprite(int i,int j, const char* spriteName)
{
	this->i = i;
	this->j = j;
	this->sprite = CCSprite::create(spriteName);
}

GroundSprite::~GroundSprite()
{
	this->sprite->release();
}