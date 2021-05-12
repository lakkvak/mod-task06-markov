#pragma once
#include <deque>
#include <map>
#include <string>
#include <vector>
class GenMarkov
{
	
private:
    typedef std:: deque<std::string> prefix;
    std:: map<prefix, std::vector<std::string>> statelab;
    int NPREF = 2;
    int MAXGEN = 1000;

public:
    GenMarkov(std::vector<std::string> words, int countPrefix, int countGen);
    GenMarkov(std::map<prefix, std::vector<std::string>> gen, int countGen);
    std::string Generate();

};

