double pH= 0;
int analogPin= A0;
double oldPH= 0; //hold previous pH value for next loop
int loopDelay = 10000; 
bool suppressNotifications= true; //removes redundant notifications

double getPH(){
    //obtain new pH reading
    double averageReading=0; //holds average value from sensor
    double values[10];  
    //collect 10 values from sensor
    for (int i=0; i<10; i++){ 
        values[i]= analogRead(analogPin);
        delay(500);
    }
    //take average of the 10 sensor values
    for(int i=0;i<10;i++){
        averageReading+= values[i]/10.0;
    }
    return averageReading/350; //convert to pH, may adjust divisor for sensor calibration 
}

void setup() {
     pinMode(analogPin, INPUT);
}

void loop() {
    pH= getPH(); 
    
    //check if pH is within safe range for system
    if(pH < 6.0 || pH > 6.5){ 
        if (suppressNotifications == true) {
            suppressNotifications = false; //enable notifications
            Particle.publish("pH", String(pH, 2));
            oldPH= pH; 
            loopDelay = 3000; //reduce loop delay
        }
        //check if pH has changed more than .2 since last read
        if (abs(oldPH - pH) > 0.2 && suppressNotifications == false){ 
            Particle.publish("pH", String(pH, 2));
            oldPH=pH; 
        }
    }
    //check if pH is back in safe range
    else if (pH >= 6.0 && pH <= 6.5 && suppressNotifications == false) { 
        Particle.publish("pH", String(pH, 2));
        loopDelay = 10000; //increase loop delay
        suppressNotifications = true; //reduce redundant notifications
    }
    delay (loopDelay);
}


