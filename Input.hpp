#pragma once
#include <string>

class Input{
    public:
        static void CommandPredict(std::string& input);
    private:
        static void ToUpper(std::string& str);
        static size_t FindFirstSpace(const std::string& input);
        static std::string m_CommandList[19];
};
