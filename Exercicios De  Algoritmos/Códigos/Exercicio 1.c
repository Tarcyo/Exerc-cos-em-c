
#include <stdio.h>
#include <stdlib.h>

int main()
{   int n;
    printf("%s","Digite o tamanho do vetor: ");
    scanf("%i",&n);
    fflush(stdin);
    while(n<=0){
         printf("%s","Digite o tamanho do vetor maior do que 0: ");
         scanf("%i",&n);
         fflush(stdin);
    }
    int vet[n];
    for(int i=0;i<n;i++){
        printf("%s%i%s","Digite a posicao ",i," do vetor: ");
        int a;
        scanf("%i",&a);
        fflush(stdin);
        vet[i]=a;
    }
    int menor=9999999;
    int maior=-999999;
    for(int i=0;i<n;i++){
        if(vet[i]<menor){
          menor=vet[i];
        }
        if(vet[i]>maior){
            maior=vet[i];
        }
    }
    printf("%s%i%s%i","\nO menor valor do vetor e: ",menor,"\nO maior valor do vetor e: ",maior);
    return 0;
}
