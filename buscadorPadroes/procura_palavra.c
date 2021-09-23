#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#define _GNU_SOURCE 							// necessário porque getline() é extensão GNU
#ifdef WIN32
   #include <windows.h>
#else
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
#endif 
#define PORT 8080 

int comunica(int message){
struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , &message, strlen(&message) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
} 

int NUM_FRASE = 0, NUM_PALAVRA = 0; 
int ocorrencias = 0;

//################################### thread 1 ###############################################
void *funcao_thread1()
{	
	
	size_t len= 200; 					// valor arbitrário
  	char palavra[10], *padrao = malloc(len);
	char texto[40], *frase = malloc(len);
	

	FILE *arquivo1 = fopen("texto_1.txt", "r");
	FILE *arquivo2 = fopen("padroes_1.txt", "r");
	
	

  if (!arquivo1)
  {
	perror("texto_1.txt");
	return 0;
  }
  while (getline(&frase, &len, arquivo1) > 0){}	
  
  if(frase)
    fclose(arquivo1); 

  if (!arquivo2)
  {
	perror("padroes_1.txt");
	return 0;
  }
  while (getline(&padrao, &len, arquivo2) > 0)
  {
	NUM_PALAVRA = strlen(padrao); 		//pega o numero de posições na linha
	NUM_FRASE = strlen(frase);		//pega o numero de posições no texto 
	//printf(" %d CF", NUM_FRASE-1);
	//printf("\n%d CP", NUM_PALAVRA-1);
	printf(" \nPadrao:%s", padrao);
	procuraPadrao(frase, padrao); 
  }
 	printf("thread 1 executada com sucesso!!!\n");
  if(padrao){
    free(padrao);
    fclose(arquivo2); 
  }

return NULL;
}
//###################################### thread 2 ###############################################
void *funcao_thread2()
{	
	
	size_t len= 200; 					// valor arbitrário
  	char palavra[10], *padrao = malloc(len);
	char texto[40], *frase = malloc(len);
	

	FILE *arquivo1 = fopen("texto_2.txt", "r");
	FILE *arquivo2 = fopen("padroes_2.txt", "r");
	
	

  if (!arquivo1)
  {
	perror("texto_2.txt");
	return 0;
  }
  while (getline(&frase, &len, arquivo1) > 0){}	
  
  if(frase)
    fclose(arquivo1); 

  if (!arquivo2)
  {
	perror("padroes_2.txt");
	return 0;
  }
  while (getline(&padrao, &len, arquivo2) > 0)
  {
	NUM_PALAVRA = strlen(padrao); 		//pega o numero de posições na linha
	NUM_FRASE = strlen(frase);		//pega o numero de posições no texto 
	//printf(" %d CF", NUM_FRASE-1);
	//printf("\n%d CP", NUM_PALAVRA-1);
	printf(" \nPadrao:%s", padrao);
	procuraPadrao(frase, padrao); 
  }
 	printf("thread 2 executada com sucesso!!!\n");
  if(padrao){
    free(padrao);
    fclose(arquivo2); 
  }

return NULL;
}
//###################################### thread 3 ##################################################
void *funcao_thread3()
{	
	
	size_t len= 200; 					// valor arbitrário
  	char palavra[10], *padrao = malloc(len);
	char texto[40], *frase = malloc(len);
	

	FILE *arquivo1 = fopen("texto_3.txt", "r");
	FILE *arquivo2 = fopen("padroes_3.txt", "r");
	
	

  if (!arquivo1)
  {
	perror("texto_3.txt");
	return 0;
  }
  while (getline(&frase, &len, arquivo1) > 0){}	
  
  if(frase)
    fclose(arquivo1); 

  if (!arquivo2)
  {
	perror("padroes_3.txt");
	return 0;
  }
  while (getline(&padrao, &len, arquivo2) > 0)
  {
	NUM_PALAVRA = strlen(padrao); 		//pega o numero de posições na linha
	NUM_FRASE = strlen(frase);		//pega o numero de posições no texto 
	//printf(" %d CF", NUM_FRASE-1);
	//printf("\n%d CP", NUM_PALAVRA-1);
	printf(" \nPadrao:%s", padrao);
	procuraPadrao(frase, padrao); 
  }
 	printf("thread 3 executada com sucesso!!!\n");
  if(padrao){
    free(padrao);
    fclose(arquivo2); 
  }

return NULL;
}
//############################################# thread 4 #########################################
void *funcao_thread4()
{	
	
	size_t len= 200; 					// valor arbitrário
  	char palavra[10], *padrao = malloc(len);
	char texto[40], *frase = malloc(len);
	

	FILE *arquivo1 = fopen("sequencial_4.txt", "r");
	FILE *arquivo2 = fopen("padroes_4.txt", "r");
	
	

  if (!arquivo1)
  {
	perror("texto_4.txt");
	return 0;
  }
  while (getline(&frase, &len, arquivo1) > 0){}	
  
  if(frase)
    fclose(arquivo1); 

  if (!arquivo2)
  {
	perror("padroes_4.txt");
	return 0;
  }
  while (getline(&padrao, &len, arquivo2) > 0)
  {
	NUM_PALAVRA = strlen(padrao); 		//pega o numero de posições na linha
	NUM_FRASE = strlen(frase);		//pega o numero de posições no texto 
	//printf(" %d CF", NUM_FRASE-1);
	//printf("\n%d CP", NUM_PALAVRA-1);
	printf(" \nPadrao:%s", padrao);
	procuraPadrao(frase, padrao); 
  }
 	printf("thread 4 executada com sucesso!!!\n");
  if(padrao)
  {
    	free(padrao);
    	fclose(arquivo2); 
  }
return NULL;
}

