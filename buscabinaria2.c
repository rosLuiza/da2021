#include <stdio.h>

const char* buscaBin(int *v, int esq, int dir, int x){

    int meio;
    int f = 0;

    if(esq<=dir){

        meio = (esq+dir)/2;
        if(v[meio] == x){
            return "ACHEI";
        }
        else if(v[meio] > x){
            //impressão
            for(f=meio; f<=dir; f++){
                if(f == dir){
                    printf("%d\n", v[f]);
                }
                else{
                    printf("%d ", v[f]);
                }
            }

            return buscaBin(v, esq, meio-1, x);
        }
        else {
            //impressão
            for(f=esq; f<=meio; f++){
                if(f == meio){
                    printf("%d\n", v[f]);
                }
                else{
                    printf("%d ", v[f]);
                }
            }

            return buscaBin(v, meio+1, dir, x);
        }
    }

    return "NAO ACHEI";
}

int main() {
    int LENGHT;
    int SEARCH_VALUE;
    int NUMBER_OF_SEARCHES;
    int i = 0;
    int t;
    const char* ANSWER;


    scanf("%d", &LENGHT);

    int ARRAY1[LENGHT];

    for (i=0; i<LENGHT; i++){
            scanf("%d", &ARRAY1[i]);
        }

    while(scanf("%d", &t) != EOF){

        scanf("%d", &SEARCH_VALUE);

        ANSWER = buscaBin(ARRAY1, 0, LENGHT-1, SEARCH_VALUE);

        if(ANSWER == "ACHEI"){
            printf("VALOR %d LOCALIZADO NA COLECAO\n", SEARCH_VALUE);
        }
        else{
            printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", SEARCH_VALUE);
        }

    }

    return 0;
}