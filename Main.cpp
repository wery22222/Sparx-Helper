#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

void takeInput();
void output(std::map<std::string, std::string> input);
void writeToFile(std::map<std::string, std::string> input);
std::map<std::string, std::string> readFile();
int main()
{
	takeInput();
	return 0;
}


void output(std::map<std::string, std::string> input)
{
	std::cout << "Enter the code: ";
	
	std::string code;
	std::cin >> code;
	for (std::map<std::string, std::string>::iterator it = input.begin(); it != input.end(); it++)
	{
		if (code == it->first)
		{
			std::cout << "Answer is: " << it->second << "\n";

			return;
		}
	}
	std::cout << "Code not found \n";
}


void takeInput()
{
	std::string currentAns;
	std::string currentCode;
	int iterationNum = 0;
	std::map<std::string, std::string> codesAndAnswers;
	while (true)
	{
		std::cout << "Type the code or Q to quit, O to get output, S to save or R to read (destroys saved codes do at start unless want to clear): ";
		std::cin >> currentCode;
		if ((currentCode == "Q" || currentCode == "q"))
		{
			return;
		}
		if ((currentCode == "O" || currentCode == "o"))
		{
			output(codesAndAnswers);
			continue;
		}
		if ((currentCode == "S" || currentCode == "s"))
		{
			writeToFile(codesAndAnswers);
			continue;
		}
		if ((currentCode == "R" || currentCode == "r"))
		{
			readFile();
			continue;
		}
		if (std::isblank(currentCode[0]))
		{
			std::cout << "\n";
			continue;
		}
	getAns:
		std::cout << "Enter the answer: ";
		std::cin >> currentAns;
		if (std::isblank(currentAns[0]))
		{
			goto getAns;
		}
		codesAndAnswers[currentCode] = currentAns;
		iterationNum++;
	}
}
void writeToFile(std::map<std::string, std::string> input)
{
	std::stringstream ss;
	std::string outputStr;
	std::map<std::string, std::string>::iterator it = input.begin();
	for (; it != input.end(); it++)
	{
		ss << it->first << "," << it->second << ";";
	}
	ss >> outputStr;
	std::ofstream outputFile("codes.txt");
	outputFile << outputStr;
	outputFile.close();
}
std::map<std::string, std::string> readFile()
{
	std::map<std::string, std::string> inputMap;
	std::string inputStr;
	std::ifstream inputFile("codes.txt");
	if (inputFile.is_open())
	{
		// >> Reads the data
		inputFile >> inputStr;
		inputFile.close();
	}
	std::stringstream ss(inputStr);
	std::string item1;
	int i = 0;
	while (std::getline(ss, item1, ';')) {
		std::string code;
		std::string item2;
		int j = 0;
		while (std::getline(ss, item2, ','))
		{
			if (j == 0)
			{
				code = item2;
				j++;
				continue;
			}
			inputMap[code] = item2;
		}
		i++;
	}
	return inputMap;
}