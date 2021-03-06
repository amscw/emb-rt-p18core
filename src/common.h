/*
 * common.h
 *
 *  Created on: 21 июн. 2018 г.
 *      Author: moskvin
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#if defined(__MINGW32__)
	#include "windows.h"
#endif

//-----------------------------------------------------------------------------
// types
//-----------------------------------------------------------------------------
typedef enum err_ {
    ERR_OK,
    ERR_TRUE,
    ERR_NULLPTR,
	ERR_CONFIGURE,
    ERR_SWI2C_READ,
    ERR_SWI2C_WRITE,
    ERR_SWI2C_NOACK,
	ERR_CORE_NO_FREE_TIMERS,
	ERR_CORE_NO_MEM,
} err_t;

//-----------------------------------------------------------------------------
// macro
//-----------------------------------------------------------------------------
#define __DBG_MSG__
#if defined(__MINGW32__)
	#define TRACE(fmt,args...) {\
		printf("%s(%s)-"fmt"\n", __FILE__, __FUNCTION__, ##args);\
		fflush(stdout);\
	}
#else
	#define TRACE(fmt,args...) printf("%s(%s)-"fmt"\n", __FILE__, __FUNCTION__, ##args)
#endif

#endif /* COMMON_H_ */
