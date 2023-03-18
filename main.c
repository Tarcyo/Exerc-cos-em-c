



                                                                                       //   MEN��O HONROSA: LEONARDO HONDA.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defini��o da localiza��o e do tipo consulta: RODRIGO
#define LOCALIZACAO "C:\\Users\\Tarcyo\\desktop\\codigo.txt"
#define TIPOCONSULTA "r+"

//Essas Vari�veis devem ser globais: TARCYO
int linha=0;
FILE *arquivo;


// ESSA FUN��O LE O ARQUIVO NA LOCALIZA��O DEFINIDA USANDO O TIPO DE CONSULTA PARA LEITURA: RODRIGO
FILE *leArquivo(char localizacao[50], char tipoConsulta[50])
{

    arquivo = fopen(localizacao, tipoConsulta);
    verificaArquivo(arquivo);
    return arquivo;
}
// ESSA FUN��O VERIFICA SE O ARQUIVO REALMENTE EXISTE: TARCYO
void verificaArquivo(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        mostraMensagemDeErro("ARQUIVO N�O EXISTE");
    }
}
// ESSA FUN��O MOSTRA MENSAGENS DE ERRO, MOSTRA A LINHA DO ERRO E ENCERRA A EXECU��O DO PROGRAMA: RODRIGO
void mostraMensagemDeErro(char comandoDoErro[45])
{
    fclose(arquivo);
    printf("Erro: %s da linha %i", comandoDoErro, linha);
    exit(0);
}



// ESSA FUN��O VERIFICA CADA VEZ QUE ENCONTRA UM !BORN: NO C�DIGO, SE J� EXISTE OUTRO !BORN: TARCYO
int verificaBorn(int temBorn, char linhaDeCodigo[500])
{
    temBorn++;
    if (temBorn != 1)
    {
        mostraMensagemDeErro("mais de um '!Born'");
    }
    return temBorn;
}

// ESSA FUN��O VERICA SE UM COMANDO ESTa FORA DE UM !BORN: RODRIGO
void verificaSeEstaDentroDoBorn(int temBorn)
{
    if (temBorn == 0)
    {
        mostraMensagemDeErro("FORA DO '!Born'");
    }
}

// ESSA FUN��O VERIFICA VARIAVEIS !NUM: TARCYO
void verificaComandoNum(int temBorn, char linhaDeCodigo[500])
{

    verificaSeEstaDentroDoBorn(temBorn);
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != ';')
    {
        mostraMensagemDeErro("Falta ';' na declara��o de v�riaveis");
    }
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] == '.')
    {
        mostraMensagemDeErro("SEM CASAS DECIM�IS AP�S O PONTO");
    }
    if (linhaDeCodigo[5] == '1' || linhaDeCodigo[5] == '2' || linhaDeCodigo[5] == '3' || linhaDeCodigo[5] == '5' || linhaDeCodigo[5] == '5' || linhaDeCodigo[5] == '6' || linhaDeCodigo[5] == '7' || linhaDeCodigo[5] == '8' || linhaDeCodigo[5] == '9' || linhaDeCodigo[5] == '0')
    {
        mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
    }

    for (int i = 5; i < strlen(linhaDeCodigo); i++)
    {

        if (linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == ',' || linhaDeCodigo[i] == '*' || linhaDeCodigo[i] == '<' || linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '?' || linhaDeCodigo[i] == '+' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '{' || linhaDeCodigo[i] == '}' || linhaDeCodigo[i] == '[' || linhaDeCodigo[i] == ']' || linhaDeCodigo[i] == '/' || linhaDeCodigo == '|' || linhaDeCodigo[i] == '-' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '.' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '&' || linhaDeCodigo[i] == '^' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == '(' || linhaDeCodigo[i] == ')'|| linhaDeCodigo[i] == ' ')
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
        if (linhaDeCodigo[i] == '=')
        {
            if(linhaDeCodigo[i+1]=='.'){
                mostraMensagemDeErro("PONTO NO COME�O DE UM N�MERO");
            }
            int temPonto=0;
            for (i = i + 1; i < strlen(linhaDeCodigo) - 2; i++)
            {
                if (linhaDeCodigo[i] != '1' && linhaDeCodigo[i] != '2' && linhaDeCodigo[i] != '3' && linhaDeCodigo[i] != '4' && linhaDeCodigo[i] != '5' && linhaDeCodigo[i] != '6' && linhaDeCodigo[i] != '7' && linhaDeCodigo[i] != '8' && linhaDeCodigo[i] != '9' && linhaDeCodigo[i] != '0' && linhaDeCodigo[i] != '+' && linhaDeCodigo[i] != '-' && linhaDeCodigo[i] != '*' && linhaDeCodigo[i] != '/' && linhaDeCodigo[i] != '%' && linhaDeCodigo[i] != ';'&& linhaDeCodigo[i] != '.')
                {
                    mostraMensagemDeErro("Na ATRIBUICAO");
                }
                if(linhaDeCodigo[i]=='.'){
                    temPonto++;
                }
                if(temPonto>1){
                    mostraMensagemDeErro("Numero com mais de um ponto");
                }

            }
        }
    }
}

