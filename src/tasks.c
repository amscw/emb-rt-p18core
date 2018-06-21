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
	// check if need loop
	pDummyParam->base.flags.bits.bIsLoop = 0;
	// set other options here, for example change priority
}



