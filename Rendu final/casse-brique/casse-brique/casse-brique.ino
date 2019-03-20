#include <memorysaver.h>
#include <UTFT.h>
int balle_posX = 160;
int balle_posY = 120;
int balle_speedX=3 ;
int balle_speedY =3 ;
int balle_finX = 170;
int balle_finY = 130;
int raquette_posX =140 ;
int raquette_posY = 232;
int raquette_finX= 180;
int raquette_finY = 237;
int raquette_speed=0;
UTFT myGLCD(SSD1289,38,39,40,41);
int i=0;
//Déclaration des polices d'écritures
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
const int nb_bloc_ligne = 8;
int blocs[nb_bloc_ligne][nb_bloc_ligne];
const int bloc_largeur =320/nb_bloc_ligne -5; 
const int bloc_hauteur = 10;
const int bouton1blanc = 9;
const int bouton2blanc = 8;
//Arduino pin numbers
const int SW_pin = 12; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output





void setup() {
  // put your setup code here, to run once:
   myGLCD.InitLCD();
      myGLCD.clrScr();
      myGLCD.setFont(SmallFont);
      pinMode(SW_pin, INPUT);
      pinMode(bouton1blanc, INPUT);
      pinMode(bouton2blanc, INPUT);
  digitalWrite(SW_pin, HIGH);
      
      for (int i = 0; i<nb_bloc_ligne; i+=1){
    for (int j = 0; j<nb_bloc_ligne; j+=1){
    blocs[j][i]=1;
}}
pinMode(bouton1blanc,INPUT);
  pinMode(bouton2blanc,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:



controle_raquette();

if(balle_finY >=238){
    balle_speedY = -3;
}
  if(balle_finX >=319){
    balle_speedX=-3;
     
     
     
  }
  //Arret du jeu
  if(balle_posX <=0){
    balle_speedX=3;
  }
  if(balle_posY <=0){
    balle_speedY=3;
  }


   
  if(balle_finX>=(raquette_finX +1) and balle_finY>=raquette_posY and balle_posX <=raquette_posX){
    balle_speedY = -3;
  }
  
    for (int ligne = 0; ligne<nb_bloc_ligne; ligne+=1){
      for (int colonne = 0; colonne<nb_bloc_ligne; colonne+=1){
      if(blocs[ligne][colonne]==1){
        
      int bloc_posX= colonne*(bloc_largeur+5)+1;
      int bloc_posY = ligne*(bloc_hauteur+4)+3;
      int bloc_finX=bloc_posX+bloc_largeur;
      int bloc_finY=bloc_posY+bloc_hauteur;
    if(balle_finX<=bloc_finX and balle_posX >=bloc_posX and (balle_posY<(bloc_finY-1)and balle_finY>(bloc_posY+1))){
        balle_speedY=-balle_speedY;
        blocs[ligne][colonne]=0;
      }
      boolean blocss=false;
      for(int k=0;k<nb_bloc_ligne;k+=1){
        for(int l=0;l<nb_bloc_ligne;l+=1){
        if(blocs[l][k]==0){
          blocss=true;
        }
       }}
       if(blocss==false){
          myGLCD.clrScr();
          myGLCD.setColor(255,255,255);
          myGLCD.print("Appuyez sur un bouton pour rejouer",CENTER,25);
          delay(5000);
          myGLCD.clrScr();
          recommencer();
       }}}}
    for (int ligne = 0; ligne<nb_bloc_ligne; ligne+=1){
      for (int colonne = 0; colonne<nb_bloc_ligne; colonne+=1){
      int bloc_posX= colonne*(bloc_largeur+5)+3;
      int bloc_posY = ligne*(bloc_hauteur+4)+3;
      int bloc_finX=bloc_posX+bloc_largeur;
      int bloc_finY=bloc_posY+bloc_hauteur;
    if(blocs[ligne][colonne]==1){
       myGLCD.setColor(ligne*colonne+100,255-ligne*31,255-colonne*31);  
       myGLCD.fillRect(bloc_posX,bloc_posY,bloc_finX,bloc_finY);
    }
    else{
    myGLCD.setColor(0,0,0);
      
      myGLCD.fillRect(bloc_posX,bloc_posY,bloc_finX,bloc_finY);
      delay(10);
    }}}

//mouvement_raquette();



  
  myGLCD.setColor(255,255,255);
  balle_posX = balle_posX + balle_speedX;
  balle_posY = balle_posY + balle_speedY;
  balle_finX = balle_finX + balle_speedX;
  balle_finY = balle_finY + balle_speedY;
  raquette_posX= raquette_posX + raquette_speed;
  raquette_finX= raquette_finX + raquette_speed;
   myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
  myGLCD.fillRect(balle_posX, balle_posY, balle_finX, balle_finY);
  delay(30);
  myGLCD.setColor(0,0,0);
  //delay(2);
  myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
  myGLCD.fillRect(balle_posX, balle_posY, balle_finX, balle_finY);
  //myGLCD.fillRect(raquette_posX, raquette_posY,raquette_finX, raquette_finY);
 delay(5);

}
void recommencer(){
  if(digitalRead(bouton1blanc)==LOW or digitalRead(bouton2blanc)==LOW ){   
    for (int i = 0; i<nb_bloc_ligne; i+=1){
      for (int j = 0; j<nb_bloc_ligne; j+=1){
        blocs[j][i]=1;
      }}
      }
      }
/*void mouvement_raquette(){
  if(analogRead(X_pin)>=750){                    //la raquette monte
    raquette_speed=-3;
    
   }
   else if(analogRead(Y_pin)>=750){              //La raquette descend
    raquette_speed=3;
     
   }
   else{              //Si on appuie pas la raquette ne bouge pas
    raquette_speed=0;
   }
   if(raquette_posX<=3){//Si la raquette est trop haute
    raquette_speed=0;
    //Lorsque la raquette 1 est en haut on peut repartir vers le bas
    for(i=0;i<318;i++){
      if(analogRead(X_pin)>=750){
        raquette_speed=2;
        break;
      }
    }
    
    }
    
  if(raquette_finX>=317){//Si la raquette est trop basse
    raquette_speed=0;
    //Lorsque la raquette 1 est en bas on peut repartir vers le haut
    for(i=0;i<318;i++){
      if(digitalRead(bouton1blanc)==LOW){
        raquette_speed=-2;
        break;
    }
    }
    delay(5);
  }
  delay(5);}*/

  void controle_raquette(){
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
   if(raquette_posX<=2){//Si la raquette est trop haute
    raquette_speed=0;
    //Lorsque la raquette 1 est en haut on peut repartir vers le bas
    for(i=0;i<318;i++){
      if(digitalRead(bouton2blanc)==LOW){
        raquette_speed=2;
        break;
      }
    }
    
    }
    
  if(raquette_finX>=238){//Si la raquette est trop basse
    raquette_speed=0;
    //Lorsque la raquette 1 est en bas on peut repartir vers le haut
    for(i=0;i<318;i++){
      if(digitalRead(bouton1blanc)==LOW){
        raquette_speed=-2;
        break;
    }
    }
  }
  }
