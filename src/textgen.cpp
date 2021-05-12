#include "textgen.h"
#include <time.h>
GenMarkov::GenMarkov(std::vector<std::string> words, int countPrefix, int countGen)
{
    NPREF = countPrefix;
    MAXGEN = countGen;

    for (int i = 0; i < words.size() - NPREF + 1; i++)
    {
        prefix prfx;
        for (int j = 0; j < NPREF; j++)
            prfx.push_back(words.at(i + j));
        if (i == words.size() - NPREF)
            statelab[prfx].push_back("|_Last prefix_|");
        else
            statelab[prfx].push_back(words.at(i + NPREF));
    }
}

GenMarkov::GenMarkov(std::map<prefix, std::vector<std::string>> gen, int countGen)
{
    statelab = gen;
    NPREF = statelab.begin()->first.size();
    MAXGEN = countGen;
}

std::string GenMarkov::Generate()
{
    srand(time(NULL));
    std::string output;
    std::deque<std::string> words;

    auto it = statelab.begin();
    advance(it, rand() % statelab.size());
    for (int i = 0; i < NPREF; i++)
        words.push_back(it->first.at(i));

    while (output.size() < MAXGEN)
    {
        prefix prfx;
        for (int i = 0; i < NPREF; i++)
            prfx.push_back(words.at(i));
        int randE = rand() % statelab.find(prfx)->second.size();
        if (statelab.find(prfx)->second.at(randE) == "|_Last prefix_|")
        {
            for (int i = 0; i < NPREF; i++)
                output += words.at(i) + ' ';
            break;
        }
        words.push_back(statelab.find(prfx)->second.at(randE));

        output += words.at(0) + ' ';
        words.pop_front();
    }

    return output;
}