const int triggerPin = A0;
const int echoPin = A1;

const int ledAzul = 12;
const int ledVermelho = 7;
const int ledVerde = 8;
const int buzzer = 2;

void setup() {
  Serial.begin(9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration, distance_cm;
  distance_cm = analogRead(echoPin);

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance_cm = duration * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if(distance_cm > 0 && distance_cm < 14){
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);

    }else if (distance_cm > 14 && distance_cm < 20) {
        digitalWrite(ledVermelho, HIGH);
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAzul, LOW);
        digitalWrite(buzzer, LOW);

      }else if (distance_cm > 20 && distance_cm < 40) {
           digitalWrite(ledAzul, LOW);
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledVermelho, HIGH);
         digitalWrite(buzzer, LOW);

      }else if(distance_cm > 40){
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledAzul, LOW);
         digitalWrite(buzzer, LOW);
      }

      delay(100);
}
