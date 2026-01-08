#include <stdio.h>

/* Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of bitcount.
 * Explain:
    * When subtracting 1 in binary, all zeros to the right of the last 1 are converted to ones, 
    * and that last 1 is turned off. By applying the & operator with the original value,
    * the original zeros eliminate those turned-on ones,  and the last 1 does not survive, 
    * remaining off.
*/
int bitcount(unsigned x);

int main(void){
    unsigned int bit=0x29c; //0x29c is 668 in decimal (binario: 0b01010011100)
    //test with 0x14c expected output:"Number of 1-bits in 668 is: 5"
    int result=bitcount(bit);
    printf("Number of 1-bits in %u is: %d\n", bit, result);
    return 0;
}


int bitcount(unsigned x){
    int i;
    for (i=0;x!=0;x&=(x-1)){
        i++;
    }
    return i;
}
