#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <list>

/*int enumerate(int *set,  int n, int k, int offset, int *subsets){
    puts("oi");
    return 0;

}*/

int main(int argc, char *argv[]){
    if(argc<4){
        printf("Uso: <subconjuntos> <k> <n> <subconjunto>\n");
        return 0;
    }
    int *set, n, k, i;
    std::list<int> subsets;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    set = new int[n];
    for(i = 3; i<argc; ++i){
		subsets.push_back(atoi(argv[i]));
	}	
    /*Create set [1...n]*/
    for(i = 0; i<n; ++i){
        set[i] = i+1;
    }
    /*Print set*/
    for(i = 0; i<n; ++i){
        printf("%d ", set[i]);
    }
	/*Print subset*/
    for(std::list<int>::iterator it=subsets.begin(); it!=subsets.end() ; ++it)
    	std::cout << *it << " ";
    //enumerate(set,  n, k, 0, subsets);
    printf("\n");
    return 0;
}
