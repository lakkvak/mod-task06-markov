
#include "textgen.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream str;
    str.open("text.txt");
    if (!str.is_open())
    {
       std::cout << "Error opening file";
        exit(0);
    }
    std::vector<std::string> words;
    std::string word;
    while (!str.eof())
    {
        str >> word;
        words.push_back(word);
    }
    str.close();

    GenMarkov markov(words, 2, 1000);
    std::string line = markov.Generate();

    std::ofstream fStream;
    fStream.open("output.txt");
    if (!fStream.is_open())
    {
        std::cout << "Error opening file";
        exit(0);
    }
    fStream.clear();
    fStream << line;
    fStream.close();

}

