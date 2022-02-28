
#define Dig1 6
#define Dig2 9
#define Dig3 10
#define Dig4 11
#define DIGIT_ON LOW
#define DIGIT_OFF HIGH
#define DISPLAY_BRIGHTNESS 5000
boolean duiz = false;
boolean hon = false;
#define segA 2
#define segB 3
#define segC 4
#define segD 5
#define segE A0
#define segF 7
#define segG 8
//int segPD = ;
void setup()
{
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(Dig1, OUTPUT);
  pinMode(Dig2, OUTPUT);
  pinMode(Dig3, OUTPUT);
  pinMode(Dig4, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int number;
  Serial.println(number);

  for ( int i = 0; i <= 9999; i++) { 
    duiz = false;
    hon = false;
    for (int k = 0; k < 50; k++) { 

      int figur = i;
      for (int digit = 1 ; digit < 5 ; digit++) { 
        switch (digit) {
          case 1:
            if (figur > 999) {
              digitalWrite(Dig1, DIGIT_ON);
              lightNumber(figur / 1000); 
              figur %= 1000; 
              delayMicroseconds(DISPLAY_BRIGHTNESS);
              if (figur < 100) {
                duiz = true;
                if (figur < 10) {
                  hon = true;

                }

              } else duiz = false;
            }

            break;
          case 2:
            if (duiz == true) {
              digitalWrite(Dig2, DIGIT_ON);
              lightNumber(0);
              delayMicroseconds(DISPLAY_BRIGHTNESS);

            } if (hon == true) {
              break;
            }

            if (figur > 99 && figur < 1000) {
              digitalWrite(Dig2, DIGIT_ON);
              lightNumber(figur / 100);
              figur %= 100;
              delayMicroseconds(DISPLAY_BRIGHTNESS);
              if (figur < 10) {
                hon = true;

              } else hon = false;
            }
            break;
          case 3:
            if (hon == true) {
              digitalWrite(Dig3, DIGIT_ON);
              lightNumber(0);
              delayMicroseconds(DISPLAY_BRIGHTNESS);
              break;
            }

            if (figur > 9 && figur < 100) {
              digitalWrite(Dig3, DIGIT_ON);
              lightNumber(figur / 10);
              figur %= 10;
              delayMicroseconds(DISPLAY_BRIGHTNESS);
            }

            break;
          case 4:
            if (figur < 10) {
              digitalWrite(Dig4, DIGIT_ON);
              lightNumber(figur);
              delayMicroseconds(DISPLAY_BRIGHTNESS);

              break;
            }
        }
        //Turn off all segments
        lightNumber(10);
        //Turn off all digits
        digitalWrite(Dig1, DIGIT_OFF);
        digitalWrite(Dig2, DIGIT_OFF);
        digitalWrite(Dig3, DIGIT_OFF);
        digitalWrite(Dig4, DIGIT_OFF);

      }
    }
  }
}
void lightNumber(int numberToDisplay) {
#define SEGMENT_ON HIGH
#define SEGMENT_OFF LOW
  switch (numberToDisplay) {
    case 0:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_OFF);
      break;
    case 1:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      break;
    case 2:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 3:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 4:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 5:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 6:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 7:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      break;
    case 8:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 9:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;
    case 10:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      break;
  }
}
