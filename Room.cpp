#include "Room.hpp"

Room::Room(std::string name):
	m_RoomName(name)
{}

Room* Room::GetDirection(e_Directions dir)
{
	if (dir == e_Directions::NORTH)
	{
		return m_pNorth;
	}
	else if (dir == e_Directions::EAST)
	{
		return m_pEast;
	}
	else if (dir == e_Directions::SOUTH)
	{
		return m_pSouth;
	}
	else if (dir == e_Directions::WEST)
	{
		return m_pWest;
	}
	return 0;
}

void Room::SetDirection(e_Directions dir, Room* pNewRoom)
{
	if (dir == e_Directions::NORTH)
	{
		m_pNorth = pNewRoom;
	}
	else if (dir == e_Directions::EAST)
	{
		m_pEast = pNewRoom;
	}
	else if (dir == e_Directions::SOUTH)
	{
		m_pSouth = pNewRoom;
	}
	else if (dir == e_Directions::WEST)
	{
		m_pWest = pNewRoom;
	}
}

std::string Room::GetName() const
{
	return m_RoomName;
}

std::string Room::GetDesc()
{
	return m_RoomDesc;
}
