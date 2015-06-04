//Matthew Koken
//Lab4
#include "stdlib.h"
#include "stdio.h"
#define false 0
#define true 1

void Asc2Bin(char *string, int binary[8]);
void TwosComp(int binary[8]);
void PrintBin(int binary[8]);

//Typedef for bool
typedef enum { FALSE = 0, TRUE = 1 } BOOL;

int main() {
	int input;
	int binary[8];

	//get user input
	printf("Enter a binary string:\t");
	char myString[101];
	scanf("%100s", myString, 101);

	//use functions to calculate and print the decimal version
	Asc2Bin(myString, &binary);
	printf("The twos complement is:\t");
	TwosComp(&binary);
	PrintBin(binary);
	return 0;
}

void TwosComp(int binary[8]) {
	BOOL one = FALSE;
	//Start from LSB, move until reach first one
	//Then flip each bit
	for (int i = 0; i < 8; i++) {
		//if we have already found the first one, flip the bit
		if (one) {
			if (binary[i] == 1)
				binary[i] = 0;
			else
				binary[i] = 1;
		}
		//check if we've found the first one
		else if (!one) {
			if (binary[i] == 1)
				one = TRUE;
		}
	}
}

void Asc2Bin(char *string, int binary[8]) {
	//Find the end so that we can extract the rightmost 8
	int pos = 0;
	for (; pos < 101; pos++) {
		if (string[pos] == '\0')
			break;
	}
	pos--;

	//extract only the 8 rightmost bits
	//if 1, then the binary is 1, else 0 to account for not enough digits
	for (int i = 7; i >= 0; i--) {
		char c = string[pos];
		if (c == '1')
			binary[7 - i] = 1;
		else
			binary[7 - i] = 0;
		pos--;
	}
}

void PrintBin(int binary[8]) {
	//print the each binary value
	//start with MSB, print to the right
	for (int i = 7; i >= 0; i--) {
		printf("%d", binary[i]);
	}
	printf("\n");
}