//
// Created by elkanatovey on 1/1/19.
//

#ifndef CPP_EXERCISE2_FILEPARSER_H
#define CPP_EXERCISE2_FILEPARSER_H
#include <iosfwd>

#include <unordered_set>
#include <unordered_map>

// --------------------------------------------------------------------------------------
// This file contains the fileParser headers.
// --------------------------------------------------------------------------------------

/**
 * read the word list in from memmory
 * @param fileName reads in the common words file
 * @param wordContainer container for the words
 */
void commonWords(const std::string &fileName, std::unordered_set<std::string> &wordContainer);

/**
 * calculate the signature of a given text file
 * @param fileName file we are working on
 * @param wordContainer where to put words
 * @param signatureWords set of signature words
 */
void unknownWords(const std::string &fileName, std::unordered_map<std::string, int>
                  &wordContainer, const std::unordered_set<std::string> &signatureWords);

/**
 * calculate the distance between to textVectors
 * @param uknownText v1
 * @param knownText v2
 * @return dist
*/
double calculateAngle(const std::unordered_map<std::string, int> &uknownText,
                      const std::unordered_map<std::string, int> &knownText);

#endif //CPP_EXERCISE2_FILEPARSER_H
