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
