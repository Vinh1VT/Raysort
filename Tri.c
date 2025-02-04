#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* randomTab(int N){
    int* tab = malloc(sizeof(int)*N);
    for(int i = 0; i<N;i++){
        tab[i] = rand() % 1000; //limite arbitraire, en soi on pourrait mettre plus/moins
    }
    return tab;
}

void printTab(int* tab, int N){
    for(int l=0;l<N;l++){
        printf("%d ",tab[l]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool sorted(int *tab,int  N){
    for(int i = 1; i<N;i++){
        if(tab[i] < tab[i-1]){
            return false;
        }
    }
    return true;
}

int* TriBulles(int* tab, int N){
    for(int i = N-1; i > 0; i--){
        for(int j = 0; j<i; j++){
            if(tab[j] > tab[j+1]){
                swap(tab +j , tab+j+1);
            }
        }
    }

    return tab;
}

int* TriSel(int* tab, int N){
    for(int i=0; i<N-1;i++){
        int indmin = i;
        for(int j=i;j<N;j++){
            if(tab[j] < tab[indmin]){
                indmin = j;
            }
        }
        if(indmin != i){
            swap(tab+i, tab+indmin);
        }
    }
    return tab;
}

int* BogoSort(int* tab, int N){
    while (!sorted(tab,N)){
        for(int i = 0; i<N;i++){
            int random = rand()%N;
            swap(tab+i,tab+random);
        }
    }
    return tab;
}

int* TriIns(int* tab,int N){
    for(int i=0;i<N;i++){
        int x = tab[i];
        int j = i;
        while(j>0 && tab[j-1]>x){
            tab[j] = tab[j-1];
            j -= 1;
        }
        tab[j] = x;
    }
    return tab;
}

//programme de test, avec temps de tri
/*int main(int argc, char** argv){
    if(argc <= 2){
        fprintf(stderr, "pas assez d'arguments\n");
        return EXIT_FAILURE;
    }
    int elem = atoi(argv[1]);
    int essai = atoi(argv[2]);
    int* tab;
    //printTab(tab,k);
    clock_t start,end;
    clock_t somme = 0;
    for(int i = 0; i<essai;i++){
        tab = randomTab(elem);
        start = clock();
        TriSel(tab, elem);
        end = clock();
        if(!sorted(tab,elem)){
            fprintf(stderr,"erreur, tableau final non trié\n");
            return EXIT_FAILURE;
        }
        somme += end-start;
    }

    printf("%f secondes pour un tableau de %d elements, en moyenne sur %d essai\n", (double)((float)somme/essai)/CLOCKS_PER_SEC,elem, essai);
    return EXIT_SUCCESS;
}*/
