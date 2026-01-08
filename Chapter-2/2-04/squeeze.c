#include <stdio.h>
/*
 * Exercise 2-4: Write an alternative version of squeeze(s_1,s_2) that deletes each 
 * character in s1 that matches any character in the string s2
 * Author: Matias Bustos (@matiasdx) 
*/

void squeezeA(char s1[], char s2[]);

int main(void){
    // test with s1="hola mundo" y s2="oha" expected output "l mund"
    char str[]="hola mundo";
    char tr[]="oha";
    squeezeA(str,tr);
    printf("%s\n",str);
    return 0;
}


void squeezeA(char s1[],char s2[]){
    int k,i,j;
    int coincidencias;
    for (k=i=0;s1[i]!='\0';i++){
        coincidencias=0;
        for (j=0; s2[j]!='\0'; j++){
            if (s1[i]==s2[j]){
                coincidencias=1;
                break;
            }
        }
        if (coincidencias==0){
            s1[k++]=s1[i];
        }
    }
    s1[k]='\0';
}





