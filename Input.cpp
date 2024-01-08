#include <iostream>
#include "Input.hpp"

using std::string;

string Input::m_CommandList[19] = {"CLOSE","EAST","NORTH","EXIT","WEST","SOUTH","UP","DOWN","TAKE","USE","CHECK","ATTACK","HELP","DEBUGMENU123","GODMODE123","HEALTH","INVENTORY","DROP","LOOK"};

void Input::ToUpper(string& str)
{
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		*iter = toupper(*iter);
	}
}

size_t Input::FindFirstSpace(const string& input)
{
    size_t i = 0;
    for(; i < input.size(); ++i)
    {
        if (input[i] == ' ' && i > 0)
            return i;
    }
    return -1;
}

void Input::CommandPredict(std::string& input)
{
    bool flag;
    ToUpper(input);
    for (string command : m_CommandList)
    {
        flag = true;
        if (FindFirstSpace(input) > command.size() || command == "GODMODE123" || command == "DEBUGMENU123")
            continue;
        size_t i = 0;
        for (; i < input.size(); ++i)
        {
            if (input[i] != command[i])
            {
                flag = false;
                continue;
            }
        }
        if (flag == true)
        {
            for (size_t j = 0; j != i; ++j)
            {
                input[j] = command[j];
            }
            return;
        }
    }
    input = "INVALID";
}
