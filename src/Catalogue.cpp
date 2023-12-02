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
#include <fstream>
#include <sstream>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Menu()
{
    // menu textuel avec les fonctionnalités représentées par des chiffres
    int choix;
    do
    {
        cout << "\r\n#####################################################################################################\r\n";
        cout << "Bienvenue dans le menu du catalogue de voyages !\r\n";
        cout << "1. Afficher les trajets du catalogue\r\n";
        cout << "2. Rechercher des itinéraires disponibles\r\n";
        cout << "3. Ajouter un trajet simple\r\n";
        cout << "4. Ajouter un trajet composé (trajet non direct, composé de différentes étapes)\r\n";
        cout << "5. Importer des trajets depuis un fichier txt\r\n";
        cout << "6. Sauvegarder des trajets du catalogue dans un fichier txt\r\n";
        cout << "7. Quitter\r\n";
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
            // ImporterTrajets("txt/test.txt", TypeTrajet::COMPOSE);
            ImporterTrajetsParVille("txt/test.txt", ParVille::DEPART, "Nantes");
            break;
        case 6:
            cout << "\r\n";
            SauvegarderTrajetsMenu();
            break;
        case 7:
            cout << "\r\n";
            cout << "Au revoir !\r\n";
            break;
        default:
            cout << "\r\n";
            cout << "Veuillez saisir un chiffre entre 1 et 7\r\n";
            break;
        }
    } while (choix != 7);
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

bool Catalogue::VerifierNomFichierSauvegarde(string nomFichier) const
{
    // Vérifier si le nom du fichier contient un slash
    if (nomFichier.find("/") != string::npos || nomFichier.find("\\") != string::npos)
    {
        cout << "Erreur : le nom du fichier ne doit pas contenir de slash.\r\n";
        return false;
    }

    // Si le fichier existe déjà, demander à l'utilisateur s'il souhaite l'écraser
    ifstream fichierExist("txt/" + nomFichier + ".txt");
    if (fichierExist)
    {
        int reponse;
        fichierExist.close();
        do
        {
            cout << "Le fichier existe déjà. Voulez-vous l'écraser ? (1 : OUI, 0 : NON)\r\n";
            cin >> reponse;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
                reponse = -1;
                cout << "Erreur : Veuillez saisir un nombre valide." << endl;
            }
        } while (reponse != 0 && reponse != 1);

        if (!reponse)
        {
            cout << "Sauvegarde annulée.\r\n";
        }
        return reponse;
    }
    return true;
}

//----------------------------------------------------- Méthodes protégées

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

void Catalogue::SauvegarderTrajetsMenu() const
{
    int choix;
    do
    {
        cout << endl
             << "#####################################################################################################\r\n";
        cout << "Bienvenue dans le menu de sauvegarde des trajets du catalogue !\r\n";
        cout << "1. Sauvegarder tous les trajets du catalogue\r\n";
        cout << "2. Sauvegarder seulement les trajets simples du catalogue\r\n";
        cout << "3. Sauvegarder seulement les trajets composés du catalogue\r\n";
        cout << "4. Sauvegarder les trajets du catalogue par ville de départ\r\n";
        cout << "5. Sauvegarder les trajets du catalogue par ville d'arrivée\r\n";
        cout << "6. Sauvegarder les trajets du catalogue par ville de départ et d'arrivée\r\n";
        cout << "7. Quitter\r\n";
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
            SauvegarderTrajetsParType(TypeTrajet::TOUS);
            break;
        case 2:
            cout << "\r\n";
            SauvegarderTrajetsParType(TypeTrajet::SIMPLE);
            break;
        case 3:
            cout << "\r\n";
            SauvegarderTrajetsParType(TypeTrajet::COMPOSE);
            break;
        case 4:
            cout << "\r\n";
            SauvegarderTrajetsParVille(ParVille::DEPART);
            break;
        case 5:
            cout << "\r\n";
            SauvegarderTrajetsParVille(ParVille::ARRIVE);
            break;
        case 6:
            cout << "\r\n";
            SauvegarderTrajetsParVille(ParVille::TOUTES);
            break;
        case 7:
            cout << "\r\n";
            cout << "Au revoir !\r\n";
            break;
        default:
            cout << "\r\n";
            cout << "Veuillez saisir un chiffre entre 1 et 7\r\n";
            break;
        }
    } while (choix != 7);
}

