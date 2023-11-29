/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
{
    if (villeDepart != NULL && villeArrivee != NULL)
    {
        cout << "De " << villeDepart << " à " << villeArrivee << " en ";
        switch (moyenTransport)
        {
        case AUTO:
            cout << "AUTO\r\n";
            break;
        case TRAIN:
            cout << "TRAIN\r\n";
            break;
        case BATEAU:
            cout << "BATEAU\r\n";
            break;
        case AVION:
            cout << "AVION\r\n";
            break;
        }
    }
    else
    {
        cout << "TrajetSimple non initialisé\r\n";
    }

} //----- Fin de Méthode

void TrajetSimple::ImporterTrajetSimple(const char *villeDepartTmp, const char *villeArriveeTmp, MoyenTransport moyenTransportTmp)
{
    if (this->villeDepart != NULL)
    {
        delete[] this->villeDepart;
    }
    this->villeDepart = new char[strlen(villeDepartTmp) + 1];
    strcpy(this->villeDepart, villeDepartTmp);

    if (this->villeArrivee != NULL)
    {
        delete[] this->villeArrivee;
    }
    this->villeArrivee = new char[strlen(villeArriveeTmp) + 1];
    strcpy(this->villeArrivee, villeArriveeTmp);

    this->moyenTransport = (MoyenTransport)moyenTransportTmp;
}

void TrajetSimple::Saisir()
{
    char *villeDepartTmp = new char[TAILLE_MAX_VILLE];
    cout << "Veuillez saisir la ville de depart :\r\n";
    cin >> villeDepartTmp;
    if (villeDepart != NULL)
    {
        delete[] villeDepart;
    }
    villeDepart = new char[strlen(villeDepartTmp) + 1];
    strcpy(villeDepart, villeDepartTmp);
    delete[] villeDepartTmp;

    char *villeArriveeTmp = new char[TAILLE_MAX_VILLE];
    cout << "Veuillez saisir la ville d'arrivee :\r\n";
    cin >> villeArriveeTmp;
    if (villeArrivee != NULL)
    {
        delete[] villeArrivee;
    }
    villeArrivee = new char[strlen(villeArriveeTmp) + 1];
    strcpy(villeArrivee, villeArriveeTmp);
    delete[] villeArriveeTmp;

    int moyenTransportTmp;
    do
    {
        cout << "Veuillez saisir le moyen de transport : (0 : AUTO, 1 : TRAIN, 2 : BATEAU, 3 : AVION)\r\n";
        cin >> moyenTransportTmp;
    } while (moyenTransportTmp < 0 || moyenTransportTmp > 3);
    moyenTransport = (MoyenTransport)moyenTransportTmp;

} //----- Fin de Méthode

const char *TrajetSimple::GetVilleDepart() const
{
    return villeDepart;
}

const char *TrajetSimple::GetVilleArrivee() const
{
    return villeArrivee;
}

// //------------------------------------------------- Surcharge d'opérateurs
// TrajetSimple &TrajetSimple::operator=(const TrajetSimple &unTrajetSimple)
// // Algorithme :
// //
// {
// } //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple &unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

    villeDepart = new char[strlen(unTrajetSimple.villeDepart) + 1];
    strcpy(villeDepart, unTrajetSimple.villeDepart);

    villeArrivee = new char[strlen(unTrajetSimple.villeArrivee) + 1];
    strcpy(villeArrivee, unTrajetSimple.villeArrivee);

    moyenTransport = unTrajetSimple.moyenTransport;

} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    villeDepart = NULL;
    villeArrivee = NULL;
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    if (villeDepart != NULL)
    {
        delete[] villeDepart;
        villeDepart = NULL;
    }
    if (villeArrivee != NULL)
    {
        delete[] villeArrivee;
        villeArrivee = NULL;
    }
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