// ESSA FUN��O VERIFICA VARI�VEIS DO TIPO !TEXT: RODRIGO
void verificaComandoText(int temBorn, char linhaDeCodigo[500])
{
    verificaSeEstaDentroDoBorn(temBorn);
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != ';')
    {
        mostraMensagemDeErro("FALTA UM ';' NO FINAL" );
    }

    if (linhaDeCodigo[6] == '1' || linhaDeCodigo[6] == '2' || linhaDeCodigo[6] == '3' || linhaDeCodigo[6] == '5' || linhaDeCodigo[6] == '5' || linhaDeCodigo[6] == '6' || linhaDeCodigo[6] == '7' || linhaDeCodigo[6] == '8' || linhaDeCodigo[6] == '9' || linhaDeCodigo[6] == '0')
    {
        mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
    }
    for (int i = 6; i < strlen(linhaDeCodigo); i++)
    {

        if (linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == ',' || linhaDeCodigo[i] == '*' || linhaDeCodigo[i] == '<' || linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '?' || linhaDeCodigo[i] == '+' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '{' || linhaDeCodigo[i] == '}' || linhaDeCodigo[i] == '[' || linhaDeCodigo[i] == ']' || linhaDeCodigo[i] == '/' || linhaDeCodigo == '|' || linhaDeCodigo[i] == '-' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '.' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '&' || linhaDeCodigo[i] == '^' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == '(' || linhaDeCodigo[i] == ')'|| linhaDeCodigo[i] == ' ')
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
        if (linhaDeCodigo[i] == '=')
        {
            if (linhaDeCodigo[i + 1] != '"')
            {
                mostraMensagemDeErro("ERRO NO NOME DA ATRIBUICAO DA LINHA");
            }
            for (i = i + 1; i < strlen(linhaDeCodigo) - 1; i++)
            {
                if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] != '"')
                {
                    mostraMensagemDeErro("ASPAS NAO ESTAO SENDO FECHADAS");
                }
            }
        }
    }
}

