#include <stdio.h>
#include <stdlib.h>

long countSteps(int remSteps);

int main(int argc, char* argv[]){

	int n = 1;
	long res;
 
	if ( argc > 1 )
		n = atol(argv[1]);

	res = countSteps(n);
	printf("For n=%d, there are %ld ways.\n", n, res);

	return 0;
}

long countSteps(int steps){

	if (steps < 0) return 0;
	if (steps == 0) return 1;

	return countSteps(steps-1) + countSteps(steps-2) + countSteps(steps-3);
}
