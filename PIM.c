#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_PEOPLE 100

//Struct login
typedef struct {
  char login[30];
  char senha[30];
} pessoa;
pessoa p[MAX_PEOPLE];

//Struct produto
typedef struct{

char nome[31];
int pid;
float valor;
} produto;
produto p1, p2, p3, p4;



//Matriz cliente
int cid[SIZE];
int cnpj[SIZE];
int ctelefone[SIZE];
char crs[SIZE][50];
char cemail[SIZE][50];
char cendereco[SIZE][100];

//Matriz funcionário
int fid[SIZE];
char fnome[SIZE][100];
int fcpf[SIZE];
char fcargo[SIZE][50];
int ftelefone[SIZE];
char femail[SIZE][50];
char fendereco[SIZE][100];
float fcomissao[SIZE];

//Matriz venda
int vid[SIZE];
float vtotal[SIZE];
float vcomissao[SIZE];

//Protótipos de Funções
void cadastro_cliente();
void cadastro_produto();
void cadastro_funcionario();
void relatorio_cliente();
void relatorio_funcionario();


//Função Login-Cadastro
void log_in_register(FILE*fpIN, char login[30], char senha[30], char ConfirmarSenha[30])
{
  if ((strcmp(senha, ConfirmarSenha) == 0)) {
        printf("Cadastrado com sucesso!");
        fprintf(fpIN, "\n%s %s", login, senha);
        fclose(fpIN);
      } else {
        printf("As senhas não coincidem.");
      }

  }
//Função Cadastro Cliente
void cadastro_cliente(){
static int linha;
int op1de1;
do{
  printf("\n***Sistema FGGRT Telecom***\n");
  printf("\nCadastrar Cliente:\n\n");
  printf("Digite o CNPJ:\n");
  scanf(" %d", &cnpj[linha]);
  fflush(stdin);
  printf("\nDigite a Razão Social:\n");
  scanf(" %[^\n]s", crs[linha]);
  fflush(stdin);
  printf("\nDigite o Telefone:\n");
  scanf(" %d", &ctelefone[linha]);
  fflush(stdin);
  printf("\nDigite o E-mail:\n");
  scanf(" %s", cemail[linha]);
  fflush(stdin);
  printf("\nDigite o Endereço:\n");
  scanf(" %[^\n]s", cendereco[linha]);
  fflush(stdin);
  printf("\nDigite 1 para Cadastrar um novo Cliente ou 2 para sair: \n");
  scanf(" %d", &op1de1);
  fflush(stdin);
  linha++;
  system("clear");

}while(op1de1==1);

}

//Função Cadastro Produto
void cadastro_produto(){
static int linha;
int op2de1;
do{
  printf("\n***Sistema FGGRT Telecom***\n");
  printf("\nCadastrar Produto:\n\n");
  fflush(stdin);
  printf("Digite o Nome do Produto:\n");
  scanf(" %[^\n]s", p4.nome);
  fflush(stdin);
  printf("\nDigite o Valor do Produto:\n");
  scanf(" %f", &p4.valor);
  fflush(stdin);
  printf("\nDigite 1 para Cadastrar um novo Produto ou 2 para sair: \n");
  scanf(" %d", &op2de1);
  fflush(stdin);
  linha++;
  system("clear");

}while(op2de1==1);

}

//Função Cadastro Funcionário
void cadastro_funcionario(){
static int linha;
int op3de1;
do{
  printf("\n***Sistema FGGRT Telecom***\n");
  printf("\nCadastrar Funcionário:\n\n");
  printf("Digite o ID:\n");
  scanf(" %d", &fid[linha]);
  fflush(stdin);
  printf("\nDigite o Nome:\n");
  scanf(" %[^\n]s", fnome[linha]);
  fflush(stdin);
  printf("\nDigite o CPF:\n");
  scanf(" %d", &fcpf[linha]);
  fflush(stdin);
  printf("\nDigite o Cargo:\n");
  scanf(" %[^\n]s", fcargo[linha]);
  fflush(stdin);
  printf("\nDigite o Telefone:\n");
  scanf(" %d", &ftelefone[linha]);
  fflush(stdin);
  printf("\nDigite o E-mail:\n");
  scanf(" %[^\n]s", femail[linha]);
  fflush(stdin);
  printf("\nDigite o Endereço:\n");
  scanf(" %[^\n]s", fendereco[linha]);
  fflush(stdin);
  printf("\nDigite 1 para Cadastrar um novo Funcionário ou 2 para sair: \n");
  scanf(" %d", &op3de1);
  fflush(stdin);
  linha++;
  system("clear");

}while(op3de1==1);

}

