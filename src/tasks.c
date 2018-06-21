/*
 * tasks.c
 *
 *  Created on: 21 июн. 2018 г.
 *      Author: moskvin
 */

#include "tasks.h"

//-----------------------------------------------------------------------------
// functions
//-----------------------------------------------------------------------------
/**
 * does nothing, for example only
 * @param p dummy param
 */
void dummyTask(paramItem_t* p)
{
	// every task must do cast pointer to it self pointer type
	dummyParams_t *pDummyParam = (dummyParams_t*)p;
	// do something, use params as you wish
#if defined(__DBG_MSG__)
	TRACE("Hello! It's dummy task, P1=%d, P2=%d", pDummyParam->p1, pDummyParam->p2);
#endif
	// ...
	// set task options here, for example change priority

	if (pDummyParam->p1 == 3 &&  pDummyParam->p2 == 4)
	{
		// schedule delay task from here
		dummyParams_t params = { {sizeof params } };
		params.p1 = 7;
		params.p2 = 8;
		params.base.flags.bits.bIsLoop = 0;
		Schedule(dummyTask, (baseParam_t*)&params, 1000);
	}
}



