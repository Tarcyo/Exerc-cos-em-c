#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int determinaQuantidadeTestesSequencial(int sequencia[100],int quantNumeros,int numeroParaProcurar){
    int quantTestes=0;
    for(int i=0;i<quantNumeros;i++){
        quantTestes++;
        if(sequencia[i]==numeroParaProcurar){
            return quantTestes;

        }

    }
    return quantTestes;
}
int determinaQuantidadeTestesBinario(int sequencia[100],int quantNumeros,int valorAProcurar){
    int quantTestes=0;
    int ordenado=0;
    while(ordenado==0){
     for(int i=0;i<quantNumeros-2;i++){
        if(sequencia[i]>=sequencia[i+1]){
        int aux=sequencia[i];
        sequencia[i]=sequencia[i+1];
        sequencia[i+1]=aux;
        }
     }
     ordenado=1;
     for(int i=0;i<quantNumeros-2;i++){
        if(sequencia[i]>sequencia[i+1]){
            ordenado=0;
        }
      }
  }
    int menorValor=0;
    int maiorValor=quantNumeros-1;
    int media=(maiorValor+menorValor)/2;

    int maximoDeMedias=sqrt(quantNumeros-1)+1;
    while(1){
        if(valorAProcurar==sequencia[maiorValor]||valorAProcurar==sequencia[menorValor]){
                quantTestes++;
                printf("O numero OCORRE no vetor!");
                return quantTestes;
              }else if(maximoDeMedias==0){
                    printf("O numero NAO ocorre no vetor!");
                    return quantTestes;
                    } else if(valorAProcurar>=sequencia[media]){
                        quantTestes+=2;
                        menorValor=media+1;
                        media=(maiorValor+menorValor)/2;
                        maximoDeMedias--;
                            }else{
                                maiorValor=media-1;
                                media=(maiorValor+menorValor)/2;
                                maximoDeMedias--;
                                    }
    }
   return quantTestes;
}
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
    printf("Digite um valor para ser procurado:");
    int valorAProcurar;
    scanf("%i",&valorAProcurar);
    printf("\nA busca sequencial usou: %i testes.\nA busca binaria usou: %i testes.",determinaQuantidadeTestesSequencial(sequencia,quantNumeros,valorAProcurar),determinaQuantidadeTestesBinario(sequencia,quantNumeros,valorAProcurar));
   return 0;
}

