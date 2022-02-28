Tim#include <MultiFuncLite.h>
MultiFuncLite MFS;
#include <TimerOne.h>




const int led = LED_BUILTIN;  // the pin with a LED
int button1 =  0; // use to store button state
int button2 =  0; 
bool Enable_Flash = true;

void setup(void)

{

  pinMode(led, OUTPUT);
  Timer1.initialize(150000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
  Serial.begin(9600);
  MFS.initialize();
  MFS.SetScrollTime(250);
}



int ledState = LOW;
volatile unsigned long blinkCount = 0; 

void blinkLED(void)
{
 blinkCount = blinkCount + 1;
 digitalWrite(led, !digitalRead(led)); 
}




void loop(void)   {

button1 = digitalRead(A1);
button2 = digitalRead(A2);  

MFS.write(blinkCount);

if (button1 == 0) {
 Timer1.stop();
 digitalWrite(led, 0);
}
if (button2 == 0) {
  Timer1.start();

}
}
