#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "CustumersPage.h"
#include "FinancierPage.h"
#include "TaskPage.h"
#include "PotentialCustomersPage.h"

int Menu(){
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------------P�ginas--------------------\n");
    printf("\t\t1 - Clientes\n");
    printf("\t\t2 - Financeiro\n");
    printf("\t\t3 - Tarefas\n");
    printf("\t\t4 - Poss�veis clientes\n");
    printf("\t\t0 - Voltar para login\n");
    printf("-----------------------------------------------\n");

	//entrada do numero da fun��o
    printf("Digite o n�mero da p�gina desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        CustomersPage();
        break;
    case 2:
        system("cls");
        FinancierPage();
        break;
    case 3:
        system("cls");
        TaskPage();
        break;
    case 4:
        system("cls");
        PotentialCustomersPage();
        break;
    default:
        system("cls");
        break;
    }
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 4){
        printf("\t\tO n�mero da p�gina n�o e v�lido\n");
    }
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da fun��o principal main
}
