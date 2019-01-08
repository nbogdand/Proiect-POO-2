#include "pch.h"
#include "Menu.h"
#include <string>
#include <stdio.h>

Menu::Menu()
{
	mPersonRepository = new PersonRepository();
	mRoomRepository = new RoomRepository();
	mActivityRepository = new ActivityRepository();
	mDisciplineRepository = new DisciplineRepository();
}

void Menu::start() {
	std::cout << "\n\n Salut! \n\n";
	std::cout << "Alegeti, ceea ce doriti: \n";
	std::cout << "0) Iesire \n";

	std::cout << "\n";

	std::cout << "1) Afiseaza toate persoanele \n";
	std::cout << "2) Adauga o persoana \n";
	std::cout << "3) Editeaza o persoana \n";
	std::cout << "4) Sterge o persoana \n";

	std::cout << "\n";
	
	std::cout << "5) Afiseaza toate salile \n";
	std::cout << "6) Adauga o sala \n";
	std::cout << "7) Editeaza o sala \n";
	std::cout << "8) Sterge o sala \n";

	std::cout << "\n";

	std::cout << "9) Afiseaza toate activitatile \n";
	std::cout << "10) Adauga o activitate \n";
	std::cout << "11) Editeaza o activitate \n";
	std::cout << "12) Sterge o activitate \n";

	std::cout << "\n";

	std::cout << "13) Afiseaza toate disciplinele \n";
	std::cout << "14) Adauga o disciplina \n";
	std::cout << "15) Editeaza o disciplina \n";
	std::cout << "16) Sterge o disciplina \n";

	std::cout << "Your choice : ";
	
	int input;

	std::cin >> input;
	std::cout << "\n";

	switch (input) {
	case 0 :
		break;
	case 1:
		listAllPersons();
		start();
		break;
	case 2:
		addPerson();
		start();
		break;
	case 3:
		editPerson();
		start();
		break;
	case 4:
		deletePerson();
		start();
		break;
	case 5:
		listAllRooms();
		start();
		break;
	case 6:
		addRoom();
		start();
		break;
	case 7:
		editRoom();
		start();
		break;
	case 8:
		deleteRoom();
		start();
		break;
	case 9:
		listAllActivities();
		start();
		break;
	case 10:
		addActivity();
		start();
		break;
	case 11:
		editActivity();
		start();
		break;
	case 12:
		deleteActivity();
		start();
		break;
	case 13:
		listAllDisciplines();
		start();
		break;
	case 14:
		addDiscipline();
		start();
		break;
	case 15:
		editDiscipline();
		start();
		break;
	case 16:
		deleteDiscipline();
		start();
		break;

	}

}

void Menu::listAllPersons() {
	
	mPersonRepository->print();

}


void Menu::addPerson() {

	std::string firstName, lastName, CNP, email, choice;

	std::cout << "Introduceti prenumele : ";
	std::cin >> firstName;
	std::cout << "Introduceti numele : ";
	std::cin >> lastName;
	std::cout << "Introduceti CNP : ";
	std::cin >> CNP;

	do{
		std::cout << "Introduceti email? [y/n] :";
		std::cin >> choice;
		
	} while ( choice != "y" && choice != "n");

	if (choice == "y") {
		std::cout << "Introduceti adresa de email : ";
		std::cin >> email;
	}

	mPersonRepository->add(new Person(firstName, lastName, CNP, email));

}

void Menu::editPerson() {
	std::string firstName, lastName;
	std::cout << "Introduceti prenumele persoanei: ";
	std::cin >> firstName;
	std::cout << "Introduceti numele persoanei: ";
	std::cin >> lastName;

	std::vector<Person*> persons = mPersonRepository->getAllEntities();
	Person* gasit = NULL;

	// Go through whole vector of Persons and 
	// find the person with matching full name
	for (int i = 0; i < persons.size(); i++) {

		//if found 
		if (persons[i]->getLastName() == lastName && persons[i]->getFirstName() == firstName)
			gasit = persons[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Persoana nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			editPerson();
		}

	}
	else {

		std::string input;
		int choice;

		std::cout << "Alegeti ce doriti sa modificati : \n";
		std::cout << "0) Prenumele \n";
		std::cout << "1) Numele \n";
		std::cout << "2) CNP \n";
		std::cout << "3) Email \n";
		std::cout << "4) Adaugare rol \n";

		std::cout << "Your choice : ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << " Introduceti prenumele :";
			std::cin >> input;
			gasit->setFirstName(input);
			break;
		case 1:
			std::cout << " Introduceti numele :";
			std::cin >> input;
			gasit->setLastName(input);
			break;
		case 2:
			std::cout << " Introduceti CNP :";
			std::cin >> input;
			gasit->setCNP(input);
			break;
		case 3:
			std::cout << " Introduceti Email :";
			std::cin >> input;
			gasit->setEmail(input);
			break;
		case 4:
			std::cout << " Adaugati rol : 1)Student sau 2)Profesor, introduce-ti nr: ";
			int ch;
			std::cin >> ch;
			if (ch == 1)
				gasit->addRole(Role::STUDENT_ROLE);
			if (ch == 2)
				gasit->addRole(Role::TEACHER_ROLE);
			break;

		}
	
		
	}
	
}

