#ifndef TRIS_DEF_H_INCLUDED
#define TRIS_DEF_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

struct Allumette
{
    int couleur;
    int taille;
    
};

typedef vector<Allumette> VecAllumette;

struct Tri{
    VecAllumette vec;
    int Number;
    
};



#endif 