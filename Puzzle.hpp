#pragma once
#include "Item.hpp"
#include <string>

class Puzzle
{
public:
	Puzzle(std::string name, std::string desc, std::string cdesc);
	std::string m_CheckDesc;
	void TestLock();
	int m_Lock = 0;
	std::string GetName() const;
	std::string m_Desc;
	Item m_Contains = Item(0,0,0,0,false,"nothing","");
private:
	std::string m_Name;
};
