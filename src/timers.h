#ifndef _TIMERS_H
#define _TIMERS_H

#include <stdint.h>
#include "common.h"

//-----------------------------------------------------------------------------
// types
//-----------------------------------------------------------------------------

typedef uint16_t paramSize_t;
typedef uint8_t paramItem_t;

typedef void (*callback_t)(paramItem_t*);

typedef struct baseParam_
{
	paramSize_t length;
	union
	{
		struct
		{
			uint8_t bIsLoop : 1;	// need loop task execution
			uint8_t nPrio : 3;		// scheduler catch task with high priority
			uint8_t reserved : 4;
		}
#if defined(__GNUC__)
		__attribute__((packed)) bits;
#else
		bits;
#endif
		uint8_t value; 
	} flags;
}
#if defined(__GNUC__)
	__attribute__((packed)) baseParam_t;
#else
	baseParam_t;
#endif

extern err_t Schedule(callback_t fn, baseParam_t *pBP, uint16_t timeToExec);
extern inline void Scheduler(void);
extern err_t SchedulerInit(void);

#endif // _TIMERS_H
