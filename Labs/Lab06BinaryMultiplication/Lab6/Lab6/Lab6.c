// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

int16_t Multiply(int8_t multiplier, int8_t multiplicand);

int _tmain(int argc, _TCHAR* argv[]) {
	int temp;
	
	//get the multiplier
	printf("Enter the multiplier:\t");
	scanf_s("%d", &temp);
	int8_t multiplier = (int8_t)temp;

	//get the multipliand
	printf("Enter the multiplicand:\t");
	scanf_s("%d", &temp);
	int8_t multiplicand = (int8_t)temp;

	//use function to get the product
	int16_t product = Multiply(multiplier, multiplicand);
	printf("The corresponding product is: %d\n", product);
	return 0;
}

/*
	@function Multiply
	@param multiplier signed 8 bit decimal number you will multiply
	@param multiplicand signed 8 bit decimal number to multiply by
	@return the signed 16 bit product of the two parameters
*/
int16_t Multiply(int8_t multiplier, int8_t multiplicand) {
	int16_t result = 0;
	
	//iterate through each bit to multiply by
	for (int i = 7; i >= 0; i--) {
		//shift left, get MSB and work down
		result <<= 1;
		//if multiplying by 1 at current bit position, add the multiplicand
		if (multiplier&(1<<i))
			result += (uint8_t)multiplicand;
	}

	//If multiplier is negative, subtract multiplicand to correct
	if (multiplier < 0)
		result -= ((int16_t)multiplicand << 8);

	//If multiplicand is negative, subtract the multiplier to correct
	if (multiplicand < 0)
		result -= ((int16_t)multiplier << 8);
	return result;
}
