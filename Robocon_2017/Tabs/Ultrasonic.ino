void Ultrasonic(){ 
     
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPin, HIGH);
        // Calculating the distance
        d= duration*0.034/2;
        Serial.print("Distance: ");
        Serial.println(d);
        //delay(8);
        sv=50;
 
       if(d>=0 && d<25)
       {         
         moveforward(sv,sv);
        // Serial.println("AppaJabbaDabba");
       }
       else if(d>25 )
       {        
        moveback(sv,sv);
         //Serial.println("AppaJabbaDabba");  
        }
      }

