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

	void FindCharIndexesInAnswer(int*& indexes, int& size, char ch);

	inline const std::string& GetQuestion() const
	{
		return question;
	}

	inline const std::string& GetAnswer() const
	{
		return answer;
	}

private:

	std::string question;
	std::string answer;
};