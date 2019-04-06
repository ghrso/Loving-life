#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXTAM 100

typedef struct voo{

	char prefixo[5];
	char tipo_aeronave[30];
	int hora_partida, min_partida;
	int hora_chegada, min_chegada;
	int hora_duracao, min_duracao;

} DADOS_VOO;

typedef struct pessoa{

	char nome_empresa[50];
	char nome_pessoa[50];
	char categoria[20];
	char CPF[11];
	int Saldo;

} DADOS_PESSOA;

typedef struct aeronave{

	char modelo[20];
	float comprimento;
	float altura;
	float envergadura;
	float velocidade;
	float alcance;
	int qtd_assentos;
	int qtd_banheiros;

} DADOS_AERONAVE;

typedef struct aeroporto{

	char nome_ORIGEM[50];
	char nome_DESTINO[50];
	char sigla_ORIGEM[6];
	char sigla_DESTINO[6];

} DADOS_AEROPORTO;

//VETORES p/ ARMAZENAR O CADASTRO NAS STRUCTS VOO E PESSOA
DADOS_PESSOA pessoa[MAXTAM];
DADOS_VOO voo[MAXTAM];
DADOS_AERONAVE aviao[MAXTAM];
DADOS_AEROPORTO aeroporto[MAXTAM];

//VARIAVEIS p/ INDENTIFICAR TAMANHO DOS VETORES ACIMA
int cont_pessoa = 0;
int cont_voo = 0;
int cont_aviao = 0;

//ENTRA COM UMA FRASE E IMPRIME AS OPCOES:
//1. SIM E 2. NAO
//RETORNA APENAS 1 OU 2
int Repete(char string[]){
	int x = 0;

	printf("%s\n1. SIM\n2. NAO\n", string);
	scanf("%d%*c", &x);
	system("cls");

	if(x < 1 || x > 2){
		printf("Escolha invalida!\n");
		return Repete(string);
	}
	
	return x;
}

