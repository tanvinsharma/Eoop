#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include "structure.h"

using namespace std; 

std::vector<Players> players;
std::list<ManagingDirectors> directors;
std::vector<Fans> fans;

void contains_non_alpha(string name) {
	if(!regex_match (name, std::regex("^[A-Za-z]+$"))) 
		throw std::invalid_argument{"Name can only contain letters"};
} 

void m_or_f(char x) {
	if(!(x == 'm' || x == 'f' || x == 'M' || x == 'F')) 
		throw std::invalid_argument{"sex must only be m/M or f/F"};
}

void age_test(int age) {
	if(age > 100) 
		throw std::out_of_range{"Age must be less than 100"};
}

//Fan Club member functions 
FanClubs::FanClubs(string name, int id) {
	clubName = name;
	clubId = id;
	fanclubs.push_back(*this);
};

int FanClubs::clubIdProvider() { return clubId; }

void FanClubs::showFans() {
	cout << "Players in " << fanclubs.begin() -> clubName << endl;
	fan.showFanas(clubId);
}

//parameterized 
void FanClubs::addFans(string name, int age, char sex) {
	//exceptions_begin
	contains_non_alpha(name);
	m_or_f(sex);
	age_test(age);
	//exceptions_end

	Fans fan(name, age, sex);
	fan.club = clubId;
	fans.push_back(fan);
}
//Soccer Teams member functions 
string SoccerTeams::nameTeam(int id) {
	return teams.begin() -> teamName;
}

void SoccerTeams::showPlayers() {
	cout << "Players in " << teams.begin() -> teamName << endl;
	player.showPlayas(this->teamId);
}

void SoccerTeams::switchTeam(int playerId, int teamId) {
	int flag = 1;
	std::vector<Players>::iterator i;
	for (i = players.begin(); i != players.end() ; ++i) {
		if(i -> playerId == playerId) {
			i -> team = teamId;
			cout << endl << i -> name << " successfully moved to " << nameTeam(teamId) << endl;
			teams.begin()->num_of_people--;
			flag = 0;
		}
	}
	if (flag != 0)
		cout << "Check player ID and team ID and try\n";
	else
		return;
}


void SoccerTeams::showManagers() {
	int counter = 1;
	list<ManagingDirectors>::iterator i;
	for (i = directors.begin(); i != directors.end(); i++) {
		if(i -> team == teams.begin() -> teamId) {
			cout << "========= Director " << counter << " =========" << endl;
			cout << "Works for team " << nameTeam(i -> directorId) << endl;
			cout << "Name: " << i -> name << endl;
			cout << "Sex : " << i -> sex << endl;
			cout << "Age : " << i -> age << endl;
			cout << "Id  : " << i -> directorId << endl;
			counter++;
		}
	}
}

void SoccerTeams::addPlayer(std::string name, int age, char sex, int id) {
	//exceptions_begin
	contains_non_alpha(name);
	m_or_f(sex);
	age_test(age);
	//exceptions_end

	contains_non_alpha(name);
	Players playernew(name, age, sex, id);
	playernew.team = teamId;
	players.push_back(playernew);
	teams.begin()->num_of_people++;
}


void SoccerTeams::deletePlayer(int id) {
	std::vector<Players>::iterator i;
	int dirId;
	for (i = players.begin(); i != players.end();) {
		if(i->playerId == id) {
			cout << "\nEnter director id for removing player: ";
			cin >> dirId;
			if(this->findManager(dirId) != 0 && this->findManager(dirId) == dirId) {
				cout << "Player " << (i) -> name << " has been removed by director " << this->findManager(dirId) << endl;
				i = players.erase(i);
				teams.begin()->num_of_people--;
			}
			else if(this->findManager(dirId) == 0) {
				cout << "Manager id incorrect or manager doesn't exist\n";
				cout << "Couldn't delete player with id " << i -> playerId << endl << endl;
				return;
			}
		}
		else
			i++;
	}
}
void SoccerTeams::deletePlayer(int id, int manId) {
	std::vector<Players>::iterator i;
	for (i = players.begin(); i != players.end();) {
		if(i->playerId == id) {
			if(this->findManager(manId) != 0 && this->findManager(manId) == manId) {
				cout << "Player " << (i) -> name << " has been removed by director " << this->findManager(manId) << endl << endl;
				i = players.erase(i);
				teams.begin()->num_of_people--;
			}
			else if(this->findManager(manId) == 0) {
				cout << "Manager id incorrect or manager doesn't exist\n";
				cout << "Couldn't delete player with id " << i -> playerId << endl << endl;
				return;
			}
		}
		else
			i++;
	}
}

void SoccerTeams::showTeam() {
	vector<SoccerTeams>::iterator i;
	for (i = teams.begin(); i != teams.end(); ++i) {
		cout << "\nTeam name: " << i -> teamName << endl;
		cout << "Team id: " << i -> teamId << endl;
		cout << "Number of players: " << i -> num_of_people << endl;
		cout << "Average age: " << i -> player.ageCalc()/teams.begin() -> num_of_people << endl;
	}
}

SoccerTeams::SoccerTeams(string tn, int id) {
	teamName = tn;
	teamId = id;
	teams.push_back(*this);
};

int SoccerTeams::findManager(int id) {
	std::list<ManagingDirectors>::iterator i;
	for (i = directors.begin(); i != directors.end(); ++i) {
		if(i -> directorId == id) 
			if(i -> team == teams.begin() -> teamId)
				return i -> directorId;
		}
		return 0;
	}

//overloaded add mgr function with args 
	void SoccerTeams::addManager(string name, int age, char sex, int id) {
		//exceptions_begin
		contains_non_alpha(name);
		m_or_f(sex);
		age_test(age);
		//exceptions_end
		
		ManagingDirectors mandir(name, age, sex, id);
		mandir.team = teamId;
		directors.push_front(mandir);
	}

	void SoccerTeams::exportToFile(const char *filename) {
		ofstream outfile;
		outfile.open(filename, ios::out);
	//send players vector and manager list to file
		std::vector<Players>::iterator i;
		std::list<ManagingDirectors>::iterator v;
		int counter = 1;
		outfile << "Team name         : " << teamName << "\nPlayers           : " << teams.begin() -> num_of_people << endl;
		outfile << "Average player age: " << teams.begin() -> player.ageCalc()/teams.begin() -> num_of_people << endl;
		outfile << "\n+==============Team Data==============+\n";
		for (i = players.begin(); i != players.end(); ++i) {
			if(i -> team == teams.begin() -> teamId) {
				outfile << "\n|" << " Player " << counter << endl;
				outfile << "|" << " Name: " << i -> name << endl;
				outfile << "|" << " Sex : " << i -> sex << endl;
				outfile << "|" << " Age : " << i -> age << endl;
				outfile << "|" << " Pid : " << i -> playerId << endl;
				counter++;
			}
		}
		outfile << "+=====================================+\n";
		counter = 0;
		outfile << "\n+============Directors data===========+\n";
		for (v = directors.begin(); v != directors.end(); ++v) {
			if(v -> team == teams.begin() -> teamId) {
				outfile << "\n|" << " Manager " << counter << endl;
				outfile << "|" << " Name: " << v -> name << endl;
				outfile << "|" << " Age : " << v -> age << endl;
				outfile << "|" << " Sex : " << v -> sex << endl; 
				outfile << "|" << " Id  : " << v -> directorId << endl; 
				counter++;
			}
		}
		outfile << "+=====================================+\n";
		outfile.close();
	}
