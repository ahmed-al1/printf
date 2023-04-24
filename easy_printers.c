
Search or jump to…
Pull requests
Issues
Codespaces
Marketplace
Explore
 
@ahmed-al1 
eslamalawy
/
printf
Public
 Watch 2
0Fork your own copy of eslamalawy/printf
 Star 0
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Beta Try the new code view
master
printf/simple_printers.c
@eslamalawy
eslamalawy a
Latest commit 13d8fa3 3 hours ago
 History
 1 contributor
84 lines (76 sloc)  1.37 KB
Raw
 
Blame

#include "mfile.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int su = 0;

	while (start <= stop)
	{
		if (start != except)
			su += _putchar(*start);
		start++;
	}
	return (su);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int length, su = 0;
	char *str = va_arg(ap, char *);
	(void)params;
				
	switch ((int)(!*str))
			case 1:
				*str = NULL_STRING;
	if (str)
	{
		
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			su += _putchar(*str);
	}
	return (su);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int dew, index;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	dew = 0;
	index = 0;
	while (a[dew])
	{
		if ((a[dew] >= 'A' && a[dew] <= 'Z')
		    || (a[dew] >= 'a' && a[dew] <= 'z'))
		{
			index = a[dew] - 65;
			count += _putchar(array[index]);
		}
		else
			count += _putchar(a[dew]);
		dew++;
	}
	return (count);
}
