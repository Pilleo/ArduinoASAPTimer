/*This is my pattern for executing some periodic actions on Arduino. 
It is not always faster and ram lighter than millis() and micros() patterns but it may be more convenient in some ways too.
It may be convenient in cases, when you dont care when exactly task will be done, you just want it to be done ASAP (as soon as possinle), but
not during that particular iteration of loop(). Basicly you can use it as a timer if you know how it takes one iteration to be done.
So, if your sketch runs 1 iteration of loop() for 1 ms, and you need some action to be done every 1 sec, 1ms*1000 == 1 sec. So you
need it to be done every 1000 iterations. 
That may be used for debouncing. My other sketch is running every loop() at least 20 ms, and if i am using 5 ms time to wait to
debounce a button, it will still be at least 20 ms waiting, also cpu will have to compare two not zero values, which is a bit slower.
That is more difficult for cpu than just incrementing and decrementing one variable and comparing it to 0. 

Please learn about millis(), micros(), hardware timers,  think about possible sideeffects before using that.
If your code works good now, i guess it will not be useful for you. 
If you have ideas, scenarios,  benchmarks of that code or critics - please write it, i will be happy to learn or know that it helped you. 
*/

boolean onOff=1; // arduino led state. My task here is LED blinking.
byte loopCounter=2; // number of iterations made by loop(). Set as little variable as possible to save ram and cpu time. 
// Your code will be executed every "loopCounter" iteration of loop(). 
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
      if (--loopCounter == 0) { //comparing with 0 should be a bit faster and easier for Arduino to process. Correct me if i am wrong. 
        loopCounter=2; // That digit sets how often your code will be executed. Every 2(3,4... set your own value) iterations of loop().
        // write your code down there
        digitalWrite(13, onOff= !onOff); // the task itself. 
        }
}