void INSERIR_PESSOA(){
	int i, ERRO = 1;
	

	//INSERE O NOME DA PESSOA, ACEITANDO APENAS LETRAS
	printf("\nNome do Participante: ");
	gets(pessoa[cont_pessoa].nome_pessoa);
	while(ERRO == 1){
		ERRO = 0;
		system("cls");

		//VERIFICA SE TEM APENAS LETRAS
		for(i = 0 ;i < strlen(pessoa[cont_pessoa].nome_pessoa); i++ ){

			if(pessoa[cont_pessoa].nome_pessoa[i] == ' ')
				i++;

			if (isalpha(pessoa[cont_pessoa].nome_pessoa[i]) == 0) {
				printf("O nome deve ter apenas letras.\n");
				ERRO = 1;
				break;
			}
		}
		if(ERRO == 1) {
			printf("Nome do Participante: ");
			gets(pessoa[cont_pessoa].nome_pessoa);
		}
	}
	system("cls");

	printf("\nInsira o Programa de Fidelidade desejado: ");
	gets(pessoa[cont_pessoa].nome_empresa);
	system("cls");
	ERRO = 1;

	//INSERE O CPF VERIFICANDO SE NAO EXISTE OUTRO IGUAL
	printf("\nCPF: ");
	gets(pessoa[cont_pessoa].CPF);
	while(ERRO == 1){
		ERRO = 0;
			//VERIFICA SE JA EXISTE O CPF
			for(i = 0; i < cont_pessoa; i++) {

				if (strcmp(pessoa[i].CPF, pessoa[cont_pessoa].CPF) == 0) {
					printf("\nCPF JA EXISTENTE NO SISTEMA!!\n");
					ERRO = 1;
					break;
				}
			}

		if(ERRO == 1){
			printf("Tente Novamente:\n");
			gets(pessoa[cont_pessoa].CPF);
		}
	}
	system("cls");

	printf("\nCategoria do Participante: ");
	gets(pessoa[cont_pessoa].categoria);
	system("cls");

	printf("\nSaldo de Milhas: ");
	scanf("%d", &pessoa[cont_pessoa].Saldo);

	cont_pessoa++;

	system("cls");

	printf("                             Participante inserido com sucesso!!\n\n");

	if(Repete("Deseja inserir mais um participante?") == 1)
		return INSERIR_PESSOA();				
}
void INSERIR_VOO(){
   	int ERRO = 0;
	int i;

	printf("\nInsira o Prefixo:\n");
	gets(voo[cont_voo].prefixo);
	for(; ;){
		ERRO = 0;

		//VERIFICA SE JA EXISTE O PREFIXO
		for(i = 0; i < cont_voo; i++) {
			if (strcmp(voo[i].prefixo, voo[cont_voo].prefixo) == 0) {
				printf("\nprefixo ja existente no sistema!!\n");
				ERRO = 1;
				break;
			}
		}

		if(ERRO == 0) break;
		printf("Tente Novamente:\n");
		gets(voo[cont_voo].prefixo);
	}

	printf("\nInsira a SIGLA do aeroporto de origem(Ex. GRU p/ Guarulhos, IGU p/ Foz do iguacu):\n");
	for(; ;){
		ERRO = 0;

		gets(aeroporto[cont_voo].sigla_ORIGEM);

			//TRANFORMA AS 3 PRIMEIRAS LETRAS DA STRING EM MAIUSCULA(SIGLA)
			for(i = 0; i < 3; i++)
				if(isalpha(aeroporto[cont_voo].sigla_ORIGEM[i]) == 0) {

					printf("A sigla do aeroporto deve constituir de 3 letras maiusculas\n");
					ERRO++;
					break;
				}
				else
					for(i = 0; i < 3; i++)
						aeroporto[cont_voo].sigla_ORIGEM[i] = toupper(aeroporto[cont_voo].sigla_ORIGEM[i]);

		if(ERRO == 0) break;
	}

	printf("\nInsira o NOME do aeroporto de origem(Ex. GRU p/ Guarulhos, IGU p/ Foz do iguacu):\n");
	gets(aeroporto[cont_voo].nome_ORIGEM);


	printf("\nInsira a SIGLA do aeroporto de destino(Ex. GRU Guarulhos, IGU Foz do iguacu):\n");
	for(; ;){
		ERRO = 0;
		gets(aeroporto[cont_voo].sigla_DESTINO);


			//TRANFORMA AS 3 PRIMEIRAS LETRAS DA STRING EM MAIUSCULA(SIGLA)
			for(i = 0; i < 3; i++)
				if(isalpha(aeroporto[cont_voo].sigla_DESTINO[i]) == 0) {

					printf("A sigla do aeroporto deve constituir de 3 letras maiusculas\n");
					ERRO++;
					break;
				}
				else
					for(i = 0; i < 3; i++)
						aeroporto[cont_voo].sigla_DESTINO[i] = toupper(aeroporto[cont_voo].sigla_DESTINO[i]);

		//VERIFICA SE OS AEROPORTOS DE ORIGEM E DESTINO SAO IGUAIS
		if(strncmp (aeroporto[cont_voo].sigla_ORIGEM , aeroporto[cont_voo].sigla_DESTINO , 3) != 0)
			break;
		else
			printf("Aeroportos de Origem e de Destino sao iguais.\n"
			"Inserir outro aeroporto de destino!!\n");

		if(ERRO == 0) break;
	}

	printf("\nInsira a NOME do aeroporto de destino(Ex. GRU Guarulhos, IGU Foz do iguacu):\n");
	gets(aeroporto[cont_voo].nome_DESTINO);


	printf("\nInserir horario de partida (hh:mm): ");
		for(; ;){
			scanf("%d%*c%d",&voo[cont_voo].hora_partida,&voo[cont_voo].min_partida);

				if(voo[cont_voo].hora_partida < 0 || voo[cont_voo].hora_partida > 23 || voo[cont_voo].min_partida < 0 || voo[cont_voo].min_partida > 59)
					printf("\nhorario invalido. Disque novamente\n");
				else break;
		}
	
	printf("\nInserir horario de chegada (hh:mm): ");
		for(; ;){
			scanf("%d%*c%d",&voo[cont_voo].hora_chegada,&voo[cont_voo].min_chegada);

				if(voo[cont_voo].hora_chegada < 0 || voo[cont_voo].hora_chegada > 23 || voo[cont_voo].min_chegada < 0 || voo[cont_voo].min_chegada > 59)
					printf("\nHorario invalido. Disque novamente\n");
				else break;
		}
	
	printf("\nInserir duracao do voo (hh:mm): ");
		for(; ;){
			scanf("%d%*c%d%*c",&voo[cont_voo].hora_duracao,&voo[cont_voo].min_duracao);

				if(voo[cont_voo].hora_duracao < 0 || voo[cont_voo].hora_duracao > 23 || voo[cont_voo].min_duracao < 0 || voo[cont_voo].min_duracao > 59)
					printf("\nhorario invalido. Disque novamente\n");
				else break;
		}
	
	printf("\nTipo de aeronave: ");
	gets(voo[cont_voo].tipo_aeronave);


	cont_voo++;

	printf("                             Cadastro realizado com sucesso!!\n\n");
	if(Repete("Deseja adicionar mais um voo?") == 1)
		return INSERIR_VOO();	
}
void INSERIR_AERONAVE(){
	int repete = 0, ERRO, i;

	printf("\nQual modelo da aeronave: ");
	gets(aviao[cont_aviao].modelo);
	for(; ;){
		ERRO = 0;

			//VERIFICA SE JA EXISTE O CPF
			for(i = 0; i < cont_aviao; i++) {
				if (strcmp(aviao[i].modelo, aviao[cont_aviao].modelo) == 0) {
					printf("\nCPF ja existente no sistema!!\n");
					ERRO = 1;
					break;
				}
			}

		if(ERRO == 0) break;
		printf("Tente Novamente:\n");
		gets(aviao[cont_aviao].modelo);
	}

	printf("\nComprimento da aeronave(em metros): ");
	scanf("%f%*c", &aviao[cont_aviao].comprimento);


	printf("\nAltura da aeronave: ");
	scanf("%f%*c", &aviao[cont_aviao].altura);


	printf("\nEnvergadura da aeronave: ");
	scanf("%f%*c", &aviao[cont_aviao].envergadura);


	printf("\nVelocidade de cruzeiro: ");
	scanf("%f%*c", &aviao[cont_aviao].velocidade);


	printf("\nAlcance maximo: ");
	scanf("%f%*c",&aviao[cont_aviao].alcance);


	printf("\nQuantidade de assentos: ");
	scanf("%d%*c", &aviao[cont_aviao].qtd_assentos);


	printf("\nQuantidade de banheiros: ");
	scanf("%d%*c", &aviao[cont_aviao].qtd_banheiros);



	cont_aviao++;

	printf("                             Cadastro realizado com sucesso!!\n\n");
	if(Repete("Deseja adicionar mais uma Aeronave?") == 1)
		return INSERIR_AERONAVE();
}

