/* ==========Football_man_pla_rel===========
This file shows how managers and players 
work together in a team, it also uses fileIO
to export all details of the teams in files
mentioned in line 60, 61 and 62 respectively*/

#include <iostream>
#include "structure.h"
#include "backbone.h"
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

	//Create teams
	/* create a team with arguments
	team name and team ID respectively*/
	SoccerTeams teamA("Manchester", 55);
	SoccerTeams teamB("Legia", 435);
	SoccerTeams teamC("Ritwick's Team", 376);
	
	/*Assign a manager to a team with arguments
	name, age, sex and ID repsectively*/
	teamA.addManager("MrBalkans", 52, 'm', 65);
	teamA.addManager("JamesBond", 22, 'm', 66);
	teamB.addManager("VGACable", 43, 'f', 62);
	teamC.addManager("Pencil", 14, 'm', 45);

	teamA.showManagers();
	teamB.showManagers();
	teamC.showManagers();
	
	/*Add a player to a team with arguments
	name, age, sex and ID respectively */
	teamA.addPlayer("Rahul", 21, 'm', 81);
	teamA.addPlayer("Pinky", 26, 'f', 82);
	teamA.addPlayer("Venkat", 12, 'm', 83);
	teamA.addPlayer("Lindsay", 64, 'f', 84);
	teamA.addPlayer("Frank", 23, 'm', 85);
	teamA.addPlayer("Jimmy", 29, 'm', 86);
	teamA.addPlayer("Maggie", 31, 'f', 87);
	//teamA.deletePlayer(84, 66);
	
	teamB.addPlayer("Amanda", 53, 'f', 12);
	teamB.addPlayer("Lula", 27, 'f', 13);
	teamB.addPlayer("Vilma", 19, 'f', 14);
	teamB.addPlayer("Jessica", 15, 'f', 15);
	teamB.switchTeam(13, 435);
	//teamB.deletePlayer(12, 66);

	teamC.addPlayer("Kerstin", 32, 'f', 32);
	teamC.addPlayer("Akash", 25, 'm', 34);
	teamC.addPlayer("Ashutosh", 16, 'm', 33);
	teamC.addPlayer("Diari", 28, 'm', 51);
	teamC.addPlayer("Deepanshu", 21, 'm', 54);
	teamC.addPlayer("Beats", 10, 'm', 24);
	teamC.addPlayer("Melnida", 19, 'f', 19);

	teamA.deletePlayer(84, 66);
	teamB.deletePlayer(12, 66);
	teamC.deletePlayer(33, 45);

	teamA.showTeam();
	teamA.showPlayers();

	teamA.exportToFile("teamA.txt");
	teamB.exportToFile("teamB.txt");
	teamC.exportToFile("teamC.txt");

	return 0;
}
