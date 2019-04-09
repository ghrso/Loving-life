#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXTAM 100

typedef struct voo{

	char prefixo[20];
	char tipo_aeronave[40];
	float hora_partida, min_partida;
	float hora_chegada, min_chegada;
	float hora_duracao, min_duracao;

} DADOS_VOO;

typedef struct pessoa{

	char nome_empresa[50];
	char nome_pessoa[50];
	char categoria[20];
	char CPF[11];
	float Saldo;

} DADOS_PESSOA;

typedef struct aeronave{

	char modelo[30];
	float comprimento;
	float altura;
	float envergadura;
	float velocidade;
	float alcance;
	float qtd_assentos;
	float qtd_banheiros;

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
int INnOUT(char string[]){
	int x = 0;

	printf("%s\n1. SIM\n2. NAO\n", string);
	scanf("%d%*c", &x);
	system("cls");

	if(x < 1 || x > 2){
		printf("Escolha invalida!\n");
		return INnOUT(string);
	}
	
	return x;
}

void imprime_pessoa(int i){
	printf("\nDigite o nome do Participante: %s", pessoa[i].nome_pessoa);
	printf("\nPrograma de Fidelidade desejado: %s", pessoa[i].nome_empresa);
	printf("\nCPF: %s", pessoa[i].CPF);
	printf("\nCategoria do Participante: %s", pessoa[i].categoria);
	printf("\nSaldo de milhas: %s\n", pessoa[i].Saldo);
}
void imprime_voo(int i){
	printf("Prefixo do voo: %s\n", voo[i].prefixo);
	printf("Saida prevista do aeroporo: %s-%s // horario: (%02.f:%02.f)\n",aeroporto[i].sigla_ORIGEM	,	aeroporto[i].nome_ORIGEM,		voo[i].hora_partida,	voo[i].min_partida);
	printf("Chegada prevista ao aeroporto: %s-%s // horario: (%02.f:%02.f)\n",aeroporto[i].sigla_DESTINO , aeroporto[i].nome_DESTINO ,	voo[i].hora_chegada,	voo[i].min_chegada);
	printf("Duracao do voo: (%02.f:%02.f)\n",voo[i].hora_duracao,voo[i].min_duracao);
	printf("Tipo de Aeronave: %s\n",voo[i].tipo_aeronave);
}
void imprime_aeronave(int i){
	printf("Modelo da Aeronave: %s\n", aviao[i].modelo);
	printf("Comprimento: %.2f m\n", aviao[i].comprimento);
	printf("Altura: %.2f m\n", aviao[i].altura);
	printf("Envergadura: %.2f m\n", aviao[i].envergadura);
	printf("Velocidade de Cruzeiro: %.2f km/h\n", aviao[i].velocidade);
	printf("Alcance Maximo: %.2fkm\n", aviao[i].alcance);
	printf("Quantidade de assentos: %f\n", aviao[i].qtd_assentos);
	printf("Quantidade de banheiros: %f\n", aviao[i].qtd_banheiros);
}


void autentifica_sigla(char string[]){
	int ERRO = 0, i;
	gets(string);

	if(strlen(string) <= 3){
		for(i = 0; i < 3; i++){

			if(isalpha(string[i]) == 0) {
			
				printf("\n           A sigla deve ser constituida de 3 letras.\n");
				printf("Digite novamente: ");
				return autentifica_sigla(string);
			}else
				string[i] = toupper(string[i]);
		}
	}
	else{
		printf("\n           A sigla deve ser constituida de 3 letras.\n"
			"Digite novamente: ");
		return autentifica_sigla(string);
	}
}
void autentifica_hora(float *hr, float *min){
	int i, cn_hr, cn_mn, erro = 1;
	char str_hr[3];
	char str_mn[3];
	char string[30];

	while(erro){
		erro = 0;
		gets(string);

		if(strlen(string) == 5){

			for(i = 0, cn_hr = 0, cn_mn = 0; i < 5; i++){
				if(i < 2){
					str_hr[cn_hr] = string[i];
					cn_hr++;
				}
				if(i > 2){
					str_mn[cn_mn] = string[i];
					cn_mn++;
				}
			}

			str_hr[2] = '\0';
			str_mn[2] = '\0';

			for(i = 0; i < 2, erro == 1; i++){

				if(isdigit(str_hr[i]) == 0 || isdigit(str_mn[i]) == 0){

					printf("\n				horario deve estar no formato hh:mm\n"
						   "Digite novamente: ");
					erro = 1;
				}
			}

			*hr = atof(str_hr);
			*min = atof(str_mn);

			if(*hr < 0 || *hr > 23 || *min < 0 || *min > 59){

				printf("\n				horario invalido.\n"
					"Digite novamente: ");
				erro = 1;
			}

		}
		else{

			printf("\n				horario deve estar no formato hh:mm\n"
				"Digite novamente: ");
			erro = 1;
		}
	}
}
void verif_string_float(char string[] , float *n){
	char buffer[30];
	int i = 0;
	int again = 1;

	while(again){

		again = 0;
		printf("%s", string);
		gets(buffer);

		while(i < strlen(buffer)){

			if(isdigit(buffer[i]) || buffer[i] == '.'){

			}
			else {
				printf("				Digite apenas numeros.\n");
				again = 1;
				break;
			}
			i++;
		}
	}

	*n = atof(buffer);
}

void INSERIR_PESSOA(){
	int i, ERRO = 1;
	
	printf("				Cadastro de participante.\n");
	imprime_pessoa(cont_pessoa);
	while(ERRO){
		ERRO = 0;

		printf("\nInsira o nome do participante: ");
		gets(pessoa[cont_pessoa].nome_pessoa);

		for(i = 0 ;i < strlen(pessoa[cont_pessoa].nome_pessoa) ; i++ ){

			if(pessoa[cont_pessoa].nome_pessoa[i] == ' ')
				i++;

			if (isalpha(pessoa[cont_pessoa].nome_pessoa[i]) == 0) {
				printf("				O nome deve ter apenas letras.\n");
				ERRO = 1;
				break;
			}
		}
	}

	system("cls");

	printf("				Cadastro de participante.\n");
	imprime_pessoa(cont_pessoa);
	printf("\nInsira o Programa de Fidelidade desejado: ");
	gets(pessoa[cont_pessoa].nome_empresa);

	system("cls");
	ERRO = 1;

	printf("				Cadastro de participante.\n");
	imprime_pessoa(cont_pessoa);
	while(ERRO){
		ERRO = 0;
		printf("\nInsira os numeros do cpf: ");
		gets(pessoa[cont_pessoa].CPF);

		for(i = 0; i < cont_pessoa; i++) {

			if (strcmp(pessoa[i].CPF, pessoa[cont_pessoa].CPF) == 0) {
				printf("				CPF JA EXISTENTE NO SISTEMA!!\n");
				ERRO = 1;
				break;
			}
		}
	}

	system("cls");

	printf("				Cadastro de participante.\n");
	imprime_pessoa(cont_pessoa);
	printf("\nInsira a categoria do Participante: ");
	gets(pessoa[cont_pessoa].categoria);

	system("cls");
	ERRO = 1;

	printf("				Cadastro de participante.\n");
	imprime_pessoa(cont_pessoa);
	verif_string_float("Insira o saldo do participante" , &pessoa[cont_pessoa].Saldo);

	system("cls");

	printf("				Cadastro de participante #%d\n", cont_pessoa+1);
	imprime_pessoa(cont_pessoa);

	cont_pessoa++;

	printf("                             Participante inserido com sucesso!!\n\n");

	if(INnOUT("Deseja inserir mais um participante?") == 1)
		return INSERIR_PESSOA();				
}
void INSERIR_VOO(){
   	int ERRO = 1, i;
   	char buffer[30];


	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_pessoa);
	while(ERRO){
		ERRO = 0;
		printf("\nInsira o Prefixo: ");
		gets(voo[cont_voo].prefixo);

		for(i = 0; i < cont_voo; i++) {

			if (strcmp(voo[i].prefixo, voo[cont_voo].prefixo) == 0) {

				system("cls");
				printf("                 prefixo ja existente no sistema!!\n");
				ERRO = 1;
			}
		}
	}

	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInsira a SIGLA do aeroporto de origem: ");
	autentifica_sigla(aeroporto[cont_voo].sigla_ORIGEM);

	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInsira o NOME do aeroporto de origem: %s-", aeroporto[cont_voo].sigla_ORIGEM);
	gets(aeroporto[cont_voo].nome_ORIGEM);

	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	while(-1){

		printf("\nInsira a SIGLA do aeroporto de destino: ");
		autentifica_sigla(aeroporto[cont_voo].sigla_DESTINO);

		if(strcmp (aeroporto[cont_voo].sigla_ORIGEM , aeroporto[cont_voo].sigla_DESTINO) != 0)
			break;

		printf("	          Aeroportos de Origem e de Destino sao iguais.\n");
	}

	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInsira a NOME do aeroporto de destino: %s-", aeroporto[cont_voo].sigla_DESTINO);
	gets(aeroporto[cont_voo].nome_DESTINO);

	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInserir horario de partida (hh:mm): ");
	autentifica_hora(&voo[cont_voo].hora_partida, &voo[cont_voo].min_partida);
	
	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInserir horario de chegada (hh:mm): ");
	autentifica_hora(&voo[cont_voo].hora_chegada, &voo[cont_voo].min_chegada);
	
	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nInserir duracao do voo (hh:mm): ");
	autentifica_hora(&voo[cont_voo].hora_duracao, &voo[cont_voo].min_duracao);
	
	system("cls");

	printf("				Cadastro de Voo.\n");
	imprime_voo(cont_voo);
	printf("\nTipo de aeronave: ");
	gets(voo[cont_voo].tipo_aeronave);

	system("cls");

	printf("				Cadastro de Voo #%d\n", cont_voo+1);
	imprime_voo(cont_voo);

	cont_voo++;


	printf("                             Cadastro realizado com sucesso!!\n\n");
	if(INnOUT("Deseja adicionar mais um voo?") == 1)
		return INSERIR_VOO();	
}
void INSERIR_AERONAVE(){
	int ERRO = 1, i;

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	while(ERRO){
		ERRO = 0;

		printf("\nQual modelo da aeronave: ");
		gets(aviao[cont_aviao].modelo);

		for(i = 0; i < cont_aviao; i++) {
			if (strcmp(aviao[i].modelo, aviao[cont_aviao].modelo) == 0) {
				printf("\nCPF ja existente no sistema!!\n");
				ERRO = 1;
				break;
			}
		}
	}

	ERRO = 1;
	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Comprimento da aeronave(em metros): " , &aviao[cont_aviao].comprimento);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Altura da aeronave(em metros): " , &aviao[cont_aviao].altura);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Envergadura da aeronave(em metros): " , &aviao[cont_aviao].envergadura);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Velocidade de cruzeiro: " , &aviao[cont_aviao].velocidade);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Alcance maximo: " , &aviao[cont_aviao].alcance);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Quantidade de assentos: " , &aviao[cont_aviao].qtd_assentos);

	system("cls");

	printf("				Cadastro de aeronave.\n");
	imprime_aeronave(cont_aviao);
	verif_string_int("Quantidade de banheiros: " , &aviao[cont_aviao].qtd_banheiros);

	system("cls");

	printf("				Cadastro de aeronave #%d\n", cont_aviao+1);
	imprime_aeronave(cont_aviao);

	cont_aviao++;

	printf("                             Cadastro realizado com sucesso!!\n\n");
	if(INnOUT("Deseja adicionar mais uma Aeronave?") == 1)
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
			printf("----------------------------------------------------------------------------------------");
			printf("				Participante [%d]", i);
			imprime_pessoa(i);
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
	if (INnOUT("Deseja consultar novamente?") == 1)
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
	if (INnOUT("Deseja consultar novamente?") == 1)
			return CONSULTA_VOO();
}
void CONSULTA_AERONAVE(){
	int i ,repetir = 1, search, x;
	char modelo_temp[20];

	while(repetir){
		printf("Deseja consultar por modelo ou uma lista com todas aeronaves?\n1. Consulta por modelo\n2. Frota de aeronaves\n");
		scanf("%d%*c", &x);
		if(x < 1 || x > 2)
			printf("Escolha invalida.\n");
		else 
			repetir = 0;
	}

	if(x == 2){
		for(i = 0 ; i < 2 ; i++){
			printf("----------------------------------------------------------------------------------------\n");
			printf("Modelo da Aeronave: %s\n", aviao[i].modelo);
			printf("Comprimento: %.1f m\n", aviao[i].comprimento);
			printf("Altura: %.1f m\n", aviao[i].altura);
			printf("Envergadura: %.1f m\n", aviao[i].envergadura);
			printf("Velocidade de Cruzeiro: %.1f km/h\n", aviao[i].velocidade);
			printf("Alcance Maximo: %.1fkm\n", aviao[i].alcance);
			printf("Quantidade de assentos: %d\n", aviao[i].qtd_assentos);
			printf("Quantidade de banheiros: %d\n", aviao[i].qtd_banheiros);
		}
		if(i != 0) printf("----------------------------------------------------------------------------------------\n");
		system("pause");
		system("cls");	
	}
	else{

		printf("Insira o modelo da aeronave desejada: ");
		gets(modelo_temp);

		//PROCURA O MODELO DO AVIAO
		for(search = 0, i = 0; i < cont_aviao; i++)
		{
			//IDENTIFICA O AVIAO
			if (strcmp(modelo_temp , aviao[i].modelo) == 0)
			{
				printf("----------------------------------------------------------------------------------------\n");
				printf("Modelo da Aeronave: %s\n", aviao[i].modelo);
				printf("Comprimento: %.1f m\n", aviao[i].comprimento);
				printf("Altura: %.1f m\n", aviao[i].altura);
				printf("Envergadura: %.1f m\n", aviao[i].envergadura);
				printf("Velocidade de Cruzeiro: %.1f km/h\n", aviao[i].velocidade);
				printf("Alcance Maximo: %.1fkm\n", aviao[i].alcance);
				printf("Quantidade de assentos: %d\n", aviao[i].qtd_assentos);
				printf("Quantidade de banheiros: %d\n", aviao[i].qtd_banheiros);
				printf("----------------------------------------------------------------------------------------\n");

				search = 1;
			}
		}

		if(search == 0){
			system("cls");
			printf("Modelo nao encontrado.\n");
		}
	}
	if (INnOUT("Deseja consultar novamente?") == 1)
		return CONSULTA_VOO();
}

