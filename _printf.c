#include "main.h"

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);

/**
 * _printf - function to process the argument based format
 *
 * @format : char array indicating the format of the argument
 * Return: integer value of the total of char in argument
 */

int _printf(const char *format, ...)
{
	int count; /* no. of characters to be return */
	/* int loop_count;  counter for while loop */
	/*int length; length of string char *s */
	char *s;
	int i;
	va_list printList;

	i = 0; /*counter for *format */
	count = 0; /* initalize count */

	va_start(printList, format); /* intializing printList with last fixed argument being format */

	/*s = va_arg(printList, char *);*/
	

	while (format && format[i]) /* if format and format[i] are valid */
	{	
		/*if (format[i] == '%' && format[i+1] != NULL )  % operand found and format[i+1] is not NULL*/
		/*{ */ 	
			/*i = 1;   increment i */

			/*if (format[i] == 'c' || format[i] == 's')  if 'c' or 's' found in format[i] */
			switch (format[i])
			{	case ('%'):	/* % operand detected */
						i++; /* increment i counter to read next array in format */
						break;				
						
				case ('c'): 	/* single char detected */
						s[0] = va_arg(printList, int);
						_putchar(s[0]); /* obtained the argument value */
						/*_putchar('\n');*/
						count++;
						break;

				case ('s'):	/* string is detected */
						s = va_arg(printList, char *); /* obtained argument value */
						if (!s)
							s = "(nil)";
						/*printf("%s", strrr);*/
						while (*s) /* s not empty */
						{	
							_putchar(*s);
							s++; /* go to next array in s */
							count++;
						}
						break;

				default : 	/* none detected thus just print the value of format[i] */
						_putchar(format[i]);
						break;

			} /* end swutch case */
			
			i++;	
	} /* end while */

	va_end(printList); /* end va variable PrintList */
	return count; /* return count value */
} /*end _printf */


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
 * _puts - display string by input
 * @str  : string pointer str
 *
 * Return: none
 *
 * Example : _puts("Hello World")
 */

void _puts(char *str)
{
        int length, count;

        length = _strlen(str);

        for (count = 0; count < length; count++)
        {
                _putchar(str[count]);
        }
        _putchar('\n');
}

/**
 * _strlen - check the length of string
 * function declaration performed in main.h
 * @s  : char pointer s
 *
 * Return: integer value of length of *s
 *
 * Example : _strlen(aa)
 */

int _strlen(char *s)
{
        int i = 0;

        while (s[i] != '\0')
        {
                i++;
        }
        return (i);
}
