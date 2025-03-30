#pragma once
class ttt
{
public:
	void drawBoard(char* spaces);
	void player1Move(char* spaces, char player1);
	void player2Move(char* spaces, char player2);
	bool checkWinner(char* spaces, char player1, char player2);
	bool checktie(char* spaces);
};

