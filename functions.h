#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <iomanip>
#include <cerrno>
#include <cstring>

std::unordered_map<std::string, int> countWords(const std::string& text);
std::map<std::string, std::vector<int>> wordReferences(const std::string& text);
void findURLs(const std::string& text);
void printWordReferences(const std::string& text);
void printURLs(const std::string& text);
void saveResults(int choice, const std::string& text);

#endif // FUNCTIONS_H
