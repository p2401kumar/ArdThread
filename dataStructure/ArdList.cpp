#include "ArdNode.cpp"
#include "../util/Utils.h"
#pragma once

class ArdList {
public:
	ArdNode* __metaData = NULL;
	ArdNode* __head = NULL;
	ArdNode* __tail = NULL;
	ArdList() {
		
	}
	ArdList(ArdNode* metaData) {
		__metaData = metaData;
	}
	
	void insertNode(ArdNode* node) {
		if (__head == NULL) {
			__head = node;
			__tail = node;			
		} else {
			__tail->__nxtNode = node;
			__tail->__isLast = false;
			__tail = node;
		}
		__tail->__isLast = true;
	}
public:
	class Iterator {
	public:
		ArdNode* ardNode = NULL;
		Iterator(ArdNode* aNode) {
			ardNode = aNode;			
		}
		
		bool hasNext() {
			return !(ardNode == NULL);
		}
		
		ArdNode* next() {
			if (ardNode == NULL)return NULL;
			ArdNode* ptr = ardNode;
			ardNode = ardNode->__nxtNode;
			return ptr;
		}
	};
public:
	Iterator* iterator() {
		return new Iterator(__head);
	}
};
