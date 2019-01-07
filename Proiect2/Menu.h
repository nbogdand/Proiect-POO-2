#pragma once
#include "PersonRepository.h"
#include "RoomRepository.h"
#include "ActivityRepository.h"

class Menu {
public:

	Menu();
	void start();
	void listAllPersons();
	void addPerson();
	void editPerson();
	void deletePerson();

	void listAllRooms();
	void addRoom();
	void editRoom();
	void deleteRoom();


private:

	PersonRepository* mPersonRepository;
	RoomRepository* mRoomRepository;
	ActivityRepository* mActivityRepository;

};
