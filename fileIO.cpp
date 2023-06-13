#include "fileIO.hpp"
void file::fileIO(std::map<std::string, std::string>& codesAndAnswers)
{
	//load filenames
	std::vector<std::string> fileNames;
	std::ifstream inputFile("storedFiles.log.gz");
	std::string line;
	while (getline(inputFile, line))
		fileNames.push_back(line);
	inputFile.close();

	//Prepare for inputting
  line = nullptr;

	std::cout << "S to save or R to read";
	std::string currentInstruction;
	getline(std::cin, currentInstruction);
	if ((currentInstruction == "R" || currentInstruction == "r"))
	{
		std::string fileName;
		getline(std::cin ,fileName);
		while (!in(fileNames, fileName))
		{
			std::cout << "File not found Try again:";
			getline(std::cin, fileName);
		}
			readFile(codesAndAnswers, fileName);
			return;
	}
	if ((currentInstruction == "S" || currentInstruction == "s"))
	{
		std::cout << "Enter filename";
	saveFile:
		std::string fileName;
    getline(std::cin, fileName);
		if (fileName != "storedFiles.log.gz")
		{
			if (!file::in(fileNames, fileName))
				fileNames.push_back(fileName);
			file::readFile(codesAndAnswers, fileName);
			return;
		}
		std::cout << "File not available as it stores the file names:";
		goto saveFile;
	}
}
void file::writeToFile(std::vector<std::string>& fileNames)
{
	std::string filenames = "";
	for (auto fileName : fileNames)
	{
		filenames += (fileName + "\n");
	}
	std::ofstream outputFile("storedFiles.log.gz");
	outputFile << filenames;
	outputFile.close();
}
void file::writeToFile(std::map<std::string, std::string>& input, const std::string& fileName)
{
	std::stringstream outputStr;
	std::map<std::string, std::string>::iterator it = input.begin();
	for (; it != input.end(); it++)
	{
		outputStr << it->first << "," << it->second << ";";
	}
	std::ofstream outputFile(fileName);
	outputFile << outputStr.str();
	outputFile.close();
}
void file::writeToFile(std::map<std::string, std::string>& input,const char* fileName)
{
	std::stringstream outputStr;
	std::map<std::string, std::string>::iterator it = input.begin();
	for (; it != input.end(); it++)
	{
		outputStr << it->first << "," << it->second << ";";
	}
	std::ofstream outputFile(fileName);
	outputFile << outputStr.str();
	outputFile.close();
}
void file::readFile(std::map<std::string, std::string>& map, const std::string& fileName)
{
	std::string inputStr;
	std::ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		// >> Reads the data
		inputFile >> inputStr;
		inputFile.close();
	}
	std::stringstream ss(inputStr);
	std::cout << inputStr << "\n";

	std::string item1;
	int i = 0;
	while (std::getline(ss, item1, ';')) {
		std::string code;
		std::string item2;
		int j = 0;
		std::stringstream sd(item1);
		while (std::getline(sd, item2, ','))
		{
			if (j == 0)
			{
				code = item2;
				j++;
				continue;
			}
			map[code] = item2;
		}
		i++;
	}
}
void file::readFile(std::map<std::string, std::string>& map, char* fileName)
{
	std::string inputStr;
	std::ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		// >> Reads the data
		inputFile >> inputStr;
		inputFile.close();
	}
	std::stringstream ss(inputStr);
	std::cout << inputStr << "\n";

	std::string item1;
	int i = 0;
	while (std::getline(ss, item1, ';')) {
		std::string code;
		std::string item2;
		int j = 0;
		std::stringstream sd(item1);
		while (std::getline(sd, item2, ','))
		{
			if (j == 0)
			{
				code = item2;
				j++;
				continue;
			}
			map[code] = item2;
		}
		i++;
	}
}
bool file::in(std::vector<std::string>& filenames, std::string& fileName)
{
	for (auto i : filenames)
	{
		if (i == fileName) return true;
	}
	return false;
}