//Função relátório cliente
void relatorio_cliente(){
int i;
  printf("\n***Sistema FGGRT Telecom*** \n");
  printf("Relatório de Clientes");
  for(i=0;i<SIZE;i++){
  if(cnpj[i]>0){
  printf("\nID1: %d | CNPJ: %d | Razão Social: %s | Telefone: %d | E-mail: %s | Endereço: %s\n", cid[i], cnpj[i], crs[i], ctelefone[i], cemail[i], cendereco[i]);
  }else{
  break;
  }
  }
  }

//Função relátório funcionario
void relatorio_funcionario(){
int i;
  printf("\n***Sistema FGGRT Telecom*** \n");
  printf("Relatório de Funcionários");
  for(i=0;i<SIZE;i++){
  if(fid[i]>0){
  printf("\nID: %d | Nome: %s | CPF: %d | Cargo: %s | Telefone: %d | E-mail: %s | Endereço: %s | Comissão: %.2f\n", fid[i], fnome[i], fcpf[i], fcargo[i], ftelefone[i], femail[i], fendereco[i], fcomissao[i]);
  }else{
  break;
  }
  }
  }

int main(void)
{

strcpy(p1.nome, "Configurar Voip");
p1.valor = 250.00;
p1.pid = 0001;
strcpy(p2.nome, "Configurar Modem");
p2.valor = 150.00;
p2.pid = 0002;
strcpy(p3.nome, "Configurar Switcher");
p3.valor = 1000.00;
p3.pid = 0003;
p4.pid = 0004;

FILE *fpIN;
int vqtd;
float valor_pedido;
char *arquivo = "usuarios.txt";
char login[30];
char senha[30];
char ConfirmarSenha[30];
int select = 0;


//switch cases
int op, op2, op3, op4, option, i, ip, result;

  do{
    printf("\n\n-----------------------");
    printf("\n     FGGRT Telecom\n");
    printf("-----------------------\n");
    printf("1) Login\n2) Cadastrar\n3) Sair\n");
    scanf("%d", &option);

    switch (option) {
    case 1:
      fpIN = fopen(arquivo, "r");
      int number[3];
      int i = 0;

      printf("\nLogin: ");
      scanf("%s", &login);

      printf("Senha: ");
      scanf("%s", &senha);


      while (!feof(fpIN)) {
        i++;
        fscanf(fpIN, "%s %s", p[i].login, p[i].senha);
       }

      for (int x = 1; x <= MAX_PEOPLE; x++) {
        if ((strcmp(login, p[x].login) == 0)) {
           number[0] = x;
           number[1] = 1;
           break;
         } else {
           number[1] = 0;
           number[0] = 0;
         }
       }

      if (number[1] == 1) {
        if ((strcmp(p[number[0]].senha, senha) == 0)) {
          printf("Usuário logado");
          select = 1;

        }else {
          printf("Senha incorreta");
        }
      } else {
        printf("Login incorreto");
      }

      fclose(fpIN);
      system("clear");
      break;

    case 2:

      fpIN = fopen(arquivo, "a");

      printf("\nLogin: ");
      scanf("%s", &login);

      printf("Senha: ");
      scanf("%s", &senha);

      printf("Confirmar senha: ");
      scanf("%s", &ConfirmarSenha);

      log_in_register(fpIN, login, senha, ConfirmarSenha);

      break;

    case 3:
      return 0;

    default:
      printf("Escolha 1, 2 ou 3...\n");
      break;
    }

  } while(select == 0);

  do
  {
  printf("\n\n\n***Sistema FGGRT Telecom*** \n");
  printf("\nMenu Principal:\n");
  printf("\n1) Cadastros");
  printf("\n2) Relatórios");
  printf("\n3) Vendas");
  printf("\n4) Arquivos");
  printf("\n5) Sair");
  printf("\nDigite a escolha: ");
  scanf("%d",&op);
  fflush(stdin);
  system("clear");

  //menu principal
  switch (op)
    {
  //Cadastros
  case 1:

  do
      {
  printf("\n***Sistema FGGRT Telecom***\n");
  printf("\nCadastros:\n\n");
  printf("1) Cadastrar Cliente\n");
  printf("2) Cadastrar Produto\n");
  printf("3) Cadastrar Funcionário\n");
  printf("4) Voltar\n");
  printf("Digite a escolha: ");
  scanf("%d",&op2);
  fflush(stdin);
  system("clear");

  switch(op2)
        {
 //Cadastrar Cliente
  case 1:
  cadastro_cliente();

  break;
//Cadastrar Produto
  case 2:
  cadastro_produto();

  break;
//Cadastrar Perfil
  case 3:
  cadastro_funcionario();
  break;

        }
      }while(op2==4);

  break;

//Relatórios
  case 2:
  do{
  printf("\n***Sistema FGGRT Telecom*** \n");
  printf("\nRelatórios:\n\n");
  printf("1) Relatório de Cliente\n");
  printf("2) Relatório de Produtos\n");
  printf("3) Relatório de Funcionários\n");
  printf("4) Voltar\n\n");
  scanf("%d",&op3);
  fflush(stdin);
  system("clear");

  switch(op3){
 //Relatório de Cliente
  case 1:
relatorio_cliente();
  break;

//Relatório de Produtos
  case 2:
  printf("\n***Sistema FGGRT Telecom*** \n");
  printf("Relatório de Produtos: \n\n");
  printf("ID: %d | Produto: %s | Valor: %.2f\n", p1.pid, p1.nome, p1.valor);
  printf("ID: %d | Produto: %s | Valor: %.2f\n", p2.pid, p2.nome, p2.valor);
  printf("ID: %d | Produto: %s | Valor: %.2f\n", p3.pid, p3.nome, p3.valor);
  printf("ID: %d | Produto: %s | Valor: %.2f\n", p4.pid, p4.nome, p4.valor);
  break;

//Relatório de Comissões
  case 3:
relatorio_funcionario();
  break;

  }
  }while(op3==4);

  return main();

  break;

//Vendas
  case 3:
  printf("\n***Sistema FGGRT Telecom*** \n");
  printf("\nVenda: \n");
  printf("\n1) %s     |  R$%.2f\n2) %s  |  R$%.2f\n3) %s  |  R$%.2f\n4) %s  |  R$%.2f\nSelecione o Produto: ",p1.nome,p1.valor,p2.nome,p2.valor,p3.nome,p3.valor,p4.nome,p4.valor);

  scanf("%d",&ip);

  switch(ip){
  case 1:
  printf("\nInsira a quantidade: ");
  scanf("%d",&vqtd);
valor_pedido = vqtd*p1.valor;

  printf("\nSeu pedido deu R$ %.2f",valor_pedido);

  break;
  case 2:
  printf("\nInsira a quantidade: ");
  scanf("%d",&vqtd);
valor_pedido = vqtd*p2.valor;

  printf("\nSeu pedido deu R$ %.2f",valor_pedido);
  break;
  case 3:
  printf("\nInsira a quantidade: ");
  scanf("%d",&vqtd);
valor_pedido = vqtd*p3.valor;

  printf("\nSeu pedido deu R$ %.2f",valor_pedido);
  break;
  case 4:
    printf("\nInsira a quantidade: ");
  scanf("%d",&vqtd);
valor_pedido = vqtd*p4.valor;

  printf("\nSeu pedido deu R$ %.2f",valor_pedido);

  break;
    }
  break;
//Arquivos
  case 4:
  printf("Imprimir Relatório de Cliente em arquivo\n");
  FILE *q;
  q=fopen("relatoriocliente.txt","a");

  if(q==NULL){
  printf("\nErro ao abrir o arquivo.\n");
  }

  else{
  printf("\nArquivo aberto com sucesso.\n");
  result = fprintf(q,&p1.pid);
  if (result == EOF){ printf("Erro na Gravação\n");}
  fclose(q);
  printf("\nArquivo fechado com sucesso");
  }
  break;

  case 5:
  printf("Programa encerrado");
  return 0;
    }
  }while(op==5);
  return main();
}
