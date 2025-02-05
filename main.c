#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define LONGUEUR 600

void echangerCase(int tab[],int i,int j){
    int temp = tab[j];
    tab[j] = tab[i];
    tab[i] = temp;
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
        float block = ((float)tab[i]/LONGUEUR)*(float)height;
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
                    DrawTab(tab, LONGUEUR);
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



int main(){
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Raysort");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    int *tab = malloc(LONGUEUR*sizeof(int));
    initTab(tab, LONGUEUR);
    SetTargetFPS(60);

    TriIns(tab, LONGUEUR);
    if(!WindowShouldClose()) CloseWindow();
    free(tab);
    return EXIT_SUCCESS;
}
