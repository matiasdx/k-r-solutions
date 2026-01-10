#include <stdio.h>

/* 
 * Exercise 3-02: Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t
 * as it copies the string t to s. Use a switch. Write a function
 * for the other direction as well, converting escape sequences
 * into the real characters.
 *
 * Author: Matias Bustos (@matiasdx)
 */


void inescape(char t[], char s[]);
void escape(char t[],char s[]);

int main(void){
    char str[15] = "hola\nmu\tndo";
    char str2[30];
    /* test with "hola
       mu	ndo", expected output: "hola\nmu\tndo"
     */
    escape(str,str2);
    printf("%s\n",str2);
    /* test with "hola\nmundo\tndo", expected output  "hola
       mu	ndo",*/
    inescape(str2,str);
    printf("%s\n",str);
    return 0;
}


void escape(char t[],char s[]){
    int i,j;
    for (i=0,j=0; t[i]!='\0'; i++){
        switch (t[i]) {
            case '\t':
                s[j++]='\\';
                s[j++]='t';
                break;
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            default:
                s[j++]=t[i];
                break;
        
        }
    }
    s[j]='\0';
}


void inescape(char t[], char s[]){
    int i, j;
    for (i=0,j=0; t[i]!='\0'; i++){
        switch (t[i]){
            case '\\':
                switch (t[i+1]){
                    case 'n':
                        s[j++]='\n';
                        ++i;
                        break;
                    case 't':
                        s[j++]='\t';
                        ++i;
                        break;
                    default:
                        s[j++]=t[i];
                        break;
                }
                break;
            default:
                s[j++]=t[i];
                break;
        }
    }
    s[j]='\0';
}





