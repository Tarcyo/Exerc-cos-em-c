#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char frase[100];
    printf("Digite uma frase: ");
    fflush(stdin);
    fgets(frase,100,stdin);
    int tamanhoFrase=strlen(frase)-2;
    int quantPalavra=1;
    for(int i=0;i<=tamanhoFrase;i++){

        if(frase[i]!=' '&& frase[i]!=','&& frase[i]!='.'){
            if(quantPalavra==1){
                printf("Palavra %i: ",quantPalavra);
                quantPalavra++;
            }
            printf("%c",frase[i]);
        }else if (frase[i+1]!=' ' && frase[i+1]!=',' && frase[i+1]!='.'){
            if(i!=tamanhoFrase&&quantPalavra>1){
                printf("\n");
                 printf("Palavra %i: ",quantPalavra);
                quantPalavra++;
            }
        }
}
return 0;
}
