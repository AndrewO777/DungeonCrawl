#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Map.hpp"
#include "Player.hpp"
#include "Input.hpp"

void ToUpper(std::string& input);
int main()
{
	srand(static_cast<unsigned int>(time(0)));
    typedef Room::e_Directions e_Directions;
	Map myMap;
	Map myMap2;
    //Input _InputInstance;
	myMap2.m_TopFloor = false;
	myMap2.CreatePuzzles();
	Player myPlayer;
	std::vector<Room::e_Directions> dirs;
	dirs.push_back(Room::e_Directions::NONE);
	myMap.RandGen(dirs, Room::e_Directions::NONE, 0);
	myMap2.RandGen(dirs, Room::e_Directions::NONE, 0);
	myPlayer.Move(myMap.GetHead());
	std::string input;
	bool cmdRdy = false;
	std::cout << "If you dont know the commands type 'help'." << std::endl;
	while (input != "CLOSE" && myPlayer.m_Health > 0 && myPlayer.m_Sanity > 0)
	{
		if (!cmdRdy && input != "CLOSE")
		{
			std::getline(std::cin, input);
            Input::CommandPredict(input);
		}
		else
		{
			cmdRdy = false;
		}
		if (input == "NORTH")
		{
			if ((myPlayer.GetCur())->GetDirection(Room::e_Directions::NORTH) != 0)
			{
				myPlayer.Move(e_Directions::NORTH);
			}
			else
			{
				std::cout << "Cant go that way!" << std::endl;
			}
		}
		else if (input == "EAST")
		{
			if ((myPlayer.GetCur())->GetDirection(Room::e_Directions::EAST) != 0)
			{
				myPlayer.Move(e_Directions::EAST);
			}
			else
			{
				std::cout << "Cant go that way!" << std::endl;
			}
		}
		else if (input == "SOUTH")
		{
			if ((myPlayer.GetCur())->GetDirection(Room::e_Directions::SOUTH) != 0)
			{
				myPlayer.Move(e_Directions::SOUTH);
			}
			else
			{
				std::cout << "Cant go that way!" << std::endl;
			}
		}
		else if (input == "WEST")
		{
			if ((myPlayer.GetCur())->GetDirection(Room::e_Directions::WEST) != 0)
			{
				myPlayer.Move(e_Directions::WEST);
			}
			else
			{
				std::cout << "Cant go that way!" << std::endl;
			}
		}
		else if (input == "LOOK")
		{
			std::cout << myPlayer.Look() << std::endl;
		}
		else if (input.substr(0, 4) == "TAKE")
		{
			if (input.length() > 5)
			{
				myPlayer.Take(input.substr(5));
			}
			else
			{
				std::cout << "Take what?" << std::endl;
			}
		}
		else if (input == "INVENTORY")
		{
			myPlayer.Inventory();
		}
		else if (input.substr(0, 4) == "DROP")
		{
			if (input.length() > 5)
			{
				myPlayer.Drop(input.substr(5));
			}
			else
			{
				std::cout << "Drop what?" << std::endl;
			}
		}
		else if (input.substr(0, 5) == "CHECK")
		{
			if (input.length() > 6)
			{
				input = myPlayer.Check(input.substr(6));
				if (input.substr(0, 4) != "TAKE" && input != "")
				{
					cmdRdy = true;
				}
			}
			else
			{
				std::cout << "Check what?" << std::endl;
			}
		}
		else if (input.substr(0, 3) == "USE")
		{
			if (input.length() > 4)
			{
				myPlayer.Use(input.substr(4));
			}
			else
			{
				std::cout << "Use what?" << std::endl;
			}
		}
		else if (input == "DOWN")
		{
			myPlayer.Down(myMap2);
		}
		else if (input == "UP")
		{
			myPlayer.Up(myMap);
		}
		else if (input == "HEALTH")
		{
			myPlayer.Health();
		}
		else if (input.substr(0, 6) == "ATTACK")
		{
			if (input.length() > 7)
			{
				bool found;
				for (std::vector<Item>::iterator iter = myPlayer.m_Inv.begin(); iter != myPlayer.m_Inv.end(); ++iter)
				{
                    found = true;
                    if(Input::CompareStrings(iter->GetName(), input.substr(7)))
					{
						if ((*iter).GetDamage() == 0)
						{
							std::cout << "That won't do anything!" << std::endl;
						}
						else
						{
							myPlayer.Attack(*iter);
						}
						found = true;
						break;
					}
                    else {
                        found = false;
                    }
				}
				if (!found)
				{
					std::cout << "You don't have that to attack with." << std::endl;
				}
			}
			else
			{
				std::cout << "Attack with what?" << std::endl;
			}
		}
		else if (input == "GODMODE123")
		{
			myPlayer.m_Health += 10000;
			myPlayer.m_Sanity += 10000;
		}
		else if (input == "DEBUGMENU123")
		{
			myPlayer.DebugMenu();
		}
		else if (input == "HELP")
		{
			myPlayer.Help();
		}
		else if (input == "EXIT")
		{
			myPlayer.Exit();
		}
		else if (input != "CLOSE")
		{
			std::cout << "Sorry I don't understand." << std::endl;
		}
	}
	if (myPlayer.m_Health <= 0 || myPlayer.m_Sanity <= 0)
	{
		std::cout << "Game Over, press any key to continue.\n" << std::endl;
		std::getline(std::cin, input);
	}
	return 0;
}

void ToUpper(std::string& input)
{
	for (std::string::iterator iter = input.begin(); iter != input.end(); ++iter)
	{
		*iter = toupper(*iter);
	}
}
