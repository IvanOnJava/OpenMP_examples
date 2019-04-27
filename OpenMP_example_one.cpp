#include <iostream>
#include <omp.h> 
#define N 7 
int main() {
	int *a = new int[N]; 
	int *b = new int[N]; 
	int *c = new int[N]; 
	for (int i = 0; i < N; i++) { 
		a[i] = rand() % 10;
		b[i] = rand() % 10;
		if (N < 20) { 
			printf("A: %d\t B:%d\n", a[i], b[i]); 
		}
	}
	
	double time = omp_get_wtime(); 
#pragma omp parallel for shared(a, b, c) schedule(static) num_threads(4) 
	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[i];  
	}


	time = omp_get_wtime() - time; 
	printf("Time: %f\n", time); 
	if (N < 20) { 
		printf("C: ");
		for (int i = 0; i < N; i++) { 
			printf("%d ", c[i]);
		}
	}
	getchar();
}
