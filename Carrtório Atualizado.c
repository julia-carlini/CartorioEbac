#include <stdio.h> //biblicoteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de alo��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar o usu�rio no sistema
{ 
	// In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final de cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletar informa��es com o usu�rio
	scanf("%s", cpf); //%s refere-se a strings, salvar string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // "w" cria o arquivo, "w" siginifica escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" acessa informa��o dentro do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" acessa informa��o dentro do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" acessa informa��o dentro do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" ler ou procurar o arquivo no documento
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o CPF!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" ler o arquivo cpf
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
	printf("Login Administradador.\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

		system("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls");
			setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
			printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Op��o:");//Fim do menu
	
			scanf("%d" , &opcao);//armazenando a escolha do usu�rio
	
			system("cls"); //respons�vel por limpar a tela
		
			switch(opcao) // In�cio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4: 
				printf("Obrigada por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel.\n");
				system("pause");
				break;
				
			}	// fim da sele��o
	 	}
	 	
	}
	
			else
				printf("Senha incorreta");
	

}
