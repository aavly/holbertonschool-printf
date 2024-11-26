#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int write_function(char *s, int size, int t_count);

/**
 * _printf - function that produces output according to a format
 *
 * @format: string passed into this function
 * Return: integer value of total number of chars
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
	{
		return (0); /* terminate with count = 0 */
	}
	while (format != NULL && format[flag] != '\0')
	{
		/* make sure the format[] after % detected is not empty */
		if ((format[flag] == '%') && (format[flag + 1]))
		/* if (format[flag] == '%') */
		{
			flag++;
			switch (format[flag])
			{
				case 'c':
					c = (char)va_arg(args, int);
					/*write(1, &c, 1); */
					/*count++; */
					count = write_function(&c, 1, count);
					break;
				case 's':
					s = va_arg(args, char*);
					if (s == NULL)
					{
						s = "(null)"; /* not needed but leave it */
					}
					while (*s != '\0')
					{
						/* write(1, s, 1); */
						/* count++; */
						count = write_function(s, 1, count);
						s++;
					}
					break;
				case '%':
					/* write(1, "%", 1); */
					/* count++; */
					count = write_function("%", 1, count);
					break;
				case 'i':
				case 'd':
					i = va_arg(args, int);
					temp_num = i;
					if (i == 0)
					{
						/* write(1, "0", 1); */
						/* count++; */
						count = write_function("0", 1, count);
						break;
					}
					 /* INT_MIN detected */
					if ((i < 0) && (i == INT_MIN))
					{
					/* assign INT_MIN value to write to prevent int overflow */
						/* 11 bytes in INT_MIN */
						count = write_function("-2147483648", 11, count) + 10;
						break;
					}

					if ((i < 0) && (i != INT_MIN))
					{
						/* write(1, "-", 1); */
						/* count++;	*/
						count = write_function("-", 1, count);
					/* printf("%d",i); debugging use only */
					/* temp_num = i;  */

					temp_num = -temp_num;  /*normalized the value */

						/* temp_num = temp_num; for debugging use :*/
					/*  int range between 2,147,483,647 and -2,147,483,648 */
					}

					/*temp_num = i;  remove by mao */
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
						num_array[j] = (char)(temp_num % 10 + '0');
						/* num_array[j] = (char)((temp_num % 10) + '0'); */
						/*printf("Testing : %c \n", num_array[j]);  for debugging */
						j++;
						temp_num /= 10;
					}

					for (j = digit - 1; j >= 0; j--)
					/*for (j = digit; j > 0; j--) */
					{
						/*if ((i == INT_MIN) && (j == 0))  i == INT_MIN and reading last digit */
						/* which is 7 due to overflow of integer */
						/* { */
						/*	write(1, "8", 1);  7 with 8 as INT_MIN is -2,147,483,648 */
						/*} */
						/*write(1, &num_array[j], 1);*/
						/*count++;*/
						count = write_function(&num_array[j], 1, count);
					}
					free(num_array);
					break;

				default:
					/*write(1, "%", 1); */
					/*write(1, &format[flag], 1); */
					/*count += 2; */
					count = write_function("%", 1, count);

					/*format is const char thus can't use write_function */
					write(1, &format[flag], 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, &format[flag], 1);
			count++;
			/*count = write_function(&format[flag], 1, count); */
		}
		flag++;
	}
	va_end(args);
	return (count);
}

/**
 * write_function - write function for character buffer
 *
 * @s : char array that is the buffer
 * @size : size of the s
 * @tcount : characters that been counted
 * Return: incremented tcount by 1
 */

int write_function(char *s, int size, int tcount)
{
	write(1, s, size);
	return (tcount++); /* increment t_count */
}
