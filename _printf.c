#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Prints a single character to stdout
 * @args: The va_list containing the character to print
 * @count: A pointer to the character count
 *
 * Return: void
 */
void print_char(va_list args, int *count)
{
    char c = va_arg(args, int);
    putchar(c);
    (*count)++;
}

/**
 * print_string - Prints a string to stdout
 * @args: The va_list containing the string to print
 * @count: A pointer to the character count
 *
 * Return: void
 */
void print_string(va_list args, int *count)
{
    char *s = va_arg(args, char*);
    fputs(s, stdout);
    (*count) += strlen(s);
}

/**
 * _printf - Prints a formatted string to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    /* Print a single character */
                    print_char(args, &count);
                    break;
                case 's':
                    /* Print a string */
                    print_string(args, &count);
                    break;
                case '%':
                    /* Print a literal % character */
                    putchar('%');
                    count++;
                    break;
                default:
                    /* Unsupported conversion specifier */
                    va_end(args);
                    return (-1);
            }
        }
        else
        {
            /* Print a literal character */
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
