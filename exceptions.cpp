#include <iostream>
#include <fstream>
#include "structure.h"
#include "backbone.h"

using namespace std;

void log_error(string error) {
	std::ofstream outfile;
  	outfile.open("error_log.txt", std::ios_base::app);
  	outfile << error << endl; 
  	outfile.close();
}

void age_exception(int age) {
	try {
		FanClubs clubA("First Club", 55);
		clubA.addFans("Random", age, 'm');
	}
	catch (std::out_of_range& oor) {
		cout << "Age error: " << oor.what() << endl;
		log_error(oor.what());
	}
}

void name_exception(string name) {
	try {
		FanClubs clubA("First Club", 55);
		clubA.addFans(name, 25, 'm');
	}
	catch (std::invalid_argument& ia) {
		cout << "Name error: " << ia.what() << endl;
		log_error(ia.what());
	}
}

void sex_exception(char sex) {
	try {
		FanClubs clubA("First Club", 55);
		clubA.addFans("Random", 52, sex);
	}
	catch (std::invalid_argument& ia) {
		cout << "Sex error: " << ia.what() << endl;
		log_error(ia.what());	
	}
}
int main(int argc, char const *argv[]) {
	
	age_exception(130);
	name_exception("PO2");
	sex_exception('p');

	return 0;
}