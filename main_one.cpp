/*
MAIN_ONE
A main file with all five main files in 
one menu driven program for convenience of the user.
*/

#include <iostream>
#include "structure.h"
#include "backbone.h"
#include "graph.h"

int main(int argc, char const *argv[])
{
	cout << "Testing!" <<endl;
	cout << "Enter your choice according to the menu: \n" ;
	cout << "1. Basketball game manager with graph \n ";
	cout << "2. Basketball game manager showing dependencies among managers and players and how they work in a team \n";
	cout << "3. Interactive version showing all fanclubs and team classes \n";
	cout << "4. Basketball game manager without graph \n";
	cout << "5. Interactive without graph \n";
	cout << "Enter a choice :\n";
	int choice;
	cin >> choice;
	while(choice<=0 || choice>=6){
		cout << "Enter a valid choice \n";
		cin >> choice;
	}

	if(choice == 1){
		//--------Fanclubs---------//
	/* create a fanclub with arguments
	club name and club ID respectively*/
	FanClubs clubA("First Fan Club", 55);
	/*Add a fan to club with arguments
	fan name, age and sex respectively*/
	clubA.addFans("Tony", 18, 'f');
	clubA.addFans("Steve", 19, 'm');
	clubA.addFans("Natasha", 43, 'f');
	clubA.addFans("Bruce", 25, 'm');
	clubA.addFans("Clint", 35, 'm');
	clubA.addFans("Thor", 11, 'f');
	//clubA.addFans("", 11, 'f');

	FanClubs clubB("Second Fan Club", 51);
	clubB.addFans("Peter", 22, 'f');
	clubB.addFans("Gamora", 31, 'f');
	clubB.addFans("Rocket", 12, 'm');
	clubB.addFans("Groot", 26, 'm');
	clubB.addFans("Drax", 62, 'f');

	FanClubs clubC("Third Fan Club", 44);
	clubC.addFans("Jon", 22, 'f');
	clubC.addFans("Arya", 31, 'f');
	clubC.addFans("Ned", 12, 'm');
	clubC.addFans("Tyrion", 26, 'm');
	clubC.addFans("Jaimie", 62, 'f');

	FanClubs clubD("Fourth Fan Club", 45);
	clubD.addFans("Cersei", 22, 'f');
	clubD.addFans("Gendry", 11, 'f');
	clubD.addFans("Sansa", 22, 'f');
	clubD.addFans("Lorem", 12, 'f');
	clubD.addFans("Ipsum", 72, 'm');
	clubD.addFans("Clegane", 12, 'm');
	clubD.addFans("Dany", 12, 'm');
	clubD.addFans("Robb", 12, 'm');
	clubD.addFans("Littlefinger", 26, 'm');
	clubD.addFans("Varys", 62, 'f');

	FanClubs clubP("PoP", 78);
	clubA.showFans();
	clubB.showFans();
	clubD.showFans();

	graphCompare(clubA, clubC);
	//graphCompare(clubB, clubD);
	showgraph();
	}
	else if(choice == 2){
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
	//teamA.deletePlayer(84, 66);
	
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
	}

	else if(choice == 3){
		//Interactive 
	FanClubs clubA("First Fan Club", 55);
	FanClubs clubB("Second Fan Club", 51);
	FanClubs clubC("Third Fan Club", 23);

	BasketballTeams teamA("Los Angeles Lakers", 55);
	BasketballTeams teamB("Golden State Warriors", 51);
	
	clubA.addFans();
	clubB.addFans();
	clubC.addFans();
	
	teamA.addPlayer();
	teamB.addPlayer();

	teamA.deletePlayer(44);

	graphCompare(clubB, clubC);
	showgraph();

	teamA.exportToFile("teamA.txt");
	teamB.exportToFile("teamB.txt");
	}

	else if(choice == 4){
		//--------Fanclubs---------
	FanClubs clubA("First Fan Club", 55);
	clubA.addFans("Tony", 18, 'f');
	clubA.addFans("Steve", 19, 'm');
	clubA.addFans("Natasha", 43, 'f');
	clubA.addFans("Bruce", 25, 'm');
	clubA.addFans("Clint", 35, 'm');
	clubA.addFans("Thor", 11, 'f');

	FanClubs clubB("Second Fan Club", 51);
	clubB.addFans("Peter", 22, 'f');
	clubB.addFans("Gamora", 31, 'f');
	clubB.addFans("Rocket", 12, 'm');
	clubB.addFans("Groot", 26, 'm');
	clubB.addFans("Drax", 62, 'f');

	FanClubs clubC("Third Fan Club", 44);
	clubC.addFans("Jon", 22, 'f');
	clubC.addFans("Arya", 31, 'f');
	clubC.addFans("Ned", 12, 'm');
	clubC.addFans("Tyrion", 26, 'm');
	clubC.addFans("Jaimie", 62, 'f');

	FanClubs clubD("Fourth Fan Club", 45);
	clubD.addFans("Cersei", 22, 'f');
	clubD.addFans("Gendry", 11, 'f');
	clubD.addFans("Sansa", 22, 'f');
	clubD.addFans("Lorem", 12, 'f');
	clubD.addFans("Ipsum", 72, 'm');
	clubD.addFans("Clegane", 12, 'm');
	clubD.addFans("Dany", 12, 'm');
	clubD.addFans("Robb", 12, 'm');
	clubD.addFans("Littlefinger", 26, 'm');
	clubD.addFans("Varys", 62, 'f');

	FanClubs clubP("PoP", 78);
	clubA.showFans();
	clubB.showFans();
	clubD.showFans();

	graphCompare(clubA, clubC);
	//graphCompare(clubB, clubD);
	}

	else if(choice == 5){
		//Interactive 
	FanClubs clubA("First Fan Club", 55);
	FanClubs clubB("Second Fan Club", 51);
	FanClubs clubC("Third Fan Club", 23);

	BasketballTeams teamA("Los Angeles Lakers", 55);
	BasketballTeams teamB("Golden State Warriors", 51);
	
	clubA.addFans();
	clubB.addFans();
	clubC.addFans();
	
	teamA.addPlayer();
	teamB.addPlayer();

	teamA.deletePlayer(44);

	graphCompare(clubB, clubC);

	teamA.exportToFile("teamA.txt");
	teamB.exportToFile("teamB.txt");
	}
	return 0;
}













