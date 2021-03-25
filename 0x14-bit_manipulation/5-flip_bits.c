#include <stdio.h>
#include "holberton.h"
/**
* flip_bits - function that returns the number of bits you would need to
* flip to get from one number to another.
*@n: 1st number
*@m: 2nd number
* Return: Always 0.
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count, flipped;

	if (n == 0 && m == 0)
		return (0);
	flipped = n ^ m;
	count = 0;
	while (flipped > 0)
	{
		count++;
		flipped = flipped & (flipped - 1);
	}
	return (count);
}