void Catalogue::SauvegarderTrajetsParType(TypeTrajet typeTrajet) const
{
    string nomFichier;
    cout << "Veuillez saisir le nom du fichier dans lequel vous souhaitez sauvegarder les trajets du catalogue :\r\n";
    cin >> nomFichier;

    if (!VerifierNomFichierSauvegarde(nomFichier))
    {
        return;
    }

    ofstream fichier("txt/" + nomFichier + ".txt", ios::out | ios::trunc);
    if (fichier)
    {
        if (typeTrajet == TypeTrajet::TOUS)
        {
            fichier << collection.GetCardActuelle() << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                collection.GetTableau()[i]->Ecrire(fichier);
            }
            fichier.close();
            return;
        }

        if (typeTrajet == TypeTrajet::SIMPLE)
        {
            unsigned int nbTrajetsSimples = 0;
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(collection.GetTableau()[i]);
                if (trajetSimple != nullptr)
                {
                    nbTrajetsSimples++;
                }
            }
            fichier << nbTrajetsSimples << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(collection.GetTableau()[i]);
                if (trajetSimple != nullptr)
                {
                    trajetSimple->Ecrire(fichier);
                }
            }
            fichier.close();
            return;
        }

        if (typeTrajet == TypeTrajet::COMPOSE)
        {
            unsigned int nbTrajetsComposes = 0;
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(collection.GetTableau()[i]);
                if (trajetCompose != nullptr)
                {
                    nbTrajetsComposes++;
                }
            }
            fichier << nbTrajetsComposes << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(collection.GetTableau()[i]);
                if (trajetCompose != nullptr)
                {
                    trajetCompose->Ecrire(fichier);
                }
            }
            fichier.close();
            return;
        }
    }
    else
    {
        cout << "Erreur : impossible de créer et/ou d'ouvrir le fichier spécifié." << endl;
    }
}

void Catalogue::SauvegarderTrajetsParVille(ParVille parVille) const
{
    string nomFichier;
    cout << "Veuillez saisir le nom du fichier dans lequel vous souhaitez sauvegarder les trajets du catalogue :\r\n";
    cin >> nomFichier;

    if (!VerifierNomFichierSauvegarde(nomFichier))
    {
        return;
    }

    ofstream fichier("txt/" + nomFichier + ".txt", ios::out | ios::trunc);
    if (fichier)
    {
        if (parVille == ParVille::DEPART)
        {
            string villeDepart;
            cout << "Veuillez saisir la ville de départ des trajets que vous souhaitez sauvegarder :\r\n";
            cin >> villeDepart;

            unsigned int nbTrajets = 0;
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if (strcmp(collection.GetTableau()[i]->GetVilleDepart(), villeDepart.c_str()) == 0)
                {
                    nbTrajets++;
                }
            }
            fichier << nbTrajets << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if (strcmp(collection.GetTableau()[i]->GetVilleDepart(), villeDepart.c_str()) == 0)
                {
                    collection.GetTableau()[i]->Ecrire(fichier);
                }
            }
            fichier.close();
            return;
        }

        if (parVille == ParVille::ARRIVE)
        {
            string villeArrivee;
            cout << "Veuillez saisir la ville d'arrivée des trajets que vous souhaitez sauvegarder :\r\n";
            cin >> villeArrivee;

            unsigned int nbTrajets = 0;
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if (strcmp(collection.GetTableau()[i]->GetVilleArrivee(), villeArrivee.c_str()) == 0)
                {
                    nbTrajets++;
                }
            }
            fichier << nbTrajets << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if (strcmp(collection.GetTableau()[i]->GetVilleArrivee(), villeArrivee.c_str()) == 0)
                {
                    collection.GetTableau()[i]->Ecrire(fichier);
                }
            }
            fichier.close();
            return;
        }

        if (parVille == ParVille::TOUTES)
        {
            string villeDepart;
            string villeArrivee;
            cout << "Veuillez saisir la ville de départ des trajets que vous souhaitez sauvegarder :\r\n";
            cin >> villeDepart;
            cout << "Veuillez saisir la ville d'arrivée des trajets que vous souhaitez sauvegarder :\r\n";
            cin >> villeArrivee;

            unsigned int nbTrajets = 0;
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if ((strcmp(collection.GetTableau()[i]->GetVilleDepart(), villeDepart.c_str()) == 0 && strcmp(collection.GetTableau()[i]->GetVilleArrivee(), villeArrivee.c_str()) == 0))
                {
                    nbTrajets++;
                }
            }
            fichier << nbTrajets << "\r\n";
            for (unsigned int i = 0; i < collection.GetCardActuelle(); i++)
            {
                if (strcmp(collection.GetTableau()[i]->GetVilleDepart(), villeDepart.c_str()) == 0 && strcmp(collection.GetTableau()[i]->GetVilleArrivee(), villeArrivee.c_str()) == 0)
                {
                    collection.GetTableau()[i]->Ecrire(fichier);
                }
            }
            fichier.close();
            return;
        }
    }
    else
    {
        cout << "Erreur : impossible de créer et/ou d'ouvrir le fichier spécifié." << endl;
    }
}

