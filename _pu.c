#include "mfile.h"

/**
 * _puts - prints sm string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *sm = str;

	while (*str)
		_putchar(*str++);
	return (str - sm);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int sam;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || sam >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, sam);
		sam = 0;
	}
	if (c != BUF_FLUSH)
		buf[sam++] = c;
	return (1);
}

