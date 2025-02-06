#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define LONGUEUR 50

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
        DrawRectangle(i*(width/nbElem+1),height-block ,width/nbElem, ((float)tab[i]/LONGUEUR)*(float)height, BLUE);
    }
}


int main(){
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Raysort");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    int *tab = malloc(LONGUEUR*sizeof(int));
    initTab(tab, LONGUEUR);
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawTab(tab, LONGUEUR);
        EndDrawing();
    }
    CloseWindow();
    free(tab);
    return EXIT_SUCCESS;
}
