//
// Created by elkanatovey on 1/1/19.
//

#include "fileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include <cmath>


// --------------------------------------------------------------------------------------
// This file contains the implementation of the fileParser functions.
// --------------------------------------------------------------------------------------


/**
 * read the word list in from memmory
 * @param fileName reads in the common words file
 * @param wordContainer container for the words
 */
void commonWords(const std::string &fileName, std::unordered_set<std::string>
                 &wordContainer)
{
    std::ifstream currentFile;
    currentFile.open(fileName);
    if(!currentFile.is_open())
    {
        std::cerr << "Unable to open file " << fileName << std::endl;
        exit(1);
    }
    std::string currentWord;
    while(getline(currentFile, currentWord))
    {
        wordContainer.insert(currentWord);
    }
    currentFile.close();
}

/**
 * receive a line and tokenize into a container (helper function)
 * @param lineContainer vector to contain tokens
 * @param currentLine line to tokenize
 */
void parseLine(std::vector<std::string> &lineContainer, const std::string &currentLine)
{
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep(" \r\n,!;:\"");
    tokenizer tokens(currentLine, sep);
    for(tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
    {
        lineContainer.push_back(*iter);
    }
}

/**
 * helper function calculates vector norm
 * @param text map unordered_map containing words
 * @return the norm
 */
double calculateNorm(const std::unordered_map<std::string, int> &text)
{
    double sum = 0;
    for(auto &word : text)
    {
        sum += std::pow(word.second, 2);
    }
    return std::sqrt(sum);
}

/**
 * calculate the distance between to textVectors
 * @param uknownText v1
 * @param knownText v2
 * @return dist
 */
double calculateAngle(const std::unordered_map<std::string, int> &uknownText,
                      const std::unordered_map<std::string, int> &knownText)
{
    double score = 0, divisor, secondVal;
    std::unordered_map<std::string, int>:: const_iterator knownTextIter;
    double norm1 = calculateNorm(uknownText);
    double norm2 = calculateNorm(knownText);
    divisor = norm1 * norm2;
    if(divisor == 0)
    {
        return 0;
    }
    for(auto &word : uknownText)
    {
        secondVal = 0;
        knownTextIter = knownText.find(word.first);
        if(knownTextIter != knownText.end())
        {
            secondVal = knownTextIter -> second;
        }
        score += word.second * secondVal;
    }
    score = score / divisor;
    return score;
}


/**
 * calculate the signature of a given text file
 * @param fileName file we are working on
 * @param wordContainer where to put words
 * @param signatureWords set of signature words
 */
void unknownWords(const std::string &fileName, std::unordered_map<std::string, int>
                  &wordContainer, const std::unordered_set<std::string> &signatureWords)
{
    std::ifstream currentFile;
    currentFile.open(fileName);
    if(!currentFile.is_open())
    {
        std::cerr << "Unable to open file " << fileName << std::endl;
        exit(1);
    }
    std::string currentLine;
    while(getline(currentFile, currentLine))
    {
        std::vector<std::string> lineWords;
        parseLine(lineWords, currentLine);
        for (auto &lineWord : lineWords)
        {
            // split up words
            std::transform(lineWord.begin(), lineWord.end(), lineWord.begin(), ::tolower);
            if (signatureWords.count(lineWord))
            {
                wordContainer[lineWord]++;
            }
        }
    }
    currentFile.close();
}
