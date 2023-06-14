#include "Main.hpp"
//#include "MapVisualisation.hpp"




int main()
{
  Main mainEngine = Main();
  mainEngine.run();
}

/*
void output(std::map<std::string, std::string>& input)
{
  std::cout << "Enter the code: ";
  
  std::string code;

  getline(std::cin ,code);
  
  if(code.empty())
  {
  //Iterate Through all elements
  for (auto& it:input)
  {
	//Print current element
    std::cout << "\n\tCode: " << it.first << " is "<< it.second << '\n';
  }
  return;
  }

  while (input.find(code) == input.end()){
    std::cout << "Code not found"<<std::endl<<"Please enter valid code: ";
    getline(std::cin, code);
  }
  std::cout <<std::endl<< "\tThe answer is: " << input.at(code)<< std::endl;

}


void takeInput()
{
  std::vector<std::string> fileNames;
  std::ifstream inputFile("storedFiles.log.gz");
  std::string line;
  while (getline(inputFile, line))
    fileNames.push_back(line);
  inputFile.close();
  
  //VisualWindow* drawing;
  std::string currentAns;
  std::string currentCode;
  char* autoSaveFile = "autosave.txt";
  std::map<std::string, std::string> codesAndAnswers;
  file::readFile(codesAndAnswers, autoSaveFile);

  //Main loop
  while (true)
  {
    std::cout << "Type the code, Q to quit, O to get output, \nF to do File IO, C clear all codes stored: ";
    getline(std::cin, currentCode);
    if (currentCode.empty())
      continue;
    if ((currentCode == "C" || currentCode == "c"))
    {
      std::map<std::string, std::string> empty;
      for (auto fileName:fileNames)
        file::writeToFile(empty, fileName);
      codesAndAnswers = empty;
      return;
    }
    if ((currentCode == "Q" || currentCode == "q"))
    {
      file::writeToFile(fileNames);
      autoSave(codesAndAnswers);
      return ;
    }
    if ((currentCode == "O" || currentCode == "o"))
    {
      output(codesAndAnswers);
      continue;
    }
    if ((currentCode == "F" || currentCode == "f"))
    {
      file::fileIO(codesAndAnswers);
      continue;
    }
    /*if ((currentCode == "D" || currentCode == "d"))
      drawing = new VisualWindow(&codesAndAnswers);
      continue;
    }
    
    if (currentCode.empty())
    {
      std::cout << "Please enter something"<< std::endl;
      continue;
    }
  getAns:
    std::cout << "Enter the answer:";
    getline(std::cin, currentAns, '\n');
    if (currentAns.empty())
      goto getAns;
        codesAndAnswers[currentCode] = currentAns;
  }
}


void autoSave(std::map<std::string, std::string>& input)
{
  std::string codes [10];
  std::map<std::string, std::string>::iterator it = input.end();
  char* autoSaveFile = "autosave.txt";
  file::writeToFile(input, autoSaveFile);
}


const std::string& mapToStr(std::map<std::string, std::string>& input)
{
  std::stringstream ss;

  return ss.str();
}
*/