#include "main.h"
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// this is an analogue to vprintf function provided
// in starg.h
// @state: kind of like return value
// 0: regular
// 1: escape
void _vprintf(const char *format, va_list arguments)
{
    int state = 0;

    while (*format)
    { // run through all chars in *format
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
                _putchar(*format);
            }
        }
        // upto now, when the loop finds a %, it skips over it (escapes)
        // then prints the next character
        else if (state == 1)
        {
            switch (*format)
            {
            // first case is printing a char
            // using %c
            case 'c':
            {
                char ch = (char)va_arg(arguments, int);
                _putchar(ch);
                break;
            }

            // next we do strings
            // using %s
            case 's': // ;
            {
                // note the semicolon
                // I have 
                // found this while debugging
                // https://www.educative.io/answers/resolving-the-a-label-can-only-be-part-of-a-statement-error
                const char *s = (char *)va_arg(arguments, const char *);
                // while there is something in the string
                while (*s)
                {
                    // print and increment
                    _putchar(*s++);
                }
                break;
            }
            case 'd':
            {
                int n = va_arg(arguments, int);
                convert(n, 10);
                _putchar(n);
                break;
            }
            case 'x':
            {
                int n = va_arg(arguments, int);
                convert(n, 16);
                _putchar(n);	
                break;
            }
            // pointers next
            case 'p':
                // recall that pointer prepends
                // 0 and x, so they start
                _putchar('0');
                _putchar('x');
                break;
                // state = 0;
            }
            // after one case is satisfied, it will rest case to 0
            // thereby continue normal printing mode
            state = 0;
        }

        *format++;
    }
}