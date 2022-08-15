#include <stdio.h>
#include <stdlib.h>





//DECLARANDO AS FUNCOES:
int leValorParaAMatriz(int linha, int coluna);
int leTamanhoDaMatriz(char letra);


// A FUNCAO GARANTE QUE O VALOR RETORNADO SEJA MAIOR OU IGUAL QUE -10 E MENOR OU IGUAL QUE 10 POR MEIO DE UM WHILE:
int leValorParaAMatriz(int linha, int coluna){
    int valor;
    printf("Digite um valor para a linha %i coluna a %i da matriz: ",linha+1,coluna+1);
    fflush(stdin);
    scanf("%i",&valor);
    while(valor>10||valor<-10){
        printf("Digite um valor entre 10 e -10: ");
        fflush(stdin);
        scanf("%i",&valor);
    }
    return valor;
}



// A FUNCAO BASICAMENTE MOSTRA UMA MENSAGEM E LE UMA DOS VALORES INICIAIS:
int leTamanhoDaMatriz(char letra){
    int a;
    printf("Digite o valor %c : \n",letra);
    fflush(stdin);
    scanf("%i",&a);
    return a;
}

//CODIGO PRINCIPAL:
int main()
{


    //LENDO OS VALORES M,N E P DO TECLADO:
    int m=leTamanhoDaMatriz('m');
    int n=leTamanhoDaMatriz('m');
    int p=leTamanhoDaMatriz('p');




    //RECEBENDO OS VALORES DAS MATRIZES PELO TECLADO:
    int a[m][n];
    int b[n][p];

    printf("Matriz A: : \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=leValorParaAMatriz(i,j);
        }
    }

    printf("Matriz B: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            b[i][j]=leValorParaAMatriz(i,j);
        }
    }


    //MULTIPLICANDO AS MATRIZES E COLOCANDO NA MATRIZ C:
    int c[m][p];
    int mult=0;
    for(int i=0;i<m;i++){
       for(int j=0;j<p;j++){
          for(int k=0;k<n;k++){
           mult=mult+(a[i][k]*b[k][j]);
        }
         c[i][j]=mult;
         mult=0;
       }
    }

    //EXIBINDO A MATRIZ C NA TELA:
    printf("\n A Matriz C: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            printf("| %i |",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}