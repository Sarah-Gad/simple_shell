#ifndef MYSHELLY_H
#define MYSHELLY_H

#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct struct_vars - a struct I used to
 * manage different aspects of the command.
 * @t_idn: token identifier.
 * @is_ext: the status of exit.
 * @p_id: the id of the process.
 * @wt_d: the file descriptor.
 * @hm_pth: num of paths.
 * @vary: the arg.
 * @cm_st: the command the user enters.
 * @whch_p: the program to be executed.
 * @c_p: the current path.
 * @o_p: the pld path.
 * @c_d: the current dir.
 * @surr_en: the environment vars.
*/
typedef struct struct_vars
{
	int t_idn;
	int is_ext;
	int p_id;
	int wt_d;
	int hm_pth;
	int vary;
	char *cm_st;
	char *whch_p;
	char *c_p;
	char *o_p;
	char **c_d;
	char **surr_en;
} strugy;

void int_t_st(char *o_st, int inttcon);
int st_t_int(char *stinp);
int putchy(char ctp);
char *s_split(char *stsplt, const char *delchrs);
int cmp_n_2st(const char *st_f1, const char *st_s2, size_t sp_fn);
char *dp_t_st(strugy *stct_ptr, char *in_st);
int cmp_2st(char *pf_st, char *ps_st);
char *fndchr(char *pt_s_st, char tg_ch);
int cnt_len(char *pt_lst);
char *ad_str(char *orgin, char *to_ad);
char *ad_n_str(char *orgn, char *t_add, int num_add);
void *memo_res(void *memo_pt, unsigned int curr_s, unsigned int nw_s);
char *memo_chk(strugy *sy_pt, char *memo, int *s_memo, int up, int cond);
int to_ext_sh(strugy *s_pt);
void ext_now(strugy *st_pt);
int dir_ch(strugy *st_pt);
char *s_envrm(char **a_str, char *srch, int p_ln);
int hnd_env_c(strugy *st_pt);
int rn_cm_n(strugy *s_pt, char *cnter);
void upd_cd_v(strugy *sc_pt);
int revy_com(char *f1_st, char *s2_st);
void sg_hndlr(int is_sgnt);
int mlt_cm(strugy *st_pt, int ind_c, int *mlt);
ssize_t gt_it(strugy *st_pt_c);
void ins_ex(strugy *st_pt, int cndt);
int sp_a_cn(char *stsplt, char *delchr);
int srch_a_rn(strugy *rst_pt);
void set_strc_vars(strugy *st_pt_s, int s_ac, char **s_av, char **vs_en);
char **gtast_wd(strugy *st_pt_v);
void dt_case(char **c_hlder, strugy *st_pt);
void rm_extr_sp(char **c_hldr, strugy *st_pt_c);
void sym_inp_hnd(char *nw_inp, char **pl_sym, strugy *s_pt);
int prcs_in(strugy *stv_pt);
char *cp_sh_st(char *plc, char *s_st);

#endif
