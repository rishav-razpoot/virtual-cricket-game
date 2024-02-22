#include "game.h"
using namespace std;

Game::Game (){

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Sharma";
	players[1] = "Jaishval";
	players[2] = "V.kohli";
	players[3] = "Kl Rahul";
	players[4] = "Surya";
	players[5] = "Hardik";
	players[6] = "Jadeja";
	players[7] = "kuldeep";
	players[8] = "Bumrah";
	players[9] = "Shami";
	players[10] = "Siraj";


	isFirstInnings = 0;
	teamA.teamName = "team-A";
	teamB.teamName = "team-B";
}

void Game::welcome(){
	cout << "---------------------------------------" <<endl;
	cout << "|=============== CRIC-IN =============|" <<endl;
	cout << "|                                     |" <<endl;
	cout << "|   Welcome to Virtual Cricket Game   |" <<endl;
	cout << "---------------------------------------" <<endl;

	cout <<endl <<endl;;

	cout << "-----------------------------------------------------" <<endl;
	cout << "|=================== Instructions ==================|" <<endl;
	cout << "-----------------------------------------------------" <<endl;
	cout << "|                                                   |" <<endl;
	cout << "| 1. Create 2 teams (Team-A and Team-B with 4       |" <<endl;
	cout <<	"     players each)from a given pool of 11 players.  |" <<endl;
	cout << "| 2. Lead the toss and decide the choice of play.   |" <<endl;
	cout << "| 3. Each innings will be of 6 balls.               |" <<endl;
	cout << "-----------------------------------------------------" <<endl;

}

void Game::allPlayers(){
	cout << "---------------------------------------" <<endl;
	cout << "============= All Players =============" <<endl;
	cout << "---------------------------------------" <<endl;

	for(int i = 0; i < totalPlayers; i++){

		cout <<"\t [" << i  <<"]" << players[i] <<endl ;
	}

}

