char count = 0;
char key[] = {0, 16 ,32, 48};
char i = 0;
char flag = 0;
char OldPortValue = 0;
void Automatic();
void Mode();
void Manual();
void main() {
 ADCON1 = 7;
 trisA.B0 = 1;
 trisA.B1 = 1;
 trisD = 0;
 portD = 0;
 trisB = 0;
 portB = 0;
 trisC = 0;
 portC = 15;
 portd.b3 = 1;//RED south
 portD.b2 = 1;//Green west
 Mode();
 }
void Automatic()
{
     for(count = 0 ; count < 10; count++)     //21  i = 2 , count = 1
     {
         portB = count + key[i];
         if(portB == 32) // 20 segment 0010 0010     //west
         {
         portD.b2 = 0;
         portD.b0 = 1; //RED west
         }
         if(portB == 35) //south
         {
          portD.b3 = 0;
          portD.b4 = 1;  //YELLOW south
         }
         if(portB == 38) //south
         {
          portD.B4 =0;
          portD.b5 =1; //GREEN south
         }
         if(portB == 53)  //west
         {
           portD.b0 = 0;
           portD.b1 = 1;  //YELLOW wesr
         }
         delay_ms(500);
         if(portB == 55) //west         //37  : 0011 0111
         {
          i = -1;
          count = 10;
          portD.b5 =0;
          portD.b1 = 0;
          portd.b3 = 1;//RED south
          portD.b2 = 1;//Green west
         }
         if(portA.b0 != 1)
         {  
            i = -1;
            portB = 0;
            Manual();
            break;
         }
     }
     i++;
}
void Mode()
{  while(1)
  {
     if(portA.b0 == 1)
     {
      Automatic();
     }
     else
     {
      Manual();
     }
   }
}
 void Manual()
 { 
   if(flag == 0)
   {
     if(portA.b1 == 1)
     {   portD.b0 = 0;
         portD.b5 = 0;
         portD.b2 = 0;
        //yellow west on 3 sec :
        portD.b1 = 1;
        //south red on :
        portD.b3 = 1;
        delay_ms(3000);
        //turn off yellow west
        portD.b1 = 0;
        //west green on :
        portD.b2 = 1;
      }
      else  //portA.b1 == 0
      {   
        portD.b2 = 0;
        portD.b5 = 0;
        portD.b3 = 0;
       //yellow south on 3 sec :
        portD.b4 = 1;
       //west red on :
        portD.b0 = 1;
        delay_ms(3000);
       //turn off yellow south
        portD.b4 = 0;
       //south green on :
        portD.b5 = 1;
      }
      flag = 1;
      OldPortValue = portA.b1;
    }
    if(portA.b1 != OldPortValue) {flag = 0;}
 }
