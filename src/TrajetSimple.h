/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
const int TAILLE_MAX_VILLE = 50;
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const;
    // Mode d'emploi :
    // Affiche les attributs de la classe TrajetSimple sous la forme :
    // "De villeDepart à Ville d'arrivée en moyenTransport"
    // Contrat :
    //

    void ImporterTrajetSimple(const char *villeDepart, const char *villeArrivee, MoyenTransport moyenTransport);

    virtual void Saisir();
    // Mode d'emploi :
    // Demande à l'utilisateur de saisir les attributs de la classe TrajetSimple : villeDepart, villeArrivee, moyenTransport
    // Contrat :
    //

    virtual const char *GetVilleDepart() const;
    // Mode d'emploi :
    // Récupère la ville de départ du trajet
    // Contrat :
    //

    virtual const char *GetVilleArrivee() const;
    // Mode d'emploi :
    // Récupère la ville d'arrivée du trajet
    // Contrat :
    //

    virtual void Ecrire(std::ofstream &fichier) const;
    // Mode d'emploi :
    // Ecrire le trajet
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    // TrajetSimple &operator=(const TrajetSimple &unTrajetSimple);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const TrajetSimple &unTrajetSimple);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char *villeDepart;
    char *villeArrivee;
    MoyenTransport moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
