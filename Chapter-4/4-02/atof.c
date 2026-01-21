/*
 * Exercise 4-02: Extend atof to handle scientific
 * notation of the form: 123.45e-6
 * where a floating-point number may be followed by
 * e or E and an optionally signed exponent.
 *
 * Author: Matias Bustos (@matiasdx)
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]);
int getLine(char s[], int lim);

int main(void) {
    double sum;
    char line[MAXLINE];
    while (getLine(line, MAXLINE) > 0){
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}

double atof(char s[]) {
    double val, power;
    double e_val = 1.0;
    int i, sign, e;
    int e_sign=1;

    for (i=0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i]=='-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power=1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i])=='e') {
        ++i;
        e_sign = (s[i] == '-') ? -1 : 1;
    }
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (e = 0.0; isdigit(s[i]); i++) {
        e = 10.0 * e + (s[i] - '0');
    }
    for (int k=0; e > k; ++k) {
        if (sign == -1) {
            e_val /= 10;
        }else {
            e_val *= 10;
        }
    }

    return sign * val / power * e_val;
}


int getLine(char s[], int lim) {
    int c,i;
    i=0;
    while (--lim > 0 && (c=getchar( ))!=EOF && c!='\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}




