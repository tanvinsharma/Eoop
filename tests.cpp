#include <iostream>
#include "structure.h"
#include "backbone.h"
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
	FanClubs clubA("First Fan Club", 55);
	cout << "Club ID of the Fan club is : " << clubA.clubIdProvider() << endl;

	cout << "======================" <<endl;
	clubA.addFans("Lauda", 21, 'M');
	clubA.showFans() ;
	cout << "======================" <<endl;

	BasketballTeams TeamA ;
	TeamA.addManager("Tanvin", 46, 'm', 1);
	TeamA.showManagers();

	cout << "======================" <<endl;


	return 0;
}