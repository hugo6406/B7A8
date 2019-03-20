void verification(){    
//Arret du jeu si la raquette2 ne la renvoie pas
  if(balle_finX >=319){
    a=0;
    j=j+1;
    delay(20);
    balle_posX=155;
    balle_posY=120+random(0,31);
    balle_finX=165;
    balle_finY=balle_posY+10;
    delay(20);
    raquette2_posX = 318;
    raquette2_posY = 100;
    raquette2_finX = 315;
    raquette2_finY = 140;
    raquette_posX = 1;
    raquette_posY = 100;
    raquette_finX = 4;
    raquette_finY = 140;
    raquette_speed=0;
     delay(2000);
     balle_speedX = random(0,2);
     balle_speedY = random(3,5);
     if(random(0,2)==1){
      balle_speedX = 3;
     }
     else{
      balle_speedX = -3;
     }
     if(random(3,5)==4){
      balle_speedY = 3;
     }
     else{
      balle_speedY = -3;
     }
     i=0;
     
     
     
  }
  //Arret du jeu si le joueur ne la renvoie pas
  if(balle_posX <=0){
    a=0;
    i=i+1;
    k=k+1;
    delay(20);
    balle_posX=155;
    balle_posY=120+random(0,31);
    balle_finX=165;
    balle_finY=balle_posY+10;
    delay(20);
    raquette2_posX = 318;
    raquette2_posY = 100;
    raquette2_finX = 315;
    raquette2_finY = 140;
    raquette_posX = 1;
    raquette_posY = 100;
    raquette_finX = 4;
    raquette_finY = 140;
    raquette_speed=0;
     delay(2000);
    // balle_speedX = random(0,2);
    balle_speedX = random(0,2);
     balle_speedY = random(0,2);
     if(random(0,2)==1){
      //balle_speedX = 1;
      balle_speedY = 3;
      balle_speedX = 3;
      
     }
     else{
      balle_speedY = -3;
      balle_speedX = -3;
     }
     i=0;
   
  }
  //Rebond en bas
  if(balle_finY >=237){
    balle_speedY = -balle_speedY;
    
    
  }
  //Rebond en haut
  if(balle_posY <=3){
    balle_speedY = -balle_speedY;
    
  }
  //Rebond sur la raquette1
  if(balle_posX<=(raquette_finX +1) and balle_posY<=raquette_finY and balle_posY >=raquette_posY){
    balle_speedX = 3;
    digitalWrite(buz,HIGH);
    delay(10);
    digitalWrite(buz,LOW);
    
    }
  //Rebond sur la raquette2
  if(balle_finX>=(raquette2_finX -1) and balle_posY<=raquette2_finY and balle_posY >=raquette2_posY){
    balle_speedX = -3;
    
  }
}
