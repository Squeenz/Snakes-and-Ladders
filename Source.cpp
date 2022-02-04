#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "console.h"

using namespace std;

class Player
{
private:
	string name;
	int position;
	int lastPosition;
	bool first;
	int roll;
	int amountOfMoves;
public:
	//When the object is created it it sets all the privates to default values
	Player(string playerName);

	//When called and variables passed in the method it sets the values
	void setName(string playerName);
	void setPosition(int playerPosition);
	void setLastPosition(int lastPosition);
	void setFirst(bool playerFirst);
	int setDiceRoll(bool setRollZero);

	//All of the bellow methods return values when called
	string getName();
	int getPosition();
	int getLastPosition();
	int getDiceRoll();
	int getPlayerTotalMoves();
	bool getFirst();
	void showAll();
	void playerMove();
};

class Ladders
{
private:
	int ladderPositions[3][2] = {
		{17, 4},
		{18, 7},
		{22, 15}
	};
public:
	int check(string playerName, int position);
};

class Snakes
{
private:
	int snakePositions[3][2] = {
		{13, 2},
		{19, 6},
		{24, 3}
	};
public:
	int check(string playerName, int position);
};

class BoardGame
{
private:
	int gameBoard[5][5] = {
		{21, 22, 23, 24, 25},
		{16, 17, 18, 19, 20},
		{11, 12, 13, 14, 15},
		{6, 7, 8, 9, 10},
		{1, 2, 3, 4, 5}
	};
public:
	BoardGame();
	void board();
	void winner(string playerName, int playerMoves);
	void exportToFile(string playerName, int playerMoves);
};

int main()
{
	Console::setWindowTitle("Snakes and Ladders - 30028170");

	srand((unsigned)time(NULL));

	BoardGame game1;
};

Player::Player(string playerName)
{
	this->name = playerName;
	this->position = 1;
	this->lastPosition = 1;
	this->first = false;
	this->amountOfMoves = 0;
	this->roll = setDiceRoll(false);
};

void Player::setName(string playerName)
{
	this->name = playerName;
};

void Player::setPosition(int playerPosition)
{
	this->position = playerPosition;
};

void Player::setLastPosition(int lastPlayerPosition)
{
	this->lastPosition = lastPlayerPosition;
};

void Player::setFirst(bool playerFirst)
{
	this->first = playerFirst;
};

int Player::setDiceRoll(bool setRollZero)
{	
	int setNull = 0;
	//If setRollZero is true then it sets the decide roll to setNull which is 0
	if (setRollZero) {
		this->roll = setNull; 
	}
	else //If setRollZero is false then it generates a random number between 6 and 1
	{
		this->roll = rand() % 6 + 1;
	}

	return this->roll;
};

string Player::getName()
{
	return this->name;
};

int Player::getPosition()
{
	return this->position;
};

int Player::getLastPosition()
{
	return this->lastPosition;
}

bool Player::getFirst()
{
	return this->first;
};

int Player::getDiceRoll()
{
	return this->roll;
};

int Player::getPlayerTotalMoves()
{
	return this->amountOfMoves;
};

void Player::showAll()
{
	//Prints out all of the variables of the player object
	cout << "NAME: " << this->name << endl;
	cout << "POSITION: " << this->position << endl;
	cout << "LAST POSITION: " << this->lastPosition << endl;
	cout << "FIRST: " << this->first << endl;
	cout << "ROLL: " << this->roll << endl;
	cout << "AMOUNT OF MOVES: " << this->amountOfMoves << endl;
};

void Player::playerMove()
{
	//Everytime the playerMove is called it will prints and set all of these variables from the object
	cout << this->name << " rolls a " << this->getDiceRoll() << " and moves to square " << this->getDiceRoll() + this->getPosition() << endl;
	this->setPosition(this->getDiceRoll() + this->getPosition());
	this->setLastPosition(this->getPosition());
	this->setDiceRoll(false);
	this->amountOfMoves++;
	Sleep(200);
};

