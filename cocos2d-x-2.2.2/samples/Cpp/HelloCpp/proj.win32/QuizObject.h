#pragma once
#include <string>
#include <memory>
#include <vector>

class QuizObject
{
public:

	QuizObject();
	QuizObject(const char* question, const char* answer);
	QuizObject(std::string question, std::string answer);
	~QuizObject();

	void FindCharIndexesInAnswer(int*& indexes, int& size, char ch); //if not found,will return -1.If found,will return 

private:

	std::string question;
	std::string answer;
};