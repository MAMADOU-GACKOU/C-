/*!
*\file InteractionBDD.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "interactionbdd.h"


/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param QObject *parent et hérite d'un QObjet
 *initialisation du test de la base de donnée à false .
 *Appel de la fonction connexion() pour connecter la base de donnée .
 *
 */
InteractionBDD::InteractionBDD(QObject *parent) : QObject(parent)
{
    dbOuvert=false;
    connexion();
}

/*!
 *\brief implémentation du destructeur .
 *A la fermeture de la base on libère la memoire en faisant appel à la fonction closeDB().
 *
 */


InteractionBDD::~InteractionBDD()
{
    closeDb();
}

/*!
 *\fn  InteractionBDD::connexion()
 *\brief Connexion à la base de donnée
 *On le nom de la base avec l'extension sqlite dans le tmp
 *On teste si la base est ouverte :
 *si non on retourne false
 *si Oui on crée une table si elle n'existe pas et on affiche si la table est bien crée "création de la table réussi " .
 *\return dbOuvert : le booleén à retourner
 */
bool InteractionBDD::connexion()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
       QString Chemin="/tmp/bddprojet.sqlite";

       db.setDatabaseName(Chemin);

       if(!db.open())
       {
           qDebug()<<"base non ouvert\n";
           dbOuvert=false;
       }
       else
       {
           qDebug()<<"ouverture  interaction reussie";
           dbOuvert=true;
           QSqlQuery query;
           query.exec("CREATE TABLE IF NOT EXISTS INTERACTION"
                         "(id_interaction integer primary key AUTOINCREMENT, "
                         "id_contact integer NOT NULL,"
                         "dateinteraction TEXT,"
                         "contenu TEXT,"
                      "FOREIGN KEY (id_contact) REFERENCES CONTACT(id_contact) ON DELETE CASCADE )");
           if(!query.exec())
           {
               qDebug()<<"Echec de la création de la table interaction";
           }
           else
           {
                qDebug()<<" creation de la table reussi";
           }
       }
       return  dbOuvert;
}


/*!
 *\fn InteractionBDD::AjoutInteraction(const int & id,Interaction & inter)
 *\brief Création d'une intéraction
 *La fonction qui nous permet de créer ou inserer une intéraction en tenant compte des contraintes concernant les clés étrangères ou primaires
 *\param Interaction & inter: representera l'intéraction qui sera ajouté .
 *\param const int & id : representera l'identifiant du contact pour lui ajouter l'intéraction .
 */
bool InteractionBDD::AjoutInteraction(const int & id,Interaction & inter)
{
    if(dbOuvert==true)
    {
        QSqlQuery query("PRAGMA foreign_keys = ON"
                        "SELECT * from INTERACTION ");
        //preparation de la requete
        query.prepare("INSERT INTO INTERACTION(id_contact,dateinteraction,contenu) "
                      "VALUES(:n, :m, :p)");
        //remplissage de valeur
        query.bindValue(":n",QString::number(id));
        query.bindValue(":m", QString::fromStdString(inter.getRDV().fromDateString()));
        query.bindValue(":p",QString::fromStdString(inter.getContenu()));

        if(!query.exec())
        {
            qDebug()<<"ajout de l'interaction non effectue";
            return false;
        }
       qDebug()<<"ajout de l'interaction bien réussi ";

    }
    return true;
}

/*!
 *\fn InteractionBDD::bddAjoutInteraction(int &i , Interaction & inter)
 *\brief Ajout de l'intéraction
 *Slot pour ajouter une intéraction pour un contact ,  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param Interaction & inter: representera l'intéraction qui sera ajouté .
 *\param const int & id : representera l'identifiant du contact pour lui ajouter l'intéraction .
 */

void InteractionBDD::bddAjoutInteraction(int &i , Interaction & inter)
{
    AjoutInteraction(i,inter);
}

/*!
 *\fn nteractionBDD::ListeInteraction(const int & id, std::list<Interaction> & li) const
 *\brief Affichage des intéractions d'un contact.
 * L'affichage des intéractions d'un contact en utilisant la requete qui selectionne toutes les interactions
 * d'un contact dans la base de donnée .
 *\param std::list<Interaction> & li : la liste des intéractions .
 *\param const int & id : representera l'identifiant du contact pour lui afficher ses intéractions .
 */
