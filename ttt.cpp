#include<iostream>
#include "ttt.h"


void ttt::drawBoard(char* spaces)
{
	std::cout << "\n";
	std::cout << "     |     |     " << "\n";
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
	std::cout << "_____|_____|_____" << "\n";
	std::cout << "     |     |     " << "\n";
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
	std::cout << "_____|_____|_____" << "\n";
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
	std::cout << "     |     |     " << "\n";
	std::cout << "\n";
}

void ttt::player1Move(char* spaces, char player1)
{
	int number;
	do 
	{
		std::cout << "Enter a spot to place a marker Player1 (1-9): ";
		std::cin >> number;
		number--;
		if (spaces[number] == ' ')
		{
			spaces[number] = player1;
			break;
		}
	} while (!number > 0 || !number < 8);
}

void ttt::player2Move(char* spaces, char player2)
{
	int number;
	do
	{
		std::cout << "Enter a spot to place a marker Player2 (1-9): ";
		std::cin >> number;
		number--;
		if (spaces[number] == ' ')
		{
			spaces[number] = player2;
			break;
		}
	} while (!number > 0 || !number < 8);
}

bool ttt::checkWinner(char* spaces, char player1, char player2)
{
	if ((spaces[0] != ' ') && spaces[0] == spaces[1] && spaces[1] == spaces[2])
	{
		spaces[0] == player1 ? std::cout << "You WIN!\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[3] != ' ') && spaces[3] == spaces[4] && spaces[4] == spaces[5])
	{
		spaces[3] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[6] != ' ') && spaces[6] == spaces[7] && spaces[7] == spaces[8])
	{
		spaces[6] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[0] != ' ') && spaces[0] == spaces[3] && spaces[3] == spaces[6])
	{
		spaces[0] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[1] != ' ') && spaces[1] == spaces[4] && spaces[4] == spaces[7])
	{
		spaces[1] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[2] != ' ') && spaces[2] == spaces[5] && spaces[5] == spaces[8])
	{
		spaces[2] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[0] != ' ') && spaces[0] == spaces[4] && spaces[4] == spaces[8])
	{
		spaces[0] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else if ((spaces[2] != ' ') && spaces[2] == spaces[4] && spaces[4] == spaces[6])
	{
		spaces[2] == player1 ? std::cout << "You WIN\n" : std::cout << "You LOSE\n";
	}

	else
	{
		return false;
	}

	return true;
}

bool ttt::checktie(char* spaces)
{
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i] == ' ')
		{
			return false;
		}
	}

	std::cout << "Its a TIE!\n";
	return true;
}