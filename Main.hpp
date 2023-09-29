#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include "fileIO.hpp"

class Main{
private:
  std::vector<std::string> m_FileNames;
  std::map<std::string, std::string> m_CodesAndAnswers;
  std::string m_CurrentCode;
  std::string m_CurrentAns;
  char* m_AutoSaveFile = "autosave.txt";
  bool input();
  void output();
  void update();
  void autoSave();
public:
  Main();
  void run();

};