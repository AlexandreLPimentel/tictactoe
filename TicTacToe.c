#include <stdio.h>
#include <stdlib.h>

/******************************************************************************************\
| Jogo do Galo. Jogador vs. Computador. O computador nunca perde. A maior parte das jogadas|
| baseiam-se no facto de se a jogada do Jogador foi numa Edge, num Corner ou no Center.    |
|                                                                                          |
|                                Corner| Edge |Corner                                      |
|                                --------------------                                      |
|                                 Edge |Center| Edge                                       |
|                                --------------------                                      |
|                                Corner| Edge |Corner                                      |
|                                                                                          |
| Para simplificar as contas, os corners são números impares (1, 3, 7 e 9), os edges são   |
| números pares (2, 4, 6 e 8) e o Center é 5, sendo as jogadas dadas por esse números.     |
|                                                                                          |
|                                        1|2|3                                             |
|                                        -----                                             |
|                                        4|5|6                                             |
|                                        -----                                             |
|                                        7|8|9                                             |                                
|                                                                                          |
\******************************************************************************************/


char v[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '}; //inicialização do vector que guarda as jogadas
int jogador, jogada, sair, primeiro, n_jogada, tactica, skip, clean, vit, der, emp;
char novo_jogo;

//protótipos de todos os procedimentos utilizados

void jogo(); //cálculo da jogada do computador
void imprime_jogo(); //o painel de jogo actual é impresso
void pede_jogada(); //é pedida a jogada ao Jogador
void primeiro_ecra(); //mostra ao Jogador o número correspondente a cada posição no jogo
void verifica_vitoria(); //verifica se já houve vitória ou se o jogo acabou
void win1block2(); //parte da jogada do computador. Se o computador foi o primeiro a jogar então vai ver se pode ganhar, se foi o segundo vai bloquear a vitória do adversário se necessário
void win2block1(); //exactamente o contrário do procedimento anterior

main(){
        srand(time(NULL));
        primeiro=rand()%2+1; //É escolhido aleatoriamente o primeiro jogador
        jogador=primeiro;
        for(novo_jogo='s';novo_jogo=='S'||novo_jogo=='s';system("cls")){ //enquanto o jogador quiser continuar a jogar não sai deste ciclo
        for(sair=0, n_jogada=1;sair==0;n_jogada++){ //Enquanto ninguém ganhar ou não houver empate vão sendo contadas mais jogadas
                                                   if(n_jogada==1){
                                                                   if(primeiro==2){ //diz quem começou, pede jogada
                                                                                   primeiro_ecra();
                                                                                   printf("Comeca o jogador.\n\n");
                                                                                   pede_jogada();
                                                                                   n_jogada++;
                                                                                   jogador=1;
                                                                                   }
                                                                   if(primeiro==1){ //diz quem começou, o computador joga
                                                                                   primeiro_ecra();
                                                                                   printf("Comecou o computador.\n\n");
                                                                                   jogo();
                                                                                   n_jogada++;
                                                                                   jogador=2;
                                                                                   }
                                                                                   
                                                                   }
                                                   
                                                   
                                                  
                                                                               
                                                   if(n_jogada>1){ //da jogada 2 para cima isto vai ser sempre executado
                                                                  imprime_jogo();
                                                                  if(jogador==2) pede_jogada();
                                                                  if(jogador==1) jogo();
                                                                  }
                                                   
                                                   if(jogador==2) jogador=1; //troca os jogadores
                                                   else jogador=2; //igual a ^^
                                                   verifica_vitoria(); //verifica se alguém ganhou
                                                   system("cls");
                                                   printf("\nO computador jogou.\n\n");
                                                   }
       
       imprime_jogo(); //imprime o último ecrã de jogo pois este foi limpo no system("cls") anterior
       if((sair==1&&primeiro==2)||(sair==2&&primeiro==1)){ //diz quem ganha
                                                          printf("Ganhou!\n");
                                                          vit++; //incrementa a variável das vitórias
                                                          }
       if((sair==1&&primeiro==1)||(sair==2&&primeiro==2)){ //diz quem ganha
                                                          printf("Perdeu! O computador e o maior! :P\n");
                                                          der++; //incrementa a variável das derrotas
                                                          }
       if(sair==3){
                   printf("\nEmpate!\n"); //diz que há empate
                   emp++; //incrementa a variável de empate
                   }
       printf("\nDeseja jogar novamente?(s/n)\n"); //pergunta se o utilizador quer jogar novamente
       scanf(" %c", &novo_jogo); //grava a resposta
       if(novo_jogo=='s'||novo_jogo=='S'){ //see sim limpa todas as jogadas e troca o primeiro jogador; se antes começou o Jogador a seguir começa o Computador e vice-versa
                                          for(clean=0;clean<9;clean++) v[clean]=' ';
                                          if(primeiro==1) primeiro=2;
                                          else primeiro=1;
                                          }
       else{ //se não diz o número de vitórias (que vão ser SEMPRE 0), derrotas e empates
            printf("Numero de vitorias: %d\nNumero de derrotas: %d\nNumero de empates: %d\n", vit, der, emp);
            system("pause"); 
            }
       }
       }

void jogo(){ //não vou estar a explicar todas as jogadas, já não aguento mais jogo do galo... a estratégia veio toda do site http://www.chessandpoker.com/tic_tac_toe_strategy.html
            if(n_jogada==1){
                            srand(time(NULL));
                            jogada=rand()%4;
                            if(jogada==0) jogada=9;
                            if(jogada==2) jogada=7;
                            }
            
            if(n_jogada==3){
                            if(v[4]=='O'){
                                          if(v[0]=='X') jogada=9;
                                          if(v[2]=='X') jogada=7;
                                          if(v[6]=='X') jogada=3;
                                          if(v[8]=='X') jogada=1;
                                          tactica=1;
                                          }
                            if(v[1]=='O'||v[3]=='O'||v[5]=='O'||v[7]=='O'){
                                                                           jogada=5;
                                                                           tactica=2;
                                                                           }
                            if(v[0]=='O'||v[2]=='O'||v[6]=='O'||v[8]=='O'){
                                                                           if(v[0]==' ') jogada=1;
                                                                           if(v[2]==' ') jogada=3;
                                                                           if(v[6]==' ') jogada=7;
                                                                           if(v[8]==' ') jogada=9;
                                                                           tactica=3;
                                                                           }
                            }
                            
            if(n_jogada==5){
                            win1block2(); //tenta ganhar
                            if(skip==0){ //se não ganhar vai às jogadas
                            
                            if(tactica==1) win2block1();
                                           
                            if(tactica==2){
                                           if(v[0]=='X'){
                                                         if(v[1]=='O'||v[7]=='O') jogada=7;
                                                         if(v[3]=='O'||v[5]=='O') jogada=3;
                                                         }
                                           if(v[2]=='X'){
                                                         if(v[1]=='O'||v[7]=='O') jogada=9;
                                                         if(v[3]=='O'||v[5]=='O') jogada=1;
                                                         }
                                           if(v[6]=='X'){
                                                         if(v[1]=='O'||v[7]=='O') jogada=1;
                                                         if(v[3]=='O'||v[5]=='O') jogada=9;
                                                         }
                                           if(v[8]=='X'){
                                                         if(v[1]=='O'||v[7]=='O') jogada=3;
                                                         if(v[3]=='O'||v[5]=='O') jogada=7;
                                                         }
                                           }
                            if(tactica==3){
                                           if(v[0]==' ') jogada=1;
                                           if(v[2]==' ') jogada=3;
                                           if(v[6]==' ') jogada=7;
                                           if(v[8]==' ') jogada=9;
                                           }
                            }
                            }
                            
            if(n_jogada==7||n_jogada==9){
                                         win1block2();
                                         if(skip==0) win2block1();
                                         if(skip==0) for(jogada=1; v[jogada-1]!=' '; jogada++);
                                         }
            
            if(n_jogada==2){
                            if(v[4]==' '){
                                          jogada=5;
                                          tactica=2;
                                          }
                            else{
                                 srand(time(NULL));
                                 jogada=rand()%4;
                                 if(jogada==0) jogada=9;
                                 if(jogada==2) jogada=7;
                                 tactica=1;
                                 }
                            }
            
            if(n_jogada==4){
                            if(tactica==1){
                                          win1block2();
                                          if(skip==0){
                                                      if(v[0]==' ') jogada=1;
                                                      if(v[2]==' ') jogada=3;
                                                      if(v[6]==' ') jogada=7;
                                                      if(v[8]==' ') jogada=9;
                                                      }
                                          }
                            if(tactica==2){
                                           if((v[1]=='X'||v[3]=='X'||v[5]=='X'||v[7]=='X')&&(v[0]=='X'||v[2]=='X'||v[6]=='X'||v[8]=='X')){
                                                                                                                                         win1block2();
                                                                                                                                         if(skip==0){
                                                                                                                                                     if(v[0]=='X') jogada=9;
                                                                                                                                                     if(v[2]=='X') jogada=7;
                                                                                                                                                     if(v[6]=='X') jogada=3;
                                                                                                                                                     if(v[8]=='X') jogada=1;
                                                                                                                                                     }
                                                                                                                                         }
                                           else if(v[1]=='X'&&v[3]=='X'){
                                                                         jogada=1;
                                                                         tactica=3;
                                                                         }
                                           else if(v[1]=='X'&&v[5]=='X'){
                                                                         jogada=3;
                                                                         tactica=3;
                                                                         }
                                           else if(v[3]=='X'&&v[7]=='X'){
                                                                         jogada=7;
                                                                         tactica=3;
                                                                         }
                                           else if(v[5]=='X'&&v[7]=='X'){
                                                                         jogada=9;
                                                                         tactica=3;
                                                                         }
                                           else if((v[0]=='X'&&v[2]=='X')||(v[0]=='X'&&v[8]=='X')||(v[0]=='X'&&v[6]=='X')||(v[2]=='X'&&v[6]=='X')||(v[2]=='X'&&v[8]=='X')||(v[6]=='X'&&v[8]=='X')){
                                                                                                                                                                                                   win1block2();
                                                                                                                                                                                                   if(skip==0){
                                                                                                                                                                                                               srand(time(NULL));
                                                                                                                                                                                                               jogada=rand()%4+2;
                                                                                                                                                                                                               if(jogada==3) jogada=5;
                                                                                                                                                                                                               if(jogada==5) jogada=8;
                                                                                                                                                                                                               tactica=4;
                                                                                                                                                                                                               }
                                                                                                                                                                                                   }
                                           else{
                                                for(jogada=1; (v[jogada-1]!=' ')||(jogada%2==0); jogada++);
                                                tactica=5;
                                                }
                                                                                                                                                                                                          
                                           
                                           
                                           
                                           }
                            }
                            
            if(n_jogada==6){
                            win2block1(); //tenta ganhar
                            if(skip==0) win1block2(); //se não ganhar bloqueia
                            if(skip==0){ //se não bloquear vai às jogadas
                            if(tactica==1){
                                           if(v[0]==' ') jogada=1;
                                           else if(v[2]==' ') jogada=3;
                                           else if(v[6]==' ') jogada=7;
                                           else if(v[8]==' ') jogada=9;
                                           else for(jogada=1;v[jogada-1]!=' ';jogada++);
                                           }
                            if(tactica==2||tactica==3||tactica==4) if(skip==0) for(jogada=1;v[jogada-1]!=' ';jogada++);
                            if(tactica==5){
                                           if(v[1]==' ') jogada=3;
                                           if(v[3]==' ') jogada=1;
                                           if(v[5]==' ') jogada=9;
                                           if(v[7]==' ') jogada=7;
                                           }               
                            
                            }               
                            }         
            if(n_jogada==8){
                            win2block1();
                            if(skip==0) win1block2();
                            if(skip==0){
                            if(tactica==1){
                                           if(v[0]==' ') jogada=1;
                                           else if(v[2]==' ') jogada=3;
                                           else if(v[6]==' ') jogada=7;
                                           else if(v[8]==' ') jogada=9;
                                           else for(jogada=1;v[jogada-1]!=' ';jogada++);
                                           }
                            if(tactica==2||tactica==3||tactica==4) if(skip==0) for(jogada=1;v[jogada-1]!=' ';jogada++);
                            }
                            }
            
            
            if(primeiro==1) v[jogada-1]='X'; //se tiver sido o computador o primeiro grava a sua jogada no vector como 'X'
            if(primeiro==2) v[jogada-1]='O'; //se tiver sido o jogador o primeiro grava a jogada do computador como 'O'
            }
void imprime_jogo(){ //imprime o painel de jogo actual
                    printf(" %c | %c | %c \n", v[0], v[1], v[2]);
                    printf("-----------\n");
                    printf(" %c | %c | %c \n", v[3], v[4], v[5]);
                    printf("-----------\n");
                    printf(" %c | %c | %c \n", v[6], v[7], v[8]);
                    }

void pede_jogada(){ //pede a jogada ao Jogador
                   printf("\nJogador e a sua vez.\nIndique a posicao.\n", jogador);
                   scanf("%d", &jogada);
                   while(v[jogada-1]!=' '||jogada<1||jogada>9){ //se essa posição já tiver sido jogada ou não existir, pede-a novamente
                                                               printf("Essa posicao ja foi jogada ou e invalida. Escolha outra.\n");
                                                               scanf("%d", &jogada);
                                                               }
                   if(primeiro==1) v[jogada-1]='O'; //se o computador foi o primeiro grava a jogada do jogador como 'O'
                   if(primeiro==2) v[jogada-1]='X'; //se o jogador foi o primeiro grava a jogada do jogador como 'X'
                   }
                   
void primeiro_ecra(){ //imprime o primeiro ecrã para o jogador saber que número corresponde a cada espaço
                     printf(" 1 | 2 | 3 \n");
                     printf("-----------\n");
                     printf(" 4 | 5 | 6 \n");
                     printf("-----------\n");
                     printf(" 7 | 8 | 9 \n");
                     }

void verifica_vitoria(){ //verifica quem ganhou
                        if((v[0]=='X'&&v[1]=='X'&&v[2]=='X')||(v[0]=='X'&&v[4]=='X'&&v[8]=='X')||(v[0]=='X'&&v[3]=='X'&&v[6]=='X')||(v[1]=='X'&&v[4]=='X'&&v[7]=='X')||(v[2]=='X'&&v[5]=='X'&&v[8]=='X')||(v[3]=='X'&&v[4]=='X'&&v[5]=='X')||(v[6]=='X'&&v[7]=='X'&&v[8]=='X')||(v[2]=='X'&&v[4]=='X'&&v[6]=='X'))sair=1;
                        //ganhou o 'X' ^^ então sair=1
                        if((v[0]=='O'&&v[1]=='O'&&v[2]=='O')||(v[0]=='O'&&v[4]=='O'&&v[8]=='O')||(v[0]=='O'&&v[3]=='O'&&v[6]=='O')||(v[1]=='O'&&v[4]=='O'&&v[7]=='O')||(v[2]=='O'&&v[5]=='O'&&v[8]=='O')||(v[3]=='O'&&v[4]=='O'&&v[5]=='O')||(v[6]=='O'&&v[7]=='O'&&v[8]=='O')||(v[2]=='O'&&v[4]=='O'&&v[6]=='O'))sair=2;
                        //ganhou o 'O' ^^ então sair=2
                        else if(n_jogada==9) sair=3;
                        //chegou-se ao fim das jogadas então não ganha ninguém, sair=3
                        }

void win1block2(){
                  skip=1; //toma como ponto de partida que vai bloquear/ganhar nesta jogada
                  if(v[0]==' '&&v[1]=='X'&&v[2]=='X') jogada=1;
                  else if(v[0]==' '&&v[3]=='X'&&v[6]=='X') jogada=1;
                  else if(v[0]==' '&&v[4]=='X'&&v[8]=='X') jogada=1;
                  else if(v[1]==' '&&v[0]=='X'&&v[2]=='X') jogada=2;
                  else if(v[1]==' '&&v[4]=='X'&&v[7]=='X') jogada=2;
                  else if(v[2]==' '&&v[0]=='X'&&v[1]=='X') jogada=3;
                  else if(v[2]==' '&&v[5]=='X'&&v[8]=='X') jogada=3;
                  else if(v[2]==' '&&v[4]=='X'&&v[6]=='X') jogada=3;
                  else if(v[3]==' '&&v[0]=='X'&&v[6]=='X') jogada=4;
                  else if(v[3]==' '&&v[4]=='X'&&v[5]=='X') jogada=4;
                  else if(v[4]==' '&&v[0]=='X'&&v[8]=='X') jogada=5;
                  else if(v[4]==' '&&v[2]=='X'&&v[6]=='X') jogada=5;
                  else if(v[4]==' '&&v[1]=='X'&&v[7]=='X') jogada=5;
                  else if(v[4]==' '&&v[3]=='X'&&v[5]=='X') jogada=5;
                  else if(v[5]==' '&&v[2]=='X'&&v[8]=='X') jogada=6;
                  else if(v[5]==' '&&v[3]=='X'&&v[4]=='X') jogada=6;
                  else if(v[6]==' '&&v[0]=='X'&&v[3]=='X') jogada=7;
                  else if(v[6]==' '&&v[7]=='X'&&v[8]=='X') jogada=7;
                  else if(v[6]==' '&&v[4]=='X'&&v[2]=='X') jogada=7;
                  else if(v[7]==' '&&v[6]=='X'&&v[8]=='X') jogada=8;
                  else if(v[7]==' '&&v[4]=='X'&&v[1]=='X') jogada=8;
                  else if(v[8]==' '&&v[6]=='X'&&v[7]=='X') jogada=9;
                  else if(v[8]==' '&&v[2]=='X'&&v[5]=='X') jogada=9;
                  else if(v[8]==' '&&v[0]=='X'&&v[4]=='X') jogada=9;
                  else skip=0; //se não o fez então entra aqui e as jogadas são feitas normalmente                                                                                       
                  }
                  

void win2block1(){ //igual ao anterior ^^
                  skip=1;
                  if(v[0]==' '&&v[1]=='O'&&v[2]=='O') jogada=1;
                  else if(v[0]==' '&&v[3]=='O'&&v[6]=='O') jogada=1;
                  else if(v[0]==' '&&v[4]=='O'&&v[8]=='O') jogada=1;
                  else if(v[1]==' '&&v[0]=='O'&&v[2]=='O') jogada=2;
                  else if(v[1]==' '&&v[4]=='O'&&v[7]=='O') jogada=2;
                  else if(v[2]==' '&&v[0]=='O'&&v[1]=='O') jogada=3;
                  else if(v[2]==' '&&v[5]=='O'&&v[8]=='O') jogada=3;
                  else if(v[2]==' '&&v[4]=='O'&&v[6]=='O') jogada=3;
                  else if(v[3]==' '&&v[0]=='O'&&v[6]=='O') jogada=4;
                  else if(v[3]==' '&&v[4]=='O'&&v[5]=='O') jogada=4;
                  else if(v[4]==' '&&v[0]=='O'&&v[8]=='O') jogada=5;
                  else if(v[4]==' '&&v[2]=='O'&&v[6]=='O') jogada=5;
                  else if(v[4]==' '&&v[1]=='O'&&v[7]=='O') jogada=5;
                  else if(v[4]==' '&&v[3]=='O'&&v[5]=='O') jogada=5;
                  else if(v[5]==' '&&v[2]=='O'&&v[8]=='O') jogada=6;
                  else if(v[5]==' '&&v[3]=='O'&&v[4]=='O') jogada=6;
                  else if(v[6]==' '&&v[0]=='O'&&v[3]=='O') jogada=7;
                  else if(v[6]==' '&&v[7]=='O'&&v[8]=='O') jogada=7;
                  else if(v[6]==' '&&v[4]=='O'&&v[2]=='O') jogada=7;
                  else if(v[7]==' '&&v[6]=='O'&&v[8]=='O') jogada=8;
                  else if(v[7]==' '&&v[4]=='O'&&v[1]=='O') jogada=8;
                  else if(v[8]==' '&&v[6]=='O'&&v[7]=='O') jogada=9;
                  else if(v[8]==' '&&v[2]=='O'&&v[5]=='O') jogada=9;
                  else if(v[8]==' '&&v[0]=='O'&&v[4]=='O') jogada=9;
                  else skip=0;                                                                                       
                  }
