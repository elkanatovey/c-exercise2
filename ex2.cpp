#include <iostream>
#include <fstream>
#include <string>
#include "fileParser.h"
#include <iomanip>

const int MIN_LEGAL_ARGS = 4;

int main(int argc, char *argv[])
{
    double distance;
    if(argc < MIN_LEGAL_ARGS)
    {
        std::cerr << "Usage: find_the_author<frequent_words.txt> <text1> ...!" << std::endl;
        exit(-1);
    }
    std::unordered_set<std::string> wordContainer; // words to use as signatures
    commonWords(argv[1], wordContainer);
    std::unordered_map<std::string, int> unknownAuthor;
    unknownWords(argv[2], unknownAuthor, wordContainer); //unknown author signature
    std::string highestAuthor = " score 0";
    double highestScore = 0;
    for(int i = 3; i < argc; i++)
    {
        std::unordered_map<std::string, int> knownAuthor;
        unknownWords(argv[i], knownAuthor, wordContainer);
        distance = calculate_angle(unknownAuthor, knownAuthor);
        std::cout << std::setprecision(6) << argv[i] << " " << distance << std::endl;
        if(distance > highestScore)
        {
            highestScore = distance;
            highestAuthor = argv[i];
        }
    }
    //print max
    std::cout << "Best matching author is " << highestAuthor << " score " << highestScore
    << std::endl;
    return 0;
}
