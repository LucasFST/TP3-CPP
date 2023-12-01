/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TableauDynamique.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const;
    // Mode d'emploi :
    // Affiche les trajets simples du trajet composé
    // Contrat :
    //


    virtual void Saisir();
    // Mode d'emploi :
    // Demande à l'utilisateur de saisir les trajets simples du trajet composé
    // Contrat :
    //

    virtual const char *GetVilleDepart() const;
    // Mode d'emploi :
    // Récupère la ville de départ du trajet composé
    // Contrat :
    //

    virtual const char *GetVilleArrivee() const;
    // Mode d'emploi :
    // Récupère la ville d'arrivée du trajet composé
    // Contrat :
    //

    void addTableau(TrajetSimple *ptrTrajet);

    //------------------------------------------------- Surcharge d'opérateurs
    // TrajetCompose &operator=(const TrajetCompose &unTrajetCompose);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const TrajetCompose &unTrajetCompose);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



    TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //
    // TableauDynamique tableauTrajets;

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    TableauDynamique tableauTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