void EXCLUIR_PESSOA(){

	int i,j;
	int search = 0;
	char cpf_temp[11];


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
				strcpy(pessoa[i].nome_empresa , pessoa[i+1].nome_empresa);
				strcpy(pessoa[i].nome_pessoa , pessoa[i+1].nome_pessoa);
				strcpy(pessoa[i].categoria , pessoa[i+1].categoria);
				strcpy(pessoa[i].CPF , pessoa[i+1].CPF);
				strcpy(pessoa[i].Saldo , pessoa[i+1].Saldo);
				search = 1;
				cont_pessoa--;
				printf("			Cadastro excluido.\n");
			}
		}
	}
	if(search == 0) printf("CPF nao encontrado!");

	if(INnOUT("Deseja excluir mais algum cadastro?") == 1)
		return EXCLUIR_PESSOA();
}
void EXCLUIR_VOO(){

	int i,j;
	int hora_temp, min_temp,repetir = 0;
	char voo_temp[5];

	printf("Digite apenas os numeros do prefixo do voo:\n");
	gets(voo_temp);

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
			cont_voo--;
		}
	}
	if(INnOUT("Deseja excluir mais algum cadastro?") == 1)
		return EXCLUIR_PESSOA();
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
			cont_aviao--;
		}
	}
	if(INnOUT("Deseja excluir mais algum cadastro?") == 1)
	return EXCLUIR_PESSOA();
}

