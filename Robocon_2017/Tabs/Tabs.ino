// Include librarires
#include <PS2X_lib.h>  //for v1.6
#include <Wire.h>

//ps2 connections to arduino
PS2X ps2x; // create PS2 Controller Class
#define PS2_DAT        5  //14    
#define PS2_CMD        4  //15
#define PS2_SEL        3  //16
#define PS2_CLK        2  //17
#define pressures   false
#define rumble      false
byte type = 0;
byte vibrate = 0;
int x,y;


/*motorpins
#define m1 27 //dir
#define s1 13//speed
#define m2 22
#define s2 10
#define m3 25
#define s3 12
#define m4 23
#define s4 11*/

// Motor driver to arduino
int m1=27,m2=22,m3=25,m4=23;
float s1=13,s2=10,s3=12,s4=11;

//defines ultrasonic 
const int trigPin = 31;
const int echoPin = 33;
long duration;
int d;


//LSA = Line sensor
#define jpulse 44
float k=0;
float kp=0;
int sp=35;//sp is the set point i.e.35 on LSA
int jvar=0;
int a=0;
int error=0;
int sv=0;
int count=1;

//fuctions - prototyping
void ps2control(); // PS2 buttons
void lsa(); // Adjust using line sensor
void Ultrasonic(); // Take input from ultrasonic
void wait(); // Wait for input
void moveforward(); // Chassis moves forward
void moveright(); // moves right
void moveleft(); // moves left
void moveback(); // moves backwards
void rotatec(); // rotates Clockwise
void rotateac(); // rotates anti - clockwise
void revlsa(); // Use other Line sensor

void setup() {
  
    Serial.begin(115200);

    // Motor pins as output
    pinMode(m1,OUTPUT);
    pinMode(m2,OUTPUT);
    pinMode(m3,OUTPUT);
    pinMode(m4,OUTPUT);
    pinMode(s1,OUTPUT);
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);
    pinMode(s4,OUTPUT);

    // Initialize ultrasonic
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(jpulse,INPUT);
   
   // Initialize PS2     
   ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

   Wire.begin();
  
}    
    
   


void loop(){

    
    jvar= digitalRead(jpulse);
    
      ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed   

      /*int ly= ps2x.Analog(PSS_LY);
      ly=map(y,0,255,254,-254);    
      int lx= ps2x.Analog(PSS_LX);
      lx=map(x,0,255,-254,254);*/
        
      int y= ps2x.Analog(PSS_LY);
      y=map(y,0,255,254,-254);    
      int x= ps2x.Analog(PSS_LX);
      x=map(x,0,255,-254,254);  
    
  
      Serial.print(y);
      Serial.print("  ");
      Serial.print(x);
      Serial.print("     ");

      /*Serial.print(ry);
      Serial.print("  ");
      Serial.print(rx);
      Serial.println("  ");
      delay(100);*/
      if(ps2x.ButtonPressed(PSB_CIRCLE))
      {
      Wire.beginTransmission(2);
      Wire.write('e');
      Wire.endTransmission();
      }
     /* if(ps2x.ButtonPressed(PSB_SQUARE))
      {
      Wire.beginTransmission(2);
      Wire.write('f');
      Wire.endTransmission();
      }
      if(ps2x.ButtonPressed(PSB_CROSS))
      {
      Wire.beginTransmission(2);
      Wire.write('g');
      Wire.endTransmission();
      }
      if(ps2x.ButtonPressed(PSB_TRIANGLE))
      {
      Wire.beginTransmission(2);
      Wire.write('h');
      Wire.endTransmission();
      }*/
     
if(y>0)
      {
        moveforward(0,0);        
      }
    else  if(x>0 )
    {      
      lsa();
      }
     else if(x<0)
      {
        revlsa();
      }
     else if(y<0)
      {
        moveback(0,0);
      }    
     else  if(ps2x.Button(PSB_L1))               
     { 
       rotatec();
     }
   else if(ps2x.Button(PSB_R1))            
      {
       rotateac();
      }
      else
      {
        wait();
      }
    
    if(ps2x.Button(PSB_PINK))
     {
       count=count*(-1);
     }
     if(ps2x.Button(PSB_BLUE))
     {
       Ultrasonic();
     } 
     if(ps2x.ButtonPressed(PSB_PAD_UP))
     {
      Wire.beginTransmission(2);
      Wire.write('a');
      Wire.endTransmission();   
     }
    else if(ps2x.ButtonPressed(PSB_PAD_DOWN))
     {
      Wire.beginTransmission(2);
      Wire.write('b');
      Wire.endTransmission();   
     }
    else if(ps2x.ButtonPressed(PSB_PAD_RIGHT))
     {
      Wire.beginTransmission(2);
      Wire.write('c');
      Wire.endTransmission();   
     }
    else if(ps2x.ButtonPressed(PSB_PAD_LEFT))
     {
      Wire.beginTransmission(2);
      Wire.write('d');
      Wire.endTransmission();   
     }
 }




     
   
     
      
