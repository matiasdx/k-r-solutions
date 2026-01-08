#include <stdio.h>

/*
 * Exercise 2-5: Write the function any(s1,s2), which returns the first location
 * in a string s1 where any character from the string s2 ocurrs, or -1 if s1 contains
 * no characther from s2
 * Author: Matias Bustos (@matiasdx)
*/

int any(char s1[], char s2[]);

int main(void){
    // test with s1="hola mundo" and s2="hello world", expected output: 0
    char str1[]="hola mundo";
    char str2[]="hello world";
    int result = any(str1, str2);
    printf("%d\n",result);
    return 0;    
}

int any(char s1[], char s2[]){
   int i,j;
   for (i=0;s1[i]!='\0';i++){
        for (j=0;s2[j]!='\0';j++){
            if (s1[i]==s2[j]){
                return i;
            }
        }
   }
   return -1;
}

