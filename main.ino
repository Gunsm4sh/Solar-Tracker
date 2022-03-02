#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo X;
Servo Y;
LiquidCrystal_I2C lcd(0x27,16,2);
//SDA <---> A4
//SCL <---> A5 
int TR,TL,DR,DL;
int theta,phi;
int s=0;
int k=0;
const int Mode = 5;
const int plus = 3;
const int minus = 2;
const int selector=4;

boolean edgeUpM=false;
boolean edgeUpS=false;
int lastButtonState=0;
int lastButtonState1=0;

String dec="2.9";

//for testing:



void setup() {
   X.attach(9);
   Y.attach(10);
   
  Serial.begin(115200);
  lcd.init();                      // initialize the lcd 

  lcd.backlight();
  lcd.print("Solar tracker");
  delay(1000);
  // Sets the two pins as Outputs

  pinMode(Mode,INPUT); //mode
  pinMode(plus,INPUT);//++
  pinMode(minus,INPUT);//--
  pinMode(selector,INPUT);//selector
  
  theta=93;
  phi=93;
  X.write(93);
  Y.write(93);
  lcd.clear();
  Serial.print("=====Soalar Tracker======");
  lcd.setCursor(0,2);
  Serial.print("Coded by J.H");
}

void loop() {
 limit();
 fMode();
 fselector();
 Serial.print("Azimuth: ");
 Serial.println(azimuth(theta,phi));
 Serial.print("tilt: ");
 Serial.println(tilt(phi));
//Serial.println(digitalRead((Mode)));

  switch(k){
   case 0:
   lcd.setCursor(15,0);
   lcd.print("A");
    pointToSun();
    printAngles((String)(90-tilt(phi)),(String)azimuth(theta,phi),dec,(String)tilt(phi));
   break;
   case 1:
   lcd.setCursor(15,0);
    lcd.print("A");
    pointToSun();
    printtp(theta,phi);
   break;
   case 2:
    lcd.print("M");
   lcd.setCursor(15,0);
    manual();
   break; 
   case 3:
   lcd.setCursor(15,0);
    lcd.print("M");
    manual();
    printAngles((String)(90-tilt(phi)),(String)azimuth(theta,phi),dec,(String)tilt(phi));
   break;
  }
}
void fMode(){
  mimpulse();
  if ((edgeUpM)&&(k>=0)&&(k<4)){
    delay(50); 
    lcd.clear();    
    k++;
    /////////////////FOR MANUAL//// CASE 2 //////////
    if (k==2){lcd.setCursor(0,0);
   lcd.print("> Theta: "+(String)theta);
   lcd.setCursor(0, 1);
   lcd.print("> Phi: "+(String)phi+" ");
    }

    /////////////////////////////////////////////////////
  } else if (k<0){
    k=3;
  }else if (k>3){
    k=0;
  }
}
void fselector(){
   simpulse();
   //Serial.println();
  if (edgeUpS){
    delay(50);
    s++;
   lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("> Theta: "+(String)theta+" ");
   lcd.setCursor(0, 1);
   lcd.print("> Phi: "+(String)phi+" ");
  }
}
void mimpulse(){
      
    int buttonState=digitalRead(Mode);
   if (buttonState != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      edgeUpM=true;
      }else{edgeUpM=false;}
   }
   else{edgeUpM=false;}
      lastButtonState1=buttonState;  
}
void simpulse(){
      
    int buttonState=digitalRead(selector);
   if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      edgeUpS=true;
      }else{edgeUpS=false;}
   }
   else{edgeUpS=false;}
      lastButtonState=buttonState;  
}
void limit(){
  if (theta>=180){
    theta=180;
  }
  if (theta<=0){
    theta=0;
  }
  if (phi>=180){
    phi=180;
  }
  if (phi<=0){
    phi=0;
  }
}
int tilt(int p){
  if (p<=90){
    return p;
  }
  if (p>90){
    return 180-p;
  }
}
int azimuth(int t,int p){
  if (p<90){
    return 270-t;
  }
  if(p>90){
    if (t<=90){
      return 90-t;
    }
    else{
      return 450-t;
    }
  }
}
int zenith(int t){
  return 90-t;
}
