 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int PotentialCustomersPage(){
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("---------P�gina de possiveis clientes----------\n");
    printf("1 - ver todos os possiveis clientes\n");
    printf("2 - adicionar um novo possivel cliente\n");
    printf("3 - remover um possivel cliente\n");
    printf("4 - editar um possivel cliente\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o n�mero da Fun��o desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        printf("ver todos os possiveis clientes\n");
        break;
    case 2:
        system("cls");
        printf("adicionar um novo possivel cliente\n");
        break;
    case 3:
        system("cls");
        printf("remover um possivel cliente\n");
        break;
    case 4:
        system("cls");
        printf("editar um possivel cliente\n");
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
