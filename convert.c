/*
C code to convert decimal number to hexadecimal
steps
1. Take a decimal number as input.
2. Divide the input number by 16. Store the remainder in the array.
3. Do step 2 with the quotient obtained until quotient becomes zero.
4. Print the array in the reversed fashion to get hexadecimal number.
*/

#include <stdio.h>
 
int main()
{
    long decimalnum, quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
 
    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);
 
    quotient = decimalnum;
 
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    putchar('0');
    putchar('x');
 
    // display integer into character
    for (i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
            printf("\n");
    return 0;
}

/*
Program Explanation
1. Take a decimal number as input and store it in the variable decimalnum.
2. Initialize the variable j=0 and copy decimalnum to variable quotient.
3. Obtain the quotient and remainder of the variable quotient. Store the obtained remainder in the variable remainder and override the variable quotient with obtained quotient.
4. Check if the remainder is less than 10. If it is, then add 48 to the remainder and store the result in the array hexadecimalnum. Otherwise, add 55 to the remainder and store the result in the array hexadecimalnum.
5. Do steps 3-4 until variable quotient becomes zero.
*/