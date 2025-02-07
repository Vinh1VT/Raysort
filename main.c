#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "tri.h"

#define LONGUEUR 500


int main(){
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Raysort");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    int *tab = malloc(LONGUEUR*sizeof(int));
    initTab(tab, LONGUEUR);
    SetTargetFPS(60);

    TriIns(tab, LONGUEUR);

    if(!WindowShouldClose()){
        WaitTime(10);
        CloseWindow();
    }
    free(tab);
    return EXIT_SUCCESS;
}
