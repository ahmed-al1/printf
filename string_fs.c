#include "mfile.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int dam = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		dam = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			dam = dam * 10 + (*p++ - '0');
	}
	params->precision = dam;
	return (p);
}

