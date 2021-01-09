# ArdThread Framework using C++11

### Threading framework for <i>Arduino</i> and other memory Constraint microprocessor. <br/>
<br/>
In a basic Arduino code, running 2 paraller block with non-interfering "delay" logic is not easy.  <br/>
<b>For example</b> try to run blink code for N led with different delays for each leds. 
or, generate different frequency signals from PWN outlets
We can come up with some mathematical function which can maintain state of leds for each moment and respect each blink delays.
<br/>
<b>Alternatively</b>, 
We can use a threading Mechanism which seems far impossible in such memory restricted environment.
ArdThread is one try to parallise multiple tasks. We divide whole program into smaller maintainable chunks using anonymous function and Cpp pointers to delegate tasks.
<br/>
<h3> Please Note: This is not actually a Threading library. More like a Handler-Looper Architecture to simplyfy processing </h3>
<h5> No bottleneck testing has been done </h5>
<br/>
Check Example.cpp file to understand how Framework works.<br/>
Original Method: 

```cpp
void ledAFunction() {
  delay(1500);
  digitalWrite(13, HIGH);
  delay(1500);
  digitalWrite(13, LOW);  
}

void ledBFunction() {
  delay(3000);
  digitalWrite(16, HIGH);
  delay(3000);
  digitalWrite(16, LOW);  
}

/**
* Loop tries to do task ledAFunction and ledBFunction together
*/ 
void loop() {
  // This method wont parallelize your blocks as delays are blocking
  // Alternative is to write whole code with millis()
  ledAFunction(); 
  ledBFunction();
}
```

with <b>ArdThread</b> same code will be converted to
```cpp
void ledAFunction(ArdObject* ard) {
  ard->runAfterDelayMillis(1500, []() {
    digitalWrite(13, HIGH);
  });
  ard->runAfterDelayMillis(1500, []() {
    digitalWrite(13, LOW);
  });
}

void ledBFunction(ArdObject* ard) {
  ard->runAfterDelayMillis(3000, []() {
    digitalWrite(16, HIGH);
  });
  ard->runAfterDelayMillis(3000, []() {
    digitalWrite(16, LOW);
  });
}

/**
* parallelize with each delay respected
*/ 
void loop() {
  ArdLooper ArdLooper;
	ArdLooper.createThread(ledAFunction);
	ArdLooper.createThread(ledBFunction);
  
  ArdLooper.startThreads();
}
```
