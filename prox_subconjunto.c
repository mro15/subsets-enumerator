#include <stdio.h>
#include <stdlib.h>

int enumerate(int *set,  int n, int k, int offset, int *subsets){
    puts("oi");
    return 0;

}

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Uso: <subconjuntos> <k> <n>\n");
        return 0;
    }
    int *set, *subsets, n, k, i;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    //printf("n: %d, k: %d\n", n, k);
    set = malloc(n*sizeof(int));
    /*Create set [1...n]*/
    for(i = 0; i<n; ++i){
        set[i] = i+1;
    }
    /*Print set
    for(i = 0; i<n; ++i){
        printf("%d ", set[i]);
    }*/
    /*Array of subsets has size k*/
    subsets = malloc(k*sizeof(int));
    enumerate(set,  n, k, 0, subsets);
    printf("\n");
    return 0;
}