void CONSULTA_PESSOA(){
	int i,repetir = 1, search = 0;
	int x;
	char cpf_temp[15];

	while(repetir){
		printf("Deseja consultar por CPF ou uma lista de todos participantes?\n1. Consulta por CPF\n2. Lista de Participantes\n");
		scanf("%d%*c", &x);
		if(x < 1 || x > 2)
			printf("Escolha invalida.\n");
		else 
			repetir = 0;
	}


	if(x == 2){
		system("cls");
		for (i = 0; i < cont_pessoa; i++){
			printf("----------------------------------------------------------------------------------------\n");
			printf("Nome do participante: %s\n", pessoa[i].nome_pessoa);
			printf("Programa de Fidelidade: %s\n", pessoa[i].nome_empresa);
			printf("CPF: %s\n", pessoa[i].CPF);
			printf("Categoria: %s\n", pessoa[i].categoria);
			printf("Saldo de Milhas: %d\n", pessoa[i].Saldo);
		}
		if(i != 0) printf("----------------------------------------------------------------------------------------\n");
		system("pause");
		system("cls");
	}
	else{

		system("cls");
		printf("Insira o CPF do participante desejado: ");
		gets(cpf_temp);

		//PROCURA O CPF DIGITADO
		for(i = 0; i <= cont_pessoa; i++)
		{
			//IDENTIFICA O CPF
			if (strcmp( cpf_temp , pessoa[i].CPF ) == 0)
			{
				printf("----------------------------------------------------------------------------------------\n");
				printf("Nome do participante: %s\n", pessoa[i].nome_pessoa);
				printf("Programa de Fidelidade: %s\n", pessoa[i].nome_empresa);
				printf("CPF: %s\n", pessoa[i].CPF);
				printf("Categoria: %s\n", pessoa[i].categoria);
				printf("Saldo de Milhas: %d\n", pessoa[i].Saldo);
				printf("----------------------------------------------------------------------------------------\n");
				search = 1;
			}
		}
		if(search == 0){
			system("cls");
			printf("                   CPF nao encontrado!!\n");
		}
	}
	if (Repete("Deseja consultar novamente?") == 1)
		return CONSULTA_PESSOA();
}
void CONSULTA_VOO(){

	int i, search = 0, repetir = 1, x;
	char voo_temp[10];

	while(repetir){
		printf("Deseja consultar por prefixo ou uma lista com todos voos?\n1. Consulta por prefixo\n2. Lista de Voos\n");
		scanf("%d%*c", &x);
		if(x < 1 || x > 2)
			printf("Escolha invalida.\n");
		else 
			repetir = 0;
	}

	if(x == 2){

		system("cls");
		for(i = 0 ; i < cont_voo ; i++){
			printf("----------------------------------------------------------------------------------------\n");
			printf("Prefixo do voo: %s\n", voo[i].prefixo);
			printf("Saida prevista do aeroporo: %s-%s // horario: (%d:%d)\n",aeroporto[i].sigla_ORIGEM,	aeroporto[i].nome_ORIGEM,		voo[i].hora_partida,	voo[i].min_partida);
			printf("Chegada prevista ao aeroporto: %s-%s // horario: (%d:%d)\n",aeroporto[i].sigla_DESTINO,aeroporto[i].nome_DESTINO,	voo[i].hora_chegada,		voo[i].min_chegada);
			printf("Duracao do voo: (%d:%d)\n",voo[i].hora_duracao,voo[i].min_duracao);
			printf("Tipo de Aeronave: %s\n",voo[i].tipo_aeronave);
		}
		if(i != 0)printf("----------------------------------------------------------------------------------------\n");
		system("pause");
		system("cls");
	}
	else{

		printf("\nInsira o prefixo do Voo que deseja consultar:\n");
		gets(voo_temp);
		system("cls");

		for(i = 0; i < cont_voo; i++)
		{
			if(strcmp(voo_temp,voo[i].prefixo) == 0)
			{
				printf("----------------------------------------------------------------------------------------\n");
				printf("Prefixo do voo: %s\n", voo[i].prefixo);
				printf("Saida prevista do aeroporo: %s-%s // horario: (%d:%d)\n",aeroporto[i].sigla_ORIGEM,	aeroporto[i].nome_ORIGEM,		voo[i].hora_partida,	voo[i].min_partida);
				printf("Chegada prevista ao aeroporto: %s-%s // horario: (%d:%d)\n",aeroporto[i].sigla_DESTINO,aeroporto[i].nome_DESTINO,	voo[i].hora_chegada,		voo[i].min_chegada);
				printf("Duracao do voo: (%d:%d)\n",voo[i].hora_duracao,voo[i].min_duracao);
				printf("Tipo de Aeronave: %s\n",voo[i].tipo_aeronave);
				search++;
			}
			printf("----------------------------------------------------------------------------------------\n");
		}

		if(search == 0){
			system("cls");
			printf("                      Nao foi possivel encontrar nenhum voo com o prefixo digitado!!\n\n");
		}else
			printf("                    %d voo(s) encontrados.\n\n", search);

	}
	if (Repete("Deseja consultar novamente?") == 1)
			return CONSULTA_VOO();
}
void CONSULTA_AERONAVE(){
	int i ,repetir = 0, search;
	char modelo_temp[20];


		printf("Insira o modelo da aeronave desejada:\n");
		gets(modelo_temp);

		//PROCURA O MODELO DO AVIAO
		for(search = 0, i = 0; i <= cont_aviao; i++)
		{
			//IDENTIFICA O AVIAO
			if (strcmp(modelo_temp , aviao[i].modelo) == 0)
			{
				printf("\nModelo da Aeronave: %s\n", aviao[i].modelo);
				printf("\nComprimento: %.1f m\n", aviao[i].comprimento);
				printf("\nAltura: %.1f m\n", aviao[i].altura);
				printf("\nEnvergadura: %.1f m\n", aviao[i].envergadura);
				printf("\nVelocidade de Cruzeiro: %.1f km/h\n", aviao[i].velocidade);
				printf("\nAlcance Maximo: %.1fkm\n", aviao[i].alcance);
				printf("\nQuantidade de assentos: %d\n", aviao[i].qtd_assentos);
				printf("\nQuantidade de banheiros: %d\n", aviao[i].qtd_banheiros);

				search = 1;
			}
		}

		if(search == 0){
			system("cls");
			printf("Modelo nao encontrado.\n");
		}
}

