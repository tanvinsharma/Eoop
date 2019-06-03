/* ==========Basketball_man_pla_rel===========
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
	BasketballTeams teamA("Los Angeles Lakers", 55);
	BasketballTeams teamB("Golden State Warriors", 435);
	BasketballTeams teamC("Toronto Raptors", 376);
	
	/*Assign a manager to a team with arguments
	name, age, sex and ID repsectively*/
	teamA.addManager("Tanvin", 52, 'm', 65);
	teamA.addManager("Arkin", 22, 'm', 66);
	teamB.addManager("Kobe", 43, 'f', 62);
	teamC.addManager("Jordan", 14, 'm', 45);

	teamA.showManagers();
	teamB.showManagers();
	teamC.showManagers();
	
	/*Add a player to a team with arguments
	name, age, sex and ID respectively */
	teamA.addPlayer("Lebron", 21, 'm', 81);
	teamA.addPlayer("Ingram", 26, 'f', 82);
	teamA.addPlayer("Lonzo", 12, 'm', 83);
	teamA.addPlayer("Hart", 64, 'f', 84);
	teamA.addPlayer("Lance", 23, 'm', 85);
	teamA.addPlayer("Kuzma", 29, 'm', 86);
	teamA.addPlayer("McGee", 31, 'f', 87);
	// teamA.deletePlayer(84, 66);
	
	teamB.addPlayer("Curry", 53, 'f', 12);
	teamB.addPlayer("Durant", 27, 'f', 13);
	teamB.addPlayer("Draymond", 19, 'f', 14);
	teamB.addPlayer("Klay", 15, 'f', 15);
	teamB.switchTeam(13, 435);
	//teamB.deletePlayer(12, 66);

	teamC.addPlayer("Kawhi", 32, 'f', 32);
	teamC.addPlayer("Damian", 25, 'm', 34);
	teamC.addPlayer("Embid", 16, 'm', 33);
	teamC.addPlayer("Simmons", 28, 'm', 51);
	teamC.addPlayer("DeAndre", 21, 'm', 54);
	teamC.addPlayer("Nash", 10, 'm', 24);
	teamC.addPlayer("Shaq", 19, 'f', 19);

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
