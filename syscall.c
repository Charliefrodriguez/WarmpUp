/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1.
 *   2.
 *
 * ILab Machine Tested on:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>                                                                                
#include <sys/syscall.h>

double avg_time = 0;

int main(int argc, char *argv[]) {

	/* Implement Code Here */
	clock_t start, end;
	pid_t pid;
	int i = 0;
	for(i; i < 3000; ++i) {
		start = clock();
		pid = syscall(SYS_getpid);	
		end = clock();
		avg_time += (end - start);
	}
	// Remember to place your final calculated average time
	// per system call into the avg_time variable

	printf("Average time per system call is %f microseconds\n", avg_time);

	return 0;
}
