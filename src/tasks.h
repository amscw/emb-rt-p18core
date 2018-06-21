/*
 * tasks.h
 *
 *  Created on: 21 июн. 2018 г.
 *      Author: moskvin
 */

#ifndef TASKS_H_
#define TASKS_H_

#include "timers.h"


/**
 * WARNING! every parameters struct must have field baseParam_t at first
 * WARNING! every task function must have signature according to callback_t:
 * typedef void (*callback_t)(paramItem_t*);
 */

//-----------------------------------------------------------------------------
// types
//-----------------------------------------------------------------------------
typedef struct
{
	baseParam_t base;
	uint8_t p1;
	uint8_t p2;
}
#if defined(__GNUC__)
	__attribute__((packed)) dummyParams_t;
#else
	dummyParams_t;
#endif

extern void dummyTask(paramItem_t* p);

#endif /* TASKS_H_ */
