#include <stdio.h>
#include <stdarg.h>

// this is an analogue to vprintf function provided
// in starg.h
// @state: kind of like return value
// 0: regular
// 1:escape
void _vprintf(const char *format, va_list arguments)
{
    int state = 0;

    while (*format)
    {   // run through all chars in *format
        // if state is 0,and char is a % sign
        if (state == 0)
        {
            if (*format == '%')
            {
                // we enter escape state (do not print it out)
                state = 1;
            }
            else
            {
                // print it out
                putchar(*format);
            }
        }
        *format++;
    }
}

// the function that we are implementing is _printf
void _printf(const char *format, ...)
{

    va_list arguments;
    va_start(arguments, format);

    _vprintf(format, arguments);

    va_end(arguments);
}

int main()
{

    void *pointer_to_main = (void *)main;

    _printf("Print a character: %c. Done!\n", 'G');
    _printf("Print a string: %s. Done!\n", "Hello World");
    _printf("Print a postive integer: %d. Done!\n", 10);
    _printf("Print a negative integer: %d. Done!\n", -10);
    _printf("Print a (zero) integer: %d. Done!\n", 0);
    _printf("Print a hexademical: %x. Done!\n", '0');
    _printf("Print a zero hexademical: %x. Done!\n", '0');
    _printf("Print a pointer: %p. Done!\n", pointer_to_main);
    return 0;
}