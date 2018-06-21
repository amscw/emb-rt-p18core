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



	// one-shot task
	dummyParams.p1 = 1;
	dummyParams.p2 = 2;
	dummyParams.base.flags.bits.bIsLoop = 0;
	Schedule(dummyTask, (baseParam_t*)&dummyParams, 0);

	// delay task
	dummyParams.p1 = 3;
	dummyParams.p2 = 4;
	dummyParams.base.flags.bits.bIsLoop = 0;
	Schedule(dummyTask, (baseParam_t*)&dummyParams, 1000);

	// repeat task
	dummyParams.p1 = 5;
	dummyParams.p2 = 6;
	dummyParams.base.flags.bits.bIsLoop = 1;
	Schedule(dummyTask, (baseParam_t*)&dummyParams, 2000);


	while(1)
	{
		Scheduler();
	}

	return EXIT_SUCCESS;
}
