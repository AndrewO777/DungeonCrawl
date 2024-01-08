#pragma once
#include <vector>
#include <string>
#include "Map.hpp"
#include "Input.hpp"
#include "Player.hpp"

class Game{
    public:
        Game();
        ~Game();
        void Start();
    private:
        Map* m_pCurrentMap;
        Player m_Player;
        Input m_Input;
};
