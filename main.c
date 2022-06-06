#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "jogoConst.c"
#include "jogoMath.c"
#include "structs.c"
#include "utils.c"
Enemies *inimigos;
int inimRestante;
int pontos;
char *nomeJogador;

void jogoLoop(clock_t time);


int main()
{
    int menu;
    nomeJogador = (char*)malloc(sizeof(char)*30);
    system("cls");
    gotoxy(50, 13);
    printf("MORTEIRO DOS PRACINHAS:");
    gotoxy(50, 15);
    printf("1- Iniciar");
    gotoxy(50, 17);
    printf("2- Dificuldade");
    gotoxy(50, 19);
    printf("3- Sair");
    gotoxy(75,13);   
    while(true){
        scanf("%d", &menu);

        switch(menu){        
            case 1:
                system("cls");
                gotoxy(50, 14);
                printf("Digite o nome do jogador: \n");
                gotoxy(78, 14);
                scanf(" %s", nomeJogador);
                gotoxy(30, 16);

                system("cls");

                gotoxy(0, LIMITE_VERT - 1);
                for (int i = 0; i < LIMITE; i++)
                {
                    printf("*");
                }
                gotoxy(0, LIMITE_VERT - 5);
                for (int i = 0; i < LIMITE; i++)
                {
                    printf("-");
                }
                gotoxy((LIMITE / 2) - 5, LIMITE_VERT - 4);
                printf("%s", nomeJogador);
                gotoxy((LIMITE / 2) - 9, LIMITE_VERT - 3);
                printf("Alvos vivos: ");
                printf("%d", numero);
                gotoxy((LIMITE / 2) - 7, LIMITE_VERT - 2);
                printf("Tempo: ");
                
                gotoxy((LIMITE / 2) - 22, (LIMITE_VERT - 4) / 2 - 2);
                printf("PRESSIONE QUALQUER BOTAO PARA COMECAR O JOGO");
                getch();
                gotoxy(0, (LIMITE_VERT - 4) / 2 - 2);
                for (int i = 0; i < LIMITE; i++)
                {
                    printf(" ");
                }

                clock_t inicio = clock();
                jogoLoop(inicio);

                system("cls");
                system("cls");
                int i;
                system("cls");
                gotoxy(50, 13);
                
                printf("MORTEIRO DOS PRACINHAS:");
                gotoxy(50, 15);
                printf("1- Iniciar");
                gotoxy(50, 17);
                printf("2- Dificuldade");
                gotoxy(50, 19);
                printf("3- Sair");
                gotoxy(75,13);

            break;
            case 2:
                system("cls");
                gotoxy(50, 14);
                printf("Digite o nivel de dificuldade que deseja: ");
                gotoxy(50, 16);
                printf("1 - Treino");
                gotoxy(50, 18);
                printf("2 - Facil");
                gotoxy(50, 20);
                printf("3 - Medio");
                gotoxy(50, 22);
                printf("4 - Dificil");
                gotoxy(93, 14);
                scanf("%d", &numero);
                system("cls");
                if(numero == 1){
                    inimigos = (Enemies*) malloc(sizeof(Enemies)*5);
                    numero = 5;
                }
                else if(numero == 2){
                    inimigos = (Enemies*) malloc(sizeof(Enemies)*10);
                    numero = 10;
                }
                else if(numero == 3){
                    inimigos = (Enemies*) malloc(sizeof(Enemies)*15);
                    numero = 15;
                } 
                else if(numero == 4){
                    inimigos = (Enemies*) malloc(sizeof(Enemies)*20);
                    numero = 20;
                } 
                inimRestante = numero;
                system("cls");
                gotoxy(50, 13);
                printf("MORTEIRO DOS PRACINHAS:");
                gotoxy(50, 15);
                printf("1- Iniciar");
                gotoxy(50, 17);
                printf("2- Dificuldade");
                gotoxy(50, 19);
                printf("3- Sair");
                gotoxy(75,13);  
            break;
            case 3:
                system("cls");
                return 0;
            break;
            default:
            //int menu;
                system("cls");
                gotoxy(50, 13);
                printf("MORTEIRO DOS PRACINHAS:");
                gotoxy(50, 15);
                printf("1- Iniciar");
                gotoxy(50, 17);
                printf("2- Dificuldade");
                gotoxy(50, 19);
                printf("3- Sair");
                gotoxy(75,13);                
    }
}
    
    return 0;
}

