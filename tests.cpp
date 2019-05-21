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

		BasketballTeams teamA("Los Angeles Lakers", 55);

	teamA.addManager("Tanvin", 52, 'm', 65);
	teamA.showManagers();


	cout << "======================" <<endl;


	return 0;
}