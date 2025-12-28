#include <stdio.h>
#include <ctype.h>
/*
* Exercise 2-3: Write the function htoi, which converts a string of hexadecimal
* digits (including an optional 0x or 0X) into its equivalent integer value.
* Author: Matias Bustos (@matiasdx)
*/
int htoi(char h[]);

int main(void){
    char chara[] = "0x1F";
    int caracter=htoi(chara);
    printf("%d\n",caracter);
    return 0;
}

int htoi (char h[]){
    int i,n;
    i=0;
    n=0;
    if (h[0]=='0' && (h[1]=='x' || h[1]=='X')){
        i=2;
    }
    while ((h[i]>='0' && h[i]<='9') || (tolower(h[i])>='a' && tolower(h[i])<='f')){
        if (tolower(h[i])>='0' && tolower(h[i])<='9'){
            n=n*16+(h[i]-'0');
        }else{
            h[i]=tolower(h[i]);
            n=n*16+(h[i]-'a'+10);
        }
        ++i;
    }
    return n;
}
