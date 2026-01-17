/*
 * Exercise 3-05: Write the function itob(n,s,b) that
 * Converts the integer n into a base b character
 * representation in the string s. In particular,
 * itob(n,s,16) formats s as a hexadecimal integer in s.
 * Author: Matias Bustos (@matiasdx)
*/


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(void) {
    char str[MAXLINE];
    //test with 34 in base 16, expected output "22" (because 2 * 16 + 2 * 1 = 34).
    itob(34,str,16);
    printf("%s\n",str);
    // test with -2147483648; Expected output: "-80000000"
    itob(INT_MIN, str, 16);
    printf("%s\n",str);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;
    i=0;
    do {
        if (abs(n % b) < 10) {
            s[i++] = abs(n % b) + '0';
        }else {
            s[i++] = abs(n % b) - 10 + 'A';
        }
    } while ((n /= b) != 0);
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
