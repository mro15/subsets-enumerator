#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <list>

int enumerate(int *set, int n,  int k, int offset, std::list<int> &subsets){
    /*	Found a subset of size k,
		then print it and return*/
	if(k==subsets.size()){
        for(std::list<int>::iterator it=subsets.begin(); it!=subsets.end() ; ++it){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        return 0;
    }
	/*If offset equals to n just return*/
	if(offset==n)
		return 0;
	/*Insert an element in subset and calls enumerate() with it*/
    subsets.push_back(set[offset]);
    enumerate(set,n, k, offset+1, subsets);
	/*Removes an element from subset and calls enumerate() without it*/
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
    set = new int[n];
    /*Create set [1...n]*/
    for(i = 0; i<n; ++i){
        set[i] = i+1;
    }
	/*subsets starts empty*/
    std::list<int> subsets;
    enumerate(set, n, k, 0, subsets);
    return 0;
}
