#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int FinancierPage(){
    //setlocale permite usar acentos para isso precisa inportar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------P�gina de finan�as---------------\n");
    printf("1 - ver todas as informa��es de finan�as\n");
    printf("2 - adicionar uma nova informa��o\n");
    printf("3 - remover uma informa��o\n");
    printf("4 - editar uma informa��o\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o n�mero da Fun��o desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        printf("ver todas as informa��es de finan�as\n");
        break;
    case 2:
        system("cls");
        printf("adicionar uma nova informa��o\n");
        break;
    case 3:
        system("cls");
        printf("remover uma informa��o\n");
        break;
    case 4:
        system("cls");
        printf("editar uma informa��o\n");
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
