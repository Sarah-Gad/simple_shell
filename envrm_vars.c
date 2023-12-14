#include "myshelly.h"
/**
 * s_envrm - a function that  used to get
 * the value of an envirnmment variable.
 * @a_str: the envirnment vars.
 * @srch: the var to search for.
 * @p_ln: the length of the prefix.
 * Return: it returns pointer to the value of the var.
*/
char *s_envrm(char **a_str, char *srch, int p_ln)
{
	int n_ind = 0, y_n;

	while (a_str[n_ind] != NULL)
	{
		y_n = cmp_n_2st(a_str[n_ind], srch, p_ln);
		if (y_n == 0)
		{
			return (&a_str[n_ind][p_ln + 1]);
		}
		n_ind++;
	}
	return (NULL);
}

/**
 * hnd_env_c - a function that I created print the
 * envirnment vars if the user entered env command.
 * @st_pt: pointer to the struct that I created.
 * Return: returns 1 or 0.
*/
int hnd_env_c(strugy *st_pt)
{
	int en_ind = 0;

	if (revy_com(st_pt->cm_st, "env"))
	{
		while (st_pt->surr_en[en_ind] != NULL)
		{
			write(1, st_pt->surr_en[en_ind], cnt_len(st_pt->surr_en[en_ind]));
			putchy('\n');
			en_ind++;
		}
		st_pt->is_ext = 0;
		return (1);
	}
	return (0);
}
