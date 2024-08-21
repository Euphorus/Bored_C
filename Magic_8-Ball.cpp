#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void getStuff(char* name, char* question) {
	printf("Enter your name = \n");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;

	printf("Enter your question = \n");
	fgets(question, sizeof(question), stdin);
	question[strcspn(question, "\n")] = 0;
}



int main() {
	char name[100];
	char question[100];
	const char* answer[9] = { "Yes - definitely", "It is decidedly so", "Without a doubt", "Reply hazy, try again", "Ask again later", "Better not tell you now", "My sources say no", "Outlook not so good", "Very doubtful"};


	getStuff(name, question);
	printf("Magic 8 ball's answer: %s", answer[rand() % 9]);

	return 0;
}