#include "Main.hpp"
bool Main::input()
{
  std::cout << "Type the code, Q to quit, O to get output, \nF to do File IO, C clear all codes stored: ";
  getline(std::cin, m_CurrentCode);
  if (m_CurrentCode.empty())
    return false;
}