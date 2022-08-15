#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    int criancas = 0;
    int dead = 0, masc = 0, meses = 0;
    char sexo[20];
    printf("Digite a quantidade de criancas nascidas no periodo: ");
    while(criancas<1){
        scanf("%i",&criancas);
        if(criancas<1){
              printf("\nDigite um numero maior que 0: ");
          }
     }

     while((strnicmp(sexo,"vazio",5)!=0)&&dead<criancas){
         printf("Digite o sexo da crianca: ");
         scanf("%s",sexo);
         if(strnicmp(sexo,"vazio",5)==0){
              calculaMedia(criancas,dead,masc,meses);
              return 0;

          }
        if(strnicmp(sexo,"masculino",9)==0){
                masc++;
                dead++;
                meses=meses+leMeses();

        }

        if(strnicmp(sexo,"feminino",8)==0){
                dead++;
                meses=meses+leMeses();
          }
     }
    calculaMedia(criancas,dead,masc,meses);
    return 0;
}
void calculaMedia(int criancas,int dead,int masc,int meses){
    float mediaMorte=(100*(float)dead)/(float)criancas;
    float mediaMasculino=(100*(float)masc)/(float)criancas;
    float media24MesesOuMenos=(100*(float)meses)/(float)criancas;
    printf("%s%.2f%s%s%.2f%s%s%.2f%s","\nA media de crianças mortas foi: ",mediaMorte,"%","\nA media de crianças do sexo masculino masc foi: ",mediaMasculino,"%","\nA media de criancas que viveram 24 meses ou menos foi:",media24MesesOuMenos,"%");
    return;
}
int leMeses(){
    printf("Digite a quantidade de meses de vida da crianca: ");
    int meses;
    scanf("%i",&meses);
    if(meses>24){
        return 0;
    }
    return 1;
}