int Ladders::check(string playerName, int position)
{
	Console::setColour(Console::LIGHT_GREEN);

	int newPosition = 0;

	//If positon is equal to any of the selected values from the laddersPositons array it will return the other value from the array
	if (position == ladderPositions[0][1])
	{
		newPosition = ladderPositions[0][0];
		cout << playerName << " has landed at the bottom of a ladder("<< ladderPositions[0][1] <<"), and moves up to square " << newPosition << endl;
	}
	else if (position == ladderPositions[1][1])
	{
		newPosition = ladderPositions[1][0];
		cout << playerName << " has landed at the bottom of a ladder(" << ladderPositions[1][1] << "), and moves up to square " << newPosition << endl;
	}
	else if (position == ladderPositions[2][1])
	{
		newPosition = ladderPositions[2][0];
		cout << playerName << " has landed at the bottom of a ladder(" << ladderPositions[2][1] << "), and moves up to square " << newPosition << endl;
	}
	else
	{
		newPosition = position;
	};

	Console::setColour(Console::LIGHT_BLUE);

	return newPosition;
};

int Snakes::check(string playerName, int position)
{
	Console::setColour(Console::LIGHT_RED);

	int newPosition = 0;

	//If positon is equal to any of the selected values from the snakePositions array it will return the other value from the array
	if (position == snakePositions[0][0])
	{
		newPosition = snakePositions[0][1];
		cout << playerName << " oh no!!! you have laded on a snakes head(" << snakePositions[0][0] << "), and you move down to square " << newPosition << endl;
	}
	else if (position == snakePositions[1][0])
	{
		newPosition = snakePositions[1][1];
		cout << playerName << " oh no!!! you have laded on a snakes head(" << snakePositions[1][0] << "), and you move down to square " << newPosition << endl;
	}
	else if (position == snakePositions[2][0])
	{
		newPosition = snakePositions[2][1];
		cout << playerName << " oh no!!! you have laded on a snakes head(" << snakePositions[2][0] << "), and you move down to square " << newPosition << endl;
	}
	else
	{
		newPosition = position;
	};

	Console::setColour(Console::LIGHT_BLUE);

	return newPosition;
};

void BoardGame::board()
{
	Console::setColour(Console::WHITE);
	cout << "-------GAME BOARD----------" << endl;
	Console::setColour(Console::LIGHT_BLUE);
	//Runs throuhg the 2d array and prints out the grid at the start
	for (int col = 0; col < 5; col++)
	{
		for (int row = 0; row < 5; row++)
		{
			cout << "[" << gameBoard[col][row] << "]";
		};
		cout << endl;
	};
};

void BoardGame::exportToFile(string playerName, int playerMoves)
{
	//Creates SnakesAndLaddersLog.txt file 
	ofstream myfile;
	myfile.open("SnakesAndLaddersLog.txt");
	myfile << "The winner was " << playerName << endl;
	myfile << playerName << " won in " << playerMoves << " moves" << endl;
	myfile.close();
};

void BoardGame::winner(string playerName, int playerMoves)
{
	Console::setColour(Console::YELLOW);
	cout << playerName << " has won the game!!!" << endl;
	exportToFile(playerName, playerMoves);
};

