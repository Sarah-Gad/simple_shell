#include "myshelly.h"
/**
 * int_t_st - a function that I used to convert an int to a string.
 * @o_st: the output string.
 * @inttcon: the int to be converted.
 * Return: nothing
*/
void int_t_st(char *o_st, int inttcon)
{
	int ind1;
	int cntln;
	int set = 0;

	set = inttcon;
	if (set == 0)
	{
		o_st[0] = '0';
		o_st[1] = '\0';
		return;
	}
	if (!set)
	{
		o_st[0] = '0';
		o_st[1] = '\0';
		return;
	}
	for (cntln = 0; set != 0; cntln++)
	{
		set /= 10;
	}
	for (ind1 = 0; ind1 < cntln; ind1++)
	{
		o_st[cntln - (ind1 + 1)] = inttcon % 10 + '0';
		inttcon /= 10;
	}
	o_st[cntln] = '\0';
}
