#include <stdio.h>
/*
 * Exercise 2-7: Write a function invert(x,p,n) that returns
 * the n bits that begin at position p inverted, leaving
 * the others unchanged.
 * Author: Matias Bustos (@matiasdx)
*/


unsigned int invert(unsigned int x, int p, int n);

int main(void){
    //test with 72 (0b01001000), expected output 68 (0b01001000)
    unsigned bit = 72;
    printf("result: %d\n",invert(bit,3,2));
    return 0;
}


unsigned int invert(unsigned int x, int p, int n){
    int mask=~(~0<<n)<<(p-n+1);
    return x^mask;
}



