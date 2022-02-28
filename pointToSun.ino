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
