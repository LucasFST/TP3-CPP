/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
// Algorithme :
//
{
    for (unsigned int i = 0; i < tableauTrajets.GetCardActuelle(); i++)
    {
        tableauTrajets.GetTableau()[i]->Afficher();
    }
} //----- Fin de Méthode


void TrajetCompose::Saisir()
{
    string input;
    int nbTrajets = 0;
    bool isNumber = false;

    do
    {
        cout << "Veuillez saisir le nombre de trajets composites (nombre >= 2 et saisie dans l'ordre chronologique) :\r\n";
        cin >> input;

        // Vérifier si l'entrée est un nombre
        isNumber = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isNumber = false;
                break;
            }
        }

        if (isNumber)
        {
            nbTrajets = stoi(input);
        }
        else
        {
            cout << "Erreur : Veuillez saisir un nombre valide." << endl;
        }
    } while (!isNumber || nbTrajets < 2);

    // Saisie du premier trajet
    Trajet *trajetSimple = new TrajetSimple;
    cout << "Veuillez saisir le trajet composite n°1 :\r\n";
    trajetSimple->Saisir();
    tableauTrajets.Ajouter(trajetSimple);

    for (int i = 1; i < nbTrajets; i++)
    {
        Trajet *trajetSimple = new TrajetSimple;

        //! Vérifier si la ville de départ correspond à la ville d'arrivée du trajet précédent
        do
        {
            cout << "Veuillez saisir le trajet composite n°" << i + 1 << " (Attention, la ville de départ doit concorder avec la ville d'arrivée du trajet précédent) :\r\n";
            trajetSimple->Saisir();
        } while (strcmp(trajetSimple->GetVilleDepart(), tableauTrajets.GetTableau()[tableauTrajets.GetCardActuelle() - 1]->GetVilleArrivee()) != 0);
        tableauTrajets.Ajouter(trajetSimple);
    }

} //----- Fin de Méthode

void TrajetCompose::addTableau(TrajetSimple *ptrTrajet)
{
    this->tableauTrajets.Ajouter(ptrTrajet);
}

const char *TrajetCompose::GetVilleDepart() const
// Algorithme :
//
{
    return tableauTrajets.GetTableau()[0]->GetVilleDepart();
} //----- Fin de Méthode

const char *TrajetCompose::GetVilleArrivee() const
// Algorithme :
//
{
    return tableauTrajets.GetTableau()[tableauTrajets.GetCardActuelle() - 1]->GetVilleArrivee();
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
// TrajetCompose &TrajetCompose::operator=(const TrajetCompose &unTrajetCompose)
// // Algorithme :
// //
// {
// } //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
// TrajetCompose::TrajetCompose(const TrajetCompose &unTrajetCompose)
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
// #endif
// } //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose() : tableauTrajets(2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
