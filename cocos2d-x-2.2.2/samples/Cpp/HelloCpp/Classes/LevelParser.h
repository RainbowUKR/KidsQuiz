#pragma once
#include <vector>
#include "include\cocos2d.h"
USING_NS_CC;

class LevelParser
{
public:
	LevelParser(void);
	~LevelParser(void);

	void GetQuizesFromJson(const char* fileName);

	inline int CountAvailableQuizes() const
	{
		return quizes.size();
	}

private:
	std::vector<std::pair<std::string, std::string>> quizes;
};

