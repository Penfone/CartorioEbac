#include <stdio.h> //biblioteca de comunica��o com o �suario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Definindo a regi�o da biblioteca locale
	setlocale(LC_ALL, "Portuguese");
	
	
	//CPF ---------------------------------
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Respons�vel por copiar o valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//"w" escreve/cria
	fprintf(file, cpf);//salva o valor no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//Nome-----------------------------------
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//"a" atualiza
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	//Sobrenome------------------------------------
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	//Cargo-------------------------------------------
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	//Definindo a regi�o da biblioteca locale
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" l�
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");		
	}
	
	
	
}


int main()
{
	//V�riaveis
	int opcao = 0;
	int x = 1;
	
	for(x=1;x=1;)
	{
		system("cls");
	
		//Definindo a regi�o da biblioteca locale
		setlocale(LC_ALL, "Portuguese");
		
		//Menu
		printf("### Cart�rio da EBAC ### \n\n");	
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1-Registrar nomes \n");
		printf("\t2-Consultar nomes \n");
		printf("\t3-Deletar nomes \n\n");
		
		printf("\t-> ");
		//Pegando valor que o usu�rio digitar e passando para a v�riavel
		scanf("%d", &opcao);
		
		//limpa a tela
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("\tEssa op��o n�o est� disponivel \n\n");
			system("pause");
			break;	
								
		}
	}
}
