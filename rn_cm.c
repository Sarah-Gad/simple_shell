#include "myshelly.h"
/**
 * rn_cm_n - a function that  used to run the command the user enters.
 * @s_pt: pointer to the struct that I created.
 * @cnter: pointer to the buff that contains the commanddd.
 * Return: returns an int representing the exit status.
*/
int rn_cm_n(strugy *s_pt, char *cnter)
{
	char **kep;
	char *itrt = s_pt->cm_st;
	int cm_idx = 0;
	int n_f = 0;

	pid_t bby_v = fork();

	if (!bby_v)
	{
		n_f = revy_com(s_pt->cm_st, "pwd");
		if (n_f)
		{
			kep = malloc(16);
			if (!kep)
				exit(255);
			kep[0] = s_pt->cm_st;
			kep[1] = NULL;
		}
		else
		{
			kep = malloc((s_pt->t_idn + 1) * 8);
			if (!kep)
				exit(255);
			while (cm_idx < s_pt->t_idn)
			{
				kep[cm_idx] = itrt;
				itrt += cnt_len(itrt) + 1;
				cm_idx++;
			}
			kep[cm_idx] = NULL;
		}
		execve(cnter, kep, NULL);
		free(kep);
		exit(s_pt->is_ext);
	}
	wait(&(s_pt->is_ext));
	s_pt->is_ext = WEXITSTATUS(s_pt->is_ext);
	return (s_pt->is_ext);
}

/**
 * srch_a_rn - a function that I used to search
 * fot the command in the path andd then use the
 * function rn_cm_n to execute the command.
 * @rst_pt: ointer to the struct that I created.
 * Return: returns a number that represnt the exit state.
*/
int srch_a_rn(strugy *rst_pt)
{
	char *hld_cp = rst_pt->c_p;
	int bgn = 0;
	int a_rslt;

	if (to_ext_sh(rst_pt) || dir_ch(rst_pt))
		return (rst_pt->is_ext);
	if (rst_pt->cm_st[0] == '/')
	{
		a_rslt = access(rst_pt->cm_st, X_OK);
		if (a_rslt == 0)
		{
			if (!hnd_env_c(rst_pt))
				return (rn_cm_n(rst_pt, rst_pt->cm_st));
			return (0);
		}
		printf("%s: %i: %s: This command is not found\n",
				rst_pt->whch_p, rst_pt->vary, rst_pt->cm_st);
	}
	else
	{
		if (!cmp_2st(rst_pt->cm_st, "env") && hnd_env_c(rst_pt))
			return (0);
		while (bgn < rst_pt->hm_pth)
		{
			char ar_in[650] = "";

			ad_str(ar_in, hld_cp);
			ad_str(ar_in, "/");
			ad_str(ar_in, rst_pt->cm_st);
			if (access(ar_in, X_OK) == 0)
				return (rn_cm_n(rst_pt, ar_in));
			hld_cp += cnt_len(hld_cp) + 1;
			bgn++;
		}
		printf("%s: No such file or directory\n", rst_pt->whch_p);
	}
	rst_pt->is_ext = 127;
	return (rst_pt->is_ext);
}

/**
 * sg_hndlr - a function that I used to handle
 * the case when the user press ctrl + C.
 * @is_sgnt: a value that represent the sigint.
 * Return: returns nothing.
*/
void sg_hndlr(int is_sgnt)
{
	if (is_sgnt == SIGINT)
	{
		putchy('\n');
		putchy('$');
		putchy(' ');
	}
}
/**
 * mlt_cm - a function that I used to indicate if there are multiple cms.
 * @st_pt: pointer to the struct that I created.
 * @ind_c: an int to represent the index of cm.
 * @mlt: this ptr is used to indicate if there are multiple cms.
 * Return: returns 0 or 1.
*/
int mlt_cm(strugy *st_pt, int ind_c, int *mlt)
{
	ssize_t rd;

	rd = gt_it(st_pt);
	if (rd == -1)
	{
		ins_ex(st_pt, ind_c);
	}
	if (*mlt)
		st_pt->vary--;
	if (st_pt->cm_st[rd - 1] == '\n')
	{
		st_pt->cm_st[rd - 1] = '\0';
	}
	if (st_pt->cm_st[rd - 1] == ';')
	{
		st_pt->cm_st[rd - 1] = '\0';
		*mlt = 1;
		return (0);
	}
	*mlt = 0;
	return (1);
}
/**
 * gt_it - a function that I used to obtain the command ffrom  strugy_wt_d.
 * @st_pt_c: pointer to the struct that I created.
 * Return: num of chars read or -1.
*/
ssize_t gt_it(strugy *st_pt_c)
{
	ssize_t kpit;
	size_t idx_c = 0;
	int cntner = 20000;
	char *rd_l;

	if (!(&(st_pt_c->cm_st)))
	{
		return (-1);
	}
	rd_l = malloc(cntner + 1);
	if (!rd_l)
	{
		ext_now(st_pt_c);
	}
	if (st_pt_c->cm_st)
	{
		free(st_pt_c->cm_st);
		st_pt_c->cm_st = NULL;
	}
	kpit = read(st_pt_c->wt_d, rd_l + idx_c, 1);
	while (kpit > 0 && idx_c < 40000)
	{
		idx_c++;
		rd_l = memo_chk(st_pt_c, rd_l, &cntner, 40000, idx_c);
		if (rd_l[idx_c - 1] == '\n' || rd_l[idx_c - 1] == ';')
			break;
		kpit = read(st_pt_c->wt_d, rd_l + idx_c, 1);
	}
	if (kpit < 0 || (!kpit && !idx_c))
	{
		free(rd_l);
		return (-1);
	}
	if (kpit > 0)
	{
		rd_l[idx_c] = '\0';
	}
	st_pt_c->cm_st = rd_l;
	return (idx_c);
}