void Menu::deletePerson() {
	std::string firstName, lastName;
	std::cout << "Introduceti prenumele persoanei: ";
	std::cin >> firstName;
	std::cout << "Introduceti numele persoanei: ";
	std::cin >> lastName;

	std::vector<Person*> persons = mPersonRepository->getAllEntities();
	Person* gasit = NULL;

	// Go through whole vector of Persons and 
	// find the person with matching full name
	for (int i = 0; i < persons.size(); i++) {

		//if found 
		if (persons[i]->getLastName() == lastName && persons[i]->getFirstName() == firstName)
			gasit = persons[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Persoana nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			deletePerson();
		}

	}
	else {
		std::string input;
		do {
			std::cout << " Sunteti sigur ca doriti sa stergeti persoana " << gasit->getFirstName() << " " << gasit->getLastName() << "?[y/n] : ";
			std::cin >> input;
		} while (input != "y" && input != "n");
		
		if (input == "y") {
			delete gasit;
		}
		
	}

}

void Menu::listAllRooms() {
	mRoomRepository->print();
}

void Menu::addRoom() {

	std::string input;
	std::cout << "Introduceti numele salii : ";
	std::cin >> input;

	mRoomRepository->add(new Room(input));
}

void Menu::editRoom() {

	std::string input;
	std::cout << "Introduceti numele salii :";
	std::cin >> input;

	std::vector<Room*> rooms = mRoomRepository->getAllEntities();
	Room* gasit = NULL;

	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getName() == input)
			gasit = rooms[i];
	}

	if (gasit == NULL) {

		do {
			std::cout << "Sala nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			editRoom();
		}
	}else {
		
		std::string choice;

		do {
			std::cout << "Doriti sa modificati numele salii ?[y/n] : ";
			std::cin >> choice;
		} while (choice != "y" && choice != "n");
		
		if (choice == "y") {
			std::cout << "Introduceti numele : ";
			std::cin >> choice;
			gasit->setName(choice);
		}

	}


}

void Menu::deleteRoom() {

	std::string input;
	std::cout << "Introduceti numele salii :";
	std::cin >> input;

	std::vector<Room*> rooms = mRoomRepository->getAllEntities();
	Room* gasit = NULL;

	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getName() == input)
			gasit = rooms[i];
	}

	if (gasit == NULL) {

		do {
			std::cout << "Sala nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			deleteRoom();
		}
	}
	else {
		std::string input;
		do {
			std::cout << " Sunteti sigur ca doriti sa stergeti sala " << gasit->getName() << "?[y/n] : ";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			delete gasit;
		}

	}


}

Room* Menu::findRoom(std::string input,void (*function)()) {

	std::vector<Room*> rooms = mRoomRepository->getAllEntities();
	Room* gasit = NULL;

	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getName() == input)
			gasit = rooms[i];
	}

	if (gasit == NULL) {

		do {
			std::cout << "Sala nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			(*function)();
		}

		if (input == "n") {
			return NULL;
		}

	}
	else {
		return gasit;
	}


}

void Menu::listAllActivities() {
	mActivityRepository->print();
}

