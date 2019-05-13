
//==========BASKETBALL_GRAPH===========
#include <iostream>
#include "structure.h"
#include "backbone.h"
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

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
	
	return 0;
}
