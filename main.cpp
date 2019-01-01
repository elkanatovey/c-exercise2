#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "fileParser.h"

const int MIN_LEGAL_ARGS = 4;

//void commonWords(const std::string &fileName, std::unordered_set<std::string> &wordContainer)
//{
//    std::ifstream currentFile;
//    currentFile.open(fileName);
//    if(!currentFile)
//    {
//        std::cerr << "Unable to open file "<< fileName << std::endl;
//        exit(1);
//    }
//    std::string currentWord;
//    while(getline(currentFile, currentWord))
//    {
//        wordContainer.insert(currentWord);
//    }
//    currentFile.close();
//}


int main(int argc, char *argv[])
{
    if(argc < MIN_LEGAL_ARGS)
    {
        std::cerr << "Usage: find_the_author<frequent_words.txt> <text1> ...!" << std::endl;
        exit(-1);
    }
    std::unordered_set<std::string> wordContainer;
    //input frequent words
    commonWords(argv[1], wordContainer);

    //input uknown + score

    for(int i = 3; i <= argc; i++)
    {
        //calculate score
    }
    //print max
    std::cout << "Hello, World!" << std::endl;
    return 0;
}