//################################# funacao que procura os padroes #############################################
int procuraPadrao(char texto[], char palavra[])
{
	int aux = 0, i = 0, j = 0,  x = 0;

	for (i=0; i < NUM_FRASE -1; i++)				//faz verificação de todas as letras da FRASE
	{
		if (palavra[0] == texto[i])				//compara a primeira letra de PALAVRA com as letras da frase
	        {
			aux = i;					//aux com valor de i
			x = 0;						//variavel de controle de sequencia
		 	for(j=0; j < NUM_PALAVRA - 1; j++)			//faz verificação da sequencia da sequencia PALAVRA com a sequencia da FRASE
		 	{	
				if(palavra[j] == texto[aux])		//faz contagem da sequencia, para fazer comparação com tamanho
				{
			     	    x++;						
				}	
			    	    aux++;
			}
			if (x >= NUM_PALAVRA - 1)			//verifica se sequencia da PALAVRA foi encontrada na FRASE
			     ocorrencias++;
	 	 }
	}
	printf("ocorrencias %d \n",ocorrencias); 
	return comunica(ocorrencias);
}


		
//#################################### escopo ########################################
int main(int argc, char **argv)
{
	int rc;		// VARIAVEL DE ERRO DA THREAD

	pthread_t t1, t2, t3, t4;

	rc = pthread_create(&t1, NULL, funcao_thread1, NULL);	//CRIA A THREAD 1 E CHAMA A FUNCAO
	if(rc)
	{
		printf("Erro %d",rc);
		exit(-1);
	}
	rc = pthread_create(&t2, NULL, funcao_thread2, NULL);	//CRIA A THREAD 1 E CHAMA A FUNCAO
	if(rc)
	{
		printf("Erro %d",rc);
		exit(-1);
	}
	rc = pthread_create(&t3, NULL, funcao_thread3, NULL);	//CRIA A THREAD 1 E CHAMA A FUNCAO
	if(rc)
	{
		printf("Erro %d",rc);
		exit(-1);
	}
	rc = pthread_create(&t4, NULL, funcao_thread4, NULL);	//CRIA A THREAD 1 E CHAMA A FUNCAO
	if(rc)
	{
		printf("Erro %d",rc);
		exit(-1);
	}
	
	pthread_join(t1, NULL);		//FUNCAO DE CONTROLE DA EXECUCAO DA THREAD
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
      
    	return 0;
}

