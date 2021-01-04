 //PS2 CONTROLLER: 
    void ps2control(){

    
    }
   /*  //DualShock Controller
      int y= ps2x.Analog(PSS_LY);
      y=map(y,0,255,254,-254);
    
      int x= ps2x.Analog(PSS_LX);
      x=map(x,0,255,-254,254);  
    
  
      Serial.print(x);
      Serial.print("  ");
      Serial.println(y);
      delay(100);
    
    if(ps2x.ButtonPressed(PSB_CIRCLE))
     {
       count=1;
     }
    if(ps2x.ButtonPressed(PSB_CROSS))
     {
      lsa();
      ps2control();
     }
     if(y>0)
      {
        Serial.println("  Forward");
        moveforward(y);
      }
      else if(x>0 )
    {
      Serial.println("  Right");
      moveright(x);
      }
      else if(x<0)
      {
        Serial.println("  Left");
        moveleft(x);
      }
      else if(y<0)
      {
        Serial.println("Reverse");
        moveback(y);
      }  
      
     //delay(1000);
       
       else if(ps2x.Button(PSB_L1))               //will be TRUE if button was JUST pressed
     { 
       Serial.println("L1 just pressed");
       rotatec();
     }
   
    else if(ps2x.Button(PSB_R1))               //will be TRUE if button was JUST pressed OR released
      {
        Serial.println("R1 just changed");
      rotateac();
      
      
      }
      else
      {
        Serial.println("  STOP");
        wait();
      } 
     }*/
