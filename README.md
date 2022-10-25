# alx printf project

## basic knowledge or requirements
- loops in c
- knowledge of printf format specifiers
- variadic functions and how they are used
- switch in c

## files you may want to implement (we will figure out)
- the _printf.c file

## files you may want to implement (we will figure out)
- using _putchar (from _putchar.c) to print a character as we go

## implementation steps
1. character.c file
- first of all prepare the test files. In this case it is the `main.c` file, in my case I have included it in the _printf.c file
- we then test with output characters first
    - here we use a state variable that determine if a character should be printed or not
    - the output should be: 
        ```
        Print a character: G. Done!
        Print a string: Hello World. Done!
        Print a positive integer: . Done!
        Print a negative integer: . Done!
        Print a (zero) integer: . Done!
        Print a hexademical: . Done!
        Print a zero hexademical: . Done!
        Print a pointer: 0x. Done! 
        ```
2. string.c file: implementing character being printed out
3. 