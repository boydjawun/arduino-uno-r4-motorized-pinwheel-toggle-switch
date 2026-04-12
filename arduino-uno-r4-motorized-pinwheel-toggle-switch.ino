// This code allows the DC motor to start upon a button press, and continue until another button press is initiated
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
int lastSwitchState = 0;
bool motorOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(motorPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin); // Reads the input from switchPin and saves as switchState
  
  if (switchState == HIGH && lastSwitchState == LOW){
    motorOn = !motorOn;

    if (motorOn) {
      digitalWrite(motorPin, HIGH);
    } else {
      digitalWrite(motorPin, LOW);
    }                                  // If switchState is read as HIGH, and lastSwitchState is read as LOW. motorPin will switch to HIGH if the previous conditions are met, and Low if anything else happens

    delay(50);
  }

  lastSwitchState = switchState; // lastSwitchState equals the switchState value after the loop finishes
}
