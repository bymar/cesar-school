#include <stdio.h>
#include <pthread.h>

// mutex == quando 2 threads querem executar o mesmo local, assim serve para fazer a sincronização entre elas

#define QTD_THREADS 10

void *increment(void *arg);
int count = 0; //vai precisar de uma variavel global, para contar as threads

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void)
{	
	pthread_t threads[QTD_THREADS]; //criando um array de threads, com 10 threads
	for (int i = 0; i < QTD_THREADS; i++) { //criando e verifica se a thread foi realmente criada
		if (pthread_create(&(threads[i]), NULL, increment, NULL)) { 
			printf("Thread %d not created", i);
		}

	}

	for (int i = 0; i < QTD_THREADS; i++) {
		pthread_join(threads[i], NULL); // quando a thread terminar, coleta todos os valores dela
	}

	printf("Final Counter = %d\n", count); // precisa ser igual a 10, dizendo que todas as threads passaram e foram criadas

}

void *increment(void *arg)
{	
	pthread_mutex_lock(&mutex); // como o count é sempre chamado para o mesmo local de memoria, é preciso realocar o espeço para que o retorno final seja 10
	count += 1;
	printf("Counter = %d\n", count);
	pthread_mutex_unlock(&mutex);
	return arg;

}

void *sumLine(void *arrayElem)
{	

	int *arr = (int *)arrayElem; 
	int size = sizeof(*arr);
	int totalLine = 0;

	for (int line = 0; line < size; line++)
		totalLine += arr[line];

	pthread_mutex_lock(&mutex);
	count += 1;
	finalSum += totalLine;
	printf("%d Line sum: %d\n", count, totalLine);
	printf("Current final sum: %d\n", finalSum);
	pthread_mutex_unlock(&mutex);
}