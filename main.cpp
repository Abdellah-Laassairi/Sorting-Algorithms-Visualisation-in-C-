#include <iostream>
#include "utils.h"
#include "tris_def.h"
#include <vector>
#include "affichage.h"
#include "tris.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std::chrono;
using namespace std;

int main() {
  //Lecture de fichier
  VecAllumette table;
  string nom="allumettes_donnees.txt";
  table=stockdata(nom);
  //writedata(table);
  VecAllumette test5=generationAleatoire(1000);
  //1iere Algorithme
  //VecAllumette test2=tri_insertion(40,  table);

  //2ieme algorithme
  //VecAllumette test3=tri_bulle(40,  table);



 
  VecAllumette allumette_random=generationAleatoire(100);

  auto start_i = high_resolution_clock::now();
  VecAllumette all1=tri_insertion(1000,allumette_random);
   auto stop_i = high_resolution_clock::now();
   auto duration_i = duration_cast<microseconds>(stop_i - start_i);
  cout << "temps d'execution Tri par insertion: "<< duration_i.count() << " microsecondes" << endl;

   auto start_b = high_resolution_clock::now();
   VecAllumette all2=tri_bulle(1000,allumette_random);
   auto stop_b = high_resolution_clock::now();
   auto duration_b = duration_cast<microseconds>(stop_b - start_b);
  cout << "temps d'execution Tri par bulle: "<< duration_b.count() << " microsecondes" << endl;
  
   //3ieme algorithme
  

   auto start_c = high_resolution_clock::now();
   VecAllumette all3=tri_rapide(allumette_random,0,999);
   auto stop_c = high_resolution_clock::now();
   auto duration_c = duration_cast<microseconds>(stop_c - start_c);
  cout << "temps d'execution Tri Rapide: "<< duration_c.count() << " microsecondes" << endl;

   auto start_d = high_resolution_clock::now();
   VecAllumette values=tri_rapide(allumette_random,0,1000);
   sort( values.begin( ), values.end( ), [ ]( const Allumette& lhs, const Allumette& rhs )
{
   return lhs.taille < rhs.taille;
});
   auto stop_d = high_resolution_clock::now();
   auto duration_d = duration_cast<microseconds>(stop_d - start_d);
  cout << "temps d'execution Sort: "<< duration_d.count() << " microsecondes" << endl;
  
}