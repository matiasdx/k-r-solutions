#include <stdio.h>
/*
 * Exercise 3-01: Our binary search makes two tests inside the loop,
 * when one would suffice (at the price more test outside.) Write
 * a version with only one test inside the loop and measure 
 * the difference in run-time.
 * Author: Matias Bustos (@matiasdx)
 *
*/



int binsearch(int x, int v[], int n);


int main(void){
    int x=1;
    int l[]={1,2,3,4,5};
    int busqueda = binsearch(x,l,5);
    printf("el %d esta en la posicion %d\n",x ,busqueda);
    return 0;
}

// encuentra x en v[0] <= v[1] <= .... <= v[n-1]
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while (low < high){
        if (x <= v[mid]){
            high = mid;
        }else{
            low = mid + 1;
        }
        mid = (low+high)/2;
    }
    if (x==v[mid]){
        return mid;
    }
    return -1;
}
