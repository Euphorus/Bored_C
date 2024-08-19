#include<stdio.h>
#include<string.h>

void copy(char* dst, char* src) {
	// Code for copying a string goes here
	while (*src != '\0') {
		strcpy(dst, src);
		src++;
		dst++;
	}
	*dst = '\0';
}

int main() {
	char srcString[] = "We promptly judged antique ivory buckles for the next prize!";

	char dstString[strlen(srcString) + 1];
	copy(dstString, srcString);
	printf("%s\n", dstString);
}