void EXCLUIR_PESSOA(){

	int i,j;
	int search = 0,repetir = 1;
	char cpf_temp[11];

	while(repetir == 1){
		printf("Escreva o CPF do participante que deseja excluir:\n");
		gets(cpf_temp);

		//caminha a lista de participantes
		for(i = 0; i <= cont_pessoa; i++)
		{	
			//IDENTIFICA
			if (strcmp(cpf_temp,pessoa[i].CPF) == 0)
			{
				//EXCLUE CADA DADO DA STRUCT(PARTICIPANE)
				for(j = i; j < cont_pessoa; j++)
				{
					strcpy(pessoa[i].nome_empresa,pessoa[i+1].nome_empresa);
					strcpy(pessoa[i].nome_pessoa,pessoa[i+1].nome_pessoa);
					strcpy(pessoa[i].categoria,pessoa[i+1].categoria);
					strcpy(pessoa[i].CPF,pessoa[i+1].CPF);
					pessoa[i].Saldo = pessoa[i+1].Saldo;
					search = 1;
					cont_pessoa--;
					printf("\nCadastro excluido com sucesso!!\n");
				}
			}
		}
		if(search == 0) printf("CPF nao encontrado!");

		//repetir = Escolha(2, "Deseja excluir mais algum participante?\n","1. SIM\n","2. NAO\n","","","");
	}
}
void EXCLUIR_VOO(){

	int i,j;
	int hora_temp, min_temp,repetir = 0;
	char voo_temp[5];

		printf("Digite apenas os numeros do prefixo do voo:\n");
			gets(voo_temp);
		printf("Digite o horario de partida: (Ex. hh:min)\n");
			scanf("%d%*c%d",&hora_temp, &min_temp);

		for(i = 0; i <= cont_voo; i++)
		{
			if (strcmp(voo_temp,voo[i].prefixo) == 0 && (voo[i].hora_partida == hora_temp) && (voo[i].min_partida == min_temp))
			{
				for(j = i; j < cont_voo; j++)
				{
					strcpy(voo[i].prefixo,voo[i+1].prefixo);
					strcpy(voo[i].tipo_aeronave,voo[i+1].tipo_aeronave);
					strcpy(aeroporto[i].sigla_ORIGEM,aeroporto[i+1].sigla_ORIGEM);
					strcpy(aeroporto[i].sigla_DESTINO,aeroporto[i+1].sigla_DESTINO);
					voo[i].hora_chegada = voo[i+1].hora_chegada;
					voo[i].min_chegada = voo[i+1].min_chegada;
					voo[i].hora_partida = voo[i+1].hora_partida;
					voo[i].min_partida = voo[i+1].min_partida;
					voo[i].hora_duracao = voo[i+1].hora_duracao;
				}
			}
		}
	cont_voo--;
}
void EXCLUIR_AERONAVE(){
	int i,j,repetir = 0;
	char modelo_temp[20];

		printf("Digite o Modelo da aeronave que deseja excluir!\n");
		gets(modelo_temp);

		for(i = 0; i <= cont_aviao; i++)
		{
			if (strcmp(modelo_temp, aviao[i].modelo) == 0)
			{
				printf("i=**%d**\n",i);
				for(j = i; j < cont_aviao; j++)
				{
					strcpy(aviao[i].modelo, aviao[i+1].modelo);
					aviao[i].comprimento = aviao[i+1].comprimento;
					aviao[i].altura = aviao[i+1].altura;
					aviao[i].envergadura = aviao[i+1].envergadura;
					aviao[i].velocidade = aviao[i+1].velocidade;
					aviao[i].alcance = aviao[i+1].alcance;
					aviao[i].qtd_assentos = aviao[i+1].qtd_assentos;
					aviao[i].qtd_banheiros = aviao[i+1].qtd_banheiros;
				}
			}
		}
	cont_aviao--;
}

