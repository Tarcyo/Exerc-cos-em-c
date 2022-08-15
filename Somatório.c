#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[100];
    float s=0;
    int quantNunInferior=0;
    for(int i=0;i<100;i++){
        printf("%s%i%s","Digite a posicao ",i," do vetor: ");
        float b;
        scanf("%f",&b);
        while(b==0){
        printf("%s","Digite um numero diferente de 0: ");
        scanf("%f",&b);
        }
        a[i]=b;
        printf("\n");
    }
    for(int i=0;i<100;i++){
        s=s+(i/(float)a[i]);
        if(i<a[i]){
           quantNunInferior++;
           }
    }
    printf("%s%f%s%i","O somatorio das divisoes e: ",s,"\nO numero de numeradores inferiores aos denominadorese: "
           ,quantNunInferior);

    return 0;
}