void ALTERA_PESSOA(){
	int i,j,repetir = 1,ERRO = 0;
	char cpf_temp[11];


	printf("Escreva o CPF do participante que deseja alterar os dados:\n");
	gets(cpf_temp);

	//PROCURA CPF
	for(i = 0; i <= cont_pessoa; i++)
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

	if(INnOUT("Deseja alterar os dados de mais algum participante?") == 2)
		return ALTERA_PESSOA();
}
void ALTERA_VOO(){
	int i,j, aux = 0;
	int repetir = 0, escolha, hora_temp, min_temp;
	int ERRO=0;
	char voo_temp[5];


	printf("Digite apenas os numeros do prefixo do voo:\n");
	gets(voo_temp);
	printf("Digite o horario de partida: (Ex. hh:min)\n");
	scanf("%d%*c%d%*c",&hora_temp, &min_temp);

	for(i = 0; i <= cont_voo; i++){

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


			printf("\nInsira a SIGLA do aeroporto de destino(Ex. GRU Guarulhos, IGU Foz do iguacu):\n");
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

			printf("\nInserir horario de partida (hh:mm): ");
			for(; ;){
				scanf("%d%*c%d",&voo[i].hora_partida,&voo[i].min_partida);

					if(voo[i].hora_partida < 0 || voo[i].hora_partida > 23 || voo[i].min_partida < 0 || voo[i].min_partida > 59)
						printf("\nhorario invalido. Disque novamente\n");
					else break;
			}
			
			printf("\nInserir horario de chegada (hh:mm): ");
			for(; ;){
				scanf("%d%*c%d",&voo[i].hora_chegada,&voo[i].min_chegada);

					if(voo[i].hora_chegada < 0 || voo[i].hora_chegada > 23 || voo[i].min_chegada < 0 || voo[i].min_chegada > 59)
						printf("\nHorario invalido. Disque novamente\n");
					else break;
			}
			
			printf("\nInserir duracao do voo (hh:mm): ");
			for(; ;){
				scanf("%d%*c%d%*c",&voo[i].hora_duracao,&voo[i].min_duracao);

					if(voo[i].hora_duracao < 0 || voo[i].hora_duracao > 23 || voo[i].min_duracao < 0 || voo[i].min_duracao > 59)
						printf("\nhorario invalido. Disque novamente\n");
					else break;
			}

			printf("\nTipo de aeronave: ");
			gets(voo[i].tipo_aeronave);


			aux = 1;
		}
	}
		if(aux == 0)
			printf("                     Nao foi possivel achar o voo.\n");

	if(INnOUT("Deseja alterar os dados de mais algum participante?") == 1)
		return ALTERA_PESSOA();
}
void ALTERA_AERONAVE(){
	int i,repetir = 0, escolha;
	char modelo_temp[20];

	printf("Digite o modelo da aeronave que deseja modificar dados: ");
	gets(modelo_temp);


	for(i = 0; i <= cont_aviao; i++)
	{

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
	if(INnOUT("Deseja alterar os dados de mais algum participante?") == 1)
		return ALTERA_PESSOA();
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

int ENTRADA_ADM();
//entra com valor dado pela entrada de administrador
//escolhe para qual funcao levar via switch
int indicador(int x){
	switch(x){
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

int ENTRADA_ADM(){
	int operacao, tipo, again = 1;

	while(again){

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
	system("cls");
	indicador ((operacao*10) + tipo);

	if(INnOUT("Deseja fazer mais alteracoes como administrador?") == 1)
		return ENTRADA_ADM();
}

int ENTRADA_USUARIO(){
	printf("USUARIO\n");
	return 0;
}

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
	else if(choice == 3)
		return 0;

	if(INnOUT("Deseja realizar Login novamente?") == 1)
		return TipoLogin();
}


int main(){

	time_t mytime;
	mytime = time(NULL);
	struct tm tempo = *localtime(&mytime);

	system("cls");
	TipoLogin();


	return 0;
}
