/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TableauDynamique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum TypeTrajet
{
    SIMPLE,
    COMPOSE,
    TOUS
};

enum ParVille
{
    ARRIVE,
    DEPART,
    TOUTES
};

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue(const Catalogue &unCatalogue);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercherTrajet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SaisirTrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SaisirTrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ImporterTrajetsParVille(const std::string &filePath, ParVille parVille, std::string ville);

    void ImporterTrajets(const std::string &filePath, TypeTrajet TypeTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SauvegarderTrajetsMenu() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SauvegarderTrajetsParType(TypeTrajet typeTrajet) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SauvegarderTrajetsParVille(ParVille parVille) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SauvegarderTrajetsParIndice() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    TableauDynamique collection;

private:
    bool VerifierNomFichierSauvegarde(std::string nomFichier) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
