#include <iostream>
#include "Input.hpp"

using std::string;

string Input::m_CommandList[19] = {"EAST","NORTH","EXIT","WEST","SOUTH","UP","DOWN","TAKE","USE","CHECK","ATTACK","HELP","DEBUGMENU123","GODMODE123","HEALTH","INVENTORY","DROP","LOOK","CLOSE"};

void Input::ToUpper(string& str)
{
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		*iter = toupper(*iter);
	}
}

short Input::FindFirstSpace(const string& input)
{
    for(size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ' && i > 0)
            return i;
    }
    return -1;
}

void Input::RemoveLeadingSpaces(string& input)
{
    for(size_t i = 0; i < input.size(); ++i)
    {
        if(input[i] == ' ')
            input.erase(i,1);
        else
            break;
    }
}

void Input::CommandPredict(std::string& input)
{
    bool flag;
    ToUpper(input);
    RemoveLeadingSpaces(input);
    short firstSpace = FindFirstSpace(input);
    for (string command : m_CommandList)
    {
        flag = true;
        if (firstSpace > (short)command.size() || command == "GODMODE123" || command == "DEBUGMENU123")
            continue;
        for (short i = 0; i < command.size() &&
            (i < firstSpace || (firstSpace == -1 && i < input.size())); ++i)
        {
            if (input[i] != command[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            if(firstSpace != -1)
                input = command + input.substr(firstSpace);
            else
                input = command;
            return;
        }
    }
    input = "INVALID";
}
