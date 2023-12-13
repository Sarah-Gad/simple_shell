#include "myshelly.h"
/**
 * fndchr - a function that I used to find the first
 * occurrence of a specific char in a str.
 * @pt_s_st: pointer to the string to search in.
 * @tg_ch: the character to search for it.
 * Return: pointer to the place of the char in the str.
*/
char *fndchr(char *pt_s_st, char tg_ch)
{
	int ind_c = 0;

	while (pt_s_st[ind_c] != 0)
	{
		if (pt_s_st[ind_c] == tg_ch)
			return (pt_s_st + ind_c);
		ind_c++;
	}
	if (pt_s_st[ind_c] == tg_ch)
		return (pt_s_st + ind_c);
	return ('\0');
}
/**
 * cnt_len - a function that I used to get the length of the strg.
 * @pt_lst: pointer to the string to calculate its leng.
 * Return: it returns the length of the string
*/
int cnt_len(char *pt_lst)
{
	int l_cntr = 0;

	while (pt_lst[l_cntr])
	{
		l_cntr++;
	}
	return (l_cntr);
}
