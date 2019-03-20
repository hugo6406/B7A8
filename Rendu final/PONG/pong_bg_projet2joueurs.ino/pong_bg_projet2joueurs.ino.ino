#include <memorysaver.h>
#include <UTFT.h>
int balle_posX = 160;
int balle_posY = 120;
int balle_speedX= random(0,2);
int balle_speedY =random(3,5) ;
int balle_finX = 170;
int balle_finY = 130;
int raquette_posX = 1;
int raquette_posY = 100;
int raquette2_posX = 318;
int raquette2_posY = 100;
int raquette2_finX = 315;
int raquette2_finY = 140;
int raquette_finX= 4;
int raquette_finY = 140;
int raquette2_speed=0;
int raquette_speed=0;
UTFT myGLCD(SSD1289,38,39,40,41);
const int button = 8 ;
boolean debut;
int i=0;
char score;
//Déclaration des polices d'écritures
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
int j=0;
int k=0;
boolean t;
const int bouton1blanc=8;
const int bouton2blanc=9;
const int bouton1noir=12;
const int bouton2noir=13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
      myGLCD.InitLCD();
      myGLCD.clrScr();
      myGLCD.setFont(BigFont);
  //Affichage des règles du jeu
  myGLCD.setColor(255,255,255);
  myGLCD.print("JEU PONG",CENTER,25);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Partie en 7 points",CENTER,125);
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
  //myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
  //Serial.begin(9600);
  randomSeed(analogRead(0));
     if(random(0,2)==1){
      balle_speedX = 2;
      balle_posY= 140;
       balle_finY = 150; 
     }
     else{
      balle_speedX = -2;
     }
     if(random(3,5)==4){
      balle_speedY = 2;
        balle_posY= 100;
       balle_finY = 110;
     }
     else{
      balle_speedY = -2;
     }
  
  pinMode(bouton1blanc,INPUT);
  pinMode(bouton2blanc,INPUT);
  pinMode(bouton1noir,INPUT);
  pinMode(bouton2noir,INPUT);
  
  
  
 
 
  
}

void loop() {
  // put your main code here, to run repeatedly:

verification();
joueur1();
joueur2();
affichage();

}
   
  void verification(){ 
//Arret du jeu
  if(balle_finX >=319){
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
    raquette2_speed=0;
     delay(2000);
     balle_speedX = random(0,2);
     balle_speedY = random(3,5);
     if(random(0,2)==1){
      balle_speedX = 2;
     }
     else{
      balle_speedX = -2;
     }
     if(random(3,5)==4){
      balle_speedY = 2;
     }
     else{
      balle_speedY = -2;
     }
     i=0;
     
     
     
  }
  //Arret du jeu
  if(balle_posX <=0){
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
    raquette2_speed=0;
     delay(2000);
    // balle_speedX = random(0,2);
    balle_speedX = random(0,2);
     balle_speedY = random(0,2);
     if(random(0,2)==1){
      //balle_speedX = 1;
      balle_speedY = 2;
      balle_speedX = 2;
      
     }
     else{
      balle_speedY = -2;
      balle_speedX = -2;
     }
     i=0;
   
  }
  //Rebond en bas
  if(balle_finY >=238){
    balle_speedY = -balle_speedY;
    
    
  }
  //Rebond en haut
  if(balle_posY <=1){
    balle_speedY = -balle_speedY;
    
  }
  //Rebond sur la raquette 1
  if(balle_posX<=(raquette_finX +1) and balle_posY<=raquette_finY and balle_posY >=raquette_posY){
    balle_speedX = 2;
    
  }
  //Rebond sur la raquette 2
  if(balle_finX>=(raquette2_finX -1) and balle_posY<=raquette2_finY and balle_posY >=raquette2_posY){
    balle_speedX = -2;
    
  }

}
  void joueur2(){
    
  
  if(digitalRead(bouton1noir)==LOW){                    //la raquette monte
    raquette2_speed=-3;
    
   }
   else if(digitalRead(bouton2noir)==LOW){              //La raquette descend
    raquette2_speed=3;
     
   }
   else{              //Si on appuie pas la raquette ne bouge pas
    raquette2_speed=0;
   }
   if(raquette2_posY<=2){//Si la raquette est trop haute
    raquette2_speed=0;
    //Lorsque la raquette 1 est en haut on peut repartir vers le bas
    for(i=0;i<238;i++){
      if(digitalRead(bouton2noir)==LOW){
        raquette2_speed=2;
        break;
      }
    }
    
    }
    
  if(raquette2_finY>=238){//Si la raquette est trop basse
    raquette2_speed=0;
    //Lorsque la raquette 1 est en bas on peut repartir vers le haut
    for(i=0;i<238;i++){
      if(digitalRead(bouton1noir)==LOW){
        raquette2_speed=-2;
        break;
    }
    }
  }
  }


 
 void joueur1(){
   //Contrôle de deux boutons pour pouvoir faire se déplacer la raquette de gauche
   if(digitalRead(bouton1blanc)==LOW){                    //la raquette monte
    raquette_speed=-3;
    
   }
   else if(digitalRead(bouton2blanc)==LOW){              //La raquette descend
    raquette_speed=3;
     
   }
   else{              //Si on appuie pas la raquette ne bouge pas
    raquette_speed=0;
   }
   if(raquette_posY<=2){//Si la raquette est trop haute
    raquette_speed=0;
    //Lorsque la raquette 1 est en haut on peut repartir vers le bas
    for(i=0;i<238;i++){
      if(digitalRead(bouton2blanc)==LOW){
        raquette_speed=2;
        break;
      }
    }
    
    }
    
  if(raquette_finY>=238){//Si la raquette est trop basse
    raquette_speed=0;
    //Lorsque la raquette 1 est en bas on peut repartir vers le haut
    for(i=0;i<238;i++){
      if(digitalRead(bouton1blanc)==LOW){
        raquette_speed=-2;
        break;
    }
    }
  }
 }

   
  
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

  if (j ==7 or k==7){
  j=0;
  k=0;
  son();
  myGLCD.clrScr();
  while(((digitalRead(bouton1blanc)==!LOW)and(digitalRead(bouton2blanc)==!LOW))and((digitalRead(bouton1noir)==!LOW)and(digitalRead(bouton2noir)==!LOW))){
    myGLCD.setFont(SmallFont);
    myGLCD.print("appuyez chacun sur un bouton",CENTER,100);
    }
   recommencer();
  
  }

}
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
void son(){
  
 
sing();

 

}
void sing() {

    #define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 11
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
 
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
};
    
    Serial.println(" 'Underworld Theme'");
    for (int thisNote = 0; thisNote < 30; thisNote++) {
 
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(melodyPin, underworld_melody[thisNote], noteDuration);
 
     
      int pauseBetweenNotes = noteDuration * 1.10;
      delay(pauseBetweenNotes);
 
      buzz(melodyPin, 0, noteDuration);
 
    }
 
  }
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
 
}


   
   
