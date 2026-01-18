/*
 * Exercise 3-06: Write a version of itoa that
 * accepts three arguments instead of two.
 * The thirs argument is a minium field width;
 * the converted number must be padded with
 * blanks on the left it necessary to make it
 * wide enough.
 *
 * Author: Matias Bustos (@matiasdx)
*/


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[], int width);

int main(void) {
    char str[MAXLINE];
    // Test: INT_MIN (len 11) with width 13. Pads with 2 chars.
    int wth=13;
    itoa(INT_MIN,str,wth);
    printf("%s",str);
    return 0;
}

void itoa(int n, char s[], int width) {
    int i, sign;
    sign = n;
    i=0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    if (i<width) {
        while (i<width) {
            s[i++] = ' ';
        }
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



