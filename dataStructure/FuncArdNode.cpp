#pragma once

class FuncArdNode: public ArdNode {
public:
	void (*__function)(void);
	long __delayWRTRoot;
	
	FuncArdNode(long delayWRTRoot, void (*function)(void)): ArdNode(NULL) {
		__delayWRTRoot = delayWRTRoot;
		__function = function;
	}	
};
