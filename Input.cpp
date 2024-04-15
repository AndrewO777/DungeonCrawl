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

bool Input::CompareStrings(const std::string& str1, const std::string& str2)
{
    for(size_t i = 0; i < str1.size() && i < str2.size(); ++i)
    {
        if(toupper(str1[i]) != toupper(str2[i]))
            return false;
    }
    return true;
}

void Input::CommandPredict(std::string& input)
{
    ToUpper(input);
    RemoveLeadingSpaces(input);
    short firstSpace = FindFirstSpace(input);
    for(string command : m_CommandList)
    {
        if(firstSpace > (short)command.size() || command == "DEBUGMENU123" || command == "GODMODE123")
            continue;
        if(CompareStrings(firstSpace != -1 ? input.substr(0,firstSpace) : input,command))
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
