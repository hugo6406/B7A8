#include <memorysaver.h>
#include <UTFT.h>
const int buz= 11;
//Paramètres balle
int balle_posX = 160;
int balle_posY = 120;
int balle_speedX= random(0,2);
int balle_speedY =random(3,5) ;
int balle_finX = 170;
int balle_finY = 130;
//Paramètres raquette1
int raquette_posX = 1;
int raquette_posY = 100;
int raquette_finX= 4;
int raquette_finY = 140;
int raquette_speed=0;
//Paramètres raquette2
int raquette2_posX = 318;
int raquette2_posY = 100;
int raquette2_finX = 315;
int raquette2_finY = 140;
int raquette2_speed=1;
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
int a=0;
char Data;
long bouton1;
long bouton2;


void setup() {
  // put your setup code here, to run once:
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  //Affichage des règles du jeu
  myGLCD.setColor(255,255,255);
  myGLCD.print("JEU PONG",CENTER,25);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Jeu contre un bot",CENTER,100);
  myGLCD.print("Partie en 5 points",CENTER,125);
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
  
  pinMode(bouton1blanc,INPUT);
  pinMode(bouton2blanc,INPUT);
  pinMode(buz,OUTPUT);
  
}
boolean newgame=false;
void loop() {
  // put your main code here, to run repeatedly:
  if(newgame){
verification();
bot();

controle_raquette();
affichage();
  }
else{
      while(Serial3.available()){
        Data = Serial3.read();
        Serial.print(Data);
        if(Data=='N') {
        newgame=true;
    }
      
    }
}

} 

/*void bluetooth(){
    while(Serial3.available()){
    Data = Serial3.read();
    Serial.print(Data);
    Serial.print("ok");
    if(Data=='M') {
      bouton2 = Serial3.parseInt();
      
    }
    if (Data=='N') {
      bouton1 = Serial3.parseInt();
    }
  }
    if (bouton1 == 1) {
    raquette_speed=-3;
    
  }

  if (bouton2 == 1) {
    raquette_speed=3;
 
}
 Serial.println(bouton1 + " " + bouton2);
 
}*/

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
void bot(){
  //Création du BOT
  if (((balle_posY+balle_finY)/2)>raquette2_finY + (raquette2_posY - raquette2_finY) / 2 &&random(0,2)==1) {  // Si la balle est plus basse que le centre
    raquette2_speed = 3;
    // Se déplacer vers le bas
  } 
  else if (((balle_posY+balle_finY)/2) < raquette2_finY + (raquette2_posY - raquette2_finY) / 2 &&random(0,2)==1) {  // Si la balle est plus haute que le centre
    raquette2_speed =-3;
  }
  if (((balle_posY+balle_finY)/2)>=214 ){
    raquette2_speed = 0;
    if(random(0,2)==1){
      raquette2_speed = -2;
    }
  }
  if(((balle_posY+balle_finY)/2)<=24 ){
    raquette2_speed = 0;
     if(random(0,2)==1){
      raquette2_speed = 2;
     }
  }
}

 
 void controle_raquette(){
   //Contrôle de deux boutons pour pouvoir faire se déplacer la raquette de gauche
   if(digitalRead(bouton1blanc)==LOW){                    //la raquette monte
    raquette_speed=-4;
    
   }
   else if(digitalRead(bouton2blanc)==LOW){              //La raquette descend
    raquette_speed=4;
     
   }
   else{              //Si on appuie pas la raquette ne bouge pas
    raquette_speed=0;
   }
   if(raquette_posY<=5){//Si la raquette est trop haute
    raquette_speed=0;
    //Lorsque la raquette 1 est en haut on peut repartir vers le bas
    for(i=0;i<238;i++){
      if(digitalRead(bouton2blanc)==LOW){
        raquette_speed=4;
        break;
      }
    }
    
    }
    
  if(raquette_finY>=236){//Si la raquette est trop basse
    raquette_speed=0;
    //Lorsque la raquette 1 est en bas on peut repartir vers le haut
    for(i=0;i<238;i++){
      if(digitalRead(bouton1blanc)==LOW){
        raquette_speed=-4;
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


   
