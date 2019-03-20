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
