#include "myshelly.h"
/**
 * dt_case - a function that I used to control
 * the case when the user enters a dot.
 * @c_hlder: the pointer that points to the command
 * @st_pt: pointer to the struct that I created.
 * Return: noothing!
*/
void dt_case(char **c_hlder, strugy *st_pt)
{
	int h_ln, dx = 0;
	char *st_hl, *c_it = *c_hlder;

	if (c_it[0] == '.')
	{
		st_hl = malloc(700);
		if (!st_hl)
		{
			free(c_hlder);
			ext_now(st_pt);
		}
		st_hl[0] = '\0';
		ad_str(st_hl, &((*(st_pt->c_d))[4]));
		h_ln = cnt_len(st_hl);
		while (c_it[dx] != ' ' && c_it[dx])
		{
			if (c_it[dx] == '.' && c_it[dx + 1] == '.')
			{
				for (; h_ln > 0 && st_hl[h_ln - 1] != '/'; h_ln--)
					st_hl[h_ln - 1] = '\0';
				st_hl[(h_ln--) - 1] = '\0';
				dx++;
			}
			else if (c_it[dx] != '/' && c_it[dx] != '.')
			{
				st_hl[h_ln++] = '/';
				while (c_it[dx] && c_it[dx] != '/' && c_it[dx] != ' ')
					st_hl[h_ln++] = c_it[dx++];
				dx--;
			}
			dx++;
		}
		st_hl[h_ln] = '\0';
		if (access(st_hl, X_OK) == 0)
		{
			ad_str(st_hl, &c_it[dx]);
			free(*c_hlder);
			*c_hlder = st_hl;
		}
	}
}
/**
 * rm_extr_sp - a function that I used to remove
 * any extra space from the command input.
 * @c_hldr: pointer to the command.
 * @st_pt_c: pointer to the struct that I created.
 * Return: it does nooot return anythiiing.
*/
void rm_extr_sp(char **c_hldr, strugy *st_pt_c)
{
	char *c_it = NULL;
	int lp_ct = 0;
	int b_dx = 0;
	int h_ln;

	h_ln = cnt_len(*c_hldr);
	c_it = malloc(h_ln + 1);
	if (c_it == NULL)
	{
		free(*c_hldr);
		ext_now(st_pt_c);
	}
	while ((*c_hldr)[lp_ct] && (*c_hldr)[lp_ct] == ' ')
		lp_ct++;
	while ((*c_hldr)[lp_ct])
	{
		if ((*c_hldr)[lp_ct] == ' ')
		{
			c_it[b_dx] = ' ';
			b_dx++;
			while ((*c_hldr)[lp_ct] == ' ')
				lp_ct++;
		}
		else
		{
			c_it[b_dx] = (*c_hldr)[lp_ct];
			lp_ct++;
			b_dx++;
		}
	}
	if (b_dx && c_it[b_dx - 1] == ' ')
		b_dx--;
	c_it[b_dx] = '\0';
	free(*c_hldr);
	*c_hldr = c_it;
}
/**
 * sym_inp_hnd - a function that I used to deal with special symbols.
 * @nw_inp: pointer that points to the modified command.
 * @pl_sym: pointet to the place of the symbol.
 * @s_pt: pointer to the structt.
 * Return: noothing!!
*/
void sym_inp_hnd(char *nw_inp, char **pl_sym, strugy *s_pt)
{
	char *en_vrs, sv_it[70] = "";
	int lp_ct = 0;

	(*pl_sym)++;
	if ((*pl_sym)[0] == '?' || (*pl_sym)[0] == '$')
	{
		if ((*pl_sym)[0] == '?')
			int_t_st(sv_it, s_pt->is_ext);
		else
			int_t_st(sv_it, s_pt->p_id);
		ad_str(nw_inp, sv_it);
		(*pl_sym)++;
		lp_ct = 0;
	}
	else
	{
		while ((*pl_sym)[lp_ct] && (*pl_sym)[lp_ct] != ' ' &&
				(*pl_sym)[lp_ct] != '#' &&
				(*pl_sym)[lp_ct] != '$' && (*pl_sym)[lp_ct] != '/')
			lp_ct++;
		if (lp_ct)
		{
			size_t nw_vr_sz = lp_ct + 1;
			char *nw_vr = malloc(nw_vr_sz);

			if (nw_vr == NULL)
			{
				ext_now(s_pt);
			}
			cp_sh_st(nw_vr, *pl_sym);
			nw_vr[lp_ct] = '\0';

			en_vrs = s_envrm(s_pt->surr_en, *pl_sym, lp_ct);
			if (en_vrs)
				ad_str(nw_inp, en_vrs);
			*pl_sym += lp_ct;
		}
		else
			ad_str(nw_inp, "$");
	}
}
/**
 * prcs_in - a function that I used to process the command input.
 * @stv_pt: pointer to the structt.
 * Return: it returnss 1 orr 0.
*/
int prcs_in(strugy *stv_pt)
{
	char *kp_it, *y_n, *nw_s;
	int ln_kp, ln_nw;
	char *rsl = fndchr(stv_pt->cm_st, '#');
	int cntn = 20000;

	if (rsl && ((rsl != stv_pt->cm_st && *(rsl - 1) == ' ')
				|| rsl == stv_pt->cm_st))
		*rsl = '\0';
	kp_it = malloc(20000 * sizeof(char));
	if (!kp_it)
		ext_now(stv_pt);
	y_n = fndchr(stv_pt->cm_st, '$');
	nw_s = stv_pt->cm_st;
	kp_it[0] = '\0';
	ln_kp = cnt_len(kp_it);
	while (y_n != NULL)
	{
		kp_it = memo_chk(stv_pt, kp_it, &cntn, 4000, ln_kp + y_n - nw_s);
		ad_n_str(kp_it, nw_s, (y_n - nw_s));
		sym_inp_hnd(kp_it, &y_n, stv_pt);
		nw_s = y_n;
		y_n = fndchr(nw_s, '$');
	}
	ln_kp = cnt_len(kp_it);
	ln_nw = cnt_len(nw_s);
	kp_it = memo_chk(stv_pt, kp_it, &cntn, 500, ln_kp + ln_nw);
	ad_str(kp_it, nw_s);
	rm_extr_sp(&kp_it, stv_pt);
	dt_case(&kp_it, stv_pt);
	free(stv_pt->cm_st);
	stv_pt->cm_st = kp_it;
	if (kp_it[0] == '\0')
		return (1);
	else
		return (0);
}