void ALTERA_PESSOA(){
	int i,j,repetir = 1,ERRO = 0;
	char cpf_temp[11];

	while(repetir == 1)
	{
		printf("Escreva o CPF do participante que deseja alterar os dados:\n");
		gets(cpf_temp);

		//PROCURA CPF
		for(i = 0; i <= i; i++)
		{
			//ENTRA APENAS QUANDO ACHAR O CPF
			if (strcmp(cpf_temp,pessoa[i].CPF) == 0){

				ERRO = 1;
				printf("\nNome do Participante: ");
				gets(pessoa[i].nome_pessoa);
				//AUTENTIFICA O NOME(APENAS LETRAS)
				while(ERRO == 1){
					ERRO = 0;
					//VERIFICA SE TEM APENAS LETRAS
					for(j = 0 ;j < strlen(pessoa[i].nome_pessoa); j++ ){
						if(pessoa[i].nome_pessoa[j] == ' ')
							i++;
						if (isalpha(pessoa[i].nome_pessoa[j]) == 0) {
							printf("Digitar apenas letras!!\n");
							ERRO = 1;
							break;
						}
					}
					if(ERRO == 1) {
						printf("Tente Novamente: ");
						gets(pessoa[i].nome_pessoa);
					}
				}

				printf("\nInsira o Programa de Fidelidade desejado: ");
				gets(pessoa[i].nome_empresa);

				ERRO = 1;
				printf("\nCPF: ");
				gets(pessoa[i].CPF);
				//AUTENTIFICA O CPF
				while(ERRO == 1){
					ERRO = 0;
						//VERIFICA SE JA EXISTE O CPF
						for(j = 0; j < i; j++) {
							if (strcmp(pessoa[i].CPF, pessoa[j].CPF) == 0) {
								printf("\nCPF JA EXISTENTE NO SISTEMA!!\n");
								ERRO = 1;
								break;
							}
						}

					if(ERRO == 1){
						printf("Tente Novamente:\n");
						gets(pessoa[i].CPF);
					}
				}
	
				printf("\nCategoria do Participante: ");
				gets(pessoa[i].categoria);

			
				printf("\nSaldo de Milhas: ");
				scanf("%d", &pessoa[i].Saldo);

				break;
			}
		}

		//repetir = Escolha(2, "Deseja alterar mais algum dado?\n", "1. SIM\n", "2. NAO\n","","","");
	}
}
void ALTERA_VOO(){
	int i,j, aux = 0;
	int repetir = 0, escolha, hora_temp, min_temp;
	int ERRO=0;
	char voo_temp[5];

	for(; ;)
	{
		printf("Digite apenas os numeros do prefixo do voo:\n");
			gets(voo_temp);
		printf("Digite o horario de partida: (Ex. hh:min)\n");
			scanf("%d%*c%d%*c",&hora_temp, &min_temp);

		//PROCURA O VOO***********************************************************************************************
		for(i = 0; i <= cont_voo; i++){

			// SE ACHAR O PREFIXO E O HORARIO, FAZ TODAS ALTERACOES***************************************************
			if (strcmp(voo_temp,voo[i].prefixo) == 0 && (voo[i].hora_partida == hora_temp) && (voo[i].min_partida == min_temp)){



				printf("\nInsira o Prefixo(APENAS NUMEROS):\nIES");
				gets(voo[i].prefixo);
				for(; ;){
					ERRO = 0;

						//VERIFICA SE JA EXISTE O PREFIXO
						for(i = 0; i < cont_voo; i++) {
							if (strcmp(voo[i].prefixo, voo[cont_voo].prefixo) == 0) {
								printf("\nPREFIXO JA EXISTENTE NO SISTEMA!!\n");
								ERRO = 1;
								break;
							}
						}

					if(ERRO == 0) break;
					printf("Tente Novamente:\n");
					gets(voo[cont_voo].prefixo);
				}


				//LÊ AEROPORTO ORIGEM**********************************************************************************
				//*****************************************************************************************************

				printf("\nInsira a SIGLA do aeroporto de origem(Ex. GRU p/ Guarulhos, IGU p/ Foz do iguacu):\n");
				for(; ;){
					ERRO = 0;

					gets(aeroporto[i].sigla_ORIGEM);

						//TRANFORMA AS 3 PRIMEIRAS LETRAS DA STRING EM MAIUSCULA(SIGLA)
						for(j = 0; j < 3; j++)
							if(isalpha(aeroporto[i].sigla_ORIGEM[j]) == 0) {

								printf("A sigla do aeroporto deve constituir de 3 letras maiusculas\n");
								ERRO++;
								break;
							}
							else
								for(j = 0; j < 3; j++)
									aeroporto[i].sigla_ORIGEM[j] = toupper(aeroporto[i].sigla_ORIGEM[j]);

					if(ERRO == 0) break;
				}

				printf("\nInsira o NOME do aeroporto de origem(Ex. GRU p/ Guarulhos, IGU p/ Foz do iguacu):\n");
				gets(aeroporto[i].nome_ORIGEM);


				//LÊ AEROPORTO DESTINO**********************************************************************************

				printf("\nInsira a SIGLA do aeroporto de destino(Ex. GRU Guarulhos, IGU Foz do iguacu):\n");
				//LE ATE DA CERTO, FECHA QUANDO A VARIAVEL ERRO ESTIVER ZERADA
				for(; ;){
					ERRO = 0;
					gets(aeroporto[i].sigla_DESTINO);


						//TRANFORMA AS 3 PRIMEIRAS LETRAS DA STRING EM MAIUSCULA(SIGLA)
						for(j = 0; j < 3; j++)
							if(isalpha(aeroporto[i].sigla_DESTINO[j]) == 0) {

								printf("A sigla do aeroporto deve constituir de 3 letras maiusculas\n");
								ERRO++;
								break;
							}
							else
								for(j = 0; j < 3; j++)
									aeroporto[i].sigla_DESTINO[j] = toupper(aeroporto[i].sigla_DESTINO[j]);

					//VERIFICA SE OS AEROPORTOS DE ORIGEM E DESTINO SAO IGUAIS
					if(strcmp (aeroporto[i].sigla_ORIGEM , aeroporto[i].sigla_DESTINO) != 0)
						break;
					else{
						printf("Aeroportos de Origem e de Destino sao iguais.\n"
						"Inserir outro aeroporto de destino!!\n");
						ERRO++;
					}
					if(ERRO == 0) break;
				}

				printf("\nInsira a NOME do aeroporto de destino(Ex. GRU Guarulhos, IGU Foz do iguacu):\n");
				gets(aeroporto[i].nome_DESTINO);


				//*****************************************************************************************************

				printf("\nInserir horario de partida (hh:mm): ");
				for(; ;){
					scanf("%d%*c%d",&voo[i].hora_partida,&voo[i].min_partida);

						if(voo[i].hora_partida < 0 || voo[i].hora_partida > 23 || voo[i].min_partida < 0 || voo[i].min_partida > 59)
							printf("\nhorario invalido. Disque novamente\n");
						else break;
				}
				//*****************************************************************************************************

				printf("\nInserir horario de chegada (hh:mm): ");
				for(; ;){
					scanf("%d%*c%d",&voo[i].hora_chegada,&voo[i].min_chegada);

						if(voo[i].hora_chegada < 0 || voo[i].hora_chegada > 23 || voo[i].min_chegada < 0 || voo[i].min_chegada > 59)
							printf("\nHorario invalido. Disque novamente\n");
						else break;
				}
				//*****************************************************************************************************

				printf("\nInserir duracao do voo (hh:mm): ");
				for(; ;){
					scanf("%d%*c%d%*c",&voo[i].hora_duracao,&voo[i].min_duracao);

						if(voo[i].hora_duracao < 0 || voo[i].hora_duracao > 23 || voo[i].min_duracao < 0 || voo[i].min_duracao > 59)
							printf("\nhorario invalido. Disque novamente\n");
						else break;
				}
				//******************************************************************************************************

				printf("\nTipo de aeronave: ");
				gets(voo[i].tipo_aeronave);


				aux++;
			}
		}
			if(aux == 0)
				printf("\nNao foi possivel achar o voo.\n");

				printf("\nAlterar mais algum dado?\n"
						"1. SIM\n"
						"2. NAO\n");
				scanf("%d%*c", &repetir);
				if (repetir != 1) break;
	}
}
void ALTERA_AERONAVE(){
	int i,repetir = 0, escolha;
	char modelo_temp[20];

	for(; ;)
	{
		printf("Digite o modelo da aeronave que deseja modificar dados: ");
		gets(modelo_temp);

		//PROCURA O MODELO
		for(i = 0; i <= cont_aviao; i++)
		{
			//ENTRA APENAS QUANDO ACHAR O MODELO
			if (strcmp(modelo_temp,aviao[i].modelo) == 0){
				printf("\nQual modelo da aeronave: ");
					gets(aviao[i].modelo);
				printf("\nComprimento da aeronave(em metros): ");
					scanf("%f%*c", &aviao[i].comprimento);
				printf("\nAltura da aeronave: ");
					scanf("%f%*c", &aviao[i].altura);
				printf("\nEnvergadura da aeronave: ");
					scanf("%f%*c", &aviao[i].envergadura);
				printf("\nVelocidade de cruzeiro: ");
					scanf("%f%*c", &aviao[i].velocidade);
				printf("\nAlcance maximo: ");
					scanf("%f%*c",&aviao[i].alcance);
				printf("\nQuantidade de assentos: ");
					scanf("%d%*c", &aviao[i].qtd_assentos);
				printf("\nQuantidade de banheiros: ");
					scanf("%d%*c", &aviao[i].qtd_banheiros);
			}
		}
			printf("\nDeseja alterar mais algum dado?\n"
					"1. SIM\n"
					"2. NAO\n");
			scanf("%d%*c", &repetir);
			if(repetir != 1) break;
		}
}

