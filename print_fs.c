#include "mfile.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pd = 1, sm = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sm += _putchar(ch);
	while (pd++ < params->width)
		sm += _putchar(pad_char);
	if (!params->minus_flag)
		sm += _putchar(ch);
	return (sm);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pd = 0, sm = 0, i = 0, sam;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	sam = pd = _strlen(str);
	if (params->precision < pd)
		sam = pd = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				sm += _putchar(*str++);
		else
			sm += _puts(str);
	}
	while (sam++ < params->width)
		sm += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				sm += _putchar(*str++);
		else
			sm += _puts(str);
	}
	return (sm);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sm = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sm += _putchar('\\');
			sm += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sm += _putchar('0');
			sm += _puts(hex);
		}
		else
		{
			sm += _putchar(*str);
		}
	}
	return (sm);
}

