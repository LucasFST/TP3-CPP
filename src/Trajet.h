/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Afficher le trajet
    // Contrat :
    //

    virtual void Saisir() = 0;
    // Mode d'emploi :
    // Saisir le trajet
    // Contrat :
    //

    virtual const char *GetVilleDepart() const = 0;
    // Mode d'emploi :
    // Récupérer la ville de départ du trajet
    // Contrat :
    //

    virtual const char *GetVilleArrivee() const = 0;
    // Mode d'emploi :
    // Récupérer la ville d'arrivée du trajet
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    // virtual Trajet &operator=(const Trajet &unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Trajet(const Trajet &unTrajet);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
