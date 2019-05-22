#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Table.h"
using namespace std;

Table::Table() {}

void Table::addTeam(Team t)
{
	teams.push_back(t);
}

string Table::toString() const
{
	stringstream s;
	s << fixed << setw(20)<< left << "Name\t" << "Played\t" << "Won\t" << "Lost\t" << "pW\t" << "pL\t" << right << endl;

	for (int i = 0; i < teams.size(); i++)
	{
		s << teams[i].toString();
	}
	return s.str();
}

void Table::sort()
{
	std::sort(teams.rbegin(), teams.rend());	
	//std::reverse(teams.begin(), teams.end());  druch rbegin / rend ausgetauscht 
}