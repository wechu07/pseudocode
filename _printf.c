#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

void unsigned_number_to_string(uint64_t number, int base, char *buffer)
{
    if (number == 0)
    {
        *buffer++ = '0'; // ascii character C
        *buffer = 0;     // null terminator
        return;
    }

    // base
    char buf[65];
    for (int i = 0; i < 17; i++)
        buf[i] = 0;

    int cur = 0;

    while (number)
    {
        int digit = number % base;
        if (digit >= 10)
        {
            buf[cur++] = 'a' + (digit - 10);
        }
        else
        {
            buf[cur++] = 'a' + digit;
        }

        number /= base;
    }

    for (int i = cur - 1; i != 0; i--)
        *buffer++ = buf[i];
    *buffer++ = buf[0];
    *buffer = 0;
}

void number_to_string(uint64_t number, int base, char *buffer)
{
    if (number < 0)
    {
        *buffer++ = '-';
        number = -number;
    }
    unsigned_number_to_string(number, base, buffer);
}

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
                putchar(*format);
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
                putchar(ch);
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
                    putchar(*s++);
                }
                break;
            }
            case 'd':
            {
                int n = va_arg(arguments, int);

                // 2^64-1 = 10*10^24
                char buf[32]; // you can do 25 and above
                number_to_string(n, 10, buf);
                for (int i = 0; buf[i]; i++)
                {
                    putchar(buf[i]);
                }
                break;
            }
            case 'x':
            {
                int n = va_arg(arguments, int);

                // 2^64-1 = 10*10^24
                char buf[32]; // you can do 25 and above
                number_to_string(n, 16, buf);
                for (int i = 0; buf[i]; i++)
                {
                    putchar(buf[i]);
                }
                break;
            }
            // pointers next
            case 'p':
                // recall that pointer prepends
                // 0 and x, so they start
                putchar('0');
                putchar('x');
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

// the function that we are implementing is _printf
// @format: the string to be formatted
// @arguments: object (struct) containing the arguments to be handled
// _vprintf: the function that implements each argument
void _printf(const char *format, ...)
{

    va_list arguments;
    va_start(arguments, format);

    _vprintf(format, arguments);

    va_end(arguments);
}

int main()
{

    void unsigned_number_to_string();
    void *pointer_to_main = (void *)main;

    _printf("Print a character: %c. Done!\n", 'G');
    _printf("Print a string: %s. Done!\n", "Hello World");
    _printf("Print a positive integer: %d. Done!\n", 10);
    _printf("Print a negative integer: %d. Done!\n", -10);
    _printf("Print a (zero) integer: %d. Done!\n", 0);
    _printf("Print a hexademical: %x. Done!\n", '0');
    _printf("Print a zero hexademical: %x. Done!\n", '0');
    _printf("Print a pointer: %p. Done!\n", pointer_to_main);

    return 0;
}