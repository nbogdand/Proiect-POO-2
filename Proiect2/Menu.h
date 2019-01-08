#pragma once
#include "PersonRepository.h"
#include "RoomRepository.h"
#include "ActivityRepository.h"
#include "DisciplineRepository.h"

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
	Room* findRoom(std::string,void (*function)());

	void listAllActivities();
	void addActivity();
	void editActivity();
	void deleteActivity();

	void listAllDisciplines();
	void addDiscipline();
	void editDiscipline();
	void deleteDiscipline();

private:

	PersonRepository* mPersonRepository;
	RoomRepository* mRoomRepository;
	ActivityRepository* mActivityRepository;
	DisciplineRepository* mDisciplineRepository;

};
