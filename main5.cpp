/*======INTERACTIVE_NO_GRAPH======
This main file shows all fanclubs
and teams classes functions with 
interactive menus, GNU plot is not 
required, graph data would be present
in "data.dat" */

#include <iostream>
#include "structure.h"
#include "backbone.h"
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

	//Interactive 
	FanClubs clubA("First Club", 55);
	FanClubs clubB("Second Club", 51);
	FanClubs clubC("Third Club", 23);

	SoccerTeams teamA("Manchester", 55);
	SoccerTeams teamB("Manchester", 51);
	
	clubA.addFans();
	clubB.addFans();
	clubC.addFans();
	
	teamA.addPlayer();
	teamB.addPlayer();

	teamA.deletePlayer(44);

	graphCompare(clubB, clubC);

	teamA.exportToFile("teamA.txt");
	teamB.exportToFile("teamB.txt");
	
	return 0;
}
