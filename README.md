# _printf()
 
## Holberton Week 8: printf
## Custom _printf function

**What is _printf ?**

Imagine you're writing a message on a piece of paper, and you want to tell a computer exactly what to write. 
The _printf function is like a tool that lets you tell the computer what to print out on the screen.


## Using _printf

```
_prinf("formatted text");
```

**"formatted text" is the message you want to print.**<br>
**The message is always inside quotes (" ").**<br>

example
```
_printf("Hello World");
```

output
```bash
Hello World
```

## Specifier option

**You can also pass and define the data type of variables into _printf by using specifier options.**<br>

Four codes listed below are called specifiers and 
they tell _printf the data type of variables that being passed in.


**%c	character**<br>
**%s	string**<br>
**%d	integer**<br>
**%i	  signed integer**<br>

### 1. using _printf with specifier

example
```
char *a = "Hello";  /* where a is the variable to be passed into printf()
_printf("%s", a)
```

**The code inside the quote (%s) is specifier of string type and a is variable that that hold the value**

output
```bash
Hello
```

### 2. using _printf with multiple specifiers

example
```
char *a = "Hello";
char *b = "World";

_printf("%s %s, a, b);
```

output
```bash
Hello World
```

### 3. using _printf with multiple specifiers of different data types

example
```
int i = 1;
int j = 2; /* int i and j are both integer */

char *a = "Hello";
char *b = "World"; /* char *a and *b are both string */

char c = '!'; /* char c is character */

_printf("%d %s\n", i, a);
_printf("%d %s%c", j, b, c); 
```

output
```bash
1 Hello
2 World!
```

### 4. using _printf with multiple specifier and formatted text

example
```
int j = 2;

char *b = "World";

char c = '!'; 

_printf("1. Hello\n%d %s%c", j, b, c);
```

output
```bash
1. Hello
2. World!
```

## Summary

_printf is a way to tell the computer what you want to see printed on the screen. 
