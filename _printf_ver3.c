#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - function that produces output according to a format
 *
 * @format : string passed into this function
 * Return : integer value of total number of chars
 */

int _printf(const char *format, ...)
{
	int flag = 0, count = 0;
	va_list args;
	char c;
	char *s;

	int i;
	/* unsigned int i, temp_num;  unsigned int to acoomodate INT_MIN */
	/* int digit = 0; */

	int temp_num, digit = 0;

	char *num_array;
	int j;

	va_start(args, format);

	if (format == NULL)
	{	/*c = ' '; */
		/* write(1, &c, 1); */
		return (0); /* terminate with count = 0 */
	}

	while (format != NULL && format[flag] != '\0')
	{
		/* make sure the format[] after % detected is not empty */
		if ((format[flag] == '%') && (format[flag + 1]))
		{
			flag++;
			switch (format[flag])
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char*);
					if (s == NULL)
					{
						s = "(null)"; /* not needed but leave it */
					}
					while (*s != '\0')
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				case 'i':
				case 'd':
					i = va_arg(args, int);
					temp_num = i;
					if (i == 0)
					{
						write(1, "0", 1);
						count++;
						break;
					}
					 /* INT_MIN detected */
					if ((i < 0) && (i == INT_MIN))
					{
					/* assign INT_MIN value to write to prevent int overflow */
						write(1, "-2147483648", 11);
						break;
					}

					if ((i < 0) && (i != INT_MIN))
					{
						write(1, "-", 1);
						count++;
					/* if (i == -2147483648)  i = INT_MIN) */
					/* printf("%d",i); debugging use only */
					/* temp_num = i;  */

						temp_num = -temp_num;  /*normalized the value */
					/* temp_num = temp_num; for debugging use :*/
					/*  int range between 2,147,483,647 and -2,147,483,648 */
					}
					
					temp_num = i;
					while (temp_num != 0)
					{
						temp_num = temp_num / 10;
						digit++;
					}
					
					num_array = malloc(digit * sizeof(char));
					if (num_array == NULL)
					{
						return (-1);
					}
					
					temp_num = i < 0 ? -i : i;
					j = 0;
					while (temp_num != 0)
					{
						/* num_array[j] = (char)(temp_num % 10 + '0'); */
						num_array[j] = (char)((temp_num % 10) + '0');
						j++;
						temp_num /= 10;
					}
					
					for (j = digit - 1; j >= 0; j--)
					{	
						/*if ((i == INT_MIN) && (j == 0))  i == INT_MIN and reading last digit which is 7 due to overflow of integer */
						/* { */
						/*	write(1, "8", 1);  7 with 8 as INT_MIN is -2,147,483,648 */
						/*} */
						
						write(1, &num_array[j], 1);
						count++;
					}
					
					free(num_array);
					break;

				default:
					write(1, "%", 1);
					write(1, &format[flag], 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, &format[flag], 1);
			count++;
		}
		flag++;
	}
	va_end(args);
	return (count);
}
