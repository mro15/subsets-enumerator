#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <list>
#include <bitset>

int main(int argc, char *argv[]){
    if(argc<4){
        printf("Uso: <subconjuntos> <k> <n> <subconjunto>\n");
        return 0;
    }
    int *set, n, k, i, *bit_set, carry=0, found=0;
    std::list<int> subsets;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    set = new int[n];
	bit_set = new int[n];
    for(i = 3; i<argc; ++i){
		subsets.push_back(atoi(argv[i]));
	}	
    /*Create set [1...n]*/
    for(i = 0; i<n; ++i){
        set[i] = i+1;
		bit_set[i] = 0;
    }
    /*Print set*/
    for(i = 0; i<n; ++i){
        printf("%d ", set[i]);
    }
	printf("\n");
	/*Print subset*/
    for(std::list<int>::iterator it=subsets.begin(); it!=subsets.end() ; ++it){
    	std::cout << *it << " ";
		bit_set[*it-1] = 1;
	}
	printf("\n");
	for(i = 0; i<n; ++i){
		printf("%d ", bit_set[i]);
	}	
	printf("\n");
	int bit_count = 0;
	while(found == 0){
		if(bit_set[0]+1==1){
			carry=0;
			bit_set[0]=1;
			bit_count++;
		}else{
			carry=1;
			bit_set[0]=0;
		}
    	for(i = 1; i<n; ++i){
			if((bit_set[i] + carry)==0){
				bit_set[i] = 0;
				carry=0;
			}else if((bit_set[i] + carry)==1){
				bit_set[i] = 1;
				carry=0;
				bit_count++;
			}else{
				bit_set[i] = 0;
				carry=1;
			}
		}
		/*for(i = 0; i<n; ++i){
			printf("%d ", bit_set[i]);
		}*/
		if(bit_count==k){
			found=1;
		}else{
			bit_count=0;
		}
	}
	for(i = 0; i<n; ++i){
		printf("%d ", bit_set[i]);
	}
    printf("\n");
    return 0;
}
