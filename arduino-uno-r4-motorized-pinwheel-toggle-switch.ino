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
  switchState = digitalRead(switchPin);

  if (switchState == HIGH && lastSwitchState == LOW){
    motorOn = !motorOn;

    if (motorOn) {
      digitalWrite(motorPin, HIGH);
    } else {
      digitalWrite(motorPin, LOW);
    }

    delay(50);
  }

  lastSwitchState = switchState;
}
