/*************************************************************************
                           TableauDynamique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TableauDynamique> (fichier TableauDynamique.h) ----------------
#if !defined(TABLEAUDYNAMIQUE_H)
#define TABLEAUDYNAMIQUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
const unsigned int CARD_MAX = 5;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TableauDynamique>
// Implémentation utilisée par Catalogue et TrajetCompose
//
//------------------------------------------------------------------------

class TableauDynamique
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    unsigned int GetCardActuelle() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    unsigned int GetCardMax() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet **GetTableau() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(Trajet *unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    TableauDynamique(const TableauDynamique &unTableauDynamique);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TableauDynamique(unsigned int cardinaliteMax = CARD_MAX);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TableauDynamique();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    unsigned int cardActuelle;
    unsigned int cardMax;
    Trajet **tableau;
};

//-------------------------------- Autres définitions dépendantes de <TableauDynamique>

#endif // TABLEAUDYNAMIQUE_H
