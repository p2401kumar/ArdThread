#include "ArdObject.cpp"
#include "util/Utils.h"
#pragma once

class ArdLooper {
	ArdList* ardList = new ArdList();
	long __nextSmallest = -1;
	long __counter = 0;
public:	
	void createThread(void (*func)(ArdObject*)) {
		ArdObject *x = new ArdObject();
		func(x);
		ardList->insertNode(x);
	}
	
	void startThreads() {
		while(true) {
			__counter++;
			systemDelay(1);	
			systemTingle(__counter);				
		}	
	}
	
	void testWithoutDelay() {
		ArdList::Iterator *it = ardList->iterator();
			while(it->hasNext()) {
				ArdObject* x = (ArdObject*)(it->next());
				x->testWithoutDelay();			
			}
			delete it;
	}
	
	void systemTingle(long counter) {
		if (__nextSmallest == -1) {
			ArdList::Iterator *it = ardList->iterator();
			while(it->hasNext()) {
				ArdObject* x = (ArdObject*)(it->next());
				long t = x->__funcMetaArdNode->__t1 + x->__POINTER__->__delayWRTRoot;
				if (__nextSmallest == -1) {
					__nextSmallest = t;	
				}
				else if (__nextSmallest > t) {					 
					__nextSmallest = t;
				}				
			}
			delete it;
		} 
		if (counter == __nextSmallest) {
			ArdList::Iterator *it = ardList->iterator();
			while(it->hasNext()) {
				ArdObject* x = (ArdObject*)(it->next());
				if (x->__funcMetaArdNode->__t1 + x->__POINTER__->__delayWRTRoot == __nextSmallest) {
					x->__POINTER__->__function();
					x->movePointerAhead(counter);
				}
			}
			delete it;
			__nextSmallest = -1;
		}
	}
};
