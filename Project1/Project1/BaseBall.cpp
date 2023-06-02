#include <iostream>

using namespace std;

class Result
{
public:
	Result(bool solved, int strike, int ball):solved(solved), strike(strike), ball(ball)
	{
		
	}
	bool solved;
	int strike;
	int ball;
};

class Baseball
{
public:
	explicit Baseball(const char* str) : question(str)
	{
		
	}

	bool isDuplicatedNumber(string guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeCharacter(string guessNumber)
	{
		for (char c : guessNumber)
		{
			if ( c < '0' || c > '9')
			{
				return true;
			}
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber == "") {
			throw std::invalid_argument("���� �־�� ��");
		}
		if (guessNumber.length() != 3)
		{
			throw std::invalid_argument("���� 3 �ڸ����� �մϴ�");
		}
		if (isIncludeCharacter(guessNumber))
		{
			throw std::invalid_argument("���ڸ� ���� ��");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw std::invalid_argument("���� ���ڰ� ����� �մϴ�.");
		}
	}

	int getStrikeCount(string guessNumber)
	{
		int strikeCnt = 0;
		for (int i = 0; i < guessNumber.size(); i++)
		{
			if (question[i] == guessNumber[i])
				strikeCnt++;
		}
		return strikeCnt;
	}

	int getBallCnt(string guessNumber)
	{
		int ballCnt = 0;
		for (int i = 0; i < guessNumber.size(); i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index != i) ballCnt++;
		}
		return ballCnt;
	}

	Result guess(string guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		int strikeCnt = getStrikeCount(guessNumber);
		int ballCnt = getBallCnt(guessNumber);

		return Result(false, strikeCnt, ballCnt);
	}
private:
	string question;
};