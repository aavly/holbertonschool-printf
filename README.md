##_printf()
 
#Holberton Week 8: printf
#Custom _printf function

What is _printf ?
'''
Imagine you're writing a message on a piece of paper, and you want to tell a computer exactly what to write. 
The _printf function is like a tool that lets you tell the computer what to print out on the screen.
'''

#Using _printf
'''
_prinf("formatted text");
'''
"formatted text" is the message you want to print. 
The message is always inside quotes (" "). 

example
'''
_printf("Hello World");
'''

output
'''
Hello World
''' 

#Specifier option

You can also pass and define the format of variables into _printf by using specifier options.

These four codes listed below are called specifiers and 
they tell _printf the format of data type of variables that being passed into the _printf


%c 	character
%s	string 
%d	integer 
%i 	signed integer


'''
1. using _printf with specifier

example
'''
char *a = "Hello";  /* where a is the variable to be passed into printf()
_printf("%s", a)
'''

The code inside the quote (%s) is specifier of string type and variable that that hold the value is char *a

output
'''
Hello
'''

2. using _printf with multiple specifiers

example
'''
char *a = "Hello";
char *b = "World";

_printf("%s %s, a, b);
'''

output
'''
Hello World
'''

3. using _printf with multiple specifiers of different data types

example
'''
int i = 1;
int j = 2; /* int i and j are both integer * /

char *a = "Hello";
char *b = "World"; /* char *a and *b are both string */

char c = '!'; /* char c is character a

printf("%d %s\n", i, a);
printf("%d %s%c", j, b, c); 
'''

output
'''
1 Hello
2 World!
'''

4. using _printf with multiple specifier and formatted text

example
'''
int j = 2;

char *b = "World";

char c = '!'; 

printf("1. Hello\n%d %s%c", j, b, c);
'''

output
'''
1. Hello
2. World!
'''

# Summary

_printf is a way to tell the computer what you want to see printed on the screen, whether it words or numbers. 
