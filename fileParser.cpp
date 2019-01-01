//
// Created by elkanatovey on 1/1/19.
//

#include "fileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

void commonWords(const std::string &fileName, std::unordered_set<std::string> &wordContainer)
{
    std::ifstream currentFile;
    currentFile.open(fileName);
    if(!currentFile)
    {
        std::cerr << "Unable to open file "<< fileName << std::endl;
        exit(1);
    }
    std::string currentWord;
    while(getline(currentFile, currentWord))
    {
        wordContainer.insert(currentWord);
    }
    currentFile.close();
}