int CALCULA(int hora_partida, int min_partida, int hora_atual, int min_atual){
	int resultado;

	resultado = (((hora_partida - hora_atual) * 60) + (min_partida - min_atual));
	return resultado;
}
void NOTIFICACAO_VOO(struct tm tempo){
	int x, hora, min;
	int resultado;

	printf("Digite o horario do voo (hh:mm): ");
	scanf("%d%*c%d%*c", &hora,&min);

	resultado = CALCULA(hora, min, tempo.tm_hour, tempo.tm_min);
	printf("\nresultado: %d\n", resultado);

	if(resultado >= 60 )
		printf("Check in Aberto.\n");

	if (resultado < 60 && resultado > 30) {
		printf("Check in Fechado.\n");
	}
	if (resultado <= 30 && resultado > 20) {
		printf("Check in Fechado.\n"
			   "Embarque proximo.\n");
	}
	if (resultado <= 20 && resultado > 10) {
		printf("Check in Fechado.\n"
			   "Embarque Imediato.\n");
	}
	if (resultado <= 10 && resultado > 0) {
		printf("Check in Fechado.\n"
			   "Ultima Chamada.\n");
	}
	if (resultado <= 0 && resultado > -10) {
		printf("Partindo.\n");
	}
	if(resultado <= -10){
		printf("Voo Encerrado.\n");
	}
}

