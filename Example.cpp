#include "ArdObject.cpp"
#include "ArdLooper.cpp"

void Al1(ArdObject* ardObject) {
	ardObject->run([&](){
		printf("A1\n");
	});
	ardObject->runAfterDelayMillis(20, [](){
		printf("A2\n");
	});
	ardObject->run([&](){
		printf("A3\n");
	});
	ardObject->runAfterDelayMillis(300, [](){
		printf("A4\n");
	});
	ardObject->runAfterDelayMillis(500, [](){
		printf("A5\n");
	});
}
void Bl1(ArdObject* ardObject) {
	ardObject->runAfterDelayMillis(50, [](){
		printf("B1\n");
	});
	ardObject->run([&](){
		printf("B2\n");
	});
	ardObject->runAfterDelayMillis(100, [](){
		printf("B3\n");
	});
	ardObject->runAfterDelayMillis(500, [](){
		printf("B4\n");
	});
	ardObject->run([&](){
		printf("B5\n");
	});
}

int main() {
//	ArdObject* x = new ArdObject();
//	l1(x);
//	x->testWithoutDelay();
	ArdLooper ArdLooper;
	ArdLooper.createThread(Al1);
	ArdLooper.createThread(Bl1);
	
//	ardManager.testWithoutDelay();
	ArdLooper.startThreads();
	
//	ArdLooper *ardLooper = new ArdLooper();
//	ardLooper->loop();	
	return 0;
}
