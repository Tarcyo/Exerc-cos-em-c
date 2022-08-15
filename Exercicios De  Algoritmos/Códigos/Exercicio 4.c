
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=0;
    printf("%s","Digite a quantidade N de numeros: ");
    fflush(stdin);
    scanf("%i",&n);
    while(n<=0){
    printf("%s","Digite um numero maior que 0: ");
    fflush(stdin);
    scanf("%i",&n);
    }
    int sequenciaInicial[n];
    for(int i=0;i<n;i++){
       printf("%s","Digite um numero para a sequencia: ");
       int  a;
       scanf("%i",&a);
       sequenciaInicial[i]=a;
    }
    int sequencias[n][n];
    int numeroAtualDaSequencia=0;
    int quantidadeDeSequencias=0;
    int tamanhoDaSequencia=0;
    int tamanhosDasSequencias[n];
    for(int i=0;i<n;i++){
      if(i==0){
        numeroAtualDaSequencia=sequenciaInicial[i];
        sequencias[quantidadeDeSequencias][tamanhoDaSequencia]=numeroAtualDaSequencia;
      }else if(numeroAtualDaSequencia==sequenciaInicial[i]){
        tamanhoDaSequencia++;
        sequencias[quantidadeDeSequencias][tamanhoDaSequencia]=numeroAtualDaSequencia;
       }else{
           tamanhoDaSequencia=0;
           quantidadeDeSequencias++;
           numeroAtualDaSequencia=sequenciaInicial[i];
           sequencias[quantidadeDeSequencias][tamanhoDaSequencia]=numeroAtualDaSequencia;
       }
       tamanhosDasSequencias[quantidadeDeSequencias]=tamanhoDaSequencia+1;
    }
    int maiorTamanhoDeSequencia=-1;
   for(int i=0;i<=quantidadeDeSequencias;i++){
        if(maiorTamanhoDeSequencia<tamanhosDasSequencias[i]){
            maiorTamanhoDeSequencia=tamanhosDasSequencias[i];
        }
    }
  for(int i=1;i<=maiorTamanhoDeSequencia;i++){
    int quantGrupos=0;
    int valores[n];
    for(int j=0;j<=quantidadeDeSequencias;j++ ){
        if(tamanhosDasSequencias[j]==i){
            valores[quantGrupos]=sequencias[j][0];
            quantGrupos++;
        }
    }
    if(quantGrupos>0){
        printf("\nHa %i grupos de %i elementos: [",quantGrupos,i);
    for(int i=0;i<quantGrupos;i++){
        printf("%i",valores[i]);
        if(i<quantGrupos-1){
             printf("%s",", ");
        }
    }
    printf("]\n");
    }
  }
    return 0;
}
