#include <AFMotor.h>

AF_DCMotor motor(4);

int ledPin = 13; // choose the pin for the LED
int decPin =18; // choose the input pin (for a pushbutton)
int incPin =19; // choose the input pin (for a pushbutton)

int currentIncButtonState = 0;
int previousIncButtonState = 0;
int currentDecButtonState = 0;
int previousDecButtonState = 0;

static int motorSpeed=255;
void setup() 
{
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(decPin, INPUT); // declare pushbutton as input
  pinMode(incPin, INPUT); // declare pushbutton as input
  Serial.begin(9600);
  
  
  
  //Set initial speed of the motor & stop
  motor.setSpeed(motorSpeed); 
  //motor.run(RELEASE);
  motor.run(FORWARD);
}

void loop() 
{
  
currentIncButtonState = digitalRead(incPin);    //current incPin button state is whatever the button shows

if (previousIncButtonState == HIGH and currentIncButtonState == LOW and motorSpeed < 245){
  motorSpeed = motorSpeed + 10;
}
previousIncButtonState = currentIncButtonState;


currentDecButtonState = digitalRead(decPin);    //current decPin button state is whatever the button shows

if (previousDecButtonState == HIGH and currentDecButtonState == LOW and motorSpeed > 100){
  motorSpeed = motorSpeed - 10;
}
previousDecButtonState = currentDecButtonState;


Serial.print("Current Speed :");
Serial.println(motorSpeed);

motor.setSpeed(motorSpeed);

delay(250);
}