void jogoLoop(clock_t inicio)
{
    char a, i;
    time_t t;
    srand((int) time(&t));
    // Bala balas;
    Bala bala[numero];
    int var = 100;
    for (int i = 0; i < numero; i++)
    {
        bala[i].x = 0;
        bala[i].y = 0;
        bala[i].ativo = false;
        bala[i].a = 0;
        bala[i].b = 0;
        bala[i].c = 0;
        bala[i].width = bala[i].height = 5;
        bala[i].img = 'o';

    }
    for(int i = 0; i < numero; i++){
        inimigos[i].img = 'X';
        inimigos[i].cont = 0;
        inimigos[i].active = true;
        inimigos[i].y = rand() % (24 + 1 - 0) + 0;
        inimigos[i].x = var;
        var++;
        inimigos[i].width = inimigos[i].height = 15;
        gotoxy(inimigos[i].x, inimigos[i].y);
        printf("%c", inimigos[i].img);
        Sleep(100);
    }
    

    while (true)
    {
        gotoxy((LIMITE / 2) - 10, LIMITE_VERT - 2);
        printf("Tempo: %d segundos", (clock()- inicio)/1000);
        // Pega tecla
        if (kbhit())
        {
            a = getch();
            if (a == ' ')
            {
                for (int i = 0; i < numero; i++)
                {
                    
                    if (bala[i].ativo == false)
                    {
                        bala[i].ativo = true;
                        bala[i].x = 0;
                        bala[i].y = 15;
                        bala[i].c = bala[i].y;
                        bala[i].a = (max(-15, 4 - bala[i].c)) / ((LIMITE / 2) * (LIMITE / 2 - LIMITE));
                        bala[i].b = -bala[i].a * LIMITE;
                        gotoxy((LIMITE / 2) - 1, LIMITE_VERT - 2);
                        break;
                    }
                    if (bala[i].ativo == false)
                    {
                        bala[i].ativo = true;
                        bala[i].x = 0;
                        bala[i].y = 15;
                        bala[i].c = bala[i].y;
                        bala[i].a = (max(-15, 4 - bala[i].c)) / ((LIMITE / 2) * (LIMITE / 2 - LIMITE));
                        bala[i].b = -bala[i].a * LIMITE;
                        gotoxy((LIMITE / 2) - 1, LIMITE_VERT - 2);
                    }
                }
            }
            if (a == 'q')
            {
                break;
            }
        }

        //Desenha
            for (int i = 0; i < numero; i++) {
                if (bala[i].ativo) {

                    gotoxy(bala[i].x, bala[i].y);
                    printf(" ");

                    if (bala[i].x > LIMITE) {
                        bala[i].ativo = false;
                        break;
                    }

                    gotoxy(20, 20);
                    //printf("%f %f %f", bala[i].a, bala[i].b, bala[i].c);

                    bala[i].x++;
                    bala[i].y = (int)solve2(bala[i].a, bala[i].b, bala[i].c, bala[i].x);

                    gotoxy(bala[i].x, bala[i].y);
                    printf("o");
                }
            }
            for(int i = 0; i < numero ; i++){
                if(inimigos[i].active){
                    gotoxy(inimigos[i].x, inimigos[i].y);
                    printf(" ");
                    if(bala[i].x < inimigos[i].x + inimigos[i].width &&
                    bala[i].x + bala[i].width > inimigos[i].x &&
                    bala[i].y < inimigos[i].y + inimigos[i].height &&
                    bala[i].y + bala[i].height > inimigos[i].y){
                        inimigos[i].img = 'X';
                        inimigos[i].active = 0;
                        inimigos[i].x = 1000;
                        inimigos[i].y = -1;
                        inimigos[i].width = inimigos[i].height = 0;
                        gotoxy(-1, -1);
                        inimigos[i].img = ' ';
                        printf("%c", inimigos[i].img);
                        

                        gotoxy((LIMITE / 2) - 9, LIMITE_VERT - 3);
                        printf("Alvos vivos: ");
                        if(inimRestante--) pontos+=100;
                        printf("%d", inimRestante);

                        if(inimRestante == 0){
                            for (int i = 0; i < numero; i++){
                                    bala[i].x = 0;
                                    bala[i].y = 0;
                                    bala[i].ativo = false;
                                    bala[i].a = 0;
                                    bala[i].b = 0;
                                    bala[i].c = 0;
                                    bala[i].width = bala[i].height = 5;
                                    bala[i].img = 'o';
                            }
                            gotoxy(45, 15);
                            system("pause");
                            system("cls");
                            goto label;
                        }
                    }

                    if(inimigos[i].x < 40){
                        //tela de game over
                        system("cls");
                        printf("Game Over!\n");
                        printf("Pressione alguma tecla para fechar o jogo!\n");
                        getch();
                        exit(0);
                    }
                    if(inimigos[i].y == 24){
                        inimigos[i].x--;
                        inimigos[i].cont = 24;
                    } 
                    if(inimigos[i].y == 0) {
                        inimigos[i].x--;
                        inimigos[i].cont = 0;
                    }
                    if(inimigos[i].cont == 48){
                        inimigos[i].cont = 0;
                    }
                    if(inimigos[i].cont < 24){
                        inimigos[i].y++;
                    }
                    if(inimigos[i].cont >= 24 && inimigos[i].cont < 48){
                        inimigos[i].y--;
                    }
                    inimigos[i].cont++;
                    // inimigos[i].x--;
                    // inimigos[i].y = sin(inimigos[i].x);
                    gotoxy(inimigos[i].x, inimigos[i].y);
                    printf("%c", inimigos[i].img);
                }
            }
            
                if (bala[i].ativo)
                {
                    gotoxy(bala[i].x, bala[i].y);
                    printf(" ");

                    if (bala[i].x > LIMITE - 2)
                    {
                        bala[i].ativo = false;
                    }

                    //    gotoxy(0, 20);
                    // printf("%f %f %f", bala[i].a, bala[i].b, bala[i].c);

                    bala[i].x++;
                    bala[i].y = (int)solve2(bala[i].a, bala[i].b, bala[i].c, bala[i].x);

                    gotoxy(bala[i].x, bala[i].y);
                    printf("o");
                }

        Sleep(30);
    }
    label:
    gotoxy(0, LIMITE_VERT-28);
    printf("------------------------------------------------------------------------------------------------------------------------");
    gotoxy(50, 10);
    printf("Voce ganhou o jogo, %s!!!\n", nomeJogador);
    gotoxy(50,12);
    printf("Total de pontos: %d\n", pontos);
    gotoxy(50,14);
    printf("Tempo total: %d\n", (clock()- inicio)/1000);
    gotoxy(50, 16);
    printf("Congrats!!!\n");
    gotoxy(0, LIMITE_VERT - 2);
    printf("------------------------------------------------------------------------------------------------------------------------");
    gotoxy(0, LIMITE_VERT - 1);
    system("pause");
    printf("                                                           ");
    printf("Pressione qualquer tecla para voltar para o menu!!!");
}