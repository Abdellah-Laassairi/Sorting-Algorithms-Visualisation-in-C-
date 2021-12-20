#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib> 
#include "tris_def.h"
#include <string>
using namespace std;
#include <random>

using std::cout;
using std::endl;

constexpr int MIN_C = 0;
constexpr int MAX_C = 6;

constexpr int MIN_T = 1;
constexpr int MAX_T = 20;

VecAllumette stockdata(string nom)
{
   ifstream indata; // indata is like cin
   Allumette temp; 
   VecAllumette table;
  //string tempNbr
  //string tempTaille
  //string tempCol
   int i=0;
   indata.open(nom); // opens the file
   if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
   
   //getline(indata, tempNbr);
   int nbr;
   indata>>nbr;
   //cout<<"Nombre d'Allumettes"<<nbr<<endl;
   table.resize(nbr);
   while ( !indata.eof() ) {
    /*
      getline(indata, tempCol, ' ');
      getline(indata, tempTaille);
      temp.couleur=std::stoi(tempCol);
      temp.taille=std::stoi(tempTaille);
      cout<<"Couleur est : "<<tempCol<<endl;
      cout<<"Taille est : "<<tempTaille<<endl;
      table[i]=temp;
      */
      indata>>table[i].couleur;
      indata>>table[i].taille;
      //cout<<"Couleur est : "<<table[i].couleur<<endl;
      //cout<<"Taille est : "<<table[i].taille<<endl;
      i++;
   }
 
   indata.close();
   cout << "End-of-file reached.." << endl;

   return table;
}

void writedata(VecAllumette table)
{

  std::ofstream outfile ("Data.txt");

  outfile << table.size() <<endl;
  for(int i=0;i<table.size();i++){
    outfile << table[i].couleur<<" "; 
    outfile << table[i].taille<<endl;
  }
  outfile.close();

}

VecAllumette generationAleatoire(int Number){
    VecAllumette all;
    all.resize(Number);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr_c(MIN_C, MAX_C);
     std::uniform_int_distribution<int> distr_t(MIN_T, MAX_T);
    for (int n = 0; n < Number; ++n) {
        all[n].couleur= distr_c(eng);
        all[n].taille= distr_t(eng);
    }
    writedata(all);
    return all;
}