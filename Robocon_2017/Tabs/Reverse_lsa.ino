
void revlsa(){
  if(count==1){ 
  k=analogRead(A0);//read LSA reading
    a=((float)k/921)*70;//convert LSA reading
    Serial.println(a);
    error=a-sp;//calculate error
    kp=3;
    sv=kp*error;
  
    
    if (jvar==1)
    {
     wait();
     }
   
   if(a>=0 && a<=32)
   {
    moveleft(-sv,0);   
   } 
   else if(a>=38 && a<=70)
   {
    moveleft(0,sv);    
   }  
   else //(a>=33 && a<=37) 
   {
     moveleft(0,0); 
   }
 }
      
  
else
 {
  moveleft(0,0);
 }
}
      


