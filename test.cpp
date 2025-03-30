#include<iostream>
#include<ctime>
#include<vector>
#include "ttt.h"

int main()
{
	char spaces[9] = { ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' ' };

	char player1 = 'X';
	char player2 = 'O';
	bool running = true;

	ttt new_ttt;

	new_ttt.drawBoard(spaces);

	while (running)
	{
		new_ttt.player1Move(spaces, player1);
		new_ttt.drawBoard(spaces);
		if (new_ttt.checkWinner(spaces, player1, player2))
		{
			running = false;
			break;
		}
		else if (new_ttt.checktie(spaces))
		{
			running = false;
			break;
		}


		new_ttt.player2Move(spaces, player2);
		new_ttt.drawBoard(spaces);
		if (new_ttt.checkWinner(spaces, player1, player2))
		{
			running = false;
			break;
		}
		else if (new_ttt.checktie(spaces))
		{
			running = false;
			break;
		}
	}

	std::cout << "Thank you for playing!\n";

	return 0;
}