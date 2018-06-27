// Assignment 2 – Single Line METRO 
// This sketch will blink & checkout all of your LED connections;
//Also it has typical defines you can use for the assignment - 
//Code for you to cut and paste to test LEDS 

// define the pins that the buttons and lights are connected to:
#define eastboundrequestButton   3   // Button Defines
#define westboundrequestButton  13

#define eastboundRed    2   // LED Defines eastbound Red 
#define eastboundYellow     4   // is at WEST END
#define eastboundGreen    1

#define westboundRed    12
#define westboundYellow     10
#define westboundGreen    11

#define yellowBlinkTime     500  // 0.5 seconds for yellow light blink

boolean Eastbound = true;       // Traffic starts out Eastbound
int flowTime = 10000;       // amount of time to let traffic flow
int changeDelay = 1000;       // amount of time between color changes

  //TEST INITIALIZE


void setup()
{
  pinMode(eastboundrequestButton, INPUT);
  pinMode(westboundrequestButton, INPUT);

  pinMode(westboundRed, OUTPUT);
  pinMode(westboundYellow, OUTPUT);
  pinMode(westboundGreen, OUTPUT);

  pinMode(eastboundRed, OUTPUT);
  pinMode(eastboundYellow, OUTPUT);
  pinMode(eastboundGreen, OUTPUT);

  //SELF SETTINGS HERE
}



void loop()
{
//      for ( int a = 0; a < 5; a++ ) // blink eastbound yellow light going to green
//        {
//  digitalWrite(eastboundYellow,   LOW);
//        digitalWrite(eastboundRed,  LOW);     
//        digitalWrite(eastboundGreen,  LOW);
//        digitalWrite(westboundYellow,   LOW);
//       digitalWrite(westboundRed,   LOW);     
//        digitalWrite(westboundGreen,  LOW);
//
//delay(yellowBlinkTime);
//
//  digitalWrite(eastboundYellow,   HIGH);
//        digitalWrite(eastboundRed,  HIGH);    
//        digitalWrite(eastboundGreen,  HIGH);
//        digitalWrite(westboundYellow,   HIGH);
//       digitalWrite(westboundRed,   HIGH);    
//        digitalWrite(westboundGreen,  HIGH);
//delay(yellowBlinkTime);
//
//  }
  //SELF DEFINE
  int eastButtonState = digitalRead(eastboundrequestButton);  // SET THE BUTTON STATE FROM BUTTON PRESS
  int westButtonState = digitalRead(westboundrequestButton);  // SET THE BUTTON STATE FROM BUTTON PRESS

  //INITIALIZE EAST AS RED & WEST AS GREEN
  smartInit();
  
  if (eastButtonState == HIGH) 
  {
    redToGreen();
    Eastbound = false;
    //eastRedToGreen();    
  }
  if (westButtonState == HIGH) 
  {
    redToGreen();
    Eastbound = true;
    //westRedToGreen();    
  }
}

//SELF DEFINE FUNCTION HERE-------------------------------------------

void eastInit()
{
  digitalWrite(eastboundYellow,   LOW);
  digitalWrite(eastboundRed,  HIGH);     
  digitalWrite(eastboundGreen,  LOW);
  digitalWrite(westboundYellow,   LOW);
  digitalWrite(westboundRed,   LOW);     
  digitalWrite(westboundGreen,  HIGH);
}

void westInit()
{
  digitalWrite(eastboundYellow,   LOW);
  digitalWrite(eastboundRed,  LOW);     
  digitalWrite(eastboundGreen,  HIGH);
  digitalWrite(westboundYellow,   LOW);
  digitalWrite(westboundRed,   HIGH);     
  digitalWrite(westboundGreen,  LOW);
}

//void biInit()               // INITIAL BOTH SIDES, WE DO NOT NEED IN THIS PROJECT
//{
//  digitalWrite(eastboundYellow,   LOW);
//  digitalWrite(eastboundRed,  LOW);     
//  digitalWrite(eastboundGreen,  LOW);
//  digitalWrite(westboundYellow,   LOW);
//  digitalWrite(westboundRed,   LOW);     
//  digitalWrite(westboundGreen,  LOW);
//}

void smartInit()              // IT CAN CHOOSE CORRECT WAY TO INITIALIZE BASED ON THE Eastbound BOOLEAN VALUE
{
  if (Eastbound == true)
  {
    eastInit();
  }
  else
  {
    westInit();
  }
}

void eastRedToGreen()
{
  delay(changeDelay);  
  digitalWrite(westboundGreen,  LOW);    //WEST CHANGE TO RED FIRST
  westYellowBlink();
  delay(changeDelay);                    
  digitalWrite(westboundRed,   HIGH);

  delay(flowTime);                       //WAIT FOR 10 SECONDS

  digitalWrite(eastboundRed,  LOW);      //EAST CHANGE TO GREEN
  eastYellowBlink();
  delay(changeDelay);
  digitalWrite(eastboundGreen,  HIGH);
}

void westRedToGreen()
{
  delay(changeDelay);  
  digitalWrite(eastboundGreen,  LOW);    //WEST CHANGE TO RED FIRST
  eastYellowBlink();
  delay(changeDelay);                    
  digitalWrite(eastboundRed,   HIGH);

  delay(flowTime);                       //WAIT FOR 10 SECONDS

  digitalWrite(westboundRed,  LOW);      //EAST CHANGE TO GREEN
  westYellowBlink();
  delay(changeDelay);
  digitalWrite(westboundGreen,  HIGH);
}

void redToGreen()
{
   if (Eastbound == true)
  {
    eastRedToGreen();
  }
  else
  {
    westRedToGreen();
  }
}

void eastYellowBlink()
{
  digitalWrite(eastboundYellow,   HIGH); //PROMPT TO NOTICE
  delay(yellowBlinkTime);                //BLINK FOR ONCE
  digitalWrite(eastboundYellow,   LOW);
  delay(yellowBlinkTime);
  digitalWrite(eastboundYellow,   HIGH);
  delay(yellowBlinkTime);                //BLINK FOR TWICE
  digitalWrite(eastboundYellow,   LOW);
}

void westYellowBlink()
{
  //PROMPT TO NOTICE
  digitalWrite(westboundYellow,   HIGH);
  delay(yellowBlinkTime);                //BLINK FOR ONCE
  digitalWrite(westboundYellow,   LOW); 
  delay(yellowBlinkTime);
  digitalWrite(westboundYellow,   HIGH);
  delay(yellowBlinkTime);                //BLINK FOR TWICE
  digitalWrite(westboundYellow,   LOW); 
}

//void yellowBlink()                    //CANNOT USE THIS
//{
//  if (Eastbound == true)
//  {
//    eastYellowBlink();
//  }
//  else
//  {
//    westYellowBlink();
//  }
//}

//void biYellowBlink()                 //DO NOT NEED HERE
//{
//  digitalWrite(eastboundYellow,   HIGH); //PROMPT TO NOTICE
//  digitalWrite(westboundYellow,   HIGH);
//  delay(yellowBlinkTime);                //BLINK FOR ONCE
//  digitalWrite(eastboundYellow,   LOW);
//  digitalWrite(westboundYellow,   LOW); 
//  delay(yellowBlinkTime);
//  digitalWrite(eastboundYellow,   HIGH);
//  digitalWrite(westboundYellow,   HIGH);
//  delay(yellowBlinkTime);                //BLINK FOR TWICE
//  digitalWrite(eastboundYellow,   LOW);
//  digitalWrite(westboundYellow,   LOW); 
//}

