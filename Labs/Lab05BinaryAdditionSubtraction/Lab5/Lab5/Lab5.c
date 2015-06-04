//Matthew Koken
//Lab5
#include "stdlib.h"
#include "stdio.h"
#define false 0
#define true 1

void Asc2Bin(char *string, int binary[8]);
void TwosComp(int binary[8]);
void PrintBin(int binary[8]);
int AddBinary(int first[8], int second[8], int result[8]);
int SubBinary(int first[8], int second[8], int result[8]);

//Typedef for bool
typedef enum { FALSE = 0, TRUE = 1 } BOOL;

int main() {
	int input;
	int first[8];
	int second[8];
	int sum[8];
	int dif[8];

	//get first input
	printf("Enter 1. binary number (8 chars):\t");
	char myString[101];
	scanf("%100s", myString, 101);
	//use functions to calculate the decimal version
	Asc2Bin(myString, &first);

	//get second
	printf("Enter 1. binary number (8 chars):\t");
	char myString2[101];
	scanf("%100s", myString2, 101);
	//use functions to calculate the decimal version
	Asc2Bin(myString2, &second);
	
	//addition
	int carryOut = AddBinary(&first, &second, &sum);
	printf("The 1st number plus the 2nd is: ");
	PrintBin(sum);
	printf("The carry out is : %d\n", carryOut);

	//subtraction
	int borrowIn = SubBinary(&first, &second, &dif);
	printf("The 1st number minus the 2nd is: ");
	PrintBin(dif);
	printf("The borrow out is : %d\n", borrowIn);

	return 0;
}

int AddBinary(int first[8], int second[8], int result[8]) {
	int carryOut = 0;
	//iterate through each bit
	for (int i = 0; i < 8; i++) {
		int cur = first[i] + second[i] + carryOut;
		// 0 + 0 + 0= 0
		if (cur == 0) {
			result[i] = cur;
			carryOut = 0;
		} 
		// 1 + 0 + 0 = 1
		else if (cur == 1) {
			result[i] = cur;
			carryOut = 0;
		} 
		// 1 + 1 + 0 = 10
		else if (cur == 2) {
			result[i] = 0;
			carryOut = 1;
		}
		// 1 + 1 + 1 = 11
		else if (cur == 3) {
			result[i] = 1;
			carryOut = 1;
		}
	}
	return carryOut;
}

int SubBinary(int first[8], int second[8], int result[8]) {
	int borrowIn = 0;
	//iterate through each bit
	for (int i = 0; i < 8; i++) {
		int dif = first[i] - second[i] - borrowIn;
		if (dif < 0) {
			//always need to borrow 
			borrowIn = 1;
			// 0 - 1
			if (dif == -1)
				result[i] = 1;
			else
				result[i] = 0;
		}
		//1-0
		else {
			//don't need to borrow
			borrowIn = 0;
			result[i] = dif;
		}
	}
	return borrowIn;
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