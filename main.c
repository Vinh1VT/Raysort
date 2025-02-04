#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"



int main(){
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Raysort");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    while(!WindowShouldClose()){
        BeginDrawing();

        EndDrawing();
    }
    CloseWindow();
    return EXIT_SUCCESS;
}
