#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char id[5];
	char name[26];
	char cnpj[15];
}Cliente;

void CriaCliente();

int CustomersPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------P�gina de clientes---------------\n");
    printf("1 - Ver todos os clientes\n");
    printf("2 - adicionar novo cliente\n");
    printf("3 - remover um cliente\n");
    printf("4 - editar um cliente\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o n�mero da Fun��o desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
    	system("cls");
        printf("Ver todos os clientes\n");
        break;
    case 2:
    	system("cls");
        printf("adicionar novo cliente\n");
        CriaCliente();
        break;
    case 3:
        system("cls");
        printf("remover um cliente\n");
        break;
    case 4:
        system("cls");
        printf("editar um cliente\n");
        break;
    default:
        system("cls");
        break;
    }
    if(select < 0 || select > 4){
        printf("O n�mero da fun��o n�o e v�lido\n");
    }

}while (select != 0);

}

void CriaCliente() {
	FILE *farq = fopen("clientes.bin", "rb");
	if(farq == NULL){
		exit(0);
	}
	Cliente tcliente;
	
	printf("Digite o id do cliente: ");
	scanf( "%4s", tcliente.id);
	fflush(stdin);
	printf("Digite o nome do cliente: ");
	scanf( "%25[^\n]s", tcliente.name);
	fflush(stdin);
	printf("Digite o cnpj do cliente: ");
	scanf( "%14s", tcliente.cnpj);
	fflush(stdin);
	
	printf("id: %s\n",tcliente.id);
	printf("name: %s\n",tcliente.name);
	printf("cnpj: %s\n",tcliente.cnpj);
	
	fwrite(&tcliente, sizeof(Cliente), 1, farq);
	fclose(farq);
}