int Game::takeIntegerInput(){

	int n;
	while(!(cin >> n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please try again with a valid input.";
	}

	return n;
}

bool Game::validateSelectedPlayer(int index){
	int n;
	vector<Player>players;
	players = teamA.players;
	n = players.size();
	for(int i = 0; i < n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for(int i = 0; i < n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	return true;

}

void Game::selectPlayers(){
	cout << endl;
	cout << "---------------------------------------" <<endl;
	cout << "======= Create Team-A and Team-B ======" <<endl;
	cout << "---------------------------------------" <<endl;

	for(int i = 0; i < playersPerTeam; i++ ){

		// selecting player for team-A;

		playerASelection :
			cout << "\nSelect " << i + 1 << " player of team-A :";

			int playerIndexForTeamA = takeIntegerInput();
			if(playerIndexForTeamA < 0 || playerIndexForTeamA > 10){
				cout << endl <<"Please select from the given player" << endl;
				goto playerASelection;
			}else if(!validateSelectedPlayer(playerIndexForTeamA)){
				cout << endl << "player has been already selected. please select other player." << endl;
				goto playerASelection;
			}else {
			Player teamAPlayer;
			teamAPlayer.id = playerIndexForTeamA;
			teamAPlayer.name = players[playerIndexForTeamA];
			teamA.players.push_back(teamAPlayer);
			}

		// selecting player for team-B;
		playerBSelection:
			cout << "\nSelect " << i + 1 << " player of team-B :";

			int playerIndexForTeamB = takeIntegerInput();

			if(playerIndexForTeamB < 0 || playerIndexForTeamB > 10){
			cout << endl <<"Please select from the given player" << endl;
			goto playerBSelection;
			}else if(!validateSelectedPlayer(playerIndexForTeamB)){
				cout << endl << "player has been already selected. please select other player." << endl;
				goto playerBSelection;
			}else {
			Player teamBPlayer;
			teamBPlayer.id = playerIndexForTeamB;
			teamBPlayer.name = players[playerIndexForTeamB];
			teamB.players.push_back(teamBPlayer);
			}

	}
}

void Game::displayTeamPlayers(){
	cout << endl;
	vector<Player>teamAplayer = teamA.players;
	vector<Player>teamBplayer = teamB.players;

	cout << "---------------------------------------\t\t---------------------------------------" << endl;
	cout << "|============== Team - A =============|\t\t|============== Team - B =============|" << endl;
	cout << "---------------------------------------\t\t---------------------------------------" << endl;

	for(int i = 0; i < playersPerTeam; i++ ){
		cout << "\t|\t" <<"[" << i <<"]" << teamAplayer[i].name << "\t|"
				<< "\t\t"
		     << "\t|\t" <<"[" << i <<"]" << teamBplayer[i].name << "\t|" << endl;
	}

	cout << "---------------------------------------\t\t---------------------------------------" << endl;

}

void Game::toss(){

	cout << "---------------------------------------" <<endl;
	cout << "============= Let's Toss ==============" <<endl;
	cout << "---------------------------------------" <<endl;

	cout << endl << "Tossing the coin..." << endl <<endl;
	sleep(2);

	srand(time(NULL));
	int outcome = rand() % 2;

	switch(outcome){
	case 0:
		cout << "Team-A Won the toss" << endl;
		tossChoice(teamA);
		break;

	case 1:
		cout << "Team-B Won the toss" <<endl;
		tossChoice(teamB);
		break;
	}

}

void Game::tossChoice(Team tossWinnerTeam){

	cout << "\nEnter 1 to bat first and 2 to ball first" << endl ;
	cout << "1. Bat\n2. Ball" << endl ;

	int tossInput = takeIntegerInput();

	switch(tossInput){
	case 1:
		cout << endl << tossWinnerTeam.teamName <<" won the toss and elected to Bat first" << endl << endl;

		if(tossWinnerTeam.teamName.compare("team-A") == 0) {
			battingTeam = &teamA;
			ballingTeam = &teamB;
		}else {
			battingTeam = &teamB;
			ballingTeam = &teamA;
		}

		break;

	case 2:
		cout << endl << tossWinnerTeam.teamName <<" won the toss and elected to Ball first" << endl << endl;

		if(tossWinnerTeam.teamName.compare("team-A") == 0) {
			ballingTeam = &teamA;
			battingTeam = &teamB;
		}else {
			ballingTeam = &teamB;
			battingTeam = &teamA;
		}

		break;

	default:
		cout << "Invalid input please try Again" << endl;
		tossChoice(tossWinnerTeam);
		break;
	}

}

void Game::startFirstInnings(){
	cout << endl;
	cout << "\t\t||| First Inning Start |||" << endl << endl;
	isFirstInnings = true;

	initializePlayers();

	playInnings();

	//bat();

}

void Game::initializePlayers(){

	batsman = &battingTeam -> players[0];
	baller = &ballingTeam -> players[0];

	cout << battingTeam -> teamName << " - " << batsman -> name << " is Batting" << endl ;
	cout << ballingTeam -> teamName << " - " << baller -> name << " is Balling" << endl ;

}



void Game::playInnings(){

	//cin.ignore(numeric_limits<streamsize>::max(),'\n');

	for(int i = 0; i < maxBalls; i++){

		cout << endl << "press Enter to ball" << endl;
		getchar();
		cout << "Bowling..." << endl;

		sleep(1);

		bat();

		//showGameScoreCard();

		if(!validateInningsScore()){
			break;
		}
	}

}


void Game::bat(){

	srand(time(NULL));
	int runScored = rand() % 7 ;

	// Update batting team and batsman score

	batsman -> runsScored = batsman -> runsScored + runScored;
	battingTeam -> totalRunsScored = battingTeam -> totalRunsScored + runScored;
	batsman -> ballsPlayed = batsman -> ballsPlayed + 1;

	// Update bowling team and bowler score

	baller -> ballsBowled = baller -> ballsBowled + 1;
	ballingTeam -> totalBallsBowled = ballingTeam -> totalBallsBowled + 1;
	baller -> runsGiven = baller -> runsGiven + runScored;

	if(runScored != 0){ // if runScored = 1,2,3,4,5 and 6;

		cout << endl << baller -> name << " to " << batsman -> name << " " << runScored <<" runs" << endl;
		showGameScoreCard();
	}else {
		cout << endl << baller -> name << " to " << batsman -> name << " OUT!" << endl;

		battingTeam -> totalWicketLost = battingTeam -> totalWicketLost + 1;
		baller -> wicketsTaken = baller -> wicketsTaken + 1;

		showGameScoreCard();

		int nextPlayerIndex = battingTeam -> totalWicketLost;
		batsman = &battingTeam -> players[nextPlayerIndex];
	}

}

bool Game::validateInningsScore(){

	if(isFirstInnings){

		if(battingTeam -> totalWicketLost == playersPerTeam || ballingTeam -> totalBallsBowled == maxBalls){

			cout << endl;
			cout << "\t\t||| First Innings End |||\t\t" << endl << endl;
			cout << battingTeam -> teamName << " " << battingTeam -> totalRunsScored << " - "
					<< battingTeam -> totalWicketLost << " (" << ballingTeam -> totalBallsBowled << ") " <<endl;

			cout << ballingTeam -> teamName <<" needs " << battingTeam -> totalRunsScored + 1
					<< " runs to win the Match" << endl;
			return false;
		}

	} else {		// Second Innings.
		if(battingTeam -> totalRunsScored > ballingTeam -> totalRunsScored || battingTeam -> totalWicketLost
				== playersPerTeam || ballingTeam -> totalBallsBowled == maxBalls){

			//cout << endl;

			if(battingTeam -> totalRunsScored > ballingTeam -> totalRunsScored){
				cout << endl << battingTeam -> teamName << " won the Match." << endl;

			}

			if(battingTeam -> totalRunsScored == ballingTeam -> totalRunsScored){
				cout << endl << " Match Tied." << endl;

			}

			if(battingTeam -> totalRunsScored < ballingTeam -> totalRunsScored){
				cout << endl << ballingTeam -> teamName << " won the Match." << endl;

			}

			cout << endl <<"\t\t||| Match Ends |||" << endl << endl;

			return false;
		}

	}

	return true;

}

void Game::showGameScoreCard(){

	cout <<endl;
	cout << "------------------------------------------------------------" <<endl;
	cout << battingTeam -> teamName << " " << battingTeam -> totalRunsScored << " - " << battingTeam -> totalWicketLost
			<< " (" << ballingTeam -> totalBallsBowled << ") " <<" | "
			<< batsman -> name <<" " <<	batsman -> runsScored << " " <<" (" << batsman -> ballsPlayed
			<< ") " <<"\t" << baller -> name << " " << baller -> ballsBowled << " - " << baller -> runsGiven << " - "
			<< baller -> wicketsTaken << endl;
	cout << "------------------------------------------------------------" <<endl << endl;
}


void Game::startSecondInnings(){

	cout << endl <<"\t\t||| Second Inning Start |||" << endl << endl;
	isFirstInnings = false;

	Team swap = *battingTeam;
		   *battingTeam = *ballingTeam;
		   *ballingTeam = swap;

    initializePlayers();

    playInnings();

}

void Game::matchScorecard(){
	cout << endl;
	cout << teamB.teamName << " " << teamB.totalRunsScored << " - " << teamB.totalWicketLost
								<< " (" << teamA.totalBallsBowled << ") " << endl;
			cout <<"==========================================" << endl;
			cout <<"  PLAYER \t BATTING \t BOWLING  " << endl;

			for(int i = 0; i < playersPerTeam; i++){
				cout <<"------------------------------------------" << endl;
				cout << "  [" << i <<"] " << teamB.players[i].name << " \t " << teamB.players[i].runsScored << "("
								<< teamB.players[i].ballsPlayed << ")" <<" \t\t " << teamB.players[i].ballsBowled <<"-" << teamB.players[i].runsGiven
								<< "-" <<teamB.players[i].wicketsTaken  << endl;

			}

			cout <<"==========================================" << endl;


	cout << endl << endl;

	cout << teamA.teamName << " " << teamA.totalRunsScored << " - " << teamA.totalWicketLost
						<< " (" << teamB.totalBallsBowled << ") " << endl;
	cout <<"==========================================" << endl;
			cout <<"  PLAYER \t BATTING \t BOWLING  " << endl;

			for(int i = 0; i < playersPerTeam; i++){
				cout <<"------------------------------------------" << endl;
				cout << "  [" << i <<"] " << teamA.players[i].name << " \t " << teamA.players[i].runsScored << "("
						<< teamA.players[i].ballsPlayed << ")" <<" \t\t " << teamA.players[i].ballsBowled <<"-" << teamA.players[i].runsGiven
						<< "-" <<teamA.players[i].wicketsTaken  << endl;

			}

	cout <<"==========================================" << endl;

}







