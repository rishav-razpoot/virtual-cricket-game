#include "game.h"  		// "team.h" "player.h" <iostream> <cstdlib> <ctime> <limits> <string> <vector>
using namespace std;

int main() {
	Game game;

	setbuf(stdout,NULL);
	game.welcome();


	cout <<"\npress enter to continue" <<endl;;
	getchar();

	game.allPlayers();

	cout <<"\npress enter to continue" <<endl;;
	getchar();

	game.selectPlayers();

	game.displayTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "\npress enter to Toss\n" << endl;
	getchar();

	game.toss();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	game.startFirstInnings();

	cout << "\npress enter to start 2nd inning\n" << endl;
	getchar();

	game.startSecondInnings();

	game.matchScorecard();

	return 0;
}
