void recommencer(){
  if(digitalRead(bouton1blanc)==LOW or digitalRead(bouton2blanc)==LOW ){   
    for (int i = 0; i<nb_bloc_ligne; i+=1){
      for (int j = 0; j<nb_bloc_ligne; j+=1){
        blocs[j][i]=1;
      }}
      }
}
