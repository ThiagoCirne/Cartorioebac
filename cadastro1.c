#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço da memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca de string



int registro()//essas funçoes sao fora da main, pq so vao acontecer quando forem chamadas. Na main, sempre vao rodar, e a principal
{	
	setlocale(LC_ALL, "Portuguese"); //informando o idioma

	//int escolha=0;
	char escolha[1];

	char arquivo[41];//criando as variaveis com numero max. de 40 caractere
	char cpf[41];
	char nome[41];
	char sobrenome[41];
	char cargo[41];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);// estamos colocando o valor digitado dentro da var cpf, como e string usa %s
	
	strcpy(arquivo, cpf); //estamos copiando o valor da var cpf para a var arquivo
	
	FILE *file; // estamos abrindo a pasta File da biblioteca(ja gravada) e criando um arquivo file
	
	file = fopen(arquivo, "w");//esta criando o 1 arquivo "w" escrever.
	fprintf(file, "CPF: " );
	fclose(file);
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo file criado, dando um nome a ele com o valor da var copiado de cpf, informando que estaremos escrevendo algo nele
	fprintf(file, cpf );//estamos salvando na pasta file o valor da var de cpf
	fclose(file);//estamos fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo novamente e informando que vamos atualiza-lo
	fprintf(file, ",");//estamos escrevendo na file uma virgula
	fclose(file);//fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	

	printf("Deseja cadastrar mais algum usuário?\n ");
	printf("Digite '1' para sim ou '2' para não:  ");
	scanf("%d", &escolha);
	
		
	//if(escolha == "s") {  uma opcoa a ser usada com if, porem esta colocando junto o nome digitado do cpf e o nome*
	//	system("cls");
	//	registro();
	//}
	
	//if(escolha == "n"){
	//	system("cls");
	//	main();
	//}
	//switch(escolha)// essa parte foi criada para perguntar a opcao para poder retornar paro novo registro ou ir para menu principal
	//{
	//	case 1:
	//	system("cls");
	//	registro();
	//	break;
		
	//	case 2:
	//	system("cls");
	//	main();
	//	break;
		
	//	default:
	//	printf("Opção inválida\n");
	//	system("pause");
	//	break;		
	//}	
	//system("pause");
		
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[41];//criando uma variavel a ser consultada
	char conteudo[200];//criando uma variavel para ser feito uma copia com os valores de cpf para ela, caso tenha cadastro
	
	printf("Consulta de Usuário! \n\n");
	printf("Digite o CPF a ser consultado:" );
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//estamos dando o comando de abrir a pasta file, ler arquivos das variaveis cpf
	
	if(file == NULL)//se na pasta file tiver arquivo vazio para aquele cpf, daremos o comando abaixo
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)// enquanto estiver valores, vai esta salvando na var=conteudo, os 200 caracteres maximo que estao dentro da pasta file, referente ao cpf informada que esta sendo lido
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);//mostrar na tela, os valores que estao dentro da string, a variavel conteudo que agora tem os valores dos dados lidos em cpf
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[41];
	
	printf("Digite o CPF a ser deleletado: ");
	scanf("%s", cpf);
	
	remove(cpf);//deleta o arquivo informada
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//verifica se o cpf existe, caso nao existe exibe a mensagem
	{
		printf("\nO usuário não se encontra no sistema!.\n");			
		system("pause");		
	}
	
	fclose(file);	
}



int main()
{
	int opcao=0;// declarando uma variavel
	int laco=1;
	
	for(laco=1;laco=1;)//com esse laco, ele percorre todo o codigo e volta perguntando se laco=1, como nao tem acrecimo sempre vai ser e ele repete o menu
	{
	
		system("cls");//apaga a tela anterior
	
	
		setlocale(LC_ALL, "Portuguese"); //informando o idioma
	
		printf("### Cartório da EBAC ###\n\n");//inicio do programa
		printf("\t1 - Registrar Usuário\n");
		printf("\t2 - Consultar Usuários\n");
		printf("\t3 - Deletar Usuário\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Escolha uma opção: ");//fim do programa
	
		scanf("%d", &opcao);//armazenando valor digitado na variavel opcao
	
		system("cls");//limpando a tela
	
	
		switch(opcao)//condicional usando este modelo switch_case
		{
			case 1://condicionais
			registro();//estou chamando o que esta dentro da funcao registro
			break;//parar o comando
			
			case 2:
			consulta();//estou chamanado o que esta na funçao consulta, fora da  main
			break;
			
			case 3:
			deletar();//chamando o que esta na funçao deletar, fora da main
			break; 
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Opção inválida\n");
			system("pause");
			break;	
		}
	
		
	}
}

