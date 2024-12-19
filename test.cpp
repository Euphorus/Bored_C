#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream file("puzzle_Input.txt");
	string content;

	while (file >> content) {
		cout << content <<" \n";
	}

	return 0;
}
