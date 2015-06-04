// Lab2.cpp 
// @Author Matthew Koken

#include "stdio.h"
#include "stdlib.h"

/*
	Dec2Bin
	@param decimal: decimal value you want to convet
	@param binary: array of length 8 for storing binary digits
*/
void Dec2Bin(int decimal, int binary[8]) {
	int cur = decimal;

	//initialize binary to be 00000000
	for (int i = 0; i < 8; i++)
		binary[i] = 0;

	//get the value for each bit from %2, /=2 to get the
	//next quotient
	for (int i = 7; cur != 0 && i >= 0; i--) {
		binary[i] = cur % 2;
		cur /= 2;
	}
}

/*
	PrintBin
	@param binary: array of binary digits to print
*/
void PrintBin(int binary[8]) {
	printf("The 8 binary bits are: \n");

	//print values for each binary digit
	for (int i = 128; i > 0; i/=2) {
		printf("%d\t", i);
	}
	printf("\n");

	//print the each binary value
	for (int i = 0; i < 8; i++) {
		printf("%d\t", binary[i]);
	}
	printf("\n");
}

int main(int argc, const char* argv[])
{
	unsigned int input;
	unsigned int binary[8];

	//get user input
	printf("Enter a decimal integer: ");
	scanf("%d", &input);

	//use functions to calculate and print the binary version
	Dec2Bin(input, &binary);
	PrintBin(binary);
	return 0;
}

