#ifndef CONTACTBDD_H
#define CONTACTBDD_H

/*!
*\file ContactBDD.h
*\author BARRY Thierno Oumar & DIALLO Iliassou
* la connexion Qt   à un base sqlite qui
* stocke les informations relatives à un  contact
*/

#include <QObject>
#include <contact.h>
#include <QDate>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <list>
#include <QString>
#include <string>
#include <QVariant>
#include <QSql>


/**
*\class ContactBDD : public QObjet
*\brief Classe qui gère la base de donnée
* La classe herite d'un QObject, permet de créer des  fonctions et des structures
* qui dialogue avec notre base d'où la création des fonctions
* CRUD(Create,Read,Update,Delete) et recherche .
*/

class ContactBDD :public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;/*!< connexion a la base de donnee*/
    bool dbOuvert;/*! < Tester si la base est ouverte ou non*/
    /*!
     *\brief Fermeture de la base
     *Methode qui ferme la base quand elle est ouverte
     */
    void closeDb();
   /*!
    *\brief Creer la connexion en ajoutant une des fonction statiques addDatabase.
    *
    *Methode qui permet d'etablir une connexion dans la base
    *Elle crée par la même occasion une table INTERACTION dans la base si elle n'existe pas.
    *
    *\return true si la connexion à reussie,
    *\return false sinon
    */
    bool connexionDB();
    /*!
     *\brief Etat de la base
     *
     *Methode qui change l'etat de la base
     *
     *\param bool& : l'etat de la base à changer
     *
     */
    void isDBopen(bool &);
    /*!
     *\brief Liste des contacts.
     * Methode qui permet de recuperer la liste
     * de l'ensemble des contact present dans la base.
     *
     *\param std::list<Contact> &:Liste des  contact
     *
     *  Ensemble des contacts
     */
public:
    void ListeContact(std::list<Contact> &) const;
    /*!
     *\brief Ajout d'un contact
     *Methode qui permet d'ajouter un contact  dans la base
     *\param Contact& : le contact a inserer
     *\return true s'il est inserer dans la base
     *\return false sinon
     */
    bool NouveauContact(const Contact &) const;
    /*!
     *\brief Modification
     *
     *Methode qui permet de modifier un contact donné dans la base
     *
     *\param int & : le id du contacNouveauContactt à modifier
     *\param Contact& : le nouveau contact  modifié
     *\return true s'il est modifie dans la base
     *\return false sinon
     */
    bool ModifContact(const int & ,const Contact &) const;
    /*!
     *\brief Suppression
     *
     *Methode qui permet de supprimer un contact donné dans la base
     *
     *\param Contact& : le contact à supprimer
     *\return true s'il est supprimé dans la base
     *\return false sinon
     */
    bool SupprimeContact(const int &) const;
    /*!
     * \brief Recherche contact
     * Methode qui permet de rechercher un contact dans la base
     * entre deux dates saisies
     *
     *\param QString&:la premiere date
     * \param QString&:la deuxieme date
     *\param std::list<Contact> &:Liste des  contact stocke entre ces 2 dates
     */
    void  RechercherContact(QString& ,QString & ,QString & ,std::list<Contact> & ) const;
    /*!
     *\brief Le nombre de total de contact dans la base
     *
     *Methode qui permet de savoir  le nombre total de contact dans la base
     *on a utilisé un requete avec count(*)  .
     *
     *\return le nombre total de contact
     *\return   -1 sinon
     */
    int  NombreContact() const;

public:
    /*!
     *\brief Constructeur
     *Constructeur de la classe ContactBDD
     *
     *\param *parent = nullptr: par defaut de type QObject .
     */
    explicit ContactBDD(QObject *parent = nullptr);
    /*!
     *\brief Destructeur
     *Destructeur de la classe ContactBDD
     */
    ~ContactBDD();

public slots:
    /*!
     *\brief  Slot liste Contact .
     *Slot qui reçoit une liste de contact afin d'envoyer
     *ceci a la methode ListeContact(std::list<Contact> &)
     *\param std::list<Contact> & : liste des contact
     */
    void bddListeContact(std::list<Contact> &);
    /*!
     *\brief Slot Nouveau contact .
     *Slot qui reçoit une contact afin d'envoyer
     *ceci a la methode NouveauContact(Contact& )
     *\param Contact& : le contact
     */
    void bbdNouveauContact(Contact &);
    /*!
     *\brief Slot Modifier un contact .
     *Slot qui reçoit le id d'un contact et  un contact afin d'envoyer
     *ceci a la methode  ModifContact(const int & ,const Contact &)
     *\param int &: le id du contact
     *\param Contact& : le contact
     */
    void bddModifContact( int &, Contact &);
    /*!
     *\brief Slot Supprimer un contact .
     *Slot qui reçoit le id d'un contact afin d'envoyer
     * ceci a la methode  SupprimeContact(const int &)
     *\param int &: le id du contact
     */
    void bddSupprimeContact( int &);
    /*!
     *\Slot Rechercher un contact  .
     *Slot qui recherche un contact par son nom entre 2 dates et ce slot rejoint
     *la methode  Recherchercontact(...)
     *\param QString&:la premiere date
     *\param QString&:la deuxieme date
     *\param std::list<Contact> &:Liste des  contact stocke ente ces 2 dates
     *
     */
    void bddRechercherContact(  QString &,QString &  ,  QString &  ,std::list<Contact> &  );


   // void convertToJson();
signals:
    /*!
     *\brief Signal envoyer le nombre total de contact .
     *\param int &:un entier en parametre
     *
     */
      void nombreTotalContact(int &);
      //json
      //void fichierConverti(QJsonDocument &);

};

#endif // CONTACTBDD_H
