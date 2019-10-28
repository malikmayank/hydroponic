int inputPin = A0;

void setup() {
    pinMode(inputPin, INPUT);      // set sensor as input
}

void loop() {
    float ph= (float)analogRead(inputPin); //read sensor
    Particle.publish("phValue", String(ph, 2)); //publish readings
    delay(5000); //wait 5 seconds before reading again
}
