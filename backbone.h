#ifndef BACKBONE_H
#define BACKBONE_H
#pragma once
#include <string>
#include <vector>
#include <regex>
#include <list> 

using namespace std;

//Groups of people one of the base classes
class groups {
	int num_of_people;
	float avg_age;
	friend class SoccerTeams;
	friend class FanClubs;
 public:
	groups(int numb = 0): num_of_people(numb) {};
	~groups(){};
};

//People base class
class people {
	std::string name;
	char sex;
	int age;
	bool under_auth;
	int auth_level;
	friend class SoccerTeams;
	friend class Players;
	friend class Fans;
	friend class FanClubs;
	friend class ManagingDirectors;
 public:
	//virtual string getclass() { return char2str(typeid(*(this)).name()); }
	people(){};
	~people(){};	
	//virtual int get_age(){ return this->age; }; 
};

//players class people
class Players : public people {
	int playerId;
	int avgAge;
	int team;
	friend class SoccerTeams;
 public:
	//show properties of one player 
	void showPlayas(int);
	//calculate the age average 
	float ageCalc();
	//default constructor
	Players(){};
	//parameterized oveloaded constructor
	Players(std::string, int, char, int);
	~Players(){};
};

//Class Managing Directors people 
class ManagingDirectors : public people {
	int directorId;
	friend class SoccerTeams;
	int team;
 public:
 	//parameterized constructor
	ManagingDirectors(std::string, int, char, int);
	//Default constructor
	ManagingDirectors(){};
	~ManagingDirectors(){};
};


//Fans people class
class Fans : public people {
	int club;
	friend class FanClubs;
 public:
	//acessor functions for
	//returning sex
 	char whatSex();
	//returning age
	int whatAge();
	//returning club name
 	int clubProvider();
	//print properties of one fan
	void showFanas(int);
	//parameterized constructor 
	Fans(std::string, int, char);
	Fans(){};
	~Fans(){};
};

extern std::vector<Players> players;
extern std::list<ManagingDirectors> directors;
extern std::vector<Fans> fans;

#endif
