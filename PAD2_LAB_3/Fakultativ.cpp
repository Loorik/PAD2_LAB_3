#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

string toString()
{
	stringstream s;
	s << fixed << setw(10) << left << "Name der Datei: " << endl;
}

int main()
{
	ifstream inBuildings("buildings.txt", ios::in | ios::binary);	//OR Verknüpfung um lesen zu können

	if (!inBuildings)
	{
		cerr << "file could not be opened" << endl;
		exit(EXIT_FAILURE);			//falls Datei nicht geöffnet werden kann beende das Programm hier
	}

	using byte = char*;
	unsigned size;

	cout << "Wie viele Bytes sollen ausgegeben werden?  ";
	cin >> size;

	inBuildings.read(byte, size)

}
