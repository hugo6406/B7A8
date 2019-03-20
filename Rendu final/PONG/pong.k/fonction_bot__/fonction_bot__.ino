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
