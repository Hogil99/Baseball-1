#include "pch.h"
#include "../Project1/BaseBall.cpp"

TEST(BaseballGame, TryGameTest) {
	Baseball baseball("123");
	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("3v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("335"), std::invalid_argument);
}

TEST(BasballGame, PerfectMatch) {
	Baseball baseball("123");
	Result result = baseball.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strike);
	EXPECT_EQ(0, result.ball);
}

TEST(BasballGame, PartialMatch) {
	Baseball baseball("123");
	Result result = baseball.guess("526");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strike);
	EXPECT_EQ(0, result.ball);
}


TEST(BasballGame, PartialMatch2) {
	Baseball baseball("123");
	Result result = baseball.guess("321");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strike);
	EXPECT_EQ(2, result.ball);
}