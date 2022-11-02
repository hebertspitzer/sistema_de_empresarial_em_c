#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declarando uma struct
typedef struct {
	float valorEnt;
	float valorSaido;
}Financas;

//declarando as fun��es
void CriaFinancas();
void ListaFinancas();

int FinancierPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");
    
    //configurando para aceitar virgula no float
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

	//entrada do numero da fun��o
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
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 4){
        printf("O n�mero da fun��o n�o e v�lido\n");
    }
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da fun��o principal main
}


//cria��o da fun��o CriaFinancas
void CriaFinancas() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/financas.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declara��o das variaveis
	Financas tfinancas;
	
	//entrada do valor entrado
	printf("Digite o valor entrado: ");
	scanf( "%f", &tfinancas.valorEnt);
	fflush(stdin);
	
	//entrada do valor saido
	printf("Digite o valor saido: ");
	scanf( "%f", &tfinancas.valorSaido);
	fflush(stdin);
	
	printf("\t------Finan�a adicionada com sucesso------\n");
	printf("valor entrado: %f\n",tfinancas.valorEnt);
	printf("valor saido: %f\n",tfinancas.valorSaido);
	
	//salvando as informa��es no arquivo txt
	fprintf(farq, "\n%f %f", tfinancas.valorEnt, tfinancas.valorSaido);
	
	//fechando o arquivo
	fclose(farq);
}

//cria��o da fun��o ListaFinancas
void ListaFinancas(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/financas.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		
		//declara��o das variaveis
		Financas tfinancas;
		
		//lendo as infos do arquivo e salvando na struct tfinancas
		fscanf(farq, "%f %f", &tfinancas.valorEnt, &tfinancas.valorSaido);
		
		//imprimindo as infos da struct tfinancas
		printf("Valor entrado: %f \nValor saido: %f\n--------------------------------\n", tfinancas.valorEnt, tfinancas.valorSaido);
	}
	
	//fechando o arquivo
	fclose(farq);
}

