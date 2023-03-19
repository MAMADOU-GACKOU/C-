/*!
*\file Interaction.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/
#include "contactbdd.h"

/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param QObject *parent et hérite d'un QObjet
 *initialisation du test de la base de donnée à false .
 *Appel de la fonction connexionBdd pour connecter la base de donnée .
 *
 */

ContactBDD::ContactBDD(QObject *parent) : QObject(parent)
{
    dbOuvert=false;
    connexionDB();

}

/*!
 *\brief implémentation du destructeur .
 *A la fermeture de la base on libère la memoire en faisant appel à la fonction closeDB().
 *
 */

ContactBDD::~ContactBDD()
{
closeDb();
}

/*!
 *\fn ContactBDD::connexionDB()
 *\brief Connexion à la base de donnée
 *On met le chemin dans tmp
 *On teste si la base est ouverte :
 *si non on retourne false
 *si Oui on crée une table si elle n'existe pas et on affiche si la table est bien crée "création de la table réussi " .
 *\return dbOuvert : le booleén à retourner
 */
bool ContactBDD::connexionDB()
{

    QString Chemin="/tmp/bddprojet.sqlite";
    db=QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(Chemin);

    if(!db.open())
    {
        qDebug()<<"Impossible d'ouvrir la base \n";
        dbOuvert=false;
    }
    else
    {
        qDebug()<<"ouverture de la base reussie";
        dbOuvert=true;
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS CONTACT"
                      "(id_contact integer primary key AUTOINCREMENT, "
                      "nom TEXT NOT NULL,"
                      "prenom TEXT NOT NULL,"
                      "entreprise TEXT NOT NULL,"
                      "mail TEXT NOT NULL,"
                      "telephone TEXT NOT NULL,"
                      "photo TEXT NOT NULL ,"
                      "datecreation TEXT)");
         if(!query.exec())
        {
            qDebug()<<"Erreur de la création de table contact";
        }
        else
        {
             qDebug()<<"création de la table reussi";
        }
    }
    return  dbOuvert;
}

/*!
 *\fn ContactBDD::closeDb()
 *\brief fermer la base
 * On teste si le boolean est à true on ferme la base
 */

void ContactBDD::closeDb()
{
  if(dbOuvert==true)
  {
    db.close();
  }
}

/*!
 *\fn ContactBDD::isDBopen(bool & b)
 *\brief Teste on affectera b à b
 *\param bool & b : le booléan en paramètre .
 */
void ContactBDD::isDBopen(bool & b)
{
dbOuvert=b;
}

/*!
 *\fn ContactBDD::ListeContact(std::list<Contact> &lc) const
 *\brief Affichage d'un contact
 * L'affichage d'un contact en utilisant la requete qui selectionne tous les contacts dans la base de donnée .
 * si l'affichage est réussi on récupère tout ce qui caractérise le contact dans la base .
 *\param std::list<Contact> &lc : la liste de contact  en paramètre on ajoutera le contact dans la liste passé en paramètre .
 */
//Affichage des contacts
void ContactBDD::ListeContact(std::list<Contact> &lc) const
{
lc.clear();

if(dbOuvert==true)
{
    QSqlQuery query("SELECT * FROM CONTACT ");
    if(!query.exec())
    {
        qDebug()<<"Affichage echoue";
    }
    else
    {
        qDebug()<<"Requete reussie";

        while(query.next())
        {
        Contact co;
        QString r=query.value(0).toString();
        co.setId_contact(r.toInt());

        r=query.value(1).toString();

        co.setNom(r.toStdString());
        r=query.value(2).toString();

        co.setPrenom((r.toStdString()));
        r=query.value(3).toString();

        co.setEntreprise((r.toStdString()));
        r=query.value(4).toString();

        co.setMail((r.toStdString()));
        r=query.value(5).toString();

        co.setTelephone((r.toStdString()));
        r=query.value(6).toString();

        co.setURIPhoto((r.toStdString()));
        r=query.value(7).toString();
        co.setDateDecreation(co.getDateDecreation().toDateString(r.toStdString()));

        lc.push_back(co);

        }
    }
}
}

/*!
 *\fn ContactBDD::ListeContact(std::list<Contact> &lc) const
 *\brief la liste des contacts
 *Slot pour afficher la liste des contacts c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param std::list<Contact> &co : la liste de contact qu'on mettra dans le paramètre lors de l'appel de la fonction ListeContact
 */
void ContactBDD::bddListeContact(std::list<Contact> & co)
{
    ListeContact(co);//appel de la fonction qui permet d'afficher le contact en mettant en paramètre une liste de contact .
    int n=NombreContact();//On met dans n la fonction qui permet de compter les contacts
    emit nombreTotalContact(n);//on emet un signal nombre total d'un contact en mettant la variable n en parametre .
}

