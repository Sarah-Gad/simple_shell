#include "myshelly.h"
/**
 * st_t_int - a function I used to convert a string to an int.
 * @stinp: pointer to the string input to be converted.
 * Return: the converted int.
*/
int st_t_int(char *stinp)
{
	unsigned int cnint = 0;
	int p_o_n = 1;

	do {
		if (*stinp == '-')
			p_o_n *= -1;
		else if (*stinp >= '0' && *stinp <= '9')
			cnint = (cnint * 10) + (*stinp - '0');
		else if (cnint > 0)
			break;
	} while (*stinp++);

	return (cnint * p_o_n);
}
