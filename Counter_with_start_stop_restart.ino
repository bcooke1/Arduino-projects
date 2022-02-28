#include <MultiFuncLite.h> // USING DB LITE LIBRARY
MultiFuncLite MFS;

  
/* 
----------------------------------------------------------------------------------------------
                                 DEFINE VARIABLE AND FLAGS USED!! 
----------------------------------------------------------------------------------------------
*/

int counter=0; // General counter

/* 
----------------------------------------------------------------------------------------------
                                 MAIN VOIDE SETUP ROUTNINE HERE!! 
----------------------------------------------------------------------------------------------
*/
int button1 = 0;
int button2 = 0;
int button3 = 0;

bool allowcount = false;

void setup() {


  Serial.begin(115200);
  Serial.println();
  Serial.println(F("MFSLite Counter Example"));
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  MFS.SetScrollTime(250); // set scrolling text time
  MFS.ScrollText (F("Starting"));

}


/* 
----------------------------------------------------------------------------------------------
                                 MAIN VOID LOOP ROUTINE!! 
----------------------------------------------------------------------------------------------
*/






void loop(){  


button1 = digitalRead(A1);
button2 = digitalRead(A2);
button3 = digitalRead(A3);

if (button1 == 0){

  allowcount = true;
  
}
if (button2 == 0){

allowcount = false;  

}

if (button3 == 0){
  counter = 0;
  MFS.write(counter);
}
if (allowcount == true){
MFS.write(counter);
delay(1000);
counter ++;
}

}
 // end void loop
