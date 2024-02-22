#include <vector>
#include "player.h"		// <string>

class Team {
	public:
		Team();
		std::string teamName;
		int totalRunsScored;
		int totalWicketLost;
		int totalBallsBowled;
		std::vector<Player>players;

};
