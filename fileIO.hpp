#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
namespace file {
void fileIO(std::map<std::string, std::string>& input);
void writeToFile(std::vector<std::string>& fileNames);
void writeToFile(std::map<std::string, std::string>& input, const std::string& fileName);
void writeToFile(std::map<std::string, std::string>& input, const char* fileName);
void readFile(std::map<std::string, std::string>& map, const std::string& fileName);
void readFile(std::map<std::string, std::string>& map, char* fileName);
bool in(std::vector<std::string>& filenames, std::string& fileName);
}
