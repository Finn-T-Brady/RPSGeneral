//This program is just to test that library works, you can ignore this
#include <stdio.h>
#include <stdlib.h>

#define options 7

#include "RPS.h"

int main() {
	int n=options,m=options;
	while(n--){
		m=options;
		while(m--){
			printf("COMP(%i,%i): %i/%i\n",n,m,RPSComp(n, m),RPSCompV(n, m));
		}
		printf("\n");
	}
	
	int* Bal=biasCheck();
	int* BalV=biasCheckV();
	printf("\nBias:%i/%i",*Bal,*BalV);

	n = options-1;

	while(n--){
		Bal++;
		BalV++;
		printf(",%i/%i",*Bal,*BalV);
	}
	printf("\n");

	return 0;
}
