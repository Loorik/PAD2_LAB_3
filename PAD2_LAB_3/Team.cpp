#include <iostream>
#include "Team.h"
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

Team::Team(const char* n , int mp, int gw, int gl, int pw, int pl)
	:  matchesplayed(mp), gamesWon(gw), gamesLost(gl), pointsWon(pw), pointsLost(pl)
{
	strncpy_s(teamName, n, 20);		
}

string Team::toString() const
{
	stringstream s;
	s << fixed << setw(20) <<left <<  teamName << "\t" << matchesplayed << "\t" << gamesWon << "\t" << gamesLost << "\t" << pointsWon << "\t" << pointsLost << endl;
	return s.str();
}

//ostream& Team::write(ostream& os) const
//{
//	os.write(reinterpret_cast<const char *>(this), sizeof(Team));//	return os;
//}

istream& Team::read(istream& is) 
{
	using byte = char*;
	is.read(reinterpret_cast<byte>(this), sizeof(Team));
	return is;
}

bool Team::operator<(const Team& t) const
{
	if (pointsWon < t.pointsWon)
	{
		return true;
	}
	else
	{
		if (pointsLost > t.pointsLost)
		{
			return true;
		}
		else if ((gamesWon - gamesLost) < (t.gamesWon - t.gamesLost))
		{
			return true;
		}
	}
		return false;
}