//POSITION FUNCTIONS: DEFAULT SPEED 180
     void moveforward(int v, int t){
     digitalWrite(m1,LOW);
     analogWrite(s1,0);
     
     digitalWrite(m2,HIGH); //clk
     analogWrite(s2,180-v);
     
     digitalWrite(m3,LOW);
     analogWrite(s3,0);
     
     digitalWrite(m4,LOW); //ANTCLK
     analogWrite(s4,180-t);
   
     }
     
     void moveright(int v,int t){
     digitalWrite(m1,HIGH);
     analogWrite(s1,180-v);
     
     digitalWrite(m2,HIGH);
     analogWrite(s2,0);
     
     digitalWrite(m3,LOW);
     analogWrite(s3,180-t);
     
     digitalWrite(m4,LOW);
     analogWrite(s4,0);
     }
     
     void moveleft(int v,int t){
    
     digitalWrite(m1,LOW);//CLK
     analogWrite(s1,180-v);
     
     digitalWrite(m2,LOW);
     analogWrite(s2,0);
     
     digitalWrite(m3,HIGH);//ANTI
     analogWrite(s3,180-t);
     
     digitalWrite(m4,LOW);
     analogWrite(s4,0);
     }
     
     void moveback(int v,int t){
  
     digitalWrite(m1,LOW);
     analogWrite(s1,0);
     
     digitalWrite(m2,LOW);// ANTI
     analogWrite(s2,180-v);
     
     digitalWrite(m3,HIGH);
     analogWrite(s3,0);
     
     digitalWrite(m4,HIGH);//CLK
     analogWrite(s4,180-t);
     v=0;
     t=0;
     }
     
     void wait(){
     jvar=0;  
     digitalWrite(m1,LOW);
     analogWrite(s1,0);
     digitalWrite(m2,HIGH);
     analogWrite(s2,0);
     digitalWrite(m3,LOW);
     analogWrite(s3,0);
     digitalWrite(m4,HIGH);
     analogWrite(s4,0);
     } 
     
     void rotateac(){
     digitalWrite(m1,HIGH);
     analogWrite(s1,100);
     digitalWrite(m2,HIGH);
     analogWrite(s2,100);
     digitalWrite(m3,HIGH);
     analogWrite(s3,100);
     digitalWrite(m4,HIGH);
     analogWrite(s4,100);
     } 
     
     void rotatec(){
     digitalWrite(m1,LOW);
     analogWrite(s1,100);
     digitalWrite(m2,LOW);
     analogWrite(s2,100);
     digitalWrite(m3,LOW);
     analogWrite(s3,100);
     digitalWrite(m4,LOW);
     analogWrite(s4,100);
     }
     
     
