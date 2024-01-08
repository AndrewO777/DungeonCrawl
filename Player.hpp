#pragma once
#include "Room.hpp"
#include "Item.hpp"
#include "Interact.hpp"
#include "Puzzle.hpp"
#include "Map.hpp"
#include <string>
#include <vector>

class Player
{
public:
	void Move(Room* pRoom);
	void Move(Room::e_Directions dir);
	Room* GetCur();
	std::string Check(std::string checkAt);
	std::string Look();
	void Take(std::string takeObj);
	void Take(std::string takeObj, Interact* interactObj);
	void Take(std::string takeObj, Puzzle* puzzleObj);
	void Inventory();
	void Use(std::string useObj);
	void Down(Map& pMap);
	void Up(Map& pMap);
	void Exit();
	void AttackedBy();
	void Attack(Item& wep);
	std::vector<Item> m_Inv;
	std::string ToUpper(const std::string& input);
	void Drop(std::string dropObj);
	int m_Health = 5;
	int m_Sanity = 7;
	int m_Negate = 0;
	void Health();
	void Help();
	void DebugMenu();
private:
	Room* m_pCur = 0;
	std::vector<Room*> m_Visited;
};
