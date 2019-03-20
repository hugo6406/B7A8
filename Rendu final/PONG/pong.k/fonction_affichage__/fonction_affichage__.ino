void affichage(){
   balle_posX = balle_posX + balle_speedX;
  balle_posY = balle_posY + balle_speedY;
  balle_finX = balle_finX + balle_speedX;
  balle_finY = balle_finY + balle_speedY;
  raquette2_posY = raquette2_posY + raquette2_speed;
  raquette2_finY = raquette2_finY + raquette2_speed;
  raquette_posY = raquette_posY + raquette_speed;
  raquette_finY = raquette_finY + raquette_speed;
  myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
  myGLCD.fillRect(raquette2_posX, raquette2_posY,raquette2_finX, raquette2_finY);
  myGLCD.fillRect(balle_posX, balle_posY, balle_finX, balle_finY);
  //myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
  
   myGLCD.setColor(0,0,0);
   delay(15);
     myGLCD.fillRect(raquette2_posX, raquette2_posY,raquette2_finX, raquette2_finY);
    myGLCD.fillRect(balle_posX, balle_posY, balle_finX, balle_finY);
     myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY); 
   delay(10);
  



   
   //Affichage du score
   myGLCD.setColor(255,255,255);
   myGLCD.printNumI(j,110,25);
   myGLCD.printNumI(k,191,25);
    //décor milieu
   myGLCD.setColor(255,255,255);
   myGLCD.fillRect(158,0,161,10);
  myGLCD.fillRect(158,20,161,30);
  myGLCD.fillRect(158,40,161,50);
  myGLCD.fillRect(158,60,161,70);
  myGLCD.fillRect(158,80,161,90);
  myGLCD.fillRect(158,100,161,110);
  myGLCD.fillRect(158,120,161,130);
  myGLCD.fillRect(158,140,161,150);
  myGLCD.fillRect(158,160,161,170);
  myGLCD.fillRect(158,180,161,190);
  myGLCD.fillRect(158,200,161,210);
  myGLCD.fillRect(158,220,161,230);

if (j == 5 or k==5){
  j=0;
  k=0;
  myGLCD.clrScr();
  while((digitalRead(bouton1blanc)==!LOW)and(digitalRead(bouton2blanc)==!LOW)){
    myGLCD.setFont(SmallFont);
    myGLCD.print("appuyez sur un bouton",CENTER,100);
    }
   recommencer();
  
}
}
