// Date Created: June 14 2024
// Date Finished: June 18 2024
// Project: Simple Tic Tac Toe Program in CPP
#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
		char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		char player = 'X';
		char computer = 'O';
		bool running = true;

		// When we pass an array to a function it decays into a pointer, so no need to do *spaces
		drawBoard(spaces); 

		while(running){
			playerMove(spaces, player);
			drawBoard(spaces);

			computerMove(spaces, computer);
			drawBoard(spaces); // To update the board after computer move

			if(checkWinner(spaces, player, computer)){
					running = false;
					break;
			}
			else if(checkTie(spaces)){
					running = false;
					break;
			}

		}
		std::cout << "Thanks for playing!";
		return 0;
}

void drawBoard(char *spaces){
		std::cout << '\n';
		std::cout << "     |     |     " << '\n';
		std::cout << " " << spaces[0] << "   |  " << spaces[1] << "  |   " << spaces[2] << " " << '\n';
		std::cout << "_____|_____|_____" << '\n';
		std::cout << "     |     |     " << '\n';
		std::cout << " " << spaces[3] << "   |  " << spaces[4] << "  |   " << spaces[5] << " " << '\n';
		std::cout << "_____|_____|_____" << '\n';
		std::cout << "     |     |     " << '\n';
		std::cout << " " << spaces[6] << "   |  " << spaces[7] << "  |   " << spaces[8] << " " << '\n';
		std::cout << "     |     |     " << '\n';
		std::cout << '\n';

}
void playerMove(char *spaces, char player){
		int number; // will enter what space the player chooses from 1-9
		do{
			std::cout << "Select a spot (1-9)";
			std::cin >> number;
			number--; // We have to decrement since the array starts at 0
			if(spaces[number] == ' '){ // If the space is NOT occupied
				spaces[number] = player; // Add a marker to that spot
				break;	// Then break out of the while loop
			}
		}while(!number > 0 || !number < 8);


}
void computerMove(char *spaces, char computer){
		int number;
		srand(time(0));

		while(true){
				number = rand() % 9; //Number will be randomized from 0-8
				if(spaces[number] == ' '){
					spaces[number] = computer;
					break;
				}
		}

}
bool checkWinner(char *spaces, char player, char computer){
	 if((spaces[0] !=  ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
				spaces[0] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[3] !=  ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
				spaces[3] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[6] !=  ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
				spaces[6] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[0] !=  ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
				spaces[0] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[1] !=  ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
				spaces[1] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[2] !=  ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
				spaces[2] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[0] !=  ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
				spaces[0] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else if((spaces[2] !=  ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
				spaces[2] == player ? std::cout << "You Win!\n" : std::cout<< "You Lose!\n";
	 }
	 else {
		return false;
	 }
	 return true;
}
bool checkTie(char *spaces){
		for(int i = 0; i < 9; i++){
			if(spaces[i] == ' '){
				return false;
			}
		}
		std::cout <<"It's a Tie!\n";
		return 0;
}
