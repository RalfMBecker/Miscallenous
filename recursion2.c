#include <stdio.h>
#include <stdlib.h>

const int q = 25;
const int d = 10;
const int n = 5;
const int p = 1;

long change(long amount, int last);

int main(int argc, char* argv[]){

	long res, amount = 10;
 
	if ( argc > 1 )
		amount = atol(argv[1]);
	if (amount == 0){ 
		printf("%s\n", "m = 0 is an illegal amount");
		exit(1);
	}

	res = change(amount, q);
	printf("For m=%ld, there are %ld ways.\n", amount, res);

	return 0;
}

long change(long amount, int last){

	long subT = 0;

	if ( (amount < 0) )
    return 0;

	if ( (amount == 0) )		
		return 1;

	if ( (amount >= q) && (q <= last) )
    subT += change(amount - q, q);
	if ( (amount >= d) && (d <= last) )
    subT += change(amount - d, d);
	if ( (amount >= n) && (n <= last) )
    subT += change(amount - n, n);
	if ( (amount >= p) )
		subT+= change(amount - p, p);

	return subT;
}
