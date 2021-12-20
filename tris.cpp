/*specification :
fonction : allumettes   inserer(allumettes, i,j)
parametres : VectAllumettes allumettes // vecteur des allumettes a trier
entier i // l'indice de l'allumette a inserer
entier j // l'indice auquel inserer l'allumette
resultats : VectAllumettes allumettes // vecteur apres l'insertion*/
#include <iostream>
#include "utils.h"
#include "tris_def.h"
#include <vector>
#include "affichage.h"

VecAllumette inserer(VecAllumette all, int i, int j){
  VecAllumette results;
  results.resize(all.size());
  for(int k=0;k<j;k++){
    results[k]=all[k];
  }
  results[j]=all[i];
  all.erase(all.begin()+i);
  for(int l=j+1;l<all.size();l++){
    results[l]=all[l-1];
  }
  return results;
}

/*variables locales
entiers i, j // indices du vecteur d'allumettes
debut
| pour i   1 a nbAllumettes-1 faire
| | // initialisation
| | j   0
| | tant que (j<i) et (allumettes(j).taille  allumettes(i).taille) faire
| | | j   j+1
| | fin tant que
| | // insertion de l'allumette au bon endroit
| | allumettes   inserer(allumettes,i,j)
| fin pour
fin*/

VecAllumette tri_insertion(int nbAllumettes, VecAllumette allumettes){
   init();
  for(int i=1;i<nbAllumettes;i++){
    int j=0;
    while(j<i && (allumettes[j].taille <=allumettes[i].taille)){
      j=j+1;
    }
   
    allumettes=inserer(allumettes,i,j);
    affiche(allumettes);
    
  }
  finish();
  return allumettes;
}
VecAllumette permute( VecAllumette &all, int i, int j){
  Allumette temp=all[i];
  all[i]=all[j];
  all[j]=temp;
  return all;
}


VecAllumette tri_bulle(int nbAllumettes, VecAllumette allumettes){
  init();
  int tmp;
  bool aucunEchange=false;
  while(!aucunEchange){
    aucunEchange=true;
    for(int j=0;j<nbAllumettes-1;j++){
      if(allumettes[j].taille>allumettes[j+1].taille){
        allumettes=permute(allumettes, j,j+1);
        affiche(allumettes);
        aucunEchange=false;
      }
      if(allumettes[j].taille==allumettes[j+1].taille && (allumettes[j].couleur>allumettes[j+1].couleur)){
        allumettes=permute(allumettes, j,j+1);
        affiche(allumettes);
        aucunEchange=false;
      }
    }
  }
  finish();
  return allumettes;
}







 Tri partition (VecAllumette arr, int low, int high)
{
    Tri result;
    int pivot = arr[high].taille;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].taille <= pivot)
        {
            i++;    // increment index of smaller element
            arr=permute(arr, i,j);
        }
    }
    arr=permute(arr, i+1,high);

    result.vec=arr;
    result.Number=i+1;
    return result;
}





VecAllumette tri_rapide( VecAllumette all, int low, int high){
  
    if (low < high)
    {

        int pi = partition(all, low, high).Number;
        all=partition(all, low, high).vec;


        all=tri_rapide(all, low, pi - 1);
        affiche(all);
    
        all=tri_rapide(all, pi + 1, high);
    }
return all;
}