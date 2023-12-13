#include "myshelly.h"
/**
 * ad_str - a function that I used to add a string at the end of another one.
 * @orgin: pointer to the string that will contain both strings.
 * @to_ad: pointer to the string to be added.
 * Return: pointer to the origin string.
*/
char *ad_str(char *orgin, char *to_ad)
{
	int orglen = 0;
	int adlen = 0;

	if (orgin == NULL || to_ad == NULL)
	{
		return (orgin);
	}
	while (orgin[orglen] != '\0')
		orglen++;
	while (to_ad[adlen] != '\0')
	{
		orgin[orglen + adlen] = to_ad[adlen];
		adlen++;
	}
	orgin[orglen + adlen] = '\0';
	return (orgin);
}
/**
 * ad_n_str - a function that I used to add num
 * of chars fron one string to another str.
 * @orgn: pointer to the string that will contain both of the two strings.
 * @num_add: num of characters to be added fron the t_add string.
 * @t_add: pointer to the string that will be added.
 * Return: pointer to the origin str.
*/
char *ad_n_str(char *orgn, char *t_add, int num_add)
{
	int org_len = 0;
	int t_d_len = 0;

	while (orgn[org_len] != 0)
		org_len++;
	while (t_add[t_d_len] != 0 && t_d_len < num_add)
	{
		orgn[org_len] = t_add[t_d_len];
		org_len++;
		t_d_len++;
	}
	return (orgn);
}
/**
 * cp_sh_st - a function that I used to copy a strinnng.
 * @plc: the place where the contenet of the strinng will be copied.
 * @s_st: the string to copy its content.
 * Return: pointer to the plc.
*/

char *cp_sh_st(char *plc, char *s_st)
{
	int idx_sh = 0;

	if (plc == s_st || s_st == 0)
		return (plc);
	while (s_st[idx_sh])
	{
		plc[idx_sh] = s_st[idx_sh];
		idx_sh++;
	}
	plc[idx_sh] = 0;
	return (plc);
}
