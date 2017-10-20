int led = 6;
int sensor = A0;
float valorSensor = 0;



void setup() {
    Serial.begin (9600);

  pinMode (led , OUTPUT);
  pinMode ( sensor , INPUT);
  }

void loop() {
valorSensor = analogRead (sensor);
    Serial.println (valorSensor);
    delay (1000);

    if ( valorSensor<750 ){
    analogWrite ( led , valorSensor);
    }
    else {
    analogWrite ( led , LOW);
      }
}
