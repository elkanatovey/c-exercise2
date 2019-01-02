//
// Created by elkanatovey on 1/1/19.
//

#ifndef CPP_EXERCISE2_FILEPARSER_H
#define CPP_EXERCISE2_FILEPARSER_H
#include <iosfwd>

#include <unordered_set>
#include <unordered_map>

//void commonWords(const boost::filesystem::path &full_path, std::unordered_set<std::string>
//&wordContainer, const std::string &fileName);

void commonWords(const std::string &fileName, std::unordered_set<std::string> &wordContainer);

void unknownWords(const std::string &fileName, std::unordered_map<std::string, int>
&wordContainer, const std::unordered_set<std::string> &signatureWords);

double calculate_angle(const std::unordered_map<std::string, int> &uknownText,
                       const std::unordered_map<std::string, int> &knownText);

#endif //CPP_EXERCISE2_FILEPARSER_H
