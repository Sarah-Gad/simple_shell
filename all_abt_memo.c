#include "myshelly.h"
/**
 * memo_res - a fucntion that I used to change the size of the memo block.
 * @memo_pt: the memory block.
 * @curr_s: the current size of the memo.
 * @nw_s: the new size of the memo
 * Return: nothing
*/
void *memo_res(void *memo_pt, unsigned int curr_s, unsigned int nw_s)
{
	void *n_memo;
	int m_ind;

	if (curr_s == nw_s)
		return (memo_pt);
	if (memo_pt == NULL)
	{
		memo_pt = malloc(nw_s);
		return (memo_pt);
	}
	if (nw_s == 0)
	{
		free(memo_pt);
		return (NULL);
	}
	n_memo = malloc(nw_s);
	if (n_memo == NULL)
	{
		free(n_memo);
		return (NULL);
	}
	for (m_ind = 0; (unsigned int)m_ind < (curr_s < nw_s ? curr_s : nw_s);
			m_ind++)
		((char *)n_memo)[m_ind] = ((char *)memo_pt)[m_ind];
	free(memo_pt);
	return (n_memo);
}

/**
 * memo_chk - a function that I uswed check for a
 * certain condition to change the sizzze of the memo.
 * @sy_pt: pointer to the struct I created.
 * @memo: the memory block.
 * @s_memo: the size of the memory.
 * @up: the size to increase.
 * @cond: the condition to check for it.
 * Return: it returns pointer to the new memo.
*/
char *memo_chk(strugy *sy_pt, char *memo, int *s_memo, int up, int cond)
{
	if (*s_memo <= cond)
	{
		memo = memo_res(memo, *s_memo, *s_memo + up);
		if (!memo)
			ext_now(sy_pt);
		*s_memo += up;
	}
	return (memo);
}
