/*
 * Exercise 4-01: Write the function strrindex(s,t),
 * which returns the position of the rightmost occurrence
 * of t in s, or -1 if there is none.
 * Author: Matias Bustos (@matiasdx)
 */



#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchFor[]);

char pattern [] = "za"; // patron para buscar

int main(void) {
    char textToSearch[] = "pizaza";
    char patternToFind[] = "za";
    // Test:"pizaza" is what i'm looking for,
    // and "za" is the place to find it.
    // The position furthest to the right is 4.
    int pos = strrindex(textToSearch, patternToFind);
    if (pos >= 0) {
        printf("The %s pattern was found in position %d",patternToFind, pos);
        return 1;
    }
    return 0;
}


int strrindex(char s[], char t[]) {
    int i, j, k;
    int s_len = strlen(s);
    int t_len = strlen(t);

    for (i=s_len-t_len ; i>=0 ; i--) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k]=='\0') {
            return i;
        }
    }
    return -1;
}

