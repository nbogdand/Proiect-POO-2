#include "pch.h"
#include "Menu.h"
#include <string>
#include <stdio.h>

Menu::Menu()
{
	mPersonRepository = new PersonRepository();
	mRoomRepository = new RoomRepository();
	mActivityRepository = new ActivityRepository();
}

void Menu::start() {
	std::cout << "\n\n Salut! \n\n";
	std::cout << "Alegeti, ceea ce doriti: \n";
	std::cout << "0) Iesire \n";
	std::cout << "1) Afiseaza toate persoanele \n";
	std::cout << "2) Adauga o persoana \n";
	std::cout << "3) Editeaza o persoana \n";
	std::cout << "4) Sterge o persoana \n";

	std::cout << "\n";
	
	std::cout << "5) Afiseaza toate salile \n";
	std::cout << "6) Adauga o sala \n";
	std::cout << "7) Editeaza o sala \n";
	std::cout << "8) Sterge o sala \n";

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
	}
	else {
		
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
			editRoom();
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

