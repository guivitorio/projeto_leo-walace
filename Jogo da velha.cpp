#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Planejamento
	
	Fazer um sistema de condições onde o jogador aperta 1 para começar o jogo
	Assim o software vai pedir o nome dos jogadores 1 e 2.
	em seguida vai fazer um laço de repetição que irá realizar o jogo enquanto a resposta for sim 	
*/

void tabuleiro(char casa2[3][3]){
	system("cls");
	printf("\t  Colunas");
	printf("\n");
	printf("\t 1   2   3");
	printf("\n\n");
	printf("\t %c | %c | %c   1\n", casa2[0][0],casa2[0][1],casa2[0][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c   2 linhas\n", casa2[1][0],casa2[1][1],casa2[1][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c   3\n", casa2[2][0],casa2[2][1],casa2[2][2]);
	printf("\n");
}


int main(){
	setlocale(0,"Portuguese");
	char resposta;
	char player1[256];
	char player2[256];
	int cont_jog = 0, lin = 0, col = 0, vez = 0, i = 0, j = 0, cont_pontosX = 0, cont_pontosO = 0;
	int iniciar;
	printf("---------------Jogo da Velha X ou O---------------");
	printf("\n\n");
	printf("\tDigite 1 para começar o jogo: ");	
	scanf("%d", &iniciar);
	getchar();
	printf("\n");
	
	
	if(iniciar == 1){
		
		
		char casa[3][3] = { {'1','2','3'},
							{'4','5','6'},
							{'7','8','9'}, };	
							
		
		printf("   ---------------Player 1----------------");
		printf("\n");
		printf("\t     Digite seu nome:  ");
		fgets(player1,256,stdin);
		printf("\n\n");
		printf("    --------------Player 2--------------");
		printf("\n");
		printf("\t     Digite seu nome:  ");
		fgets(player2,256,stdin);
		printf("\n\n");
		do{
			cont_jog = 1;
			for(i=0;i<=2;i++){
				for(j=0;j<=2;j++){
					casa[i][j] = ' ';
				}
			}
			do{
				tabuleiro(casa);//A função tabuleiro vai receber as cordenadas do vetor de char (CASA)
				
				if(vez%2==0){
					printf("     Vez do Jogador X\n");//sistema para indentificar vez do jogador X
					printf("\n");
				}else{
					printf("     Vez do Jogador O\n");//sistema para indentificar vez do jogador O
					printf("\n");
				}
				printf("  Digite a linha da jogada: ");
				scanf("%d", &lin);
				getchar();
				printf("  Digite a coluna da jogada: ");
				scanf("%d", &col);
				getchar();
				if (lin < 1 || lin > 3 || col < 1 || col > 3){//se a jogador digitar a linha e coluna menor q 1 e mairo q 3, vai pedir novamente para o jogador digitar as cordenadas
					lin = 0;
					col = 0;
				}
				else if(casa[lin-1][col-1] != ' '){
					lin = 0;//se o jogador digitar um espaço no software, vai pedir que o jogador repita sua jogada
					col = 0;
					printf("\tEsta Posição já foi escolhida !");
				}
				else{
					if (vez %2 == 0){
						casa[lin-1][col-1] =  'X';//Vai imprimir o X na jogada desejada
					}
					else{
					casa[lin-1][col-1] =  'O';//Vai imprimir o O na jogada desejada
					}
					vez++;
					cont_jog++;
				}
				//condições do jogador X ganhar
				if(casa[0][0] == 'X' && casa[0][1] == 'X' && casa[0][2] == 'X'){
				cont_jog = 11;
				}
				if(casa[1][0] == 'X' && casa[1][1] == 'X' && casa[1][2] == 'X'){
				cont_jog = 11;
				}
				if(casa[2][0] == 'X' && casa[2][1] == 'X' && casa[2][2] == 'X'){
				cont_jog = 11;
				}
				if(casa[0][0] == 'X' && casa[1][0] == 'X' && casa[2][0] == 'X'){
				cont_jog = 11;
				}
				if(casa[0][1] == 'X' && casa[1][1] == 'X' && casa[2][1] == 'X'){
				cont_jog = 11;
				}
				if(casa[0][2] == 'X' && casa[1][2] == 'X' && casa[2][2] == 'X'){
				cont_jog = 11;
				}
				if(casa[0][0] == 'X' && casa[1][1] == 'X' && casa[2][2] == 'X'){
				cont_jog = 11;
				}
				if(casa[0][2] == 'X' && casa[1][1] == 'X' && casa[2][0] == 'X'){
				cont_jog = 11;
				}
				//Condições do jogador O ganhar
				if(casa[0][0] == 'O' && casa[0][1] == 'O' && casa[0][2] == 'O'){
				cont_jog = 12;
				}
				if(casa[1][0] == 'O' && casa[1][1] == 'O' && casa[1][2] == 'O'){
				cont_jog = 12;
				}
				if(casa[2][0] == 'O' && casa[2][1] == 'O' && casa[2][2] == 'O'){
				cont_jog = 12;
				}
				if(casa[0][0] == 'O' && casa[1][0] == 'O' && casa[2][0] == 'O'){
				cont_jog = 12;
				}
				if(casa[0][1] == 'O' && casa[1][1] == 'O' && casa[2][1] == 'O'){
				cont_jog = 12;
				}
				if(casa[0][2] == 'O' && casa[1][2] == 'O' && casa[2][2] == 'O'){
				}
				if(casa[0][0] == 'O' && casa[1][1] == 'O' && casa[2][2] == 'O'){
				cont_jog = 12;
				}
				if(casa[0][2] == 'O' && casa[1][1] == 'O' && casa[2][0] == 'O'){
				cont_jog = 12;
				}
			}while(cont_jog <=9);
			tabuleiro(casa);
			if (cont_jog == 10){//se contador de jogadas for ==10 vai imprimir uma mensagem, o jogo deu velha !
				printf("Deu velha!!\n");
			}
			if (cont_jog == 11){//se contador de jogadas for ==11 vai imprimir uma mensagem, o jogador X Venceu !
				printf("Jogador %s venceu!!\n", player1);
			}
			if (cont_jog == 12){//se contador de jogadas for ==11 vai imprimir uma mensagem, o jogador O Venceu !
				printf("Jogador %s venceu!!\n", player2);
			}
			printf("\n");
			printf("Os usuários desejam jogar novamente?\nDigite [S ou N]: ");
			scanf("%s", &resposta);
			getchar();
			printf("\n");
			if(resposta != 's' || resposta != 'S'){
				system("CLS");
				printf("\n\n");
				printf("------------------------------------------------------------------\n");
				printf("\t\tObrigado por jogar!!\nFeito por: Arthur Pimentel, Marcely Pereira, Guilherme Vitório, Augusto\n");
				printf("------------------------------------------------------------------");
				printf("\n\n");
				printf("\n");
				
			}
		}while(resposta == 's' || resposta == 'S');//vai repetir em quanto a resposta for , "S" ou "s"
	}else{
		printf("\n\n");
		printf("\tVocê não digitou um número válido!");
	}
	
	return 0; 
}