// ESSA FUN��O VERIFICA COMANDOS DE ENTRADA: TARCYO
void verificaComandoListen(int temBorn, char linhaDeCodigo[500])
{
    verificaSeEstaDentroDoBorn(temBorn);
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != ';')
    {
        mostraMensagemDeErro("FALTA UM ';' NO FINAL DA LINHA");
    }
    else
    {
        if (linhaDeCodigo[8] == '1' || linhaDeCodigo[8] == '2' || linhaDeCodigo[8] == '3' || linhaDeCodigo[8] == '4' || linhaDeCodigo[8] == '5' || linhaDeCodigo[8] == '6' || linhaDeCodigo[8] == '7' || linhaDeCodigo[8] == '8' || linhaDeCodigo[8] == '9' || linhaDeCodigo[8] == '0' || linhaDeCodigo[8] == ')')
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
        if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] != ')')
        {
            mostraMensagemDeErro("PARENTESES NAO ESTAO SENDO FECHADOS");
        }
    }

    for (int i = 8; i < strlen(linhaDeCodigo) - 3; i++)
    {
        if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == ',' || linhaDeCodigo[i] == '*' || linhaDeCodigo[i] == '<' || linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '?' || linhaDeCodigo[i] == '+' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '{' || linhaDeCodigo[i] == '}' || linhaDeCodigo[i] == '[' || linhaDeCodigo[i] == ']' || linhaDeCodigo[i] == '/' || linhaDeCodigo == '|' || linhaDeCodigo[i] == '-' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '.' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '&' || linhaDeCodigo[i] == '^' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == '(' || linhaDeCodigo[i] == ')' || linhaDeCodigo[i] == ' '))
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
    }
}
// ESSA FUN��O VERIFICA COMANDOS DE SA�DA: RODRIGO
void verificaComandoSpeak(char linhaDeCodigo[500], int temBorn)
{
   verificaSeEstaDentroDoBorn(temBorn);
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != ';')
    {
        mostraMensagemDeErro("FALTA UM ';' NO FINAL DA LINHA");
    }
    else
    {
        if (linhaDeCodigo[7] == '1' || linhaDeCodigo[7] == '2' || linhaDeCodigo[7] == '3' || linhaDeCodigo[7] == '4' || linhaDeCodigo[7] == '5' || linhaDeCodigo[7] == '6' || linhaDeCodigo[7] == '7' || linhaDeCodigo[7] == '8' || linhaDeCodigo[7] == '9' || linhaDeCodigo[7] == '0' || linhaDeCodigo[7] == ')')
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
        if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] != ')')
        {
            mostraMensagemDeErro("PARENTESES NAO ESTAO SENDO FECHADOS");
        }
    }

    for (int i = 7; i < strlen(linhaDeCodigo) - 3; i++)
    {
        if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == ',' || linhaDeCodigo[i] == '*' || linhaDeCodigo[i] == '<' || linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '?' || linhaDeCodigo[i] == '+' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '{' || linhaDeCodigo[i] == '}' || linhaDeCodigo[i] == '[' || linhaDeCodigo[i] == ']' || linhaDeCodigo[i] == '/' || linhaDeCodigo == '|' || linhaDeCodigo[i] == '-' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '.' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '&' || linhaDeCodigo[i] == '^' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == '(' || linhaDeCodigo[i] == ')' || linhaDeCodigo[i] == ' '))
        {
            mostraMensagemDeErro("NOME DA VARIAVEL ERRADO");
        }
    }
}

