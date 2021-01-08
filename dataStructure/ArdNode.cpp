#pragma once

class ArdNode {
public:
	ArdNode *__nxtNode;
	bool __isLast;
	ArdNode(ArdNode *nxtNode): __nxtNode(nxtNode), __isLast(false) {}
};