/*!
 *\fn  ContactBDD::NouveauContact(const Contact & co) const
 *\brief Création d'un contact
 *La fonction qui nous permet d'insérer un contact en tenant compte des contraintes concernant les clés étrangères ou primaires
 *\param const Contact & co: le contact qu'on utilisera pour recuperer ses setteurs afin de les inserer dans la base .
 */
bool ContactBDD::NouveauContact(const Contact & co) const
{
    if(dbOuvert==true)
    {
        QSqlQuery query("PRAGMA foreign_keys = ON"
                        "SELECT * from CONTACT");
        //preparation de  la requete
        query.prepare("INSERT INTO CONTACT (nom, prenom, entreprise, mail,telephone, photo, datecreation) "
                      "VALUES(:n, :p, :e, :m, :t, :u, :d)");

        //remplir les valeurs
        query.bindValue(":n", QString::fromStdString(co.getNom()));
        query.bindValue(":p", QString::fromStdString(co.getPrenom()));
        query.bindValue(":e", QString::fromStdString(co.getEntreprise()));
        query.bindValue(":m", QString::fromStdString(co.getMail()));
        query.bindValue(":t", QString::fromStdString(co.getTelephone()));
        query.bindValue(":u", QString::fromStdString(co.getURIPhoto()));
        query.bindValue(":d", QString::fromStdString(co.getDateDecreation().fromDateString()));

        if(!query.exec())
        {
            qDebug()<<"Insertion a echoue";
            return false;
        }
         qDebug()<<"Insertion à reussi";

    }
    return true;
}
/*!
 *\fn ContactBDD::bbdNouveauContact(Contact &co)
 *\brief Création d'un contact
 *Slot pour créer un contact  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param Contact &co:le contact qu'on mettra dans le paramètre de la fonction NouveauContact lors de son appel .
 */
void ContactBDD::bbdNouveauContact(Contact &co)
{
            NouveauContact(co);
}

/*!
 *\fn ContactBDD::ModifContact(const int & id_ancien,const Contact & co) const
 *\brief Modification d'un contact
 *La fonction qui nous permet de modifier un contact en tenant compte des contraintes concernant les clés étrangères ou primaires
 *en mettant à jour la liste de contact ein utilisant UPDATE dans la requete .
 *\param const int & id_ancien : represente l'identifiant du contact à modifier .
 *\param const Contact & co: represente le contact qu'on utilisera pour recuperer ses setteurs afin de faire la modification du contact dans la base .
 */
bool ContactBDD::ModifContact(const int & id_ancien,const Contact & co) const
{
        if(dbOuvert==true)
        {
            QSqlQuery query("PRAGMA foreign_keys = ON");
            //ouverture de la base

            query.prepare("UPDATE CONTACT SET nom=:nn, prenom=:np, entreprise=:ne, mail=:nm, telephone=:nt, photo=:npp, datecreation=:nd WHERE id_contact=:n ");
            query.bindValue(":n", QString::number(id_ancien));
            query.bindValue(":nn",QString::fromStdString(co.getNom()));
            query.bindValue(":np",QString::fromStdString(co.getPrenom()));
            query.bindValue(":ne",QString::fromStdString(co.getEntreprise()));
            query.bindValue(":nm",QString::fromStdString(co.getMail()));
            query.bindValue(":nt",QString::fromStdString(co.getTelephone()));
            query.bindValue(":npp",QString::fromStdString(co.getURIPhoto()));
            query.bindValue(":nd",QString::fromStdString(co.getDateDecreation().fromDateString()));
            if(!query.exec())
             {
                 qDebug()<<"Modification   echoue";
                 return false;
             }
             qDebug()<<"Modification   accepté";
        }
        return true;
}

/*!
 *\fn ContactBDD::bddModifContact(int & id_ancien, Contact & co)
 *\brief Modification d'un contact
 *Slot pour modifier un contact  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param const int  &:l'identifiant du contact qu'on mettra dans le paramètre de la fonction modifContact lors de son appel .
 *\param Contact &co:le contact qu'on mettra dans le paramètre de la fonction ModifContact lors de son appel .
 */

void ContactBDD::bddModifContact(int & id_ancien, Contact & co)
{
        ModifContact(id_ancien,co);
}

/*!
 *\fn  ContactBDD::SupprimeContact(const int  & id_cont) const
 *\brief Supprimer un contact
 *La fonction qui nous permet de supprimer un contact en tenant compte des contraintes concernant les clés étrangères
 *ou primaires en supprimant toutes ces intéractions et taches en utilisant la requete "DELETE" .
 *\param const int  & id_cont: l'identifiant du contact à supprimer .
 */
bool ContactBDD::SupprimeContact(const int  & id_cont) const
{

    if(dbOuvert==true)
        {
                    QSqlQuery query("PRAGMA foreign_keys = ON");
                    query.prepare("DELETE  FROM CONTACT WHERE id_contact=:n");
                    query.bindValue(":n", QString::number(id_cont));
                    query.exec();

            if(!query.exec())
            {
                qDebug()<<"Suppression echoue";
                return false;
            }
            qDebug()<<"Suppression reussie";

        }
         return true;
}

