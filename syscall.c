/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1. Gianluca Delbarba, NetId: gfd15
 *   2. Charles Rodriguez, NetId: cfr47
 *
 * ILab Machine Tested on:
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>                                                                                
#include <sys/syscall.h>

double avg_time = 0;

int main(int argc, char *argv[]) {

	/* Implement Code Here */
	//clock_t start, end;
	//time_t start, end;
	
	
	
	
	pid_t pid;
	int i = 0; 
	struct timeval value, interval , value_old, interval_old; 
	
	value.tv_sec = 60; 
	value.tv_usec = 0;  

	value_old.tv_sec = 0; 
	value_old.tv_usec = 0; 
	
	interval.tv_sec = 0;
	interval.tv_usec = 0;

	interval_old.tv_sec = 0; 
	interval_old.tv_usec = 0;

	struct itimerval new,old; 

	new.it_value = value; 
	new.it_interval = interval; 

	old.it_value = value_old; 
	old.it_interval = interval_old; 

 setitimer (ITIMER_REAL, &new, &old);

	for(i; i < 3000; ++i) {
		pid = syscall(SYS_getpid);	
	} 
	
	getitimer (ITIMER_REAL , &old); 

//	avg_time  = (end-start)/2;
	// Remember to place your final calculated average time
	// per system call into the avg_time variable

//	printf("Average time per system call is %ld seconds and %ld \n",60- old.it_value.tv_sec,1000000- old.it_value.tv_usec );
	
		printf("Average time per system call is %lf \n", (60- old.it_value.tv_sec + 0.10 * (1000000- old.it_value.tv_usec))/3000 );


	return 0;
}
