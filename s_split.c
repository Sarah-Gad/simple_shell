#include "myshelly.h"
/**
 * s_split - a function that I used to split a string.
 * @delchrs: pointer to the delimiter used to split the string.
 * @stsplt: pointer to the string that I want to split
 * Return: it returns pointer to the splited string.
*/
char *s_split(char *stsplt, const char *delchrs)
{
	char *spltd;
	static char *kptrk;

	if (stsplt)
		kptrk = stsplt;
	else if (kptrk == NULL)
		return (NULL);
	spltd = kptrk;
	while (*kptrk != '\0')
	{
		if (*delchrs == *kptrk)
		{
			*kptrk = '\0';
			kptrk++;
			return (spltd);
		}
		kptrk++;
	}
	kptrk = NULL;
	return (spltd);
}

/**
 * sp_a_cn - a function that I used to call the s_split
 * function and count the number of splitted strings.
 * @stsplt: this is a pointer to the stirng that needs to be splitted.
 * @delchr: pointer to the delimiter.
 * Return: returns the num of strings that were
 * generated from the string to be splitted.
*/
int sp_a_cn(char *stsplt, char *delchr)
{
	char *st_kp = NULL;
	int trkn = 0;

	st_kp = s_split(stsplt, delchr);

	for (trkn = 0; st_kp != NULL; trkn++)
	{
		st_kp = s_split(NULL, delchr);
	}
	return (trkn);
}
