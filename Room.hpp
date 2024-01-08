#pragma once
#include "Enemy.hpp"
#include "Item.hpp"
#include "Interact.hpp"
#include "Puzzle.hpp"
#include <string>
#include <vector>

class Room
{
public:
	Room(std::string name);
    enum class e_Directions{
        NONE = 0,NORTH,EAST,SOUTH,WEST
    };
    Room* GetDirection(e_Directions dir);
	void SetDirection(e_Directions dir, Room* pNewRoom);
	std::string GetName() const;
	std::string GetDesc();
	std::string m_RoomDesc;
	std::vector<Item> m_Inv;
	std::vector<Interact> m_Interacts;
	std::vector<Puzzle> m_Puzzles;
	std::vector<Enemy> m_Enemies;
private:
	std::string m_RoomName;
	Room* m_pNorth = 0;
	Room* m_pEast = 0;
	Room* m_pSouth = 0;
	Room* m_pWest = 0;
};
