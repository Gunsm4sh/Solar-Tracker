
void manual(){

  if (s<0){
    s=1;
  }
  if (s>1){
    s=0;
  }
  X.write(theta);
  Y.write(phi);
  
  switch(s){
      case 0:
        if((theta<=180) && (theta>=0)){
           if (digitalRead(plus)==HIGH){
               theta++;
              delay(50);
            }
           if (digitalRead(minus)==HIGH){
              theta--;
              delay(50);
            }  
        }
        if (k==2){
         blinc("> Theta: "+(String)theta+" ", 500, 0, 0);
        }
      break;
      case 1:
        if((phi<=180) && (phi>=0)){  
          if (digitalRead(plus)==HIGH){         
              phi++;
              delay(50);
            }
           if (digitalRead(minus)==HIGH){
              phi--;
              delay(50);
           } 
        }
        if (k==2){
          blinc("> Phi: "+(String)phi+" ", 500, 0, 1);
        } 
     break;
    }
 
}
