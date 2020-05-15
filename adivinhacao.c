// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// definindo as constantes
#define NUMERO_DE_TENTATIVAS 3
#define PONTOS 1000

int main() {

	setlocale(LC_ALL, "Portuguese");
	
	// declarando variaveis que serao usadas mais a frente
	int chute;
	int acertou;
	int nivel;
	int totaldetentativas;
	int intervaloInicial;
	int intervaloFinal;
	int acabou = 0;

	// definindo a quantidade de pontos inicial
	double pontos = 1000;

	// loop principal do jogo

	do {

		// imprimindo cabecalho bonito do jogo
		printf("\n\n");
		printf("          P  /_\\  P                              \n");
		printf("         /_\\_|_|_/_\\                            \n");
		printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
		printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
		printf("    |\" \"  |  |_|  |\"  \" |                     \n");
		printf("    |_____| ' _ ' |_____|                         \n");
		printf("          \\__|_|__/                              \n");
		printf("\n\n");

		// Escolhendo o intervalo entre dois números que o usuário deseja jogar.
		printf("Digite o nº de intervalo inicial que deseja jogar: \n");
		scanf("%d", &intervaloInicial);
		printf("Digite o nº de intervalo final que deseja jogar: \n");
		scanf("%d", &intervaloFinal);
		printf("O intervalo escolhido foi entre %d e %d. \n", intervaloInicial, intervaloFinal);

		// função time(), srand() e rand() das libs time.h e stdlib 
		srand(time(0));
		int numerosecreto = intervaloInicial + (rand() % intervaloFinal);

		printf("O numero secreto é %d \n", numerosecreto); 

		// escolhendo o nivel de dificuldade
		printf("Qual o nível de dificuldade?\n");
		printf("(1) Fácil (2) Médio (3) Difícil\n\n");
		printf("Escolha: ");

		scanf("%d", &nivel);

		switch(nivel) {
			case 1: 
			totaldetentativas = 20;
			break;
			case 2:
			totaldetentativas = 15;
			break;
			default:
			totaldetentativas = 6;
			break;
		}

		for(int i = 1; i <= totaldetentativas; i++) {

			printf("-> Tentativa %d de %d\n", i, totaldetentativas);

			printf("Chute um número: ");
			scanf("%d", &chute);

		// tratando chute de numero negativo
			if(chute < 0) {
				printf("Você não pode chutar números negativos\n");
				i--;
				continue;
			}

		// verifica se acertou, foi maior ou menor
			acertou = chute == numerosecreto;
			
			if(acertou) {
				break;
			} else if(chute > numerosecreto) {
				printf("\nSeu chute foi maior do que o número secreto!\n\n");
			} else {
				printf("\nSeu chute foi menor do que o número secreto!\n\n");
			}

		// calcula a quantidade de pontos
			double pontosperdidos = abs(chute - numerosecreto) / 2.0;
			pontos = pontos - pontosperdidos;
		} 

		//imprimindo mensagem de vitoria ou derrota
		printf("\n");
		if(acertou) {
			printf("             OOOOOOOOOOO               \n");
			printf("         OOOOOOOOOOOOOOOOOOO           \n");
			printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
			printf("    OOOOOO      OOOOO      OOOOOO      \n");
			printf("  OOOOOOOO  $   OOOOO  $   OOOOOOOO    \n");
			printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
			printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
			printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
			printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
			printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
			printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
			printf("         OOOOOO         OOOOOO         \n");
			printf("             OOOOOOOOOOOO              \n");
			printf("\nParabéns! Você acertou!\n");
			printf("Você fez %.2f pontos. Até a próxima!\n\n", PONTOS);
		} else {

			printf("       \\|/ ____ \\|/    \n");   
			printf("        @~/ ,. \\~@      \n");   
			printf("       /_( \\__/ )_\\    \n");   
			printf("          \\__U_/        \n");

			printf("\nVocê perdeu! Tente novamente!\n\n");
		}
		// Deseja jogar novamente?
		printf("Deseja jogar novante? \n");
		printf("(1) Sim (2) Não\n");
		int resposta;
		scanf("%d", &resposta);

		if(resposta == 2) {
			acabou = 1;
			break;
		} 
	} while(acabou == 0);
}
