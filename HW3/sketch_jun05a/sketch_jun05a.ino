
int ledPins[] = {2,4,6};  // SPECIAL NOTE: THE INDEX FOR 3 LIGHT ARE 0, 1, 2 NOT 2, 4, 6
int a = 0;        // THIS IS ANALOG VARIABLE
int beep = 13;    // BUZZER PIN


void setup() {
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  pinMode(ledPins[2],OUTPUT);
  pinMode(beep,OUTPUT);
  Serial.begin(9600);       // initialize serial port  (We’ve done this)
  Serial.flush();       //Using Serial input – clean out anything in there!
  Serial.println("Type '1' in Output window for Battery check,  '2’  for Alarm circuit; ");

}

void loop() {  
  if (Serial.available() )   // If a character has been typed from keyboard      
          //START Serial Read if -- control Arduino from keyboard !!!      
  {
    char ch = Serial.read();   //READ it in !!
  
    // USE SWITCH TO CONTROL THE OPERATION USERS WANT
    switch(ch)
    {
      case('1'):
      while(ch == '1')           // CONTINUE DO THIS
      {
        a = analogRead(0);       // GET ANALOG VALUE
        if (0.0048*a >= 1.6)     // GREEN LIGHT ON
        {
          digitalWrite(ledPins[0], HIGH);
          delay(1000); 
          digitalWrite(ledPins[0], LOW);
          delay(500);
        }
        else if ((0.0048*a > 1.4) && (0.0048*a < 1.6))  // YELLOW LIGHT ON
        {
          digitalWrite(ledPins[1], HIGH);
          delay(1000);
          digitalWrite(ledPins[1], LOW);
          delay(500); 
        }
        else if (0.0048*a <= 1.4)  // RED LIGHT ON
        {
          digitalWrite(ledPins[2], HIGH);
          delay(1000);
          digitalWrite(ledPins[2], LOW);
          delay(500); 
        }
        if (Serial.available() )   // If a character has been typed from keyboard      
                                    // TYPE '3' TO STOP STATE '1'   
        {
         ch = Serial.read();      // WE MUST CHECK IT EACH TIME, OTHERWISE IT ONLY DEFINTE ONCE FOR EACH STATE
        }
      }
      break;
      
      case('2'):
      while (ch == '2')             // CONTINUE DO THIS
      {
        tone(beep, 500,500);
        delay(500);
        noTone(beep);
        delay(500);
        if (Serial.available() )   // If a character has been typed from keyboard      
                                    // TYPE '3' TO STOP STATE '1'        
        {
         ch = Serial.read(); 
        }
      }
      break;
  
      default:break;
    }
  }
}
