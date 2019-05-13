#include <iostream>
#include <algorithm>
#include "interactive.h"

using namespace std;

void FanClubs::addFans() {
	int choice = 0;
	cout << "1. Add a bunch of fans\n2. Add custom fans\nEnter your Choice: ";
	cin >> choice;
	switch(choice) {
		case 1: {
			int requirement;
			cout << "How many fans do you need: ";
			cin >> requirement;
			static const string names[] = {
				"Margarita", "Amalia", "Sam", "Mertie", "Jamila", "Vilma", 
				"Mazie", "Margart", "Lindsay", "Kerstin", "Lula", "Corinna", "Jina",
				"Jimmy", "Melynda", "Demetrius", "Beverly", "Olevia", "Jessika", 
				"Karina", "Abdallah", "Max", "Prateek", "Aghaid"
			};
			for (int i = 0; i < requirement; ++i) {
				fan.name = names[rand() % 24];
				fan.age = (rand() % 80 + 1);
				fan.sex = ((rand() % 2) ? 'M' : 'F');
				fan.under_auth = false;
				fan.auth_level = 0;
				fan.club = clubId;
				fans.push_back(fan);
			}
			break;   
		} 			
		case 2: {
			int requirement;
			cout << "How many fans you want to add?\nnumber: ";
			cin >> requirement;
			for (int i = 0; i < requirement; ++i) {
				cout << "======Fan " << i + 1 << "=======\n";
				cout << "Enter name: ";
				cin >> fan.name;
				cout << "Enter age: ";
				cin >> fan.age;
				cout << "Enter sex: ";
				cin >> fan.sex;
				fan.under_auth = false;
				fan.auth_level = 0;
				fan.club = clubId;
				fans.push_back(fan);
			}	
			break;
		}
		default: 
		cout << "Incorrect choice\n";
		break;
	}
}

void BasketballTeams::addPlayer() {
	int newId;
	int number;
	int page;
	char psex;
	cout << "Number of players to be added: ";
	cin >> number;
	for (int i = 0; i < number; ++i) {
		cout << "\nPlayer " << i + 1;
		cout << "\nEnter player name: ";
		cin >> player.name;
		cout << "Enter sex(M/F): ";
		cin >> player.sex;
		cout << "Enter age: ";
		cin >> player.age;
		while(cin.fail()) {
			cout << "Age must be an integer, try again: ";
			cin.clear();
			cin.ignore(256);
			cin >> player.age;
		}
		cout << "Enter player id(0 for random id): ";
		cin >> newId;
		newId == 0 ? player.playerId = (rand() % 100 + 1) : player.playerId = newId;
		player.under_auth = true;
		player.auth_level = 0;
		player.team = teamId;
		players.push_back(player);
		teams.begin()->num_of_people++;
	}
}

//When no args passes ask user for args 
void BasketballTeams::addManager() {
	ManagingDirectors mandir;
	int number;
	char msex;
	cout << "How many managers you want to add: ";
	cin >> number;
	for (int i = 0; i < number; i++) { 
		cout << "Manager " << i + 1 << endl;
		cout << "Enter name of the director: ";
		cin >> mandir.name;
		cout << "Enter the age: ";
		cin >> mandir.age;
		cout << "Enter the sex(M/F): ";
		cin >> mandir.sex;
		cout << "Enter director id: ";
		cin >> mandir.directorId;
		mandir.auth_level = 3;
		mandir.under_auth = false;
		directors.push_front(mandir);
	}
}