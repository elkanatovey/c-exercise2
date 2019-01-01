//
// Created by elkanatovey on 1/1/19.
//

#include "fileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * read the word list in from moemory
 * @param fileName
 * @param wordContainer
 */
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

void parseLine(std::vector<std::string> &lineContainer, std::string currentLine)
{
    boost::
}

double calculate_angle(){}



void uknownWords(const std::string &fileName, std::unordered_map<std::string, int>
        &wordContainer, const std::unordered_set<std::string> &signatureWords)
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

        // split up words
        if(signatureWords.count(currentWord))
        {
            wordContainer[currentWord]++;
        }
    }
    currentFile.close();
}
