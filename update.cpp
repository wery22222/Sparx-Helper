#include "Main.hpp"

void Main::update()
{
    if ((m_CurrentCode == "C" || m_CurrentCode == "c"))
    {
      std::map<std::string, std::string> empty;
      for (auto fileName:m_FileNames)
        file::writeToFile(empty, fileName);
      m_CodesAndAnswers = empty;
      return;
    }
    if ((m_CurrentCode == "Q" || m_CurrentCode == "q"))
    {
      file::writeToFile(m_FileNames);
      autoSave();
      return ;
    }
    if ((m_CurrentCode == "O" || m_CurrentCode == "o"))
    {
      if(m_CodesAndAnswers.empty()){
        std::cout<<"Please enter something first";
        return;
      }
      output();
      return;
    }
    if ((m_CurrentCode == "F" || m_CurrentCode == "f"))
    {
      file::fileIO(m_CodesAndAnswers);
      return;
    }
}