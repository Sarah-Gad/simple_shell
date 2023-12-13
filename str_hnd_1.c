#include "myshelly.h"
/**
 * cmp_n_2st - a function that I used to compare
 * the first num of chars in two strings.
 * @st_f1: pointer to the fisrt string to compare.
 * @st_s2: pointer to the seconf string to comapre.
 * @sp_fn: the num of chars to compare.
 * Return: 0 or non_zero value.
*/
int cmp_n_2st(const char *st_f1, const char *st_s2, size_t sp_fn)
{
	while (sp_fn-- && (*st_f1 != '\0' || *st_s2 != '\0'))
	{
		if (*st_s2 != *st_f1)
			return (*st_f1 - *st_s2);
		st_f1++;
		st_s2++;
	}
	return (0);
}
/**
 * dp_t_st - a function that I used to duplicate the input str.
 * @stct_ptr: prt to the struct I created
 * @in_st: pointer tio the string to duplicte.
 * Return: pointer to the new string.
*/
char *dp_t_st(strugy *stct_ptr, char *in_st)
{
	int ind_ct;
	int cn_ln;
	char *nw_d_str;

	if (!in_st)
		return (NULL);
	cn_ln = cnt_len(in_st);
	nw_d_str = malloc(cn_ln + 1);
	if (!nw_d_str)
		ext_now(stct_ptr);
	for (ind_ct = 0; ind_ct <= cn_ln; ind_ct++)
	{
		nw_d_str[ind_ct] = in_st[ind_ct];
	}
	return (nw_d_str);
}
/**
 * cmp_2st - a function that I used to compare 2 strs.
 * @pf_st: ointer to the first string to compae.
 * @ps_st: pointer to the secind string to compare.
 * Return: zero or non zero value.
*/
int cmp_2st(char *pf_st, char *ps_st)
{
	while (*pf_st && *ps_st)
	{
		if (*pf_st != *ps_st)
		{
			return (*pf_st - *ps_st);
		}
		pf_st++;
		ps_st++;
	}
	if (*pf_st == *ps_st)
		return (0);
	else
		return (*pf_st - *ps_st);
}
/**
 * revy_com - a function that I used to compare 2 strings in reverse.
 * @f1_st: pointer to the first stringg.
 * @s2_st: pointer to the second string.
 * Return: it returns 1 or 0 .
*/
int revy_com(char *f1_st, char *s2_st)
{
	int f1_ln;
	int s2_ln;
	int tr_ind = 0;

	s2_ln = (cnt_len(s2_st) - 1);
	f1_ln = (cnt_len(f1_st) - 1);
	if (s2_ln > f1_ln)
		return (0);
	for (tr_ind = s2_ln; tr_ind >= 0; tr_ind--)
	{
		if (f1_st[f1_ln] != s2_st[tr_ind])
			return (0);
		f1_ln--;
	}
	return (1);
}
