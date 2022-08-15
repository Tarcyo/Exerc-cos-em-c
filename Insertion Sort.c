#include <stdio.h>
#include <stdlib.h>
int main()
{
    fflush(stdin);
    printf("Digite o tamanho do vetor: ");
    int numeroPos;
    scanf("%i",&numeroPos);
    while(numeroPos<=0){
       fflush(stdin);
       printf("Digite o tamanho maior que 0: ");
       scanf("%i",&numeroPos);
    }
    int vetor[numeroPos];
    for(int i=0;i<numeroPos;i++){
          fflush(stdin);
          int a;
          printf("Digite um numero para o vetor: ");
          scanf("%i",&a);
          vetor[i]=a;
    }
    for(int i=1;i<numeroPos;i++){
      if(vetor[i]<vetor[i-1]){
        int aux=vetor[i];
        int j;
        for(j=i-1;j>=0&&aux<=vetor[j];j--){
            vetor[j+1]=vetor[j];
            vetor[j]=aux;
        }
     }
   }
     for(int i=0;i<numeroPos;i++){
          printf("%i\n",vetor[i]);
     }
 return 0;
}