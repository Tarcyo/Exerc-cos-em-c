#include <stdlib.h>
typedef struct _funcionario{
    char nome[50];
    float sal,hed,hen,nd,fal,de,ref,val;
    float horasExtras;
    float salarioFamilia;
    float salarioBruto;
    float inamps;
    float faltas;
    float impostodeRenda;
    float descontoTotal;
    float salarioLiquido;
}funcionario;
float lerValores(char tipo[45]){
    fflush(stdin);
    float valor;
    printf("Digite o valor %s:",tipo);
    scanf("%f",&valor);
    return valor;
}
float calculaHorasExtras(float hed,float sal,float hen){
    float horasExtras= hed * sal/160 + hen * 1.2 * sal/160;
    return horasExtras;
}
float calculaSalarioFamilia(float nd){
     float salarioFamilia=(nd* 0.05 * 1212.00);
     return salarioFamilia;
}
float calculaSalarioBruto(float sal,float horasExtras, float salarioFamilia){
     float salarioBruto=sal + horasExtras + salarioFamilia;
     return salarioBruto;
}
float calculaInamps(float sal){
    float inamps = 0.08 * sal;
    return inamps;
}
float calculaFaltas(float sal,float fal){
    float faltas = fal * sal/160;
    return faltas;
}
float calculaImpostoDeRenda(float salarioBruto){
      float impostodeRenda = 0.08 * salarioBruto;
      return impostodeRenda;
}
float calculaDescontoTotal(float faltas, float ref,float de,float va,float inamps,float impostoDeRenda){
    float descontoTotal= faltas+ref+de+va+inamps+impostoDeRenda;
    return descontoTotal;
}
float calculaSalarioLiquido(float salarioBruto,float descontoTotal){
     float salarioLiquido= salarioBruto-descontoTotal;
     return salarioLiquido;
}

funcionario calculaValores(funcionario f){
    f.horasExtras= calculaHorasExtras(f.hed,f.sal,f.hen);
    f.salarioFamilia=calculaSalarioFamilia(f.nd);
    f.salarioBruto=calculaSalarioBruto(f.sal,f.horasExtras,f.salarioFamilia);
    f.inamps = calculaInamps(f.sal);
    f.faltas = calculaFaltas(f.sal,f.fal);
    f.impostodeRenda = calculaImpostoDeRenda(f.salarioBruto);
    f.descontoTotal= calculaDescontoTotal(f.faltas,f.ref,f.de,f.val,f.inamps,f.impostodeRenda);
    f.salarioLiquido=calculaSalarioLiquido(f.salarioBruto,f.descontoTotal);
    return f;
}
void mostraFolhaDePagamento(funcionario f){
     printf("\n\n                          FOLHA DE PAGAMENTO:\n\n");
    printf("Nome: %s",f.nome);
    printf("Salario: %.2f\n",f.sal);
    printf("Horas Extras: %.2f\n",f.horasExtras);
    printf("Salario Familia: %.2f\n",f.salarioFamilia);
    printf("Salario Bruto: %.2f\n",f.salarioBruto);
    printf("Inamps: %.2f\n",f.inamps);
    printf("Faltas: %.2f\n",f.faltas);
    printf("Refeicoes; %.2f\n",f.ref);
    printf("Descontos Eventuais: %.2f\n",f.de);
    printf("Vales: %.2f\n",f.val);
    printf("Imposto de renda: %.2f\n",f.impostodeRenda);
    printf("Salario Liquido: %.2f\n",f.salarioLiquido);
}
int main()
{
  funcionario funcionario1;
  char nome[50];
  fflush(stdin);
  printf("Digite seu nome: ");
  fgets(nome,50,stdin);
  strcpy(funcionario1.nome,nome);
  funcionario1.sal=lerValores("do seu salario");
  funcionario1.hed=lerValores("das suas horas extras diurnas");
  funcionario1.hen=lerValores("das suas horas extras noturnas");
  funcionario1.nd=lerValores("dos seus numeros de dependentes");
  funcionario1.fal=lerValores("das faltas em horas");
  funcionario1.de=lerValores("dos descontos eventuais");
  funcionario1.ref=lerValores("dos seus gastos com refeicoes");
  funcionario1.val=lerValores("dos seus vales retirados");
  funcionario1=calculaValores(funcionario1);
  mostraFolhaDePagamento(funcionario1);
  return 0;
}