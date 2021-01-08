#include "dataStructure/ArdList.cpp"
#include "dataStructure/FuncArdNode.cpp"
#include "dataStructure/FuncMetaArdNode.cpp"
#pragma once

class ArdObject: public ArdNode {
public:
	FuncMetaArdNode *__funcMetaArdNode = new FuncMetaArdNode();
private:
	ArdList *__ardList = new ArdList(__funcMetaArdNode);	
public:	
	FuncArdNode *__POINTER__ = NULL;
	ArdObject(): ArdNode(NULL) {
		
	}
	
	void run(void (*func)(void)) {
		__funcMetaArdNode->__t0 += 1;
		__ardList->insertNode(new FuncArdNode(__funcMetaArdNode->__t0, func));
		__POINTER__ = (FuncArdNode*) (__ardList->__head);
	}	
	
	void runAfterDelayMillis(int millis, void (*func)(void)) {
		__funcMetaArdNode->__t0 += millis;
		__ardList->insertNode(new FuncArdNode(__funcMetaArdNode->__t0, func));
		__POINTER__ = (FuncArdNode*) (__ardList->__head);
	}
	
	void testWithoutDelay() {
		ArdList::Iterator *it = __ardList->iterator();
		while(it->hasNext()) {
			FuncArdNode *pk = (FuncArdNode*)it->next();
			pk->__function();
		}
		delete it;
	}
	
	void movePointerAhead(long counter) {
		if(__POINTER__->__isLast) {
			__funcMetaArdNode->__t1 = counter;
			__POINTER__ = (FuncArdNode*)__ardList->__head;
		} else {
			__POINTER__ = (FuncArdNode*)__POINTER__->__nxtNode;
		}
	}
};
