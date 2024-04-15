#pragma once
#include <string>

class Input{
    public:
        static void CommandPredict(std::string& input);
        static bool CompareStrings(const std::string& str1, const std::string& str2);
    private:
        static void ToUpper(std::string& str);
        static short FindFirstSpace(const std::string& input);
        static std::string m_CommandList[19];
        static void RemoveLeadingSpaces(std::string& input);
};
