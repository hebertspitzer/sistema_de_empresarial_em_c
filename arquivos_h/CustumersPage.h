#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//declarando uma struct
typedef struct {
	char id[5];
	char name[26];
	char cnpj[15];
}Cliente;

//declarando as fun��es
void CriaCliente();
void ListaClientes();
void ExcluiCliente();
void EditarCliente();

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

	//entrada do numero da fun��o
    printf("Digite o n�mero da Fun��o desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
    	system("cls");
        ListaClientes();
        break;
    case 2:
    	system("cls");
        CriaCliente();
        break;
    case 3:
        system("cls");
        ExcluiCliente();
        break;
    case 4:
        system("cls");
        EditarCliente();
        break;
    default:
        system("cls");
        break;
    }
    if(select < 0 || select > 4){
    	//teste para se o usuario inserir numero menor ou maior do que o permitido
        printf("O n�mero da fun��o n�o e v�lido\n");
    }
    
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da fun��o principal main
}


//cria��o da fun��o CriaCliente

void CriaCliente() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/clientes.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declara��o das variaveis
	Cliente tcliente;
	char tstring[26];
	
	//entrada do id do cliente
	printf("Digite o id do cliente: ");
	scanf( "%4s", tcliente.id);
	fflush(stdin);
	
	//entrada do nome do cliente
	printf("Digite o nome do cliente: ");
	scanf( "%25[^\n]s", tcliente.name);
	fflush(stdin);
	
	//tratamento do nome do cliente alterando o espa�o por "_" e salvando em outra string
	for(int i = 0; i < 26; i++) {
        if (tcliente.name[i] == ' '){
        	tstring[i] = '_';
		}else if(tcliente.name[i] == '\n'){
        	tstring[i] = '\0';
        }else{
        	tstring[i] = tcliente.name[i];
		}
    }
    
    //entrada do cnpj do cliente
	printf("Digite o cnpj do cliente: ");
	scanf( "%14s", tcliente.cnpj);
	fflush(stdin);
	system("cls");
	
	
	printf("\t------Cliente adicionado com sucesso------\n");
	printf("id: %s\n",tcliente.id);
	printf("name: %s\n",tcliente.name);
	printf("cnpj: %s\n\n",tcliente.cnpj);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %s %s", tcliente.id, tstring, tcliente.cnpj);
	
	//fechando o arquivo
	fclose(farq);
}


//cria��o da fun��o ListaClientes
void ListaClientes(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/clientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		//declara��o das variaveis
		Cliente tcliente;
		char tstring[26];
		
		//lendo as infos do arquivo e salvando na struct tcliente
		fscanf(farq, "%s %s %s", tcliente.id, tcliente.name, tcliente.cnpj);
		
		//tratando o nome do cliente, trocando o "_" por espa�o
		for(int i = 0; i < 26; i++) {
        if (tcliente.name[i] == '_'){
        	tstring[i] = ' ';
		}else{
        	tstring[i] = tcliente.name[i];
		}
    	}
    	
    	//imprimindo as infos da struct tcliente
		printf("Id:%s \nNome:%s \nCNPJ:%s\n--------------------------------\n", tcliente.id, tstring, tcliente.cnpj);
	}
	
	//fechando o arquivo
	fclose(farq);
}

