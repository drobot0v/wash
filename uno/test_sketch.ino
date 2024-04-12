/* Variables */
int vibration_sensor = A5; // The contact in the board to which the vibration sensor is connected
int present_condition = 0;
int previous_condition = 0;


/* Method for blinking with the built-in LED */
void blink(int n = 1, int d = 5) {
  for(int i = 0; i < n; i++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(d);
        digitalWrite(LED_BUILTIN, LOW);
        delay(d);
    }
}

// put your setup code here, to run once:
void setup() {
  // Serial.begin(9600);
  pinMode(vibration_sensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // digitalWrite(LED_BUILTIN, LOW);
}

// put your main code here, to run repeatedly:
void loop() {

  previous_condition = present_condition;
  present_condition = digitalRead(A5);
  if (previous_condition != present_condition) {
    blink();
  }

  /*
  if (Serial.available() > 0) {
    String recievedData = Serial.readString();
    if (recievedData.indexOf("Hi") >= 0) {
        blink(5, 500);
      }
    Serial.print("Recieved now: " + recievedData);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(100);
  */
}
