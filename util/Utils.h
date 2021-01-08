#pragma once
#define NULL 0

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include<windows.h>
#include<stdio.h>
#endif

inline void systemDelay(unsigned long millis) {
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		Sleep(millis*1);
		//printf("stopped\n");
	#else
		delay(millis);
	#endif
}
