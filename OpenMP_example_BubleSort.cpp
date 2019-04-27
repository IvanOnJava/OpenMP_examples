#include <iostream>
#include <omp.h>

int SIZE = 80;

int main() {
	int *a = new int[SIZE]; 
	printf("\n Matrix: \n");            
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % 10;
		printf("%d ", a[i]);

	}
	printf("\n");

	int i, j, k, t; 
	double time = omp_get_wtime(); 

#pragma omp parallel for shared(a) schedule(static) firstprivate(i, j)  num_threads(4)
	for (int i = SIZE; i > 0; i--) {
		for (int j = 1; j <= i; j++)
		{
			if (a[j] > a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}

		time = omp_get_wtime() - time;

		printf("\n Matrix: \n"); 
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", a[i]);

		}
		printf("\n");
		printf("Time: %f", time); 
		system("pause");
}