void InteractionBDD::ListeInteraction(const int & id, std::list<Interaction> & li) const
{
    li.clear();
    if(dbOuvert==true)
        {
            QSqlQuery query;
            query.prepare("SELECT * FROM INTERACTION WHERE id_contact=:n");
            query.bindValue(":n",QString::number(id));
            query.exec();
            if(!query.exec())
            {
                qDebug()<<"echec de la requete d'affichage de la liste";
            }
            else {
                qDebug()<<" affichage reussie";
                while(query.next())
                {
                    Interaction inter;
                    QString r=query.value(0).toString();
                         inter.setIdInteraction(r.toInt());

                           r=query.value(1).toString();

                           inter.setIdContact(r.toInt());
                           r=query.value(2).toString();

                           inter.setRDV(inter.getRDV().toDateString(r.toStdString()));
                           r=query.value(3).toString();

                           inter.setContenu(r.toStdString());

                           li.push_back(inter);

                }
                li.sort();
            }

    }
}

/*!
 *\fn InteractionBDD::bddListeInteraction(int & id, std::list<Interaction> & li)
 *\brief Slot afficher la liste des intéractions
 *Slot pour afficher les intéractions pour un contact ,  c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param std::list<Interaction> & li: represente une liste d'intéraction
 *\param const int & id : represente l'identifiant du contact pour lui afficher ses intéractions .
 */

void InteractionBDD::bddListeInteraction(int & id, std::list<Interaction> & li)
{
    ListeInteraction(id,li);
}


/*!
 *\fn InteractionBDD::ListeInteractionALL(std::list<Interaction> & li) const
 *\brief Affichage toutes les interactions de tous les contacts .
 *On affiche toutes les intéractions en selectionnant toute la table INTERACTION et on l'affiche .
 *\param std::list<Interaction> & li : la liste des intéractions  en paramètre.
 */

void InteractionBDD::ListeInteractionALL(std::list<Interaction> & li) const
{
    li.clear();

        if(dbOuvert==true)
        {
            QSqlQuery query("SELECT  * FROM INTERACTION  ");



            if(!query.exec())
            {
                qDebug()<<"probleme d'affichage de recherche des interactions";
            }
            else
                {
                     qDebug()<<"Affichage réussi pour la recherche interactions";

                     while(query.next())
                     {

                            Interaction inter;
                          QString  r=query.value(0).toString();
                                 inter.setIdInteraction(r.toInt());

                                   r=query.value(1).toString();

                                   inter.setIdContact(r.toInt());
                                     r=query.value(2).toString();
                                   inter.setRDV(inter.getRDV().toDateString(r.toStdString()));
                                   r=query.value(3).toString();

                                   inter.setContenu(r.toStdString());

                                   li.push_back(inter);
                          }


                     }


            }

}

/*!
 *\fn InteractionBDD::bddListeInteractionALL(std::list<Interaction> & li)
 *\brief Slot afficher toutes les intéractions
 *Slot pour afficher toutes les intéractions de tous les contacts ,  c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param std::list<Interaction> & li: c'est la liste qu'on met dans le paramètre de la  fonction ListeInteractionALL pour
 * nous afficher toutes ses d'intéractions
 */

void InteractionBDD::bddListeInteractionALL(std::list<Interaction> & li)
{
    ListeInteractionALL(li);
}

/*!
 *\fn  InteractionBDD::RechercheInteraction(QString & date1, QString & date2, std::list<Interaction> & li)
 *\brief Rechercher les intéractions entre deux dates
 *c'est cette fonction qui nous permet de rechercher des intéractions entre deux dates .
 *On rentrera l'intervalle à rechercher en Selectionnant la table:
 *on n'affiche rien si les intérations n'existent pas entre ces dates
 *si oui on affiche toutes les intéractions entre ces dates  en triant les dates avec sort() par date de création .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & li :liste de contacts
 */
void InteractionBDD::RechercheInteraction(QString & date1, QString & date2, std::list<Interaction> & li)
{
    li.clear();
    Date d;

    Date d1=d.toDateString(date1.toStdString());
    Date d2=d.toDateString(date2.toStdString());

        if(dbOuvert==true)
        {
            QSqlQuery query("SELECT  * FROM INTERACTION  ");



            if(!query.exec())
            {
                qDebug()<<"Requete échoué ";
            }
            else
                {
                     qDebug()<<"Recherche réussi ";

                     while(query.next())
                     {
                         QString r=query.value(2).toString();
                         Date dc=d.toDateString(r.toStdString());
                         if(d1<dc && dc<d2 )
                         {
                            Interaction inter;
                            r=query.value(0).toString();
                                 inter.setIdInteraction(r.toInt());

                                   r=query.value(1).toString();

                                   inter.setIdContact(r.toInt());


                                   inter.setRDV(dc);
                                   r=query.value(3).toString();

                                   inter.setContenu(r.toStdString());

                                   li.push_back(inter);//ajout de l'intéraction dans la liste
                          }


                     }
           li.sort(); //tri la liste d'intéraction

            }
        }


}