//entra com valor dado pela entrada de administrador
//escolhe para qual funcao levar via switch
void indicador(int x){
	switch(x)
		{
			case 11: INSERIR_PESSOA();
				break;
			case 12: INSERIR_VOO();
				break;
			case 13: INSERIR_AERONAVE();
				break;

			case 21: CONSULTA_PESSOA();
				break;
			case 22: CONSULTA_VOO(); 
				break;
			case 23: CONSULTA_AERONAVE();
				break;

			case 31: ALTERA_PESSOA();
				break;
			case 32: ALTERA_VOO();
				break;
			case 33: ALTERA_AERONAVE();
				break;

			case 41: EXCLUIR_PESSOA();
				break;
			case 42: EXCLUIR_VOO();
				break;
			case 43: EXCLUIR_AERONAVE();
				break;
			}
}

//ENTRADA PARA ADMINISTRADOR
//ESCOLHE A OPERACAO E O TIPO DE DADOS A ALTERAR
int ENTRADA_ADM(){
	int operacao, tipo, again;

	while(again){
		again = 1;

		system("cls");

		printf("Qual tipo de operacao deseja realizar?\n1. Inserir\n2. Consultar\n3. Alterar\n4. Excluir\n5. Sair\n");
		scanf("%d%*c",&operacao);
		if(operacao == 5) return 0;

		if(operacao < 1 || operacao > 5){
			system("cls");
			printf("Opcao invalida.\n");
		}
		else
			again = 0;
	}

	again = 1;
	system("cls");

	while(again){
		printf("Deseja operar em quais tipos de dados?\n1. Pessoa\n2. Voo\n3. Aeronave\n4. Sair\n");
		scanf("%d%*c",&tipo);
		if(tipo == 4) return 0;
		
		if(tipo < 1 || tipo > 4){
			system("cls");
			printf("Opcao invalida.\n");
		}
		else
			again = 0;
	}

	indicador ((operacao*10) + tipo);
}

int ENTRADA_USUARIO(){
	printf("USUARIO\n");
	return 0;
}

//ESCOLHI TIPO DE LOGIN ENTRE USUARIO E ADMINISTRADOR
int TipoLogin(){
	int choice;

	printf("Qual tipo de Login deseja realizar?\n1. Administrador\n2. Usuario\n3. Sair\n");
	scanf("%d%*c", &choice);

	if (choice < 1 || choice > 3){
		printf("Escolha invalida\n");
		return TipoLogin();
	}


	if(choice == 1)
		ENTRADA_ADM();
	else if(choice == 2)
		ENTRADA_USUARIO();
	else return 0;
}


int main(){

	time_t mytime;
	mytime = time(NULL);
	struct tm tempo = *localtime(&mytime);

	system("cls");
	CONSULTA_VOO();
	//TipoLogin();


	return 0;
}
