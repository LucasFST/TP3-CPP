/*************************************************************************
                           TTrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TTrajetCompose> (fichier TTrajetCompose.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TTrajetCompose.h"
#include "../TrajetCompose.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
// static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom

int main()
{
    TrajetCompose t;
    t.Saisir();
    t.Afficher();
    const char *villeDepart = t.GetVilleDepart();
    const char *villeArrivee = t.GetVilleArrivee();
    cout << "Ville de départ : " << villeDepart << endl;
    cout << "Ville d'arrivée : " << villeArrivee << endl;
    return 0;
}