#ifndef INTERACTIONBDD_H
#define INTERACTIONBDD_H
/*!
*\file InteractionBDD.h
*\brief Application Qt.
*\author BARRY Thierno & DIALLO Iliassou
*
*/

#include "Interaction.h"
#include <QObject>
#include <QDate>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <list>
#include <QString>
#include <string>
#include <QVariant>

/*!
 *\class InteractionBDD
 *\brief Classe interaction de la base de donnée
 *La classe herite d'un QObject, permet d'ajouter des interactions pour un contact donné
 *en la stockant dans la base de donnée .
 */

class InteractionBDD : public QObject
{
    Q_OBJECT

private:
        QSqlDatabase db;/*!< connexion a la base de donnee*/
        bool dbOuvert;/*!<Savoir si la base est ouverte ou non*/
        /*!
         *\brief Fermeture de la base
         *Methode qui ferme la base si elle est ouverte
         */
        void closeDb();
        /*!
         *\brief Creer la connexion
         *Methode qui permet d'etablir une connexion avec la base et
         * elle crée  une table INTERACTION dans la base si elle n'existe pas
         *\return true si la connexion à reussie,
         *\return  false sinon
         */
        bool connexion();
        /*!
         *\brief Etat de la base
         *Methode qui change l'etat de la base
         *\param bool& : l'etat de la base à changer
         */
        void isDBopen(bool &);
        /*!
         *\brief Ajout d'une Interaction
         *Methode qui permet d'ajouter une interaction pour un contact
         *\param  Interaction &:l'interaction à inserer
         *\param const int &: l'id du contact courant
         *\return true s'il est inserer dans la base
         *\return false sinon
         */
        bool AjoutInteraction(const int &,Interaction &);
        /*!
         *\brief Liste des Intéractions .
         *Methode qui permet de recuperer la liste des interactions d'un contact selectionné
         *\param std::list<Interaction> &:Liste des  Interactions
         * \param const int &: l'identifiant du contact
         */
        void ListeInteraction(const int &,std::list<Interaction> &)const ;
        /*!
         *\brief Liste des Intéractions .
         *Methode qui permet de recuperer la liste des interactions de tous les  contacts
         *\param std::list<Interaction> &:Liste des  Interactions
         */
public:
        void ListeInteractionALL(std::list<Interaction> &)const ;
        /*!
         *\brief Rechercher des Intéractions entre deux dates .
         *La Méthode qui permet de rechercher entre deux dates les interactions de tous les contacts
         *\param std::list<Interaction> &:Liste des  Interactions
         *\param QString &: la premiere date de type Qstring .
         *\param QString &: la deuxieme date de type Qstring.
         */
        void RechercheInteraction(QString &,QString &,std::list<Interaction> &);
        /*!
         *\brief Rechercher des Intéractions entre deux dates pour un contact .
         *La Méthode qui permet de rechercher entre deux dates les interactions d'un contact
         *\param int &: l'identifiant d'un contact
         *\param std::list<Interaction> &:Liste des  Interactions
         *\param QString &: la premiere date de type Qstring .
         *\param QString &: la deuxieme date de type Qstring.
         */
        void RechercheInteractionCont(int &,QString &,QString &,std::list<Interaction> &);
public:
        /*!
         *\brief Constructeur
         *Constructeur de la classe InteractionBDD
         *\param *parent = nullptr: par defaut
         */
         explicit InteractionBDD(QObject *parent = nullptr);
        /*!
         * \brief Destructeur
         * Le Destructeur de la classe InteractionBDD càd la fonction qui libère la memoire utilisé .
         */
          ~InteractionBDD();



public slots:
        /*!
         *\brief Slot Ajout interaction .
         *slot qui permet d'ajouter une intéraction
         *\param int & : l'identifiant du contact
         *\param Interaction & : l'interaction
         */
        void bddAjoutInteraction(int &,Interaction &);
        /*!
         *\brief  Slot liste Interaction .
         * slot qui permet d'afficher la liste d'intéraction pour un contact selectionné
         *\param int &: l'identifiant d'un contact
         *\param std::list<Interaction> & : liste des Intéractions
         */
        void bddListeInteraction(int &,std::list<Interaction> &);
        /*!
         *\brief  Slot liste de toutes les Interactions .
         *slot qui permet d'afficher toutes les intéractions de tous les contacts .
         *\param std::list<Interaction> & : liste des Intéractions
         */
        void bddListeInteractionALL(std::list<Interaction> &);
        /*!
         *\brief  Slot Recherche Interaction .
         *Slot qui permet de rechercher les intéractions pour tous les contacts entre deux dates
         *\param QString: la première date
         *\param QString: la deuxième date
         *\param std::list<Interaction> & : liste des Intéractions
         */
        void bddRechercheInteraction(QString &,QString &,std::list<Interaction> &);
        /*!
         *\brief  Slot Recherche Interaction d'un contact .
         *Slot qui permet de rechercher les intéractions d'un contact entre deux dates
         *\param int &  :identifiant du contact
         *\param QString: la première date
         *\param QString: la deuxième date
         *\param std::list<Interaction> & : liste des Intéractions
         */
        void bddRechercheInteractionCont(int & , QString & , QString & , std::list<Interaction> &);
        /*!
         *\brief Etat de la base
         *
         *Methode qui change l'etat de la base
         *
         *\param bool& : l'etat de la base à changer
         *
         */
        void isOpen(bool &);
};

#endif // INTERACTIONBDD_H
