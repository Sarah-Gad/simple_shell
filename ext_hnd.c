#include "myshelly.h"
/**
 * to_ext_sh - a function that I used to exit the
 * shell if the user enters exit command.
 * @s_pt: pointer to the struct that I created.
 * Return: -1 or 0.
*/
int to_ext_sh(strugy *s_pt)
{
	int cm_len;
	int rslt = 0;

	rslt = cmp_2st(s_pt->cm_st, "exit");
	if (!rslt)
	{
		if (s_pt->t_idn > 1)
		{
			cm_len = cnt_len(s_pt->cm_st) + 1;
			s_pt->is_ext = st_t_int(s_pt->cm_st + cm_len);
		}
		if (st_t_int(s_pt->cm_st + cm_len) != -1)
		{
			if (s_pt->c_p)
			{
				free(s_pt->c_p);
			}
			if (s_pt->o_p)
			{
				free(s_pt->o_p);
			}
			if (s_pt->cm_st)
			{
				free(s_pt->cm_st);
			}
			if (s_pt->c_d)
			{
				free(*(s_pt->c_d));
			}
			exit(s_pt->is_ext);
		}
		printf("%s: %i: This is illegal number: %s\n",
				s_pt->whch_p, s_pt->vary, s_pt->cm_st + cm_len);
		s_pt->is_ext = 2;
		return (1);
	}
	return (0);
}

/**
 * ext_now - a function that I created to exit the prog with no memo leaks.
 * @st_pt: pointet to the structure.
 * Return: it doesn't return anything.
*/
void ext_now(strugy *st_pt)
{
	if (st_pt->c_p)
	{
		free(st_pt->c_p);
	}
	if (st_pt->o_p)
	{
		free(st_pt->o_p);
	}
	if (st_pt->cm_st)
	{
		free(st_pt->cm_st);
	}
	if (st_pt->c_d)
	{
		free(*(st_pt->c_d));
	}
	exit(255);
}
/**
 * ins_ex - a function that I used to close st_pt->wt_d and free memo.
 * @st_pt: pointer to the struct that I created.
 * @cndt: an int that represents certain context.
 * Return: doesn't return anything.
*/
void ins_ex(strugy *st_pt, int cndt)
{
	if (isatty(STDIN_FILENO) && cndt && !st_pt->wt_d)
		putchy('\n');
	close(st_pt->wt_d);
	if (st_pt->cm_st)
	{
		free(st_pt->cm_st);
	}
	if (st_pt->c_p)
	{
		free(st_pt->c_p);
	}
	if (st_pt->c_d)
	{
		free(*(st_pt->c_d));
	}
	if (st_pt->o_p)
	{
		free(st_pt->o_p);
	}
	exit(st_pt->is_ext);
}
