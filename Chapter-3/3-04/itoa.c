/*
 * Exercise 3-04: In a two's complement number
 * Representation, our version of itoa does not
 * handle the largest negative number, that is, the value
 * of n equal to -(2^{wordsize-1}). Explain why not.
 * Modify it to print that value correctly, regardless
 * of the machine of which it runs.
 *
 * Author: Matias Bustos (@matiasdx)
*/

/*
 * In an 8-bit machine using two's complement, I know that int_max is 127 (0b01111111)
 * while int_min is -128 (0b10000000).
 * The logic fails in the conversion from -128 to 128 due to overflow. To solve this,
 * I use the absolute value in the body of the loop and obtain
 * the positive digits. Then I change the guard condition since n will be negative.
*/


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void) {
    char str[MAXLINE];
    itoa(INT_MIN,str);
    printf("%s",str);
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    i=0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i=0, j=strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

