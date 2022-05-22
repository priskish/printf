#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes out the string input to stdout
 * @str: the string inputed into the function.
 * 
 * Return: always return 0 on success.
 */
int _puts(char *str)
{
    int i;
    
    for (i = 0; str[i]!= '\0'; i++)
        _putchar(str[i]);
    return (0);
}

/**
 * print_number - prints an int to stdout
 * @num: the digit to ouput.
 *
 * Return: nothing
 */
void print_number(int num, int base, int sign, int caps)
{
	int pos;
	const char digits_hexa[] = "0123456789abcdef";
	
	if (!sign)
		num = (unsigned int)num;	
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num / base != 0)
		print_number((num / base), base, sign, caps);
	pos = num % base;
	if (caps && pos >= 11)
	{
		_putchar(digits_hexa[pos++] - 32);
	}
	else
	{
		_putchar(digits_hexa[pos++]);
	}
}
