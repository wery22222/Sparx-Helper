#include "Main.hpp"

Main::Main()
{
  std::ifstream inputFile("storedFiles.log.gz");
  std::string line;
  while (getline(inputFile, line))
    m_FileNames.push_back(line);
  inputFile.close();

  file::readFile(m_CodesAndAnswers, m_AutoSaveFile);
}
void Main::run()
{
  while (true)
  {
    if (input())
      continue;
    update();
    output();
  }
}
void Main::autoSave(){
  std::string codes [10];
  char* autoSaveFile = "autosave.txt";
  file::writeToFile(m_CodesAndAnswers, autoSaveFile);
}