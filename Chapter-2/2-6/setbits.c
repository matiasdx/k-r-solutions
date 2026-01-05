#include <stdio.h>
/*Write a function setbits(x,p,n,y) that returns x
 * with the n bits that begin at position p set to
 * the rightmost n bits of y, leaving other bits unchanged.
 * Author: Matias Bustos (@matiasdx)
*/


unsigned setbits(unsigned x,int p, int n, unsigned y);

int main(void){
    unsigned int bit1=0b01001010;
    unsigned int bit2=0b10011001;
    // test with x=01001010, y=10011001, expected output: 70 (0b0100110)
    printf("result: %d\n", setbits(bit1, 4, 3, bit2));
    return 0;
}

unsigned setbits(unsigned x,int p, int n, unsigned y){
    unsigned int mask = ~(~0<<n);
    y = y & mask;
    y = y << (p-n+1);
    mask =  ~(~0<<n) << (p-n+1);
    x = ~mask & x;
    return x|y;
}



