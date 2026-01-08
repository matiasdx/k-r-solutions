#include <stdio.h>
/* 
 * Exercise 2-10: Rewrite the function lower, which converts upper case
 * letters to lower case, with a conditional expression instead of if-else
 * Author: Matias Bustos (@matiasdx)
*/
int lower (int c);

int main(void){
    // The expected output in both cases is 'a'
    // Case 1: Test with capital letters
    char upper_c = 'A';
    char low_c = lower(upper_c);
    printf("%c\n", low_c);
    // Case 2: Test with lowercase letters (Should remain unchanged)
    upper_c = 'a';
    low_c = lower(upper_c);
    printf("%c\n", low_c);
    return 0;
}

int lower (int c){
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}


