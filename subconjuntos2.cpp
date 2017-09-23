#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <list>

int cont = 0;

int enumerate(int *set, int n,  int k, int offset, std::list<int> &subsets){
    if(k==subsets.size()){
        for(std::list<int>::iterator it=subsets.begin(); it!=subsets.end() ; ++it){
            std::cout << *it << " ";
			cont++;
        }
        std::cout << std::endl;
        return 0;
    }
	//puts("AAAA");
	if(offset==n)
		return 0;
    subsets.push_back(set[offset]);
    enumerate(set,n, k, offset+1, subsets);
    subsets.remove(set[offset]);
    enumerate(set, n, k, offset+1, subsets); 
    return 0;
}

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Uso: <subconjuntos> <k> <n>\n");
        return 0;
    }
    int *set, n, k, i;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    //printf("n: %d, k: %d\n", n, k);
    set = new int[n];
    /*Create set [1...n]*/
    for(i = 0; i<n; ++i){
        set[i] = i+1;
    }
    /*Print set
    for(i = 0; i<n; ++i){
        printf("%d ", set[i]);
    }*/
    std::list<int> subsets;
    enumerate(set, n, k, 0, subsets);
	printf("%d\n", cont);
    return 0;
}
