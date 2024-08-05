#line 1 "C:/Users/mshms/OneDrive/Desktop/Traffic Project/Software.c"
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
 portd.b3 = 1;
 portD.b2 = 1;
 Mode();
 }
void Automatic()
{
 for(count = 0 ; count < 10; count++)
 {
 portB = count + key[i];
 if(portB == 32)
 {
 portD.b2 = 0;
 portD.b0 = 1;
 }
 if(portB == 35)
 {
 portD.b3 = 0;
 portD.b4 = 1;
 }
 if(portB == 38)
 {
 portD.B4 =0;
 portD.b5 =1;
 }
 if(portB == 53)
 {
 portD.b0 = 0;
 portD.b1 = 1;
 }
 delay_ms(150);
 if(portB == 55)
 {
 i = -1;
 count = 10;
 portD.b5 =0;
 portD.b1 = 0;
 portd.b3 = 1;
 portD.b2 = 1;
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
{ while(1)
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
 { portD.b0 = 0;
 portD.b5 = 0;
 portD.b2 = 0;

 portD.b1 = 1;

 portD.b3 = 1;
 delay_ms(3000);

 portD.b1 = 0;

 portD.b2 = 1;
 }
 else
 {
 portD.b2 = 0;
 portD.b5 = 0;
 portD.b3 = 0;

 portD.b4 = 1;

 portD.b0 = 1;
 delay_ms(3000);

 portD.b4 = 0;

 portD.b5 = 1;
 }
 flag = 1;
 OldPortValue = portA.b1;
 }
 if(portA.b1 != OldPortValue) {flag = 0;}
 }
