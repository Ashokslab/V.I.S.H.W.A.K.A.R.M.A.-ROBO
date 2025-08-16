// Motor driver pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define IN5 6
#define IN6 7
#define IN7 8
#define IN8 9

char command;

void setup() {
  // Set all motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  // Start Serial Communication
  Serial.begin(9600);
  Serial.println("Motor Control Ready - Type F/B/L/R/S");
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    command = toupper(command);  // Convert input to uppercase

    Serial.print("Command Received: ");
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopMotors(); break;
      default: Serial.println("Unknown Command! Use F/B/L/R/S.");
    }
  }
}

void forward() {
  Serial.println("Moving Forward");
  digitalWrite(IN1,LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3,LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5,LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7,LOW); digitalWrite(IN8, HIGH);
}

void backward() {
  Serial.println("Moving Backward");
  digitalWrite(IN1, HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4,LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6,LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8,LOW);
}

void left() {
  Serial.println("Turning Left");
  digitalWrite(IN1, LOW); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); digitalWrite(IN6,LOW);
  digitalWrite(IN7,HIGH); digitalWrite(IN8, LOW);
}

void right() {
  Serial.println("Turning Right");
  digitalWrite(IN1,HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8,HIGH);
}

void stopMotors() {
  Serial.println("Stopping Motors");
  digitalWrite(IN1, HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4,LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6,LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8,LOW);
  delay(14);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, HIGH);
}
