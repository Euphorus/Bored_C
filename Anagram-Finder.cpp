#include<stdio.h>
#include<string.h>

int areAnagrams(char* s1, char* s2)
{
	int counter1[4] = { 0 };
	int counter2[4] = { 0 };
	int i;

	for (i = 0; s1[i] && s2[i]; i++) {
		counter1[s1[i]]++;
		counter2[s2[i]]++;
	}

	if (s1[i] || s2[i])
		return 0;

	for (i = 0; i < 4; i++) {
		if (counter1[i] != counter2[i])
			return 0;
	}

	return 1;
}



int main() {
	char s1[] = "String 1";
	char s2[] = "String 2";

	if (areAnagrams(s1, s2)) {
		printf("Anagrams");
	}
	else {
		printf("Not Anagrams");
	}
}