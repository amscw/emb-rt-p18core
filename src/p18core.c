/*
 ============================================================================
 Name        : p18core.c
 Author      : moskvin
 Version     :
 Copyright   : ELINS
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

int main(void) {
	SchedulerInit();

	// create parameters
	dummyParams_t dummyParams = { {sizeof dummyParams} };
	dummyParams.base.flags.bits.bIsLoop = 1;


	// schedule task 1
	dummyParams.p1 = 5;
	dummyParams.p2 = 7;
	Schedule(dummyTask, (baseParam_t*)&dummyParams, 1000);

	// schedule task 2
	dummyParams.p1 = 8;
	dummyParams.p2 = 9;
	Schedule(dummyTask, (baseParam_t*)&dummyParams, 200);

	while(1)
	{
		Scheduler();
	}

	return EXIT_SUCCESS;
}
