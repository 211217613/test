#include <iostream>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

const string Score[] = {"0", "15", "30", "40", "ADV"};

class Game{
	public:
	Game(); //constructor
	bool CreatePlayer(unsigned int playerID, string playerName);
	string getName(unsigned int playerID);
	bool hasADV(unsigned int playerID);
	bool setScore(unsigned int playerID, unsigned int score);
	unsigned int getIntScore(unsigned int playerID);
	string getStringScore(int playerID);

	private:
	string players[2];
	unsigned int scores[2];
};

Game::Game(){
	scores[0] = 0;
	scores[1] = 0;
}

