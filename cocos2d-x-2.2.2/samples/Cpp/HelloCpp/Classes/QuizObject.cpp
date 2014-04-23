#include "QuizObject.h"

QuizObject::QuizObject()
{

}

QuizObject::~QuizObject()
{
}
	
QuizObject::QuizObject(const char* question, const char* answer)
	:question(std::string(question))
	,answer(std::string(answer))
{
}

QuizObject::QuizObject(std::string question, std::string answer)
	:question(question)
	,answer(answer)
{
}

void QuizObject::FindCharIndexesInAnswer(int*& indexes, int& size, char ch)
{
	size = 0;
	for(int i = 0; i < answer.length(); ++i)
	{
		if(answer[i] == ch)
		{
			indexes[size++] = i;
		}
	}
}