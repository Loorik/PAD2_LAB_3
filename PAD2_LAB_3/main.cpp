#include<iostream>
#include <fstream>
#include <cstdlib>
#include "Table.h"
#include "Team.h"
using namespace std;

int main()
{
	ifstream inTabletennis("../tabletennis.dta", ios::in | ios::binary);	//OR Verknüpfung um lesen zu können

	if (!inTabletennis)
	{
		cerr << "file could not be opened" << endl;
		exit(EXIT_FAILURE);			//falls Datei nicht geöffnet werden kann beende das Programm hier
	}

	Table tab;
	Team team;

	while (team.read(inTabletennis))
	{
		tab.addTeam(team);
	}

	cout << tab.toString(); // unsortiert
	tab.sort();	
	cout << "\n"<<tab.toString(); //sortiert
	inTabletennis.close();

	ofstream outTable("../Table.txt", ios::out);	// erstelle neue .txt Datei in "oberen" Ordner
	outTable << tab.toString();
	outTable.close();
}