void Menu::addActivity() {

	// For a new activity to be registered it needs:
	// 1-- a room
	// 2-- an owner (person)
	// 3-- a descriptiom (name)
	Room* theRoom;
	Person* thePerson;
	std::string theDescription;


	std::string description,input;
	std::cout << "Introduceti numele activitaty : ";
	std::cin >> description;
	std::cout << "Introduceti numele salii : ";
	std::cin >> input;

	theDescription = description;
	std::vector<Room*> rooms = mRoomRepository->getAllEntities();
	Room* gasit = NULL;

	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getName() == input)
			gasit = rooms[i];
	}

	if (gasit == NULL) {

		do {
			std::cout << "Sala nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			addActivity();
		}
	}
	else {

		theRoom = gasit;

		std::string prenume, nume;

		std::cout << "Introduceti prenumele proprietarului : ";
		std::cin >> prenume;
		std::cout << "Introduceti numele proprietarului : ";
		std::cin >> nume;

		std::vector<Person*> persons = mPersonRepository->getAllEntities();
		Person* gasitP = NULL;

		// Go through whole vector of Persons and 
		// find the person with matching full name
		for (int i = 0; i < persons.size(); i++) {

			//if found 
			if (persons[i]->getLastName() == nume && persons[i]->getFirstName() == prenume)
				gasitP = persons[i];
		}

		if (gasitP == NULL) {
			std::string input;
			do {
				std::cout << "Persoana nu a fost gasita. Mai incercati inca o data? [y/n] :";
				std::cin >> input;
			} while (input != "y" && input != "n");

			if (input == "y") {
				addActivity();
			}

		}
		else {
			thePerson = gasitP;
			mActivityRepository->add(new Activity(theRoom,thePerson,theDescription));

		}

	}


}

void Menu::editActivity() {

	std::string desc;

	std::cout << "Introduceti numele activitatii : ";
	std::cin >> desc;

	std::vector<Activity*> activities = mActivityRepository->getAllEntities();
	Activity* gasit = NULL;

	for (int i = 0; i < activities.size(); i++) {
		if (activities[i]->getDescription() == desc)
			gasit = activities[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Activitatea nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			editActivity();
		}

	}
	else {
		
		int ch;

		std::cout << "Alegeti ce doriti sa modificati : \n";
		std::cout << "1) Sala \n";
		std::cout << "2) Proprietarul \n ";
		std::cout << "3) Numele \n";
		std::cout << "Alegerea dvs: ";
		std::cin >> ch;

		switch (ch)
		{
		case 1: {
			std::string input;
			std::cout << "Introduceti numele noii sali :";
			std::cin >> input;

			std::vector<Room*> rooms = mRoomRepository->getAllEntities();
			Room* gasitR = NULL;

			for (int i = 0; i < rooms.size(); i++) {
				if (rooms[i]->getName() == input)
					gasitR = rooms[i];
			}

			if (gasitR == NULL) {

				do {
					std::cout << "Sala nu a fost gasita. Mai incercati inca o data? [y/n] :";
					std::cin >> input;
				} while (input != "y" && input != "n");

				if (input == "y") {
					editActivity();
				}
			}
			else {
				gasit->setLocation(gasitR);

			}
			break; 
		}
		case 2: {

			// Search if the new person actually exists 
			// then change the old activity's owner to the new person

			std::string firstName, lastName;
			std::cout << "Introduceti prenumele noii persoanei: ";
			std::cin >> firstName;
			std::cout << "Introduceti numele noii persoanei: ";
			std::cin >> lastName;

			std::vector<Person*> persons = mPersonRepository->getAllEntities();
			Person* gasitPers = NULL;

			// Go through whole vector of Persons and 
			// find the person with matching full name
			for (int i = 0; i < persons.size(); i++) {

				//if found 
				if (persons[i]->getLastName() == lastName && persons[i]->getFirstName() == firstName)
					gasitPers = persons[i];
			}

			if (gasitPers == NULL) {
				std::string input;
				do {
					std::cout << "Persoana nu a fost gasita. Mai incercati inca o data? [y/n] :";
					std::cin >> input;
				} while (input != "y" && input != "n");

				if (input == "y") {
					editActivity();
				}

			}
			else {

				gasit->setOwner(gasitPers);

			}
			break;
		}
		case 3: {
			std::string nume;
			std::cout << "Introduceti numele nou : ";
			std::cin >> nume;
			gasit->setDescription(nume);
			break;
		}
		}

	}

}

void Menu::deleteActivity() {
	std::string desc;

	std::cout << "Introduceti numele activitatii : ";
	std::cin >> desc;

	std::vector<Activity*> activities = mActivityRepository->getAllEntities();
	Activity* gasit = NULL;

	for (int i = 0; i < activities.size(); i++) {
		if (activities[i]->getDescription() == desc)
			gasit = activities[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Activitatea nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			deleteActivity();
		}

	}
	else {
		std::string input;
		do {
			std::cout << " Sunteti sigur ca doriti sa stergeti activitatea " << gasit->getDescription() << "?[y/n] : ";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			delete gasit;
		}

	}
}

