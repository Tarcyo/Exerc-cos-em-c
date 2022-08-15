#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char palavra[100];
    printf("%s","Digite uma palavra: ");
    fflush(stdin);
    fgets(palavra,100,stdin);
    for(int i=0,j=strlen(palavra)-2;i<strlen(palavra)-2;i++,j--){
         if(palavra[i]!=palavra[j]){
            printf("A palavra NAO e um palindromo!");
            return 0;
         }
    }

    printf("A palavra E um palindromo!\n");
    return 0;
}
