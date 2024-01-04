const int ledPin = 2;  // Pin connected to the LED for transmitting

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String message = "Hi";
  digitalWrite(13, LOW);
  // Send the message
  send(message);
  digitalWrite(13, HIGH);
  Serial.println("Done");
 }

void send(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);
    sendCharacter(c);
    Serial.println(c, BIN);
  }
}

void sendCharacter(char c) {
  // Send each bit of the character based on pulse duration
  for (int i = 7; i >= 0; i--) {
    int bitValue = (c >> i) & 1;

    if (bitValue == 0) {
      digitalWrite(ledPin, HIGH);
      delay(100);  // Short pulse duration for '0' bit
      digitalWrite(ledPin, LOW);
      delay(10);
    } else {
      digitalWrite(ledPin, HIGH);
      delay(300);  // Long pulse duration for '1' bit
      digitalWrite(ledPin, LOW);
      delay(10);
    }
  }
}
