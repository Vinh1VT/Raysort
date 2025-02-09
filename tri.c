#include "tri.h"
#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void printTab(int* tab, int nbElem){
    for(int l=0;l<nbElem;l++){
        printf("%d ",tab[l]);
    }
    printf("\n");
}


void echangerCase(int tab[],int i,int j){
    int temp = tab[j];
    tab[j] = tab[i];
    tab[i] = temp;
}

bool sorted(int tab[], unsigned int nbElem){
    int precedent = tab[0];
    for(unsigned int i = 1; i<nbElem;i++){
        if(precedent>tab[i]){
            return false;
        }
        precedent = tab[i];
    }
    return true;
}

void initTab(int tab[],int nbElem){
    for(int i=0; i<nbElem;i++){
        tab[i] = i;
    }

    for(int i = 0; i<nbElem;i++){
        int random1 = GetRandomValue(0, nbElem-1);
        int random2 = GetRandomValue(0, nbElem-1);
        echangerCase(tab, random1, random2);
    }
}

void DrawTab(int tab[],int nbElem){
    int height = GetScreenHeight();
    int width = GetScreenWidth();
    for(int i = 0; i<nbElem;i++){
        float block = ((float)tab[i]/nbElem)*(float)height;
        DrawRectangle(i*(width/nbElem),height-block,width/nbElem-1, block, BLUE);
    }
}

void TriBulles(int tab[],int nbElem){
        for(int i = nbElem-1; i>0 ;i--){

            for (int j = 0; j<i ;j++){
                if(WindowShouldClose()){
                    CloseWindow();
                    return;
                }
                if(tab[j]>tab[j+1]){
                    echangerCase(tab, j, j+1);
                    BeginDrawing();
                    ClearBackground(BLACK);
                    DrawTab(tab, nbElem);
                    EndDrawing();
                }
            }
        }
}

void TriIns(int tab[],int nbElem){
    for(int i=0;i<nbElem;i++){
        int x = tab[i];
        int j = i;
        while(j>0 && tab[j-1]>x){
            tab[j] = tab[j-1];
            j -= 1;
        }
        tab[j] = x;
        if(WindowShouldClose()){
            CloseWindow();
            return;
            }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTab(tab, nbElem);
        EndDrawing();
    }
}

void BogoSort(int* tab, int nbElem){
    while (!sorted(tab,nbElem)){
        if(WindowShouldClose()){
            CloseWindow();
            return;
            }

        for(int i = 0; i<nbElem;i++){
            int random = GetRandomValue(0, nbElem-1);
            echangerCase(tab,i,random);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTab(tab, nbElem);
        EndDrawing();
        WaitTime(0.1);
    }
}

int calculerPuissanceMax(int tab[], int nbElem){
    int exposant = 1;
    int puissance = 10;
    int max = 0;
    for(int i = 0; i<nbElem; i++){
        if(tab[i]>max){
            max = tab[i];
        }
    }
    while(puissance<=max){
        puissance *=10;
        exposant++;
    }
    return exposant-1;
}

void divideBase(int tab[],int nbElem, int exp, int* Base[]){
    for(int i = 0; i<10; i++){
        int compte = 0;
        int puissance = pow(10,exp);
        for(int parcours = 0; parcours < nbElem; parcours++){
            if(((int)(tab[parcours]/puissance)%10) == i){
                compte++;
            }
        }
        Base[i] = malloc((compte+1)*sizeof(int));
        compte = 0;
        for(int parcours = 0; parcours < nbElem; parcours++){
            if((int)(tab[parcours]/puissance)%10 == i){
                Base[i][compte] = tab[parcours];
                compte++;
            }
        }
        Base[i][compte] = -1;
    }
}

void fusionnerBase(int tab[],int* Base[]){
    int indice = 0;
    int j = 0;
    for(int i = 0; i<10;i++){
        while(Base[i][j] != -1){
            tab[indice] = Base[i][j];
            j++;
            indice++;
        }
        j = 0;
    }
}

void TriRadix(int tab[], int nbElem){
    int* Base[10];
    int max = calculerPuissanceMax(tab, nbElem);
    for(int i = 0; i<=max;i++){
        divideBase(tab, nbElem, i, Base);
        fusionnerBase(tab, Base);
        for(int j = 0; j<10;j++){
            free(Base[j]);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTab(tab, nbElem);
        EndDrawing();
        WaitTime(1);
    }
}
