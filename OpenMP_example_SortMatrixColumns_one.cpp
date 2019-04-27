#include <iostream>
#include <omp.h>
int n = 60; 
int m = 20; 

int main() {

	int **a = new int *[n]; 
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}

	printf("\n Matrix: \n");            
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 10;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int i, j, o; 
	double time = omp_get_wtime(); 
#pragma omp parallel for shared(a) schedule(static) firstprivate(i,j,o) num_threads(1) 
	for (i = 0; i < m; i++)  
	{
		for (j = 0; j < n; j++)
		{
			for (o = 0; o < n - 1; o++)
			{

				if (a[i][o] > a[i][o + 1])
				{
					int tmp = a[i][o];
					a[i][o] = a[i][o + 1];
					a[i][o + 1] = tmp;
				}

			}
		}
	}
	time = omp_get_wtime() - time;

	printf("\n Matrix: \n"); 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("Time: %f", time); 
	system("pause");
}
