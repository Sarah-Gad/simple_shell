#include "myshelly.h"
/**
 * putchy - a function I used to print a character.
 * @ctp: the char to print.
 * Return: num of written chars.
*/

int putchy(char ctp)
{
	unsigned int r_num;

	r_num = write(1, &ctp, 1);
	return (r_num);
}
