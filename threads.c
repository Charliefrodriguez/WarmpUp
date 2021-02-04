/* threads.c
 *
 * Group Members Names and NetIDs:
 *   1. gfd15
 *   2.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t t1, t2;
pthread_mutex_t mutex;
int x = 0;
int loop = 10;

/* Counter Incrementer function:
 * This is the function that each thread will run which
 * increments the shared counter x by LOOP times.
 *
 * Your job is to implement the incrementing of x
 * such that is sychronized among threads
 *
 */
void *inc_shared_counter(void *arg) {

	int i;

	pthread_mutex_lock(&mutex);

	printf("Thread Running\n");

	for(i = 0; i < loop; i++){

		/* Part 2: Modify the code within this for loop to
		   allow for synchonized incrementing of x
		   between the two threads */
		x = x + 1;
		printf("x is incremented to %d\n", x);

	}

	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);

	return NULL;
}


/* Main function:
 * This is the main function that will run.
 *
 * Your job is two create two threads and have them
 * run the inc_shared_counter function().
 */
int main(int argc, char *argv[]) {

	if(argc != 2){
		printf("Bad Usage: Must pass in a integer\n");
		exit(1);
	}

	loop = atoi(argv[1]) / 2;

//	printf("Going to run two threads to increment x up to %d\n", loop);


	// Part 1: create two threads and have them
	// run the inc_shared_counter function()
	/* Implement Code Here */
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, &attr, inc_shared_counter, NULL);	
	pthread_create(&t2, &attr, inc_shared_counter, NULL);
	pthread_attr_destroy(&attr);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);

	printf("The final value of x is %d\n", x);

	return 0;
}