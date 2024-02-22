#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>

#include "team.h" 		// "player.h" <string> <vector>

class Game {

	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];


		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *ballingTeam;
		Player *batsman, *baller;

		void welcome();
		void allPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectedPlayer(int);
		void displayTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScoreCard();
		void startSecondInnings();
		void matchScorecard();
};
