#pragma once
#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>

class Team
{
public:
	Team(const char* ="", int=0, int=0, int=0, int=0, int=0);
	std::string toString() const;
	bool operator<(const Team&) const;
	//std::ostream & write(std::ostream &) const;
	std::istream & read(std::istream &);

private:
	char teamName[20];
	int matchesplayed;
	int gamesWon;
	int gamesLost;
	int pointsWon;
	int pointsLost;
};

#endif