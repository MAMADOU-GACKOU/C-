#ifndef TODOBDD_H
#define TODOBDD_H
/*!
*\file TodoBDD.h
*\brief Application Qt.
*\author BARRY Thierno & DIALLO Iliassou
*
*/

#include "Todo.h"
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
 *\class TodoBDD
 *\brief Classe TodoBDD de la base de donnée
 *La classe herite d'un QObject, permet d'ajouter des TodoBDD pour un contact donné
 *en la stockant dans la base de donnée .
 */

class TodoBDD : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;/*!< connexion a la base de donnee*/
    bool dbOuvert;/*!< Savoir si la base est ouverte ou non*/
    /*!
     *\brief Fermeture de la base
     *Methode qui ferme la base si elle est ouverte
     */
    void closeDb();
    /*!
     *\brief Creer la connexion
     *Methode qui permet d'etablir une connexion avec la base et
     * elle crée  une table Todo dans la base si elle n'existe pas
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
     *\brief Ajout d'une Tache
     *Methode qui permet d'ajouter une tache pour une intéraction
     *\param const int &:l'id du contact courant
     *\param Todo &: la tache à ajouter
     *\return true s'i elle est insereré dans la base
     *\return false sinon
     */
    bool AjoutTodo(const int &,Todo &);
    /*!
     *\brief Liste des taches .
     *Methode qui permet de recuperer la liste des taches  d'un contact selectionné
     *\param std::list<Todo> &:Liste des  taches
     *\param const int &: l'identifiant de l'intéraction
     */
    void ListeTodoContact(const int &,std::list<Todo>&)const;
    /*!
     *\brief Liste des Intéractions .
     *Methode qui permet d'afficher la liste des Taches de tous les  contacts
     *\param std::list<Todo>:Liste des  Taches
     */
    void ListeALLContact(std::list<Todo>&) const;
    /*!
     *\brief Rechercher des Taches entre deux dates .
     *La Méthode qui permet de rechercher entre deux dates les Taches de tous les contacts
     *\param std::list<Todo>  &:Liste des  Taches
     *\param QString &: la premiere date de type Qstring .
     *\param QString &: la deuxieme date de type Qstring.
     */
    void RechercheALLTodoCont(QString &,QString &,std::list<Todo> &)const;
    /*!
     *\brief Rechercher des Taches entre deux dates pour un contact .
     *La Méthode qui permet de rechercher entre deux dates les taches d'un contact
     *\param int &: l'identifiant d'une interaction
     *\param std::list<Todo> &:Liste des  Taches
     *\param QString &: la premiere date de type Qstring .
     *\param QString &: la deuxieme date de type Qstring.
     */
    void RechercheTodoCont(const int &,QString &,QString &,std::list<Todo> &)const;
public:
    /*!
     *\brief Constructeur
     *Constructeur de la classe TodoBDD
     *\param *parent = nullptr: par defaut
     */
    explicit TodoBDD(QObject *parent = nullptr);
    /*!
     * \brief Destructeur
     * Le Destructeur de la classe TodoBDD càd la fonction qui libère la memoire utilisé .
     */
    ~TodoBDD();

public slots:
    /*!
     *\brief Slot Ajout Todo .
     *slot qui permet d'ajouter une tache
     *\param int & : l'identifiant du contact
     *\param Todo & : la tache a ajouter
     */
    void bddAjoutTodo(int &,Todo &);
    /*!
     *\brief  Slot liste Taches pour un contact .
     * slot qui permet d'afficher la liste des taches pour un contact selectionné
     *\param int &: l'identifiant d'un contact
     *\param std::list<Todo>& & : liste des taches
     */
    void bddListeTodoContact(int &,std::list<Todo>&);
    /*!
     *\brief  Slot liste Taches pour tous les contacts.
     * slot qui permet d'afficher la liste des taches pour tous les contacts
     *\param std::list<Todo>& & : liste des taches
     */
    void bddListeALLContact(std::list<Todo> &);
    /*!
     *\brief  Slot Rechercher Taches pour un contact entre deux dates  .
     * slot qui permet d'afficher la liste des taches pour un contact entre deux dates
     *\param std::list<Todo>& & : liste des taches
     *\param  QString  & : la premiere date pour le debut de la recherche
     *\param QString & : la deuxieme date pour la fin de la recherche
     *\param int & :l'identifiant de l'interaction
     */
    void bddRechercheTodoCont(int & , QString & , QString & , std::list<Todo> &);
    /*!
     *\brief  Slot Rechercher Taches pour tous les contacts entre deux dates.
     * slot qui permet d'afficher la liste des taches pour tous les contacts
     * entre deux dates entré par l'utilisateur
     *\param std::list<Todo>& & : liste des taches
     *\param  QString  & : la premiere date pour le debut de la recherche
     *\param QString & : la deuxieme date pour la fin de la recherche
     */
    void bddRechercheALLTodoCont( QString & , QString & , std::list<Todo> &);
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

#endif // TODOBDD_Hvoi
