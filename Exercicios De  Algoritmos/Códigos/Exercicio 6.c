#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int sequencia[100];
    int quantNumeros=0;
    int continua=0;
    while (continua==0){
        int numero;
        fflush(stdin);
        printf("digite um numero positivo para a sequencia(digite 0 para parar): ");
        scanf("%i",&numero);
        while(numero<0){
           printf("digite um numero positivo! ");
           scanf("%i",&numero);
        }
        if(numero==0){
            continua=1;
        }else{
            sequencia[quantNumeros]=numero;
            quantNumeros++;

        }


    }
    int numeroParaProcurar;
    printf("digite um numero para se procurar dentro da sequencia: ");
    scanf("%i",&numeroParaProcurar);
    for(int i=0;i<quantNumeros;i++){
        if(sequencia[i]==numeroParaProcurar){
            printf("O numero digitado ocorre no vetor!.");
            return 0;
        }
    }
    printf("O numero digitado NAO ocorre no vetor!.");

   return 0;
}
