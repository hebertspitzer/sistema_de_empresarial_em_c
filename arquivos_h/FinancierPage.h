#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	float valorEnt;
	float valorSaido;
}Financas;

void CriaFinancas();
void ListaFinancas();

int FinancierPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");
    
    setlocale(LC_NUMERIC, "pt_BR");

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
        ListaFinancas();
        break;
    case 2:
    	system("cls");
        CriaFinancas();
        break;
    case 3:
        system("cls");
        printf("remover uma finan�a\n");
        break;
    case 4:
        system("cls");
        printf("editar uma finan�a\n");
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

void CriaFinancas() {
	FILE *farq = fopen("arquivos_txt/financas.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	Financas tfinancas;
	
	printf("Digite o valor entrado: ");
	scanf( "%f", &tfinancas.valorEnt);
	fflush(stdin);
	printf("Digite o valor saido: ");
	scanf( "%f", &tfinancas.valorSaido);
	fflush(stdin);
	
	printf("\t------Finan�a adicionada com sucesso------\n");
	printf("valor entrado: %f\n",tfinancas.valorEnt);
	printf("valor saido: %f\n",tfinancas.valorSaido);
	
	fprintf(farq, "\n%f %f", tfinancas.valorEnt, tfinancas.valorSaido);
	fclose(farq);
}

void ListaFinancas(){
	FILE *farq = fopen("arquivos_txt/financas.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		Financas tfinancas;
		fscanf(farq, "%f %f", &tfinancas.valorEnt, &tfinancas.valorSaido);
		printf("Valor entrado: %f \nValor saido: %f\n--------------------------------\n", tfinancas.valorEnt, tfinancas.valorSaido);
	}
	fclose(farq);
}

