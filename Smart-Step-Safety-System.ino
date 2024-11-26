// Pin Definitions
int fsrPin = A0;       // FSR sensor connected to A0
int buzzerPin = 8;     // Passive buzzer connected to D8
int IN1 = 9;           // Motor driver input pin 1
int IN2 = 10;          // Motor driver input pin 2
int ENA = 5;           // Motor driver enable pin (PWM)

// Variables
int fsrValue = 0;      // To store FSR readings
int threshold = 100;   // FSR threshold value for detection
unsigned long startTime = 0;
bool pressureDetected = false;
bool buzzerActivated = false;
bool motorSpeedReduced = false;

void setup() {
  pinMode(fsrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT); 

  // Start serial communication for debugging
  Serial.begin(9600);

  // Initialize motor direction and full speed
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);  // Full motor speed
}

void loop() {
  // Read FSR sensor value
  fsrValue = analogRead(fsrPin);

  // Print FSR value to Serial Monitor for debugging
  Serial.print("FSR Value: ");
  Serial.println(fsrValue);

  // Check if pressure exceeds threshold
  if (fsrValue > threshold) {
    if (!pressureDetected) {
      // Start timer when pressure is detected for the first time
      startTime = millis();
      pressureDetected = true;
      Serial.println("Pressure detected. Timer started.");
    }

    // Calculate elapsed time since pressure was first detected
    unsigned long elapsedTime = millis() - startTime;
    Serial.print("Elapsed Time: ");
    Serial.println(elapsedTime / 1000); // Print elapsed time in seconds

    // If pressure has been detected for 1 minute, activate the buzzer
    if (elapsedTime >= 30000 && !buzzerActivated) { // 1 minute = 60,000 milliseconds
      tone(buzzerPin, 1000); // Sound the buzzer at 1000 Hz
      buzzerActivated = true;
      Serial.println("Buzzer activated for 1 minute of pressure.");
    }

    // If pressure continues for an additional 1 minute after the buzzer sounds, reduce motor speed
    if (buzzerActivated && elapsedTime >= 60000 && !motorSpeedReduced) { // 2 minutes total
      analogWrite(ENA, 128);  // Set motor to half speed
      motorSpeedReduced = true;
      Serial.println("Motor speed reduced to half.");
    }
  } else {
    // Reset everything if pressure is removed
    pressureDetected = false;
    buzzerActivated = false;
    motorSpeedReduced = false;
    noTone(buzzerPin);          // Turn off buzzer
    analogWrite(ENA, 255);      // Return motor to full speed

    Serial.println("Pressure removed. Resetting everything.");
  }

  // Add a small delay to make the Serial Monitor readable
  delay(1000);  // Delay for 1 second
}