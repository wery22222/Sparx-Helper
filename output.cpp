#include "Main.hpp"
void Main::output()
{
  std::cout << "Enter the code: ";
  
  std::string code;

  getline(std::cin ,code);
  
  if(code.empty())
  {
  //Iterate Through all elements
  for (auto& it:m_CodesAndAnswers)
  {
	//Print current element
    std::cout << "\n\tCode: " << it.first << " is "<< it.second << '\n';
  }
  return;
  }
  while (m_CodesAndAnswers.lower_bound(code) != m_CodesAndAnswers.end()){
    std::cout << "Code not found"<<std::endl<<"Please enter valid code: ";
    getline(std::cin, code);
  }
  std::cout <<std::endl<< "\tThe answer is: " << m_CodesAndAnswers.at(code)<< std::endl;
  
}