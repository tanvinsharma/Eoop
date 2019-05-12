#include "graph.h" 
#include <cstdlib>
#include <fstream>

void graphCompare(FanClubs a, FanClubs b) {
	if(&a == NULL || &b == NULL) 
		throw domain_error("Cannot operate on empy objects!\n");
	ofstream outfile;
	int people_a = 0, people_b = 0, male_a = 0, male_b = 0;
	int female_a = 0, female_b = 0, age_a = 0, age_b = 0;
	outfile.open("data.dat", ios::out);
	vector<Fans>::iterator i, j;
	for (i = fans.begin(); i != fans.end(); ++i) {
		if(i -> clubProvider() == a.clubIdProvider()) {
			people_a++;
			age_a += i -> whatAge();
			if(tolower(i -> whatSex()) == 'M' || tolower(i -> whatSex()) == 'm') 
				male_a++;
			else 
				female_a++;
		}
	}
	for (j = fans.begin(); j != fans.end(); ++j) {
		if(j -> clubProvider() == b.clubIdProvider()) {
			people_b++;
			age_b += j -> whatAge();
			if(tolower(j -> whatSex()) == 'm' || tolower(j -> whatSex()) == 'M')
				male_b++;
			else
				female_b++;
		}
	}
	outfile << "Data   " << "TeamOne " << "TeamTwo\n";
	outfile << "Fans   " << people_a << "    " << people_b << endl;
	outfile << "Male   " << male_a << "    " << male_b << endl;
	outfile << "Female " << female_a << "    " << female_b << endl;
	outfile << "Avg.Age " << age_a/people_a << "   " << age_b/people_b << endl;
	outfile.close();
}


void showgraph() {
	system("sh graph.sh");
}