void Catalogue::ImporterTrajets(const std::string &filePath, TypeTrajet typeTrajet)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    int nb_line = stoi(line.substr(0, 1));
    for (int i = 0; i < nb_line; i++)
    {
        std::getline(file, line);
        int nb_traj = stoi(line.substr(0, 1));

        if (nb_traj == 1 && (typeTrajet == TypeTrajet::SIMPLE || typeTrajet == TypeTrajet::TOUS))
        {

            line.erase(0, 2);
            std::string depart = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);
            std::string arrivee = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);
            int moyen = stoi(line.substr(0, 1));
            line.erase(0, 2);

            TrajetSimple *ptrTrajet;
            ptrTrajet = new TrajetSimple;
            ptrTrajet->ImporterTrajetSimple(depart.c_str(), arrivee.c_str(), (MoyenTransport)moyen);
            collection.Ajouter(ptrTrajet);
        }
        else if (nb_traj > 1 && (typeTrajet == TypeTrajet::COMPOSE || typeTrajet == TypeTrajet::TOUS))
        {

            TrajetCompose *ptrTrajetComp;
            ptrTrajetComp = new TrajetCompose;

            for (int j = 0; j < nb_traj; j++)
            {
                std::getline(file, line);

                line.erase(0, 2);
                std::string depart = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);
                std::string arrivee = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);
                int moyen = stoi(line.substr(0, 1));
                line.erase(0, 2);

                TrajetSimple *ptrTrajet;
                ptrTrajet = new TrajetSimple;
                ptrTrajet->ImporterTrajetSimple(depart.c_str(), arrivee.c_str(), (MoyenTransport)moyen);
                ptrTrajetComp->addTableau(ptrTrajet);
            }
            collection.Ajouter(ptrTrajetComp);
        }
    }

    file.close();
}

void Catalogue::ImporterTrajetsParVille(const std::string &filePath, ParVille parVille, std::string ville)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    int nb_line = stoi(line.substr(0, 1));
    for (int i = 0; i < nb_line; i++)
    {
        std::getline(file, line);
        int nb_traj = stoi(line.substr(0, 1));

        if (nb_traj == 1)
        {

            line.erase(0, 2);
            std::string depart = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);
            std::string arrivee = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);
            int moyen = stoi(line.substr(0, 1));
            line.erase(0, 2);

            TrajetSimple *ptrTrajet;
            ptrTrajet = new TrajetSimple;
            ptrTrajet->ImporterTrajetSimple(depart.c_str(), arrivee.c_str(), (MoyenTransport)moyen);
            if (parVille == ParVille::DEPART && strcmp(ptrTrajet->GetVilleDepart(), ville.c_str()) == 0)
            {
                collection.Ajouter(ptrTrajet);
            }
            else if (parVille == ParVille::ARRIVE && strcmp(ptrTrajet->GetVilleArrivee(), ville.c_str()) == 0)
            {
                collection.Ajouter(ptrTrajet);
            }
            else if (parVille == ParVille::TOUTES && (strcmp(ptrTrajet->GetVilleArrivee(), ville.c_str()) == 0 || strcmp(ptrTrajet->GetVilleDepart(), ville.c_str()) == 0))
            {
                collection.Ajouter(ptrTrajet);
            }
        }
        else if (nb_traj > 1)
        {

            TrajetCompose *ptrTrajetComp;
            ptrTrajetComp = new TrajetCompose;

            for (int j = 0; j < nb_traj; j++)
            {
                std::getline(file, line);

                line.erase(0, 2);
                std::string depart = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);
                std::string arrivee = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);
                int moyen = stoi(line.substr(0, 1));
                line.erase(0, 2);

                TrajetSimple *ptrTrajet;
                ptrTrajet = new TrajetSimple;
                ptrTrajet->ImporterTrajetSimple(depart.c_str(), arrivee.c_str(), (MoyenTransport)moyen);
                ptrTrajetComp->addTableau(ptrTrajet);
            }
            if (parVille == ParVille::DEPART && strcmp(ptrTrajetComp->GetVilleDepart(), ville.c_str()) == 0)
            {
                collection.Ajouter(ptrTrajetComp);
            }
            else if (parVille == ParVille::ARRIVE && strcmp(ptrTrajetComp->GetVilleArrivee(), ville.c_str()) == 0)
            {
                collection.Ajouter(ptrTrajetComp);
            }
            else if (parVille == ParVille::TOUTES && (strcmp(ptrTrajetComp->GetVilleArrivee(), ville.c_str()) == 0 || strcmp(ptrTrajetComp->GetVilleDepart(), ville.c_str()) == 0))
            {
                collection.Ajouter(ptrTrajetComp);
            }
        }
    }

    file.close();
}