#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // LEITURA DAS PALAVRAS:
    char p1[250];
    char p2[250];
    printf("%s","Digite a primeira palavra: ");
    fflush(stdin);
    fgets(p1,230,stdin);
    fflush(stdin);
    printf("%s","Digite a segunda palavra: ");
    fflush(stdin);
    fgets(p2,230,stdin);
    fflush(stdin);

    // O TAMANHO E REDUZIDO EM 1 PARA IGNORAR O \0:
    int tamanho1 = strlen(p1)-1;
    int tamanho2 = strlen(p2)-1;

    //TESTE PARA SABER SE O TAMANHO sSAO DIFERENTES:
    if(tamanho1!=tamanho2){
        printf("%s","As palavras NAO sao anagramas");
        return 0;
    }
    // VERIFICACAO DE QUAIS LETRAS A PALAVRA POSSUI:
    char letras[]="abcdefghijklmnopqrstuvwxyz";
    char letrasQpossui1[230];
    int QuantLetras1=0;
    for(int i=0;i<26;i++){
       for(int j=0;j<tamanho1;j++){
           if(letras[i]==p1[j]){
              letrasQpossui1[QuantLetras1]=letras[i];
              QuantLetras1++;
           }
       }
    }
    char letrasQpossui2[230];
    int QuantLetras2=0;
    for(int i=0;i<26;i++){
       for(int j=0;j<tamanho2;j++){
           if(letras[i]==p2[j]){
              letrasQpossui2[QuantLetras2]=letras[i];
              QuantLetras2++;
           }
       }
    }
    //SE AS PALAVRAS POSSUEM O MESMO TAMANHO E A MESMA QUANTIDADE DE CADA PALAVRA ENTÃO SÃO ANAGRAMAS:
    if(strnicmp(letrasQpossui1,letrasQpossui2,tamanho1)==0){
         printf("%s","As palavras SAO anagramas!");
         return 0;
    }

    printf("%s","As palavras NAO sao anagramas!");
    return 0;
}
