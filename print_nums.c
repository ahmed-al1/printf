#include "mfile.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int ne = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (ne)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (ne)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int nu = 0, ne, ne2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	ne = ne2 = (!params->unsign && *str == '-');
	if (ne && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		ne = 0;
	if ((params->plus_flag && !ne2) ||
		(!params->plus_flag && params->space_flag && !ne2))
		i++;
	if (ne && pad_char == '0')
		nu += _putchar('-');
	if (params->plus_flag && !ne2 && pad_char == '0' && !params->unsign)
		nu += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ne2 &&
		!params->unsign && params->zero_flag)
		nu += _putchar(' ');
	while (i++ < params->width)
		nu += _putchar(pad_char);
	if (ne && pad_char == ' ')
		nu += _putchar('-');
	if (params->plus_flag && !ne2 && pad_char == ' ' && !params->unsign)
		nu += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ne2 &&
		!params->unsign && !params->zero_flag)
		nu += _putchar(' ');
	nu += _puts(str);
	return (nu);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int nu = 0, ne, ne2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	ne = ne2 = (!params->unsign && *str == '-');
	if (ne && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		ne = 0;

	if (params->plus_flag && !ne2 && !params->unsign)
		nu += _putchar('+'), i++;
	else if (params->space_flag && !ne2 && !params->unsign)
		nu += _putchar(' '), i++;
	nu += _puts(str);
	while (i++ < params->width)
		nu += _putchar(pad_char);
	return (nu);
}
