/*
 * Exercise 3-3: Write a function expand(s1,s2) that
 * expands shorthand notations like a-z in the string
 * s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and
 * prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally
 * Author: Matias Bustos (@matiasdx)
 */

#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main(void) {
    //test with 0-7a-d-, Expected output: 01234567abcd-
    char str1[MAXLINE]="0-7a-d-";
    char str2[MAXLINE];
    //test with "a-d1-4" ; Expected output:"abcd1234-"
    expand(str1,str2);
    printf("%s",str2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i=0;
    int j,k;
    k=0;
    while (s1[i]!='\0') {
        switch (s1[i]) {
            case '-':
                if (i==0 || s1[i+1]=='\0') {
                    s2[k++] = s1[i];
                    break;
                }
                int inicio = s1[i-1];
                int final = s1[i+1];
                if (isdigit(inicio) && isdigit(final)
                || islower(inicio) && islower(final)
                || isupper(inicio) && isupper(final)) {
                    for (j=inicio+1; j<final ; j++, k++) {
                        s2[k] = j;
                    }
                }else {
                    s2[k++] = '-';
                }
                break;
            default:
                s2[k++] = s1[i];
                break;
        }
        i++;
    }
    s2[k]='\0';
}


