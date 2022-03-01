void pointToSun(){
  TR=analogRead(A3)/100;
  TL=analogRead(A2)/100;
  DR=analogRead(A1)/100;
  DL=analogRead(A0)/100;
if(phi<=90){
  if((DR<DL)||(TR<TL)){
    X.write(theta--);
  }
   if((DR>DL)||(TR>TL)){
    X.write(theta++);
  }
  if((TL<DL)||(TR<DR)){
    Y.write(phi--);
  }
  if((TL>DL)||(TR>DR)){
    Y.write(phi++);
  }
}

if(phi>90){
  //Serial.println(phi);
  if((DR<DL)||(TR<TL)){
    X.write(theta++);
  }
   if((DR>DL)||(TR>TL)){
    X.write(theta--);
  }
  if((TL<DL)||(TR<DR)){
    Y.write(phi--);
  }
  if((TL>DL)||(TR>DR)){
    Y.write(phi++);
  }
}

 /**
  delay(100);
  Serial.print("Top Right: " );
  Serial.println(TR);
  Serial.print("Top Left: " );
  Serial.println(TL);
  Serial.print("Down Right: " );
  Serial.println(DR);
  Serial.print("Down Left: ");
  Serial.println(DL);
  Serial.println(digitalRead(4));
   Serial.println("  ");
    Serial.println("  ");
delay(200);


     Serial.print("theta: ");
  Serial.println((String)theta);
   Serial.print("Phi: ");
  Serial.println((String)phi);
   Serial.println("  ");
*/
}
void printtp(int t,int p){
   
   
   lcd.setCursor(2,0);
   lcd.print("Theta: "+(String)t);
   lcd.setCursor(2, 1);
   lcd.print("Phi: "+(String)p+" ");
   lcd.setCursor(0,16);
}



void printAngles(String z,String a,String d, String t){
   String zenith="Zen:"+z+" ";
   String azimuth="Azi:"+a+"  ";
   String declination="Dec:"+d+" ";
   String tilt="Tilt:"+t+" ";
   //if (atoi(a)==0){a=a+"N";}else{a=a+" ";}
   //if (atoi(a)==90){a=a+"E";}else{a=a+" ";}
   //if (atoi(a)==180){a=a+"S";}else{a=a+" ";}
   //if (atoi(a)==270){a=a+"W";}else{a=a+" ";}
   lcd.setCursor(0,0);
   lcd.print(zenith+azimuth);
   lcd.setCursor(0, 1);
   lcd.print(declination+tilt);
 }


 


unsigned long previousMillis = 0;
int ledState = LOW; 

void blinc(String s, int interval, int x, int y){
  
 unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }
  }  
 if (ledState==LOW){
  lcd.setCursor(x,y);
       lcd.print(s);
 }
 if (ledState==HIGH){
    lcd.setCursor(x,y);
    lcd.print("            ");  
 }
 //Serial.print(ledState);
}
