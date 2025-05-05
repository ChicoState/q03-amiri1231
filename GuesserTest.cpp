/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, correctguess) {
    Guesser g("hello");
    ASSERT_TRUE(g.match("hello"));
}

TEST(GuesserTest, wrongguess) {
    Guesser g("hello");
    ASSERT_FALSE(g.match("hells"));
    ASSERT_EQ(g.remaining(), 2);
}

TEST(GuesserTest, locksout) {
    Guesser g("hello");
    ASSERT_FALSE(g.match("xxxxx"));
    ASSERT_FALSE(g.match("hello"));
    ASSERT_EQ(g.remaining(), 3);
}

TEST(GuesserTest, Threeguesses) {
    Guesser g("hello");
    g.match("hella");
    g.match("helly");
    g.match("hellz");
    ASSERT_FALSE(g.match("hello"));
    ASSERT_EQ(g.remaining(), 0);
}

TEST(GuesserTest, correct) {
    Guesser g("hello");
    g.match("hella");
    ASSERT_EQ(g.remaining(), 2);
    ASSERT_TRUE(g.match("hello"));  
}


TEST(GuesserTest, BruteForce) {
    Guesser g("test");
    g.match("xxxxxxxx");
    ASSERT_FALSE(g.match("test"));
}

TEST(GuesserTest, reminder) {
    Guesser g("hey");
    g.match("hex");
    g.match("hez");
    g.match("hem");
    ASSERT_EQ(g.remaining(), 0);
    g.match("hey");
    ASSERT_EQ(g.remaining(), 0);
}

TEST(GuesserTest, Partial) {
    Guesser g("abcde");
    g.match("abfde");
    ASSERT_EQ(g.remaining(), 2);
    g.match("abfge");
    ASSERT_EQ(g.remaining(), 1);
    ASSERT_TRUE(g.match("abcde")); 
}

TEST(GuesserTest, secondtry) {
    Guesser g("secret");
    g.match("secrex");
    g.match("secrer");
    ASSERT_TRUE(g.match("secret"));
}

TEST(GuesserTest, spaces) {
    Guesser g("hello world");
    ASSERT_TRUE(g.match("hello world"));
    ASSERT_FALSE(g.match("hello_world")); 
    ASSERT_EQ(g.remaining(), 2);
}

TEST(GuesserTest, numbers) {
    Guesser g("test123");
    ASSERT_TRUE(g.match("test123"));
    ASSERT_FALSE(g.match("test321"));
    ASSERT_EQ(g.remaining(), 2);
}

TEST(GuesserTest, mixcase) {
    Guesser g("TEst123");
    ASSERT_TRUE(g.match("TEst123"));
    ASSERT_FALSE(g.match("test123")); 
    ASSERT_EQ(g.remaining(), 2);
}

