/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <limits>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::SaisirTrajetSimple()
// Algorithme :
//
{
    Trajet *ptrTrajet;
    ptrTrajet = new TrajetSimple;
    ptrTrajet->Saisir();
    collection.Ajouter(ptrTrajet);
} //----- Fin de Méthode

void Catalogue::SaisirTrajetCompose()
// Algorithme :
//
{
    Trajet *ptrTrajet;
    ptrTrajet = new TrajetCompose;
    ptrTrajet->Saisir();
    collection.Ajouter(ptrTrajet);
} //----- Fin de Méthode

void Catalogue::Afficher() const
// Algorithme :
//
{
    if (collection.GetCardActuelle() == 0)
    {
        cout << "Le catalogue est vide\r\n";
    }
    else
    {
        cout << "Voici les trajets du catalogue :\r\n\r\n";
        for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
        {
            cout << "Trajet n°" << i + 1 << " : \r\n";
            collection.GetTableau()[i]->Afficher();
            cout << "\r\n";
        }
    }
} //----- Fin de Méthode

void Catalogue::RechercherTrajet() const
{
    if (collection.GetCardActuelle() == 0)
    {
        cout << "Le catalogue est vide\r\n";
    }
    else
    {
        char *villeDepart = new char[TAILLE_MAX_VILLE];
        char *villeArrivee = new char[TAILLE_MAX_VILLE];

        cout << "Veuillez saisir la ville de départ de votre voyage:\r\n";
        cin >> villeDepart;
        cout << "Veuillez saisir la ville d'arrivée de votre voyage:\r\n";
        cin >> villeArrivee;

        cout << "\r\nVoici les trajets correspondants à votre recherche :\r\n\r\n";
        for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
        {
            if (strcmp(collection.GetTableau()[i]->GetVilleDepart(), villeDepart) == 0 && strcmp(collection.GetTableau()[i]->GetVilleArrivee(), villeArrivee) == 0)
            {
                cout << "Trajet n°" << i + 1 << " : \r\n";
                collection.GetTableau()[i]->Afficher();
                cout << "\r\n";
            }
        }

        delete[] villeDepart;
        delete[] villeArrivee;
    }
}

// void Catalogue::RechercherTrajet() const
// {
//     if (collection.GetCardActuelle() == 0)
//     {
//         cout << "Le catalogue est vide\r\n";
//     }
//     else
//     {
//         string villeDepart;
//         string villeArrivee;

//         cout << "Veuillez saisir la ville de départ de votre voyage:\r\n";
//         cin >> villeDepart;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer le reste de la ligne

//         cout << "Veuillez saisir la ville d'arrivée de votre voyage:\r\n";
//         cin >> villeArrivee;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer le reste de la ligne

//         // Vérifier que les caractères saisis sont valides
//         bool isVilleDepartValid = true;
//         bool isVilleArriveeValid = true;

//         for (char c : villeDepart)
//         {
//             if (!isalpha(c) && c != '-' && c != '\'')
//             {
//                 isVilleDepartValid = false;
//                 break;
//             }
//         }

//         for (char c : villeArrivee)
//         {
//             if (!isalpha(c) && c != '-' && c != '\'')
//             {
//                 isVilleArriveeValid = false;
//                 break;
//             }
//         }

//         if (!isVilleDepartValid || !isVilleArriveeValid)
//         {
//             cout << "La saisie des villes est invalide. Veuillez entrer uniquement des lettres, des tirets '-' et des apostrophes '\''." << endl;
//             return;
//         }

//         cout << "\r\nVoici les trajets correspondants à votre recherche :\r\n\r\n";
//         for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
//         {
//             if (collection.GetTableau()[i]->GetVilleDepart() == villeDepart && collection.GetTableau()[i]->GetVilleArrivee() == villeArrivee)
//             {
//                 cout << "Trajet n°" << i + 1 << " : \r\n";
//                 collection.GetTableau()[i]->Afficher();
//                 cout << "\r\n";
//             }
//         }
//     }
// }



void Catalogue::Menu()
{
    int choix;
    do
    {
        cout << "\r\n#####################################################################################################\r\n";
        cout << "Bienvenue dans le menu du catalogue de voyages !\r\n";
        cout << "1. Afficher les trajets du catalogue\r\n";
        cout << "2. Rechercher des itinéraires disponibles\r\n";
        cout << "3. Ajouter un trajet simple\r\n";
        cout << "4. Ajouter un trajet composé (trajet non direct, composé de plusieurs étapes)\r\n";
        cout << "5. Quitter\r\n";
        cout << "#####################################################################################################\r\n";
        
        if (!(cin >> choix))
        {
            cout << "\r\n";
            cout << "Veuillez entrer un nombre. Saisie annulée.\r\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        switch (choix)
        {
        case 1:
            cout << "\r\n";
            Afficher();
            break;
        case 2:
            cout << "\r\n";
            RechercherTrajet();
            break;
        case 3:
            cout << "\r\n";
            SaisirTrajetSimple();
            break;
        case 4:
            cout << "\r\n";
            SaisirTrajetCompose();
            break;
        case 5:
            cout << "\r\n";
            cout << "Au revoir !\r\n";
            break;
        default:
            cout << "\r\n";
            cout << "Veuillez entrer un nombre entre 1 et 5\r\n";
            break;
        }
    } while (choix != 5);
}



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
// Catalogue::Catalogue(const Catalogue &unCatalogue)
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Catalogue>" << endl;
// #endif
// } //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