/*!
 *\fn ContactBDD::bddSupprimeContact( int  & id_cont)
 *\brief Slot pour la suppression d'un contact
 *Slot pour supprimer un contact  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param const int  &:l'identifiant du contact à supprimer qu'on mettra dans le paramètre de la fonction
 * modifContact lors de l'appel appel de la fonction SupprimeContact() .
 */
void ContactBDD::bddSupprimeContact( int  & id_cont)
{
    SupprimeContact( id_cont);
}

/*!
 *\fn  ContactBDD::RechercherContact(QString & noms, QString & date1 ,  QString & date2 ,std::list<Contact> & lc ) const
 *\brief Rechercher contact par le nom
 *c'est cette fonction qui nous permet de rechercher un contact par son nom dans la liste des contacts entre deux dates .
 *On rentrera l'intervalle à rechercher et le nom en Selectionnant la table où le nom entrer par l'utilisateur
 *correspond à un nom  dans la liste contact : on l'affiche sinon on affiche rien tout en triant par date de création .
 *\param QString & noms: le nom du contact à réchercher .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & lc :liste de contacts
 */

void ContactBDD::RechercherContact(QString & noms, QString & date1 ,  QString & date2 ,std::list<Contact> & lc ) const
{
lc.clear();
Date d;

Date d1=d.toDateString(date1.toStdString());
Date d2=d.toDateString(date2.toStdString());

    if(dbOuvert==true)
    {
        QSqlQuery query;
        query.prepare("SELECT  * FROM CONTACT where nom=:n ");//Requete pour chercher dans la table contact le nom
        query.bindValue(":n",QString::fromStdString(noms.toStdString()));
        query.exec();


        if(!query.exec())
        {
            qDebug()<<"Recherche échoué";
        }
        else
            {
                 qDebug()<<"Recherche réussi";

                 while(query.next())
                 {
                     QString r=query.value(7).toString();
                     Date dc=d.toDateString(r.toStdString());
                     if(d1<dc && dc<d2 )
                     {
                        Contact co;
                        r=query.value(0).toString();
                        co.setId_contact(r.toInt());
                        r=query.value(1).toString();
                        co.setNom(r.toStdString());
                        r=query.value(2).toString();
                        co.setPrenom((r.toStdString()));
                        r=query.value(3).toString();
                        co.setEntreprise((r.toStdString()));
                        r=query.value(4).toString();
                        co.setMail((r.toStdString()));
                        r=query.value(5).toString();
                        co.setTelephone((r.toStdString()));
                        r=query.value(6).toString();
                        co.setURIPhoto((r.toStdString()));
                        co.setDateDecreation(dc);
                        lc.push_back(co);
                      }


                 }
       lc.sort();//on trie les contacts qui se trouvent dans la liste en faisant appel à la fonction c++ sort() .

        }
    }

}

/*!
 *\fn ContactBDD::bddRechercherContact( QString & nom, QString & date1 ,  QString & date2 ,std::list<Contact> & lc )
 *\brief Slot pour la recherche d'un contact
 *Slot pour rechercher un contact  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale ,on a fait appel à la fonction bddRechercherContact pour lui donner en parametre
 * les variable suivante : nom,date1, date2,la liste des contacts .
 *\param QString & nom : le nom du contact à réchercher .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Contact> & lc :liste de contacts
 */

void ContactBDD::bddRechercherContact( QString & nom, QString & date1 ,  QString & date2 ,std::list<Contact> & lc )
{
        RechercherContact(nom,date1,date2,lc);
}

/*!
 *\fn  ContactBDD::NombreContact() const
 *\brief Afficher le nombre total de contact .
 *c'est cette fonction qui nous permet d'afficher en comptant le nombre total de contact dans la base de donnée contactBDD
 *pour y arriver on a utilisé count(*) qui permet de compter en sqlite et sql,plus précisement sur notre application lors
 *d'un clic sur sur le boutons afficher les contact on voit afficher le nombre total de conatact dans la base de donnée .
 *On le liera dans le main avec sa fonction correspondante .
 *\return total: on a retourné l'entier total .
 */
int ContactBDD::NombreContact() const
{
        if(dbOuvert==true)
         {
            QSqlQuery query;
                query.prepare("select  count(*) from CONTACT");//Requete pour compter le nombre de contact
                query.exec();
            if(!query.exec())
              {
                qDebug()<<"Compte échoué"  ;
                  return -1;
               }

           else
                 {
                    int total; //déclaration d'un entier
                while(query.next())
                     {
                        total=query.value(0).toInt();//On met dans l'entier total la valeur qui se trouve à la position 0 convertie en entier

                     }
                     qDebug()<<"Compte reussi "  ;
                return total;
                }

        }
}