//cria��o da fun��o ExcluiCliente AINDA NAO ESTA FUNCIONANDO
void ExcluiCliente(){
	//declara��o das variaveis
	Cliente tcliente[50];
	int cont=0, excCliente=-1;
	char id[5];
	
	//entrada do id do cliente
	printf("Qual o id do cliente que voce deseja excluir: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/clientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(original == NULL){
		exit(0);
	}
	
	//posicionando no inicio do arquivo
	fseek(original, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(original)){
		//declarando a variavel
		int buscaId;
		
		//lendo as infos do arquivo e salvando nas struct tcliente
		fscanf(original, "%s %s %s", tcliente[cont].id, tcliente[cont].name, tcliente[cont].cnpj);
		
		//buscando o id do cliente digitado
    	buscaId = strncmp(tcliente[cont].id, id, 4);
    	
    	//salvando a posi��o que esta o cliente que deseja remover 
    	if(buscaId == 0){
    		excCliente = cont;
		}
		
		//aumentando o contador para criar um novo cliente
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(excCliente == -1){
		system("cls");
		printf("\nO id do cliente n�o existe\n");
	} else {
	
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo, menos o cliente removido
		for(int i=0;i<cont;i++){
		
			if(i == excCliente) {
				printf("-");
			} else {
				fprintf(alterado, "\n%s %s %s", tcliente[i].id, tcliente[i].name, tcliente[i].cnpj);
			}
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/clientes.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/clientes.txt");
	
		//limpando a tela e falando que o cliente foi excluido
		system("cls");
		printf("o cliente foi excluido com sucesso\n");
	}
}

//cria��o da fun��o EditarCliente
void EditarCliente(){
	//declara��o das variaveis
	Cliente tcliente[50];
	int cont=0, clienteSel=-1;
	char id[5];
	
	//entrada do id da tarefa
	printf("Qual o id da tarefa que voce deseja editar: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/clientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(original == NULL){
		exit(0);
	}
	
	//posicionando no inicio do arquivo
	fseek(original, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(original)){
		//declarando a variavel
		int buscaId;
		
		//lendo as infos do arquivo e salvando nas struct ttarefas
		fscanf(original, "%s %s %s", tcliente[cont].id, tcliente[cont].name, tcliente[cont].cnpj);
		
		//buscando o id da tarefa digitado
    	buscaId = strncmp(tcliente[cont].id, id, 4);
    	
    	//salvando a posi��o que esta a tarefa que deseja editar
    	if(buscaId == 0){
    		clienteSel = cont;
		}
		
		//aumentando o contador para criar uma nova tarefa
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(clienteSel == -1){
		system("cls");
		printf("\nO id do cliente n�o existe\n");
	} else {
		//var usada para selecionar o item do menu
		char tstring[26];
    	int select;
		do{
    		printf("------------O que vc deseja editar?------------\n");
    		printf("1 - Id\n");
    		printf("2 - Nome\n");
    		printf("3 - Cnpj\n");
    		printf("-----------------------------------------------\n");
	
			//entrada do numero da fun��o
    		printf("Digite o n�mero da Fun��o desejada:");
    		scanf("%d",&select);

    		//switch case usado para selecionar o item do menu
    		switch (select)
    		{
    		case 1:
    			fflush(stdin);
    			system("cls");
        		printf("Digite o novo Id do cliente:");
        		scanf( "%4s", tcliente[clienteSel].id);
				fflush(stdin);
				printf("\n%s %s %s\n",tcliente[clienteSel].id);
       		 	break;
    		case 2:
    			system("cls");
    			fflush(stdin);
				//entrada do nome do cliente
				printf("Digite o nome do cliente: ");
				fgets(tstring, sizeof(tstring), stdin);
				fflush(stdin);
				
				//tratamento do nome do cliente alterando o espa�o por "_" e salvando em outra string
				for(int i = 0; i < 26; i++) {
			        if (tstring[i] == ' '){
			        	tcliente[clienteSel].name[i] = '_';
					}else if(tstring[i] == '\n'){
			        	tcliente[clienteSel].name[i] = '\0';
			        }else{
			        	tcliente[clienteSel].name[i] = tstring[i];
					}
			    }
				fflush(stdin);
        		break;
    		case 3:
        		system("cls");
        		fflush(stdin);
        		//entrada do cnpj do cliente
				printf("Digite o cnpj do cliente: ");
				scanf( "%14s", tcliente[clienteSel].cnpj);
				fflush(stdin);
				system("cls");
        		break;
    		default:
        		system("cls");
        		break;
    		}
    		//teste para se o usuario inserir numero menor ou maior do que o permitido
    		if(select < 0 || select > 3){
        		printf("O n�mero da fun��o n�o e v�lido\n");
    		}
			//so sai do loop se o valor tiver uma funcao
		}while (select < 0 || select > 3);
		
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo e a tarefa editada
		for(int i=0;i<cont;i++){
			fprintf(alterado, "\n%s %s %s", tcliente[i].id, tcliente[i].name, tcliente[i].cnpj);
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/clientes.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/clientes.txt");
	
		//limpando a tela e falando que a tarefa foi editado
		system("cls");
		printf("o cliente foi editada com sucesso\n");
	}
}

