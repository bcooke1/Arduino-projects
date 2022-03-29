
#include <MultiFuncLite.h>
MultiFuncLite MFS;

int datapin = 8;
int CLKpin = 7;
int latchpin = 4;

// Output 1 goes to A, Output2 goes to B, etc.
// Output Arrays

// "A" means segment A,B,C,E,F,G are on, 1,1,1,0,1,1,1
// "-" means segment G is on, 0,0,0,0,0,0,1

unsigned char A = 01110111;
unsigned char neg = 00000001;

bool allow = true; 
int button1 = 1;      //Defines variable button 1 as integer
int button2 = 1;      //Defines variable button 2 as integer
int button3 = 1;      //Defines variable button 3 as integer

void setup() {
  // put your setup code here, to run once:
  
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(CLKpin, OUTPUT);
  pinMode(12, OUTPUT);            // Sets pin 12 to output
  pinMode(13, OUTPUT);            // Sets pin 13 to output
  Serial.begin(9600);             // Begins serial monitor
  digitalWrite(13,HIGH);          // Sets pin 13 to HIGH which turns off the light
  digitalWrite(12,HIGH);          // Sets pin 12 to HIGH which turns off the light
}



int blinkd1(){                                  // Custom function name
  for (int i=0; i<=9; i++){                     // For loop to run the code inside of it 5 times
      digitalWrite(13, !digitalRead(13));       // Sets the output of pin 13 to whatever it isnt
      delay(300);                               // Delay so the light blinks
      Serial.println("pause");                  // Debugging, when the function runs should print "pause" into the serial monitor
      }

  }
  

int screen (){
  if (allow == true){
    digitalWrite(latchpin,LOW);
    shiftOut(datapin, CLKpin, MSBFIRST, A);
    delay(200);
  }
  else{
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, CLKpin, MSBFIRST, neg);
    delay(200);
   }


  
}


void loop() {                     //Begins a infinite loop of code to run


button1 = digitalRead(A1);        // Defines button1 as whatever pin A1 is outputing
button2 = digitalRead(A2);        // Defines button2 as whatever pin A2 is outputing 
button3 = digitalRead(A3);

if (button1 == 0 && allow == true) {    //checks to see if button1 (A1) has been pressed as its resting state is 1
  blinkd1();                               //calls the function defined above
  }

if (button2 == 0 && allow == true) {   //checks to see if button2 (A2) has been pressed as its resting state is 1
  digitalWrite(12, !digitalRead(12));     // Sets the output of pin 12 to whatever it isnt
  delay(1000);                            // Delay is so someone can click the button once and not accidently run the function 2+ times
  }

if (button3 == 0){
  allow=  (!allow);
  Serial.println(allow);
  delay(300);
  screen();
  }
}
