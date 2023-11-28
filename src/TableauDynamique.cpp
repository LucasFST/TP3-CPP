/*************************************************************************
                           TableauDynamique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TableauDynamique> (fichier TableauDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TableauDynamique.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TableauDynamique::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

unsigned int TableauDynamique::GetCardActuelle() const
// Algorithme :
//
{
    return cardActuelle;
} //----- Fin de Méthode

unsigned int TableauDynamique::GetCardMax() const
// Algorithme :
//
{
    return cardMax;
} //----- Fin de Méthode

Trajet **TableauDynamique::GetTableau() const
// Algorithme :
//
{
    return tableau;
} //----- Fin de Méthode

void TableauDynamique::Ajouter(Trajet *unTrajet)
// Algorithme :
//
{
    if (cardActuelle < cardMax)
    {
        tableau[cardActuelle] = unTrajet;
        cardActuelle++;
    }
    else
    {
        Trajet **nouveauTableau = new Trajet *[cardMax * 2];
        cardMax *= 2;
        for (unsigned int i = 0; i < cardActuelle; i++)
        {
            nouveauTableau[i] = tableau[i];
            tableau[i] = NULL;
        }
        nouveauTableau[cardActuelle] = unTrajet;
        cardActuelle++;
        delete[] tableau;
        tableau = nouveauTableau;
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
// TableauDynamique::TableauDynamique(const TableauDynamique &unTableauDynamique)
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <TableauDynamique>" << endl;
// #endif
// } //----- Fin de TableauDynamique (constructeur de copie)

TableauDynamique::TableauDynamique(unsigned int cardinaliteMax)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif
    cardMax = cardinaliteMax;
    cardActuelle = 0;
    tableau = new Trajet *[cardinaliteMax];
} //----- Fin de TableauDynamique

TableauDynamique::~TableauDynamique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif
    for (unsigned int i = 0; i < cardActuelle; i++)
    {
        delete tableau[i];
        tableau[i] = NULL;
    }
    delete[] tableau;
    tableau = NULL;
} //----- Fin de ~TableauDynamique

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
