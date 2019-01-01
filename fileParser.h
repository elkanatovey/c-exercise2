//
// Created by elkanatovey on 1/1/19.
//

#ifndef CPP_EXERCISE2_FILEPARSER_H
#define CPP_EXERCISE2_FILEPARSER_H
#include <iosfwd>

#include <unordered_set>
#include <unordered_map>

void commonWords(const std::string &fileName, std::unordered_set<std::string> &wordContainer);

void uknownWords(const std::string &fileName, std::unordered_map<std::string, int>
&wordContainer, const std::unordered_set<std::string> &signatureWords);

#endif //CPP_EXERCISE2_FILEPARSER_H
