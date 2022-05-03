#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTY_THREADS 3

int array = 0;

void *average(int *num)
{
	int total = 0, final = 0;

	for (int index = 0; index < array; index++)
		total += num[index];

	final = total/array;
	printf("The average value is %d\n", final);
	
}

void *maxNum(int *num)
{
	int maxi = 0;

	for (int index = 0; index < array; index++) {
		if (num[index] > maxi)
			maxi = num[index];
	}

	printf("The maximum value is %d\n", maxi);
}

void *miniNum(int *num)
{
	int mini = 0;

	for (int index = 0; index < array; index++) {
		if (index == 0 || num[index] < mini)
			mini = num[index];
	}

	printf("The minimum value is %d\n", mini);
}

int main(void)
{

	scanf("%d", &array);

	int arrayNum[array];
	for (int i = 0; i < array; i++)
		scanf("%d", &arrayNum[i]);
	

	pthread_t thread1, thread2, thread3;
	pthread_create(&thread1, NULL, (void *)average, (int *)arrayNum);
	pthread_create(&thread2, NULL, (void *)miniNum, (int *)arrayNum);
	pthread_create(&thread3, NULL, (void *)maxNum, (int *)arrayNum);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

    return 0;
}
