#include <iostream>
#include <omp.h>
//Shell sorting

int SIZE = 50;

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
	
	for (k = SIZE / 2; k > 0; k /= 2) {
#pragma omp parallel for shared(a) schedule(static) firstprivate(i, j, t) num_threads(4)
		for (i = k; i < SIZE; i++)
		{
			t = a[i];
			for (j = i; j >= k; j -= k)
			{
				if (t < a[j - k])
					a[j] = a[j - k];
				else
					break;
			}
			a[j] = t;
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