// ESSA FUN��O VERIFICA COMANDOS DE TESTES L�GICOS E ATUALIZA O PONTEIRO PARA O FINAL DAS CHAVES: TARCYO
int verificaComandosWAYandAWAY(int temBorn, char linhaDeCodigo[500], int linha)
{
    verificaSeEstaDentroDoBorn(temBorn);

    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != '{')
    {
        mostraMensagemDeErro("FALTA UM '{' NO FINAL DA LINHA");
    }
    if (linhaDeCodigo[5] == ')')
    {
        mostraMensagemDeErro("ERRO NO '!Way'");
    }
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] != ')')
    {
        mostraMensagemDeErro("PARENTESES NAO ESTAO SENDO FECHADOS");
    }
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '!' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '=' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '<' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '>' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '/' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '*' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '+' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '-' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '&' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '|')
    {
        mostraMensagemDeErro("ERRO NO '!Way'");
    }
    if (linhaDeCodigo[5] == '!' || linhaDeCodigo[5] == '=' || linhaDeCodigo[5] == '+' || linhaDeCodigo[5] == '-' || linhaDeCodigo[5] == '*' || linhaDeCodigo[5] == '/' || linhaDeCodigo[5] == '&' || linhaDeCodigo[5] == '|')
    {
        mostraMensagemDeErro("ERRO NO '!Way'");
    }
    for (int i = 5; i < strlen(linhaDeCodigo) - 3; i++)
    {
        if (linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == ' ')
        {
            mostraMensagemDeErro("ERRO NO '!Way'");
        }
        if ((linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '<'))
        {
            if (linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*'  || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 1] == '!' || linhaDeCodigo[i - 1] == '#' || linhaDeCodigo[i - 1] == '$' || linhaDeCodigo[i - 1] == ',' || linhaDeCodigo[i - 1] == '*' ||  linhaDeCodigo[i - 1] == '?' || linhaDeCodigo[i - 1] == '+' || linhaDeCodigo[i - 1] == '�' || linhaDeCodigo[i - 1] == '{' || linhaDeCodigo[i - 1] == '}' || linhaDeCodigo[i - 1] == '[' || linhaDeCodigo[i - 1] == ']' || linhaDeCodigo[i - 1] == '/' || linhaDeCodigo[i - 1] == '|' || linhaDeCodigo[i - 1] == '-' || linhaDeCodigo[i - 1] == '"' || linhaDeCodigo[i - 1] == '.' || linhaDeCodigo[i - 1] == '@' || linhaDeCodigo[i - 1] == '&' || linhaDeCodigo[i - 1] == '^' || linhaDeCodigo[i - 1] == '�' || linhaDeCodigo[i - 1] == '~' || linhaDeCodigo[i - 1] == '%' || linhaDeCodigo[i - 1] == '(' || linhaDeCodigo[i] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
          if(linhaDeCodigo[i+1]=='='){
            i=i+2;
          }
        }
        else if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '='))
        {

            if (linhaDeCodigo[i + 1] != '=')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
        if ((linhaDeCodigo[i] == '|'))
        {

            if (linhaDeCodigo[i + 1] != '|')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
        else if ((linhaDeCodigo[i] == '&'))
        {

            if (linhaDeCodigo[i + 1] != '&')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
        else if ((linhaDeCodigo[i] == '/') || (linhaDeCodigo[i] == '*') || (linhaDeCodigo[i] == '>') || (linhaDeCodigo[i] == '<') || (linhaDeCodigo[i] == '+') || (linhaDeCodigo[i] == '-'))
        {
            if ((linhaDeCodigo[i + 1] == '/') || (linhaDeCodigo[i + 1] == '*')  || (linhaDeCodigo[i + 1] == '+') || (linhaDeCodigo[i + 1] == '-'))
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
        if ((linhaDeCodigo[i] == '1' || linhaDeCodigo[i] == '2' || linhaDeCodigo[i] == '3' || linhaDeCodigo[i] == '4' || linhaDeCodigo[i] == '5' || linhaDeCodigo[i] == '6' || linhaDeCodigo[i] == '7' || linhaDeCodigo[i] == '8' || linhaDeCodigo[i] == '9')|| linhaDeCodigo[i] == '0')
        {

            if (linhaDeCodigo[i + 1] != '1' && linhaDeCodigo[i + 1] != '2' && linhaDeCodigo[i + 1] != '3' && linhaDeCodigo[i + 1] != '4' && linhaDeCodigo[i + 1] != '5' && linhaDeCodigo[i + 1] != '6' && linhaDeCodigo[i + 1] != '7' && linhaDeCodigo[i + 1] != '8' && linhaDeCodigo[i + 1] != '9' && linhaDeCodigo[i + 1] != '+' && linhaDeCodigo[i + 1] != '-' && linhaDeCodigo[i + 1] != '/' && linhaDeCodigo[i + 1] != '*' && linhaDeCodigo[i + 1] != '%' && linhaDeCodigo[i + 1] != '>' && linhaDeCodigo[i + 1] != '<' && linhaDeCodigo[i + 1] != '|' && linhaDeCodigo[i + 1] != '&' && linhaDeCodigo[i + 1] != ')'&&linhaDeCodigo[i + 1] != '0'&&linhaDeCodigo[i + 1]!='=')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
    }
    if (linhaDeCodigo[5] == '1' || linhaDeCodigo[5] == '2' || linhaDeCodigo[5] == '3' || linhaDeCodigo[5] == '4' || linhaDeCodigo[5] == '5' || linhaDeCodigo[5] == '6' || linhaDeCodigo[5] == '7' || linhaDeCodigo[5] == '8' || linhaDeCodigo[5] == '9' || linhaDeCodigo[5] == '0')
    {
        int i = 5;
        while (linhaDeCodigo[i] == '1' || linhaDeCodigo[i] == '2' || linhaDeCodigo[i] == '3' || linhaDeCodigo[i] == '4' || linhaDeCodigo[i] == '5' || linhaDeCodigo[i] == '6' || linhaDeCodigo[i] == '7' || linhaDeCodigo[i] == '8' || linhaDeCodigo[i] == '9' || linhaDeCodigo[i] == '0')
        {
            i++;
        }

        if (linhaDeCodigo[i] != '<' && linhaDeCodigo[i] != '>' && linhaDeCodigo[i] != '+' && linhaDeCodigo[i] != '-' && linhaDeCodigo[i] != '*' && linhaDeCodigo[i] != '/' && linhaDeCodigo[i] != '=' && linhaDeCodigo[i] != '!')
        {
            mostraMensagemDeErro("ERRO NO '!Way'");
        }
        if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '='))
        {

            if (linhaDeCodigo[i + 1] != '=')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
        }
    }

    for (linha = linha + 1; fgets(linhaDeCodigo, 500, arquivo) != NULL && linhaDeCodigo[0] != '}'; linha++)
    {

        if ((strcmp(linhaDeCodigo, "\n") != 0))
        {
            mostraMensagemDeErro("AS CHAVES NAO ESTAO SENDO FECHADAS");
        }
    }
    if (strncmp("}!away{", linhaDeCodigo, 7) == 0)
    {
        for (linha = linha + 1; fgets(linhaDeCodigo, 500, arquivo) != NULL && linhaDeCodigo[0] != '}'; linha++)
        {

            if ((strcmp(linhaDeCodigo, "\n") != 0))
            {
                mostraMensagemDeErro("AS CHAVES NAO ESTAO SENDO FECHADAS");
            }
        }
    }
    return linha;
}

// ESSA FUN��O VERIFICA COMANDOS DE REPETI��O: RODRIGO
int verificaComandoWalk(int temBorn, char linhaDeCodigo[500], int linha)
{
    verificaSeEstaDentroDoBorn(temBorn);

    if (linhaDeCodigo[strlen(linhaDeCodigo) - 2] != '{')
    {
        mostraMensagemDeErro("FALTA UM '{' NO FINAL DA LINHA");
    }
    if (linhaDeCodigo[6] == ')')
    {
        mostraMensagemDeErro("ERRO NO '!Walk'");
    }
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 3] != ')')
    {
        mostraMensagemDeErro("PARENTESES NAO ESTAO SENDO FECHADOS");
    }
    if (linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '!' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '=' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '<' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '>' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '/' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '*' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '+' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '-' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '&' || linhaDeCodigo[strlen(linhaDeCodigo) - 4] == '|')
    {
        mostraMensagemDeErro("ERRO NO '!Walk'");
    }
    if (linhaDeCodigo[6] == '!' || linhaDeCodigo[6] == '=' || linhaDeCodigo[6] == '+' || linhaDeCodigo[6] == '-' || linhaDeCodigo[5] == '*' || linhaDeCodigo[6] == '/' || linhaDeCodigo[5] == '&' || linhaDeCodigo[6] == '|')
    {
        mostraMensagemDeErro("ERRO NO '!Walk'");
    }
    for (int i = 6; i < strlen(linhaDeCodigo) - 3; i++)
    {
        if (linhaDeCodigo[i] == '#' || linhaDeCodigo[i] == '$' || linhaDeCodigo[i] == '"' || linhaDeCodigo[i] == '@' || linhaDeCodigo[i] == '�' || linhaDeCodigo[i] == '~' || linhaDeCodigo[i] == '%' || linhaDeCodigo[i] == ' ')
        {
            mostraMensagemDeErro("ERRO NO '!Walk'");
        }
        if ((linhaDeCodigo[i] == '>' || linhaDeCodigo[i] == '<'))
        {
            if (linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*'  || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            if (linhaDeCodigo[i - 1] == '!' || linhaDeCodigo[i - 1] == '#' || linhaDeCodigo[i - 1] == '$' || linhaDeCodigo[i - 1] == ',' || linhaDeCodigo[i - 1] == '*' ||  linhaDeCodigo[i - 1] == '?' || linhaDeCodigo[i - 1] == '+' || linhaDeCodigo[i - 1] == '�' || linhaDeCodigo[i - 1] == '{' || linhaDeCodigo[i - 1] == '}' || linhaDeCodigo[i - 1] == '[' || linhaDeCodigo[i - 1] == ']' || linhaDeCodigo[i - 1] == '/' || linhaDeCodigo[i - 1] == '|' || linhaDeCodigo[i - 1] == '-' || linhaDeCodigo[i - 1] == '"' || linhaDeCodigo[i - 1] == '.' || linhaDeCodigo[i - 1] == '@' || linhaDeCodigo[i - 1] == '&' || linhaDeCodigo[i - 1] == '^' || linhaDeCodigo[i - 1] == '�' || linhaDeCodigo[i - 1] == '~' || linhaDeCodigo[i - 1] == '%' || linhaDeCodigo[i - 1] == '(' || linhaDeCodigo[i] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
          if(linhaDeCodigo[i+1]=='='){
            i=i+2;
          }
        }
        else if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '='))
        {

            if (linhaDeCodigo[i + 1] != '=')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
        if ((linhaDeCodigo[i] == '|'))
        {

            if (linhaDeCodigo[i + 1] != '|')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
        else if ((linhaDeCodigo[i] == '&'))
        {

            if (linhaDeCodigo[i + 1] != '&')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
        else if ((linhaDeCodigo[i] == '/') || (linhaDeCodigo[i] == '*') || (linhaDeCodigo[i] == '>') || (linhaDeCodigo[i] == '<') || (linhaDeCodigo[i] == '+') || (linhaDeCodigo[i] == '-'))
        {
            if ((linhaDeCodigo[i + 1] == '/') || (linhaDeCodigo[i + 1] == '*')  || (linhaDeCodigo[i + 1] == '+') || (linhaDeCodigo[i + 1] == '-'))
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
        if ((linhaDeCodigo[i] == '1' || linhaDeCodigo[i] == '2' || linhaDeCodigo[i] == '3' || linhaDeCodigo[i] == '4' || linhaDeCodigo[i] == '5' || linhaDeCodigo[i] == '6' || linhaDeCodigo[i] == '7' || linhaDeCodigo[i] == '8' || linhaDeCodigo[i] == '9')|| linhaDeCodigo[i] == '0')
        {

            if (linhaDeCodigo[i + 1] != '1' && linhaDeCodigo[i + 1] != '2' && linhaDeCodigo[i + 1] != '3' && linhaDeCodigo[i + 1] != '4' && linhaDeCodigo[i + 1] != '5' && linhaDeCodigo[i + 1] != '6' && linhaDeCodigo[i + 1] != '7' && linhaDeCodigo[i + 1] != '8' && linhaDeCodigo[i + 1] != '9' && linhaDeCodigo[i + 1] != '+' && linhaDeCodigo[i + 1] != '-' && linhaDeCodigo[i + 1] != '/' && linhaDeCodigo[i + 1] != '*' && linhaDeCodigo[i + 1] != '%' && linhaDeCodigo[i + 1] != '>' && linhaDeCodigo[i + 1] != '<' && linhaDeCodigo[i + 1] != '|' && linhaDeCodigo[i + 1] != '&' && linhaDeCodigo[i + 1] != ')'&&linhaDeCodigo[i + 1] != '0'&&linhaDeCodigo[i + 1]!='=')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
    }
    if (linhaDeCodigo[6] == '1' || linhaDeCodigo[6] == '2' || linhaDeCodigo[6] == '3' || linhaDeCodigo[6] == '4' || linhaDeCodigo[6] == '5' || linhaDeCodigo[6] == '6' || linhaDeCodigo[6] == '7' || linhaDeCodigo[6] == '8' || linhaDeCodigo[6] == '9' || linhaDeCodigo[6] == '0')
    {
        int i = 6;
        while (linhaDeCodigo[i] == '1' || linhaDeCodigo[i] == '2' || linhaDeCodigo[i] == '3' || linhaDeCodigo[i] == '4' || linhaDeCodigo[i] == '5' || linhaDeCodigo[i] == '6' || linhaDeCodigo[i] == '7' || linhaDeCodigo[i] == '8' || linhaDeCodigo[i] == '9' || linhaDeCodigo[i] == '0')
        {
            i++;
        }

        if (linhaDeCodigo[i] != '<' && linhaDeCodigo[i] != '>' && linhaDeCodigo[i] != '+' && linhaDeCodigo[i] != '-' && linhaDeCodigo[i] != '*' && linhaDeCodigo[i] != '/' && linhaDeCodigo[i] != '=' && linhaDeCodigo[i] != '!')
        {
            mostraMensagemDeErro("ERRO NO '!Walk'");
        }
        if ((linhaDeCodigo[i] == '!' || linhaDeCodigo[i] == '='))
        {

            if (linhaDeCodigo[i + 1] != '=')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
            i++;
            // AQUI QUE PULA UM CARACTER PRA NaO DAR MERDA NA EXECU��O
            if (linhaDeCodigo[i + 1] == ' ' || linhaDeCodigo[i + 1] == '!' || linhaDeCodigo[i + 1] == '#' || linhaDeCodigo[i + 1] == '$' || linhaDeCodigo[i + 1] == ',' || linhaDeCodigo[i + 1] == '*' || linhaDeCodigo[i + 1] == '<' || linhaDeCodigo[i + 1] == '>' || linhaDeCodigo[i + 1] == '?' || linhaDeCodigo[i + 1] == '+' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '{' || linhaDeCodigo[i + 1] == '}' || linhaDeCodigo[i + 1] == '[' || linhaDeCodigo[i + 1] == ']' || linhaDeCodigo[i + 1] == '/' || linhaDeCodigo[i + 1] == '|' || linhaDeCodigo[i + 1] == '-' || linhaDeCodigo[i + 1] == '"' || linhaDeCodigo[i + 1] == '.' || linhaDeCodigo[i + 1] == '@' || linhaDeCodigo[i + 1] == '&' || linhaDeCodigo[i + 1] == '^' || linhaDeCodigo[i + 1] == '�' || linhaDeCodigo[i + 1] == '~' || linhaDeCodigo[i + 1] == '%' || linhaDeCodigo[i + 1] == '(' || linhaDeCodigo[i + 1] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Way'");
            }
            if (linhaDeCodigo[i - 2] == ' ' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '!' || linhaDeCodigo[i - 2] == '#' || linhaDeCodigo[i - 2] == '$' || linhaDeCodigo[i - 2] == ',' || linhaDeCodigo[i - 2] == '*' || linhaDeCodigo[i - 2] == '<' || linhaDeCodigo[i - 2] == '>' || linhaDeCodigo[i - 2] == '?' || linhaDeCodigo[i - 2] == '+' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '{' || linhaDeCodigo[i - 2] == '}' || linhaDeCodigo[i - 2] == '[' || linhaDeCodigo[i - 2] == ']' || linhaDeCodigo[i - 2] == '/' || linhaDeCodigo[i - 2] == '|' || linhaDeCodigo[i - 2] == '-' || linhaDeCodigo[i - 2] == '"' || linhaDeCodigo[i - 2] == '.' || linhaDeCodigo[i - 2] == '@' || linhaDeCodigo[i - 2] == '&' || linhaDeCodigo[i - 2] == '^' || linhaDeCodigo[i - 2] == '�' || linhaDeCodigo[i - 2] == '~' || linhaDeCodigo[i - 2] == '%' || linhaDeCodigo[i - 2] == '(' || linhaDeCodigo[i - 2] == ')')
            {
                mostraMensagemDeErro("ERRO NO '!Walk'");
            }
        }
    }

    for (linha = linha + 1; fgets(linhaDeCodigo, 500, arquivo) != NULL && linhaDeCodigo[0] != '}'; linha++)
    {

        if ((strcmp(linhaDeCodigo, "\n") != 0))
        {
            mostraMensagemDeErro("AS CHAVES NAO ESTAO SENDO FECHADAS");
        }
    }
    return linha;

}




// ESSA FUN��O VERIFICA SE A FUN��O PRINCIPAL � ENCERRADA CORRETAMENTE E SE NaO H� NADA EMBAIXO DELA: RODRIGO
FILE *verificaComandoDie(char linhaDeCodigo[500], int temBorn, FILE *arquivo)
{
    verificaSeEstaDentroDoBorn(temBorn);
    while (fgets(linhaDeCodigo, 500, arquivo) != NULL && linhaDeCodigo[0] != '}')
    {
        if ((strcmp(linhaDeCodigo, "\n") != 0))
        {
            mostraMensagemDeErro("NAO PODEM HAVER COMANDOS ABAIXO DO '!Die'");
        }
        else
        {
            linha++;
        }
    }
    return arquivo;
}

// INICIO DA FUN��O PRINCIPAL:TARCYO
int main()
{
    //Recebimento do Arquivo
    arquivo = leArquivo(LOCALIZACAO, TIPOCONSULTA);
    verificaArquivo(arquivo);
    fflush(arquivo);

    //Vari�veis importantes:
    char linhaDeCodigo[500];
    int temBorn = 0;
    int temDie=0;

    //Esse while verifica todos os tokens
    while(fgets(linhaDeCodigo, 500, arquivo) != NULL)
    {
       linha++;

        if (strcmp(linhaDeCodigo, "\n") == 0)
        {
            // SE FOR UMA LINHA VAZIA NaO FAZ NADA.
        }
        else if (strncmp("!born:", linhaDeCodigo, 6) == 0)
        {
            temBorn += verificaBorn(temBorn, linhaDeCodigo);
        }
        else if (strncmp("!num", linhaDeCodigo, 4) == 0)
        {
            verificaComandoNum(temBorn, linhaDeCodigo);
        }
        else if (strncmp("!text", linhaDeCodigo, 5) == 0)
        {
            verificaComandoText(temBorn, linhaDeCodigo);
        }
        else if (strncmp("!listen(", linhaDeCodigo, 8) == 0)
        {
            verificaComandoListen(temBorn, linhaDeCodigo);
        }
        else if (strncmp("!way(", linhaDeCodigo, 5) == 0)
        {
            linha = verificaComandosWAYandAWAY(temBorn, linhaDeCodigo, linha);
        }
        else if (strncmp("!walk(", linhaDeCodigo, 5) == 0)
        {
            linha = verificaComandoWalk(temBorn, linhaDeCodigo, linha);
        }
        else if (strncmp("!speak(", linhaDeCodigo, 7) == 0)
        {
            verificaComandoSpeak(linhaDeCodigo, temBorn);
        }
        else if (strncmp("!die;", linhaDeCodigo, 5) == 0)
        {
            arquivo = verificaComandoDie(linhaDeCodigo, temBorn, arquivo);
            temDie++;
        }
        else if (strncmp("!away{", linhaDeCodigo, 6) == 0)
        {
            mostraMensagemDeErro("UM '!away' SO PODE EXISTIR SE UM '!way'EXISTIR ANTERIORMENTE");
        }
        else
        {
            mostraMensagemDeErro("COMANDO DESCONHECIDO");
        }
    }
    if(temDie!=1){
        mostraMensagemDeErro("Est� faltando !die; na fun��o principal");
    }
    fclose(arquivo);
    printf("Codigo analisado com sucesso!\nNumero de linhas: %i", linha);
    return 0;
}

// CR�DITOS:
// TARCYO: AJUDOU A COMPLICAR O TRABALHO.
// RODRIGO: AJUDOU A CORSERTAR A ZONA QUE O TARCYO FEZ.
// LEORNADO: FOI PRA PRAIA PEGAR MULHER.

