#include<stdio.h>
#include<string.h>

int main() {
	char str1[100], str2[100], result[200];

	printf("Enter the first line (eg: I have waited) ");
	fgets(str1, sizeof(str1), stdin); //using fgets because scanf has a really low buffer size meaning fixed-size buffer to store the input data, which is typically defined by the format specifier
	str1[strcspn(str1, "\n")] = 0; // strcspn is string function in C that calculates the length of the initial segment of a string that consists entirely of characters not in a specified reject set.

	printf("Enter the second line (eg: A long time) ");
	fgets(str2, sizeof(str2), stdin);
	str2[strcspn(str2, "\n")] = 0;
	
	//Concatenate str2 to str1 with a space in between
	sprintf(result, "%s, %s", str2, str1); //"string print formatted," and it's used to format a string by inserting values into a format string
	printf("Yoda says: %s\n", result);

	return 0;
}