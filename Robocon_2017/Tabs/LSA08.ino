// FOR LSA COONECTED AS SHOWINF VALUES 0  -  70 WHILE LOOKING TOWARDS FRONT SIDE
void lsa(){
  if(count==1){ 
  k=analogRead(A0);//read LSA reading
    a=((float)k/921)*70;//convert LSA reading
    Serial.println(a);
    error=a-sp;//calculate error
    kp=3;   //FOR WHEEL DEFAULT SPEED 180
    sv=kp*error;
  
 if (jvar ==1)
 {
  wait();
 }
   
   if(a>=0 && a<=32)
   {
    moveright(-sv,0);
    
    
   } 
   else if(a>=38 && a<=80)
   {
    moveright(0,sv);
   
    
   }  
   else //(a>=33 && a<=37) 
   {
     moveright(0,0); 
   }
      }
      
  
else{
     moveright(0,0);
}
  }
      


