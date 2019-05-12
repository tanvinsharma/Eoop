#include <iostream>
#include "backbone.h"
#include "structure.h"

//Fan class member functions
Fans::Fans(string name, int age, char sex) {
	this -> name = name;
	this -> age = age;
	this -> sex = sex;
}

//accessor functions 
int Fans::clubProvider() { return club; }
char Fans::whatSex() { return sex; }
int Fans::whatAge() { return age; }

void Fans::showFanas(int clubid) {
	int counter = 1;
	vector<Fans>::iterator i;
	for (i = fans.begin(); i != fans.end(); ++i) {
		if(i -> club == clubid) {
			cout << "\nFan " << counter << endl;
			cout << "Name: " << i -> name << endl;
			cout << "Sex: " << i -> sex << endl;
			cout << "Age: " << i -> age << endl;
			counter++;
		}
	}
}

//Players class member functions
Players::Players(string name, int age, char sex, int id) {
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->playerId = id;
}


float Players::ageCalc() {
	int totalAge = 0;
	vector<Players>::iterator i;
	for (i = players.begin(); i != players.end(); ++i) {
		totalAge += i->age;
	}
	return totalAge;
}

void Players::showPlayas(int id) {
	int counter = 1;
	vector<Players>::iterator i;
	for (i = players.begin(); i != players.end(); ++i) {
		if(i -> team == id) {
			cout << "\n======== Player " << counter << " =========\n";
			cout << "Name: " << i -> name << endl;
			cout << "Sex: " << i -> sex << endl;
			cout << "Age: " << i -> age << endl;
			cout << "Player id: " << i -> playerId << endl;
			counter++;
		}
	}
}

//Member functions of Managing DIrectos
ManagingDirectors::ManagingDirectors(string name, int age, char sex, int id) {
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->directorId = id;
};
