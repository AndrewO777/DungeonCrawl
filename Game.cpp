#include <iostream>
#include "Game.hpp"

using std::cin, std::cout, std::string;

/*  m_pCurrentMap
 *  m_Player
 *  m_Input
 */

Game::Game()
{

}

Game::~Game()
{

}

void Game::Start()
{
    string input;
    cout << "welcome, enter command\n";
    cin >> input;
    m_Input.CommandPredict(input);
    cout << "input:" << input << '\n';
}
