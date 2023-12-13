#include "myshelly.h"
/**
 * set_strc_vars - a function that I used to the values of the struct members.
 * @st_pt_s: pointer to the struct that I created.
 * @s_ac: num of arguments.
 * @s_av: poimter to the arguments.
 * @vs_en: envirnment vars.
 * Return: noooothing.
*/
void set_strc_vars(strugy *st_pt_s, int s_ac, char **s_av, char **vs_en)
{
	st_pt_s->c_d = NULL;
	st_pt_s->o_p = NULL;
	st_pt_s->cm_st = NULL;
	st_pt_s->surr_en = vs_en;
	st_pt_s->c_p = dp_t_st(st_pt_s, s_envrm(vs_en, "PATH", 4));
	st_pt_s->c_d = gtast_wd(st_pt_s);
	if (st_pt_s->c_d)
		st_pt_s->o_p = dp_t_st(st_pt_s, &((*st_pt_s->c_d)[4]));
	st_pt_s->whch_p = s_av[0];
	st_pt_s->is_ext = 0;
	st_pt_s->wt_d = 0;
	st_pt_s->vary = 0;
	st_pt_s->p_id = (int)getpid();
	st_pt_s->hm_pth = sp_a_cn(st_pt_s->c_p, ":");
	if (s_ac > 1)
	{
		st_pt_s->wt_d = open(s_av[1], O_RDONLY);
		if (st_pt_s->wt_d == -1)
		{
			printf("%s: 0: It can not be opened %s\n", s_av[0], s_av[1]);
			exit(2);
		}
	}
}
/**
 * main - a function to start the program.
 * @sh_ac: the number or arguments.
 * @sh_av: pointer to the arguments.
 * @sh_en: the envirnment varss.
 * Return: 0 on successsss.
*/
int main(int sh_ac, char **sh_av, char **sh_en)
{
	int is_d = 0;
	int y_on = 1;
	strugy st_pt;

	set_strc_vars(&st_pt, sh_ac, sh_av, sh_en);
	while (1)
	{
		if (isatty(STDIN_FILENO) && y_on && !st_pt.wt_d)
		{
			putchy('$');
			putchy(' ');
		}
		signal(SIGINT, sg_hndlr);
		st_pt.vary++;
		y_on = mlt_cm(&st_pt, y_on, &is_d);
		if (prcs_in(&st_pt))
			continue;
		st_pt.t_idn = sp_a_cn(st_pt.cm_st, " ");
		if (srch_a_rn(&st_pt) == 255)
			ext_now(&st_pt);
	}
	return (0);
}
