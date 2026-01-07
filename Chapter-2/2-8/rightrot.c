#include <stdio.h>
/*
 * Exercise 2-8: Write a function rightrot(x,n) that returns 
 * the value of the integer x rotated to the right by n positions
 * Author: Matias Bustos (@matiasdx)
 */



unsigned int rightrot(unsigned int a, int b);

int main(void){
    // test with 32 (0b100000) expected output 8 (0b001000)
    printf("result: %u\n",rightrot(32,2));
    return 0;
}


unsigned int rightrot(unsigned int x, int n){
    unsigned int mask = ~(~0<<n) & x;
    // 1 byte=8 bits
    unsigned int bit=sizeof(int)*8;
    mask=mask << (bit-n);
    x=x>>n;
    return mask | x;
}


