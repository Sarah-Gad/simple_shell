#include "myshelly.h"
/**
 * dir_ch - a function that I used to change the current dir.
 * @st_pt: ppinter to the structure that I created.
 * Return: it returns 0 or -1.
*/
int dir_ch(strugy *st_pt)
{
	char *hld, *curr = st_pt->cm_st;
	int rslt = 0;

	rslt = cmp_2st(curr, "cd");
	if (!rslt)
	{
		if (st_pt->t_idn == 1)
			hld = s_envrm(st_pt->surr_en, "HOME", 4);
		else
		{
			curr += 3;
			if (cmp_2st(curr, "-"))
				hld = curr;
			else
			{
				hld = st_pt->o_p;
				write(1, hld, cnt_len(hld));
				putchy('\n');
			}
		}
		if (chdir(hld) == -1)
		{
			printf("%s: %i: cd: Can not change the directory to %s\n",
					st_pt->whch_p, st_pt->vary, hld);
			st_pt->is_ext = 2;
		}
		else
		{
			free(st_pt->o_p);
			st_pt->o_p = dp_t_st(st_pt, &((*(st_pt->c_d))[4]));
			if (!st_pt->o_p)
				ext_now(st_pt);
			upd_cd_v(st_pt);
			st_pt->is_ext = 0;
		}
		return (1);
	}
	return (0);
}

/**
 * upd_cd_v - a function that I used to change the value of the c_d variable.
 * @sc_pt: pointer to the struct that I created.
 * Return: nothing.
*/
void upd_cd_v(strugy *sc_pt)
{
	char st_curr[256];
	char *nwcd = malloc(256);

	if (!nwcd)
		ext_now(sc_pt);
	getcwd(st_curr, 256);
	nwcd[0] = '\0';
	ad_str(nwcd, "PWD=");
	ad_str(nwcd, st_curr);
	free(*(sc_pt->c_d));
	*(sc_pt->c_d) = nwcd;
}

/**
 * gtast_wd - a function that I used to get and store
 * the envinment var of the current working dir.
 * @st_pt_v: pointer to the struct that I created.
 * Return: retuurns pointer to the value of the current working dir.
*/
char **gtast_wd(strugy *st_pt_v)
{
	char *kp_vl = NULL;
	int rsl = 0;
	int x_v = 0;

	while (st_pt_v->surr_en[x_v] != NULL)
	{
		rsl = cmp_n_2st(st_pt_v->surr_en[x_v], "PWD", 3);
		if (rsl == 0)
		{
			kp_vl = dp_t_st(st_pt_v, st_pt_v->surr_en[x_v]);
			st_pt_v->surr_en[x_v] = kp_vl;
			return (&(st_pt_v->surr_en[x_v]));
		}
		x_v++;
	}
	return (NULL);
}
