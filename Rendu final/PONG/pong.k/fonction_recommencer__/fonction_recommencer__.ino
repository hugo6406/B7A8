void recommencer(){
    myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255,255,255);
  //myGLCD.print("Pong est l'un des premiers jeux d'arcade",LEFT,75);
  myGLCD.print("Jeu contre un bot",LEFT,100);
  myGLCD.print("Partie en 5 points",LEFT,125);
  delay(5000);
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  //Affichage du texte (ready,3,2,1)
  myGLCD.setColor(255,255,255);
   myGLCD.print("Ready",CENTER,110);
  delay(3000);
  myGLCD.clrScr();
  myGLCD.setColor(255,255,255);
  myGLCD.printNumI(3,CENTER,110);
  delay(1000);
  myGLCD.clrScr();
  myGLCD.printNumI(2,CENTER,110);
  delay(1000);
  myGLCD.clrScr();
  myGLCD.printNumI(1,CENTER,110);
  delay(1000);
  myGLCD.clrScr();
  myGLCD.setColor(255,255,255);
  randomSeed(analogRead(0));
     if(random(0,2)==1){
      balle_speedX = 3;
      balle_posY= 140;
       balle_finY = 150; 
     }
     else{
      balle_speedX = -3;
     }
     if(random(3,5)==4){
      balle_speedY = 3;
        balle_posY= 100;
       balle_finY = 110;
     }
     else{
      balle_speedY = -3;
     }
}
