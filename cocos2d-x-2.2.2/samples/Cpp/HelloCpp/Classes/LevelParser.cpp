#include "LevelParser.h"
#include "..\extensions\CocoStudio\Json\rapidjson\document.h"
#include "..\extensions\CocoStudio\Json\rapidjson\prettywriter.h"
#include "..\extensions\CocoStudio\Json\rapidjson\rapidjson.h"
#include "CCFileUtilsWin32.h"
USING_NS_CC;
using namespace rapidjson;

LevelParser::LevelParser(void)
{

}


LevelParser::~LevelParser(void)
{
}

void LevelParser::GetLevelFromJson(const char* fileName)
{
	unsigned long filesize = 0;
	std::string content;
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
    unsigned long bufferSize = 0;
	const char* mFileData = (const char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &bufferSize);

  std::string clearData(mFileData);
  size_t pos = clearData.rfind("}");
  clearData = clearData.substr(0, pos+1);

  Document document;
  document.Parse<0>(clearData.c_str());
  
  if(document.HasMember("level"))
  {
	  const Value& level = document["level"];

	  if(level.IsObject())
	  {
		  const Value& tilesArr = level["tiles"];
		  assert(tilesArr.IsArray());

		  for(size_t i = 0; i < tilesArr.Size(); ++i)
		  {
			  auto loadpath = tilesArr[i].GetString();
			  tileContainer.push_back(loadpath);
		  }

		  this->levelWidth = level["width"].GetInt();
		  this->levelHeight = level["height"].GetInt();

		  const Value& map = level["map"];
		  assert(map.IsArray());
		  {
			  for(size_t i = 0; i < map.Size(); ++i)
			  {
				  auto index = map[i].GetInt();
				  
				  levelGround.push_back(CCSprite::create(tileContainer[index]));
			  }
		  }
	  }
  }


}

void LevelParser::AddGroundToLayer(const CCLayer* layer)
{
	int x = 0;
	int y = 0;

	for(int i = 0; i < levelGround.size(); ++i)
	{
		levelGround[i]->setPosition(ccp(x,y));
		if(i % levelWidth == 0)
		{
			x = 0;
		}
		else
		{
			x += (levelGround[i]->boundingBox().getMaxX() - levelGround[i]->boundingBox().getMinX());
		}


	}
}