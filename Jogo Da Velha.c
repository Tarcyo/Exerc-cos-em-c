#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
void mostraVetor(char jogo[3][3]){
    for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              printf("|%c|",jogo[i][j]);
             }
        printf("\n");
    }
}
int verificaSeGanhou(int linha,int coluna,char rodadaAtual,char jogo[3][3]){
            if(jogo[linha][0]==jogo[linha][1]&&jogo[linha][1]==jogo[linha][2]){
               return 1;
            }
            if(jogo[0][coluna]==jogo[1][coluna]&&jogo[1][coluna]==jogo[2][coluna]){
                return 1;
            }
            if((jogo[0][0]==jogo[1][1]&&jogo[1][1]==jogo[2][2])||(jogo[0][2]==jogo[1][1]&&jogo[1][1]==jogo[2][0])){
              return 1;
            }
return 0;
}
int main()
{
    char jogo[3][3]={'1','2','3',
                     '4','5','6',
                     '7','8','9'};
    char jogadorX[50],jogadorO[50];
    fflush(stdin);
    printf("Digite o nome do jogador de X: ");
    fgets(jogadorX,50,stdin);
    fflush(stdin);
    printf("Digite o nome do jogador de O: ");
    fgets(jogadorO,50,stdin);
    char rodadaAtual;
    char proximaRodada;
    srand(time(NULL));
    int aleatorio=(rand()%2);
    if(aleatorio==1){
        rodadaAtual='X';
        proximaRodada='O';
    }else{
       rodadaAtual='O';
       proximaRodada='X';
    }
    int numeroRodada=1;
    do{
      printf("\nRodada atual: %c\n",rodadaAtual);
      mostraVetor(jogo);
      fflush(stdin);
      printf("\nDigite um numero de posicao livre: ");
      char n;
      scanf("%c",&n);
      while(n!='1'&&n!='2'&&n!='3'&&n!='4'&&n!='5'&&n!='6'&&n!='7'&& n!='8'&& n!='9'){
        printf("\nDigite um numero entre 1 e 9 ");
        scanf("%c",&n);
      }
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           if(jogo[i][j]==n && jogo[i][j]!='X' && jogo[i][j]!='O'){
            jogo[i][j]=rodadaAtual;
            if(verificaSeGanhou(i,j,rodadaAtual,jogo)==1){
                if(rodadaAtual=='X'){
                    printf("O vencedor foi: %s",jogadorX);
                }else{
                    printf("O vencedor foi: %s",jogadorO);
                }
                mostraVetor(jogo);
                return 0;
            }
            numeroRodada++;
            char aux=rodadaAtual;
            rodadaAtual=proximaRodada;
            proximaRodada=aux;
           }
        }
    }
    }while(numeroRodada<=9);
     printf("\nDeu Velha!\n");
     mostraVetor(jogo);
     return 0;
}
