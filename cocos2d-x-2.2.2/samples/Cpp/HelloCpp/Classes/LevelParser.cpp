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

void LevelParser::GetQuizesFromJson(const char* fileName)
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
  
  if(document.HasMember("quizes"))
  {
	  const Value& level = document["quizes"];

		for(size_t i = 0; i < level.Size(); ++i)
		{
			const Value& quiz = level[i];
			std::pair<std::string, std::string> quizPair;
			quizPair.first = quiz["question"].GetString();
			quizPair.second = quiz["answer"].GetString();

			quizes.push_back(quizPair);
		}
  }
}