/*!
 *\fn InteractionBDD::bddRechercheInteraction(QString & date1, QString & date2, std::list<Interaction> &li)
 *\brief Slot afficher les intéractions entre deux dates .
 *Slot qui nous permet d'afficher entre deux dates les intéractions ,c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & li :liste de contacts
 *ces paramètre qu'on utilisera dans la fonction recherche intéraction lors de son appel dans le slot .
 */

void InteractionBDD::bddRechercheInteraction(QString & date1, QString & date2, std::list<Interaction> &li)
{
            RechercheInteraction(date1,date2,li);
}

/*!
 *\fn  InteractionBDD::RechercheInteractionCont(int & id, QString & date1, QString &date2, std::list<Interaction> & li)
 *\brief Rechercher les intéractions entre deux dates pour un contact
 *c'est cette fonction qui nous permet de rechercher des intéractions entre deux dates pour un contact selectionné .
 *On rentrera l'intervalle à rechercher
 *on selectionnera dans la comboBox le contact
 *on appuyera sur le bouton rechercher .
 *Cette requete nous permet de selectionner pour une interaction son identifiant et l'identifiant de son concat en
 *faisant le test quand l'identifiant du contact de l'intéraction est égale à l'identifiant du contact .
 *on n'affiche rien si les intérations n'existent pas entre ces dates  pour le contatc
 *si oui on affiche toutes les intéractions entre ces dates  en triant les dates avec sort() par date de création .
 *\param int & id: l'identifiant du contact pour le quel on fera la recherche .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & li :liste de contacts
 */
void InteractionBDD::RechercheInteractionCont(int & id, QString & date1, QString &date2, std::list<Interaction> & li)
{
    li.clear();
    Date d;

    Date d1=d.toDateString(date1.toStdString());
    Date d2=d.toDateString(date2.toStdString());

        if(dbOuvert==true)
        {
            QSqlQuery query;
            query.prepare("SELECT interaction.id_interaction ,interaction.id_contact ,interaction.dateinteraction,interaction.contenu"
                          " from INTERACTION,CONTACT "
                          "where INTERACTION.id_contact=CONTACT.id_contact"
                          " and "
                          "CONTACT.id_contact=:n");

            query.bindValue(":n",QString::number(id));
            query.exec();


            if(!query.exec())
            {
                qDebug()<<"probleme niveau recherche contact";
            }
            else
                {
                qDebug()<<"commençons la  recherche de l'interaction du contact";

                while(query.next())
                {
                      QString r=query.value(2).toString();
                    Date dc=d.toDateString(r.toStdString());
                    if(d1<dc && dc<d2 )
                    {
                       Interaction inter;
                       r=query.value(0).toString();
                            inter.setIdInteraction(r.toInt());

                              r=query.value(1).toString();

                              inter.setIdContact(r.toInt());
                              r=query.value(2).toString();

                              inter.setRDV(dc);
                              r=query.value(3).toString();

                              inter.setContenu(r.toStdString());

                              li.push_back(inter);
                     }


                }
      li.sort();
            }

     }
}

/*!
 *\fn InteractionBDD::bddRechercheInteractionCont(int & id, QString & date1, QString &date2, std::list<Interaction> & li)
 *\brief Slot afficher les intéractions entre deux dates pour un contact  .
 *Slot qui nous permet d'afficher entre deux dates les intéractions pour un contact ,c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param int & id: l'identifiant du contact pour le quel on fera la recherche .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & li :liste de contacts
 *ces paramètres qu'on utilisera dans la fonction recherche intéraction lors de son appel dans le slot .
 */

void InteractionBDD::bddRechercheInteractionCont(int & id, QString & date1, QString &date2, std::list<Interaction> & li)
{
    RechercheInteractionCont(id,date1,date2,li);
}

/*!
 *\fn InteractionBDD::isOpen(bool &b)
 *\brief Teste on affectera b à b
 *\param bool & b : le booléan en paramètre .
 */
void InteractionBDD::isOpen(bool &b)
{
    isDBopen(b);
}

/*!
 *\fn ContactBDD::closeDb()
 *\brief fermer la base
 * On teste si le boolean est à true on ferme la base
 */

void InteractionBDD::closeDb()
{
    if(dbOuvert==true)
    {
         db.close();
    }

}

/*!
 *\fn InteractionBDD::isDBopen(bool &b)
 *\brief Teste on affectera b à b
 *\param bool & b : le booléan en paramètre .
 */
void InteractionBDD::isDBopen(bool &b)
{
    dbOuvert=b;
}

