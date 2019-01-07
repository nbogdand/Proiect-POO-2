#include "pch.h"
#include "Room.h"


Room::Room(std::string mName) : mName(mName)
{

}

std::string Room::getName() {
	return mName;
}

void Room::setName(std::string roomName) {
	mName = roomName;
}

std::ostream& operator << (std::ostream& out, Room r) {
	out << r.mName << " ";
	return out;
}