void Menu::listAllDisciplines() {
	
	mDisciplineRepository->print();

}

void Menu::addDiscipline() {

	std::string discname,actname;

	std::cout << "Introduceti numele disciplinei : ";
	std::cin >> discname;

	std::cout << "Introduceti numele activitatii : ";
	std::cin >> actname;

	std::vector<Activity*> activities = mActivityRepository->getAllEntities();
	Activity* gasit = NULL;

	for (int i = 0; i < activities.size(); i++) {
		if (activities[i]->getDescription() == actname)
			gasit = activities[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Activitatea nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			addDiscipline();
		}

	}
	else {
		Discipline * newDiscipline = new Discipline(discname);
		newDiscipline->addActivity(gasit);
		mDisciplineRepository->add(newDiscipline);
	}



}

void Menu::editDiscipline() {

	std::string discname;
	
	std::cout << "Introduceti numele disciplinei : ";
	std::cin >> discname;

	std::vector<Discipline*> disciplines = mDisciplineRepository->getAllEntities();
	Discipline* gasit = NULL;

	for (int i = 0; i < disciplines.size(); i++) {
		if (disciplines[i]->getName() == discname)
			gasit = disciplines[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Disciplina nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			editDiscipline();
		}

	}
	else {

		int choice;

		std::cout << " Alegeti ce doriti sa modificati : \n";
		std::cout << " 1)Numele disciplinei \n";
		std::cout << " 2)Adauga activitate \n";
		std::cout << " 3)Elimina activitate \n";
		
		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			std::string numeNou;
			std::cout << "Introduceti noul nume : ";
			std::cin >> numeNou;
			break; 
		}
		case 2: {

			std::string desc;

			std::cout << "Introduceti numele activitatii : ";
			std::cin >> desc;

			std::vector<Activity*> activities = mActivityRepository->getAllEntities();
			Activity* gasitAct = NULL;

			for (int i = 0; i < activities.size(); i++) {
				if (activities[i]->getDescription() == desc)
					gasitAct = activities[i];
			}

			if (gasitAct == NULL) {
				std::string input;
				do {
					std::cout << "Activitatea nu a fost gasita. Mai incercati inca o data? [y/n] :";
					std::cin >> input;
				} while (input != "y" && input != "n");

				if (input == "y") {
					editDiscipline();
				}

			}
			else {

				gasit->addActivity(gasitAct);

			}

			break;
		}
		case 3: {
			std::string actRemoveName;
			std::cout << "Introduceti numele activitatii pentru eliminare ";
			std::cin >> actRemoveName;

			std::vector<Activity*> discActivities = gasit->getAllActivities();
			Activity *gasitDiscAct = NULL;

			for (int i = 0; i < discActivities.size(); i++) {
				if (discActivities[i]->getDescription() == actRemoveName)
					gasitDiscAct = discActivities[i];
			}

			if (gasitDiscAct == NULL) {
				std::string input;
				do {
					std::cout << "Activitatea nu a fost gasita. Mai incercati inca o data? [y/n] :";
					std::cin >> input;
				} while (input != "y" && input != "n");

				if (input == "y") {
					editDiscipline();
				}

			}
			else
			{
				gasit->removeActivity(actRemoveName);
			}

			break;
		}
		}


	}

}


void Menu::deleteDiscipline() {
	std::string discname;

	std::cout << "Introduceti numele disciplinei : ";
	std::cin >> discname;

	std::vector<Discipline*> disciplines = mDisciplineRepository->getAllEntities();
	Discipline* gasit = NULL;

	for (int i = 0; i < disciplines.size(); i++) {
		if (disciplines[i]->getName() == discname)
			gasit = disciplines[i];
	}

	if (gasit == NULL) {
		std::string input;
		do {
			std::cout << "Disciplina nu a fost gasita. Mai incercati inca o data? [y/n] :";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			deleteDiscipline();
		}

	}
	else {
		std::string input;
		do {
			std::cout << " Sunteti sigur ca doriti sa stergeti disciplina " << gasit->getName() << "?[y/n] : ";
			std::cin >> input;
		} while (input != "y" && input != "n");

		if (input == "y") {
			delete gasit;
		}

	}


}








