#ifndef TRIS_H_INCLUDED
#define TRIS_H_INCLUDED

#include <string>
#include <vector>
#include "tris_def.h"

VecAllumette inserer(VecAllumette all, int i, int j);
VecAllumette tri_insertion(int nbAllumettes, VecAllumette allumettes);
VecAllumette tri_bulle(int nbAllumettes, VecAllumette allumettes);
VecAllumette tri_rapide( VecAllumette all, int low, int high);

#endif