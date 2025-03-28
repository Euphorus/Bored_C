#include<iostream>
#include "profile.h"

int main()
{
	profile sam("Yuvraj Kumpavat", 25, "Milan", "Italy", "he/him");

	sam.add_hobby("skateboarding and shredding down the park.");
	sam.add_hobby("Grinding to armor in Destiny 2");
	sam.add_hobby("Thinks he is Jeremy Clarkson.");
	sam.add_hobby("But ends up being Richard Hammond by driving like a maniac.");
	sam.add_hobby("programs in C++, thats it. That's his strength.");
	std::cout << sam.view_profile();


}
