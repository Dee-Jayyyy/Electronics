unsigned long Button1PreviousTime = millis(); // unsigned long is essentially an extended variable meant to store larger numbers which will be useful for something like this as the time will always go up. Store previous time to know if the button has just been pressed or already was pressed.
int Button1PreviousSwap = HIGH; // Stores the state of the button the last time it was changed state
int Button1PreviousReading = HIGH; // Stores the state of the button as quick as the loop allows
unsigned long Button2PreviousTime = millis(); 
int Button2PreviousSwap = HIGH; 
int Button2PreviousReading = HIGH;
unsigned long Button3PreviousTime = millis(); 
int Button3PreviousSwap = HIGH; 
int Button3PreviousReading = HIGH; 

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); // Sets the data rate in bits per second (9600) Allows for communication with the Serial Monitor
  pinMode(2,INPUT_PULLUP); // INPUT_PULLUP uses the Arduino's internal resistors so you don't need the external ones. HIGH = off, LOW = on
  pinMode(4,INPUT_PULLUP); 
  pinMode(6,INPUT_PULLUP);
}
void loop() 
{
  // My control scheme will be jkl, so each of those buttons will be the equivalent of one of those keys
  int Button1CurrentReading = digitalRead(2);
  if (Button1CurrentReading != Button1PreviousReading) // State of button has changed
  {
    Button1PreviousReading = Button1CurrentReading;
    unsigned long Button1CurrentTime = millis();
    if (Button1PreviousTime + 30 < Button1CurrentTime) // Ensures that it isn't a false flag
    {
      Button1PreviousSwap = Button1CurrentReading;
      Button1PreviousTime = Button1CurrentTime;
      if (Button1CurrentReading == LOW) // Pressed
      {
        Serial.println("j"); // Tells the series monitor the print the message if the button is pushed in (using the 9600 bit rate so it checks very frequently)
      }
      else // Released
      {
        Serial.println("J");
      }
    }
  }
  int Button2CurrentReading = digitalRead(4);
  if (Button2CurrentReading != Button2PreviousReading) // State of button has changed
  {
    Button2PreviousReading = Button2CurrentReading;
    unsigned long Button2CurrentTime = millis();
    if (Button2PreviousTime + 30 < Button2CurrentTime) // Ensures that it isn't a false flag
    {
      Button2PreviousSwap = Button2CurrentReading;
      Button2PreviousTime = Button2CurrentTime;
      if (Button2CurrentReading == LOW) // Pressed
      {
        Serial.println("k"); // Tells the series monitor the print the message if the button is pushed in (using the 9600 bit rate so it checks very frequently)
      }
      else // Released
      {
        Serial.println("K");
      }
    }
  }
  int Button3CurrentReading = digitalRead(6);
  if (Button3CurrentReading != Button3PreviousReading) // State of button has changed
  {
    Button3PreviousReading = Button3CurrentReading;
    unsigned long Button3CurrentTime = millis();
    if (Button3PreviousTime + 30 < Button3CurrentTime) // Ensures that it isn't a false flag
    {
      Button3PreviousSwap = Button3CurrentReading;
      Button3PreviousTime = Button3CurrentTime;
      if (Button3CurrentReading == LOW) // Pressed
      {
        Serial.println("l"); // Tells the series monitor the print the message if the button is pushed in (using the 9600 bit rate so it checks very frequently)
      }
      else // Released
      {
        Serial.println("L");
      }
    }
  }
}