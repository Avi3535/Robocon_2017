


int x,a,b,count=0,ch=0;
#define dir 6
#define pwm 5
void setup() {
  // put your setup code here, to run once:
pinMode(dir,OUTPUT);
pinMode(pwm,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
digitalWrite(dir,HIGH);
analogWrite(pwm,250);
Serial.begin(57600);
attachInterrupt(0, counter, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(count);
  if(count>=420 && count<=600)
  {
   
    analogWrite(pwm,0);
   /* count=0;
    delay(500);
    */
  }
 // analogWrite(pwm,250);
  

}
void counter()
{
  count++;
}


