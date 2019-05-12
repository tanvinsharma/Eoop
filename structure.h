#ifndef STRUCTURE_H
#define STRUCTURE_H
#pragma once
#include "backbone.h"

//SoccerTeam group class
class SoccerTeams : public groups {
	std::string teamName;
	std::vector<SoccerTeams> teams;
	int teamId;
	friend class Players;
public:
	Players player;
	//menu driven manager addition
	void addManager();
	//overloaded direct call
	void addManager(std::string, int, char, int);
	//accessor function got returning team name
	std::string nameTeam(int);
	//interactive player removal
	void deletePlayer(int);
	//overloaded direct call removal
	void deletePlayer(int, int);
	//show all details of the team
	void showTeam();
	//menu driven player addition
	void addPlayer();
	//oveloaded direct call 
	void addPlayer(std::string, int, char, int);
	//find manager details by ID
	int findManager(int);
	//switch a player's team
	void switchTeam(int, int);
	//print all players in a team
	void showPlayers();
	//print all managers in a team
	void showManagers();
	//export all team details to a file
	void exportToFile(const char *);
	//default constructor
	SoccerTeams() {};
	//parameterized constructor
	SoccerTeams(std::string, int);
	~SoccerTeams() {};
};

//FanClub group class
class FanClubs : public groups{
	std::string clubName; 
	int clubId;
	std::vector<FanClubs> fanclubs;
public:
	Fans fan;
	//accessor function for clubId
	int clubIdProvider();
	//interactive add fans to a fanclub
	void addFans();
	//overloaded direct call to add fans
	void addFans(std::string, int, char);
	//show all fans in a fanclub
	void showFans();
	//default constructor
	FanClubs() {};
	//overloaded parameterized constructor
	FanClubs(std::string, int);
	~FanClubs() {};
};

#endif
