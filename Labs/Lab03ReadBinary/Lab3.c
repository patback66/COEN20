//Matthew Koken
//Lab3
#include "stdlib.h"
#include "stdio.h"

void Asc2Bin(char *string, int binary[8]);
int Bin2Unsigned(int binary[8]);
int Bin2Signed(int binary[8]);

int main() {
	int input;
	int binary[8];

	//get user input
	printf("Enter a binary string: ");
	char myString[101];
	scanf("%100s", myString, 101);

	//use functions to calculate and print the decimal version
	Asc2Bin(myString, &binary);
	printf("The unsigned decimal integer is: %d\n", Bin2Unsigned(&binary));
	printf("The signed decimal integer is: %d\n", Bin2Signed(&binary));
	return 0;
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
	for (int i = 7; i >=0 ; i--) {
		char c = string[pos];
		if (c == '1')
			binary[7 - i] = 1;
		else
			binary[7 - i] = 0;
		pos--;
	}
}

//pow returns an unexpected value from int conversion
//needed to use different solution for exponents
int power(int x, int y){
	return y ? (y % 2 ? x : 1)*power(x*x, y >> 1) : 1;
}

int Bin2Unsigned(int binary[8]) {
	int result = 0;

	//add each bit times its represented power of 2
	for (int i = 0; i < 8; i++) {
		int num = (int)power(2, i);
		result += binary[i] * num;
	}
	return result;
}

int Bin2Signed(int binary[8]) {
	//for MSB, needs to be negative if 1 and signed
	int result = binary[7] * -1 * (int)power(2, 7);

	//add all other bits as normal
	for (int i = 0; i < 7; i++) {
		result += binary[i] * (int)power(2, i);
	}
	return result;
}