BoardGame::BoardGame()
{
	//Calls the board method which prints the grid of the board on the screen in the console
	board();

	Console::setCursorPosition(7, 0);
	Console::setColour(Console::WHITE);
	cout << "---------GAME INFO---------------" << endl;
	Console::setColour(Console::LIGHT_BLUE);

	string player;

	cout << "Enter First players name: ";
	cin >> player;

	//Creates the first player object
	Player player1(player);

	cout << "Enter Second players name: ";
	cin >> player;

	//Creates the second player object
	Player player2(player);

	//Rolls both of the players starting dice
	cout << player1.getName() << " rolls a " << player1.getDiceRoll() << endl;
	cout << player2.getName() << " rolls a " << player2.getDiceRoll() << endl;

	bool diceRollIsTheSame = true;

	while (diceRollIsTheSame)
	{
		/*Checks if the first player has rolled higher than the second player 
		if it's true then setFirst will be set to true*/
		if (player1.getDiceRoll() > player2.getDiceRoll())
		{
			cout << player1.getName() << " " << "will start first" << endl;
			player1.setFirst(true);
			diceRollIsTheSame = false;
		}
		/*if both of the dice rolls are the same both of the dices will be re-rolled*/
		else if (player1.getDiceRoll() == player2.getDiceRoll())
		{
			cout << "Rolling again" << endl;
			player1.setDiceRoll(false);
			player2.setDiceRoll(false);
		}
		else
		{		
			/*if second player's dice roll is higher than the setFirst 
			will be set to true for the second player*/
			cout << player2.getName() << " " << "will start first" << endl;
			player2.setFirst(true);
			diceRollIsTheSame = false;
		};
	};

	bool gameEnd = false;

	//Creates ladders and snaeks objects
	Ladders ladders;
	Snakes snakes;

	//While gameEnd is false the loop will be run
	while (!gameEnd)
	{
		//If player1 position is 25 then the player has won the game and the loop ends by chaning gameEnd to true
		if (player1.getPosition() == 25)
		{
			winner(player1.getName(), player1.getPlayerTotalMoves());
			gameEnd = true;
		}
		//If player2 position is 25 then the player has won the game and the loop ends by chaning gameEnd to true
		if (player2.getPosition() == 25)
		{
			winner(player2.getName(), player2.getPlayerTotalMoves());
			gameEnd = true;
		}

		//While gameEnd is false the loop will be run
		if (!gameEnd) {

			//If player1 current position + dice roll or last position + dice roll is over 25 it will set the dice roll to 0 and then re-set it
			if (player1.getPosition() + player1.getDiceRoll() > 25 || player1.getLastPosition() + player1.getDiceRoll() > 25)
			{
				Console::setColour(Console::PURPLE);
				cout << player1.getName() << " You have to roll the exact number to win" << endl;
				player1.setDiceRoll(true);
				player1.setDiceRoll(false);
				player1.setPosition(player1.getLastPosition() - player1.getDiceRoll());
				player1.setLastPosition(player1.getLastPosition() - player1.getDiceRoll());
				Console::setColour(Console::LIGHT_BLUE);
			}
			//If player2 current position + dice roll or last position + dice roll is over 25 it will set the dice roll to 0 and then re-set it
			if (player2.getPosition() + player2.getDiceRoll() > 25 || player2.getLastPosition() + player2.getDiceRoll() > 25)
			{
				Console::setColour(Console::PURPLE);
				cout << player2.getName() << " You have to roll the exact number to win" << endl;
				player2.setDiceRoll(true);
				player2.setDiceRoll(false);
				player2.setPosition(player2.getLastPosition() - player1.getDiceRoll());
				player2.setLastPosition(player2.getLastPosition() - player2.getDiceRoll());
				Console::setColour(Console::LIGHT_BLUE);
			};

			if (player1.getFirst() == true)
			{
				player1.playerMove();
				player1.setLastPosition(snakes.check(player1.getName(), player1.getLastPosition()));
				player1.setPosition(ladders.check(player1.getName(), player1.getLastPosition()));

				player2.playerMove();
				player2.setLastPosition(snakes.check(player2.getName(), player2.getLastPosition()));
				player2.setPosition(ladders.check(player2.getName(), player2.getLastPosition()));
			}
			else
			{
				player2.playerMove();
				player2.setLastPosition(snakes.check(player2.getName(), player2.getLastPosition()));
				player2.setPosition(ladders.check(player2.getName(), player2.getLastPosition()));

				player1.playerMove();
				player1.setLastPosition(snakes.check(player1.getName(), player1.getLastPosition()));
				player1.setPosition(ladders.check(player1.getName(), player1.getLastPosition()));
			};
		};
	};
};