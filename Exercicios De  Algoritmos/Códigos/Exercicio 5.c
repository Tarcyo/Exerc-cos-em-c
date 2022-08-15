#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char primeira[100];
    char segunda[100];
    int vezes=0;
    printf("Digite a primera sequencia: ");
    fflush(stdin);
    fgets(primeira,100,stdin);
    printf("Digite a segunda sequencia: ");
    fflush(stdin);
    fgets(segunda,100,stdin);
    int tamanhoPrimeira=strlen(primeira)-2;
    int tamanhoSegunda=strlen(segunda)-2;
    if(tamanhoPrimeira>tamanhoSegunda){
        printf("a primeria sequencia deve ser menor que a segunda.");
        return 0;
    }
    for(int i=0;i<=tamanhoSegunda;i++){
            int aparece=0;
        for(int j=0;j<=tamanhoPrimeira;j++){
            if(segunda[i+j]==primeira[j]){
                aparece++;
            }
        }
        if(aparece==tamanhoPrimeira+1){
            vezes++;
        }
    }
    printf("\nA primeira sequencia aparece %i vezes na segunda sequencia.",vezes);
    return 0;
}

