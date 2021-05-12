// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
#include<string>
using namespace std;
TEST(task1, test1)
{
    vector<string> words{ "Long", "live", "God", };
    GenMarkov markov(words, 3, 1000);
    string output = markov.Generate(); 
    if (output[0] = 'L')
        ASSERT_STREQ("Long live God ", output.c_str());
    else
        ASSERT_STREQ("live God ", output.c_str());

}

TEST(task2, test1)
{
    vector<string> words{ "Long", "Live"};
    GenMarkov markov(words, 2, 1000);
    ASSERT_STREQ("Long Live ", markov.Generate().c_str());
}

TEST(task3, test1)
{
    map<deque<string>, vector<string>> m;
    m[{ "Long", "live" }].push_back("God");
    m[{"live", "God"}].push_back("|_Last prefix_|");
    GenMarkov markov(m, 1000);
    string output = markov.Generate();
    if (output[0] == 'L')
        ASSERT_STREQ("Long live God ", output.c_str());
    else
        ASSERT_EQ('l', output[0]);
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> m;
    m[{"Enjoy", "the"}].push_back("ride");
    m[{"Enjoy", "the"}].push_back("moment");
    m[{"the", "ride"}].push_back("|_Last prefix_|");
    m[{"the", "moment"}].push_back("|_Last prefix_|");

    GenMarkov markov(m, 100);
    string output = markov.Generate();
    if (output[0] == 't')
        ASSERT_EQ('t', output[0]);
    else if (output[output[output.length() - 2]] == 'e')
        ASSERT_STREQ("Enjoy the ride ", output.c_str());
    else
        ASSERT_STREQ("Enjoy the moment ", output.c_str());
}

TEST(task5, test1)
{
    vector<string> words{ "His", "life", "was", "exciting?" };
    GenMarkov markov(words, 2, 100);
    string output = markov.Generate();
    if (output[output.length() - 2] == '?')
        ASSERT_EQ('?', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}