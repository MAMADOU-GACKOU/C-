/*!
*\file InteractionBDD.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "todobdd.h"

/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param QObject *parent et hérite d'un QObjet
 *initialisation du test de la base de donnée à false .
 *Appel de la fonction connexion() pour connecter la base de donnée .
 *
 */
TodoBDD::TodoBDD(QObject *parent) : QObject(parent)
{
    dbOuvert=false;
    connexion();
}
/*!
 *\brief implémentation du destructeur .
 *A la fermeture de la base on libère la memoire en faisant appel à la fonction closeDB().
 *
 */

TodoBDD::~TodoBDD()
{
    closeDb();
}

/*!
 *\fn  TodoBDD::connexion()
 *\brief Connexion à la base de donnée
 *On le nom de la base avec l'extension sqlite dans le tmp
 *On teste si la base est ouverte :
 *si non on retourne false
 *si Oui on crée une table si elle n'existe pas en verifiant la contrainte  pour la clé etrangère "ON DELETE CASCADE" ça signifie
 *si l'enregistrement parent est supprimé tous les enregistrements enfants vont suivre ensuite on affiche  "création de la table réussi " .
 *\return dbOuvert : le booleén à retourner
 */

bool TodoBDD::connexion()
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
           qDebug()<<"ouverture  todo reussie";
           dbOuvert=true;
           QSqlQuery query;
           query.exec("CREATE TABLE IF NOT EXISTS TODO"
                         "(id_todo integer primary key AUTOINCREMENT, "
                         "id_interaction integer NOT NULL,"
                         "datetodo TEXT,"
                         "contenu TEXT,"
 "FOREIGN KEY (id_interaction) REFERENCES INTERACTION (id_interaction) ON DELETE CASCADE )");/*création de la table ,
la contrainte pour la clé etrangère ça signifie si l'enregistrement parent est supprimé tous les enregistrements enfants vont suivre .*/
           if(!query.exec())
           {
               qDebug()<<"Erreur de creation todo";
           }
           else
           {
                qDebug()<<" creation table reussi";
           }
       }
       return  dbOuvert;
}

/*!
 *\fn TodoBDD::AjoutTodo(const int & id,Todo & inter)
 *\brief Création d'une tache
 *La fonction qui nous permet de créer ou inserer une tache en tenant compte des contraintes concernant les clés étrangères ou primaires
 *\param Todo & inter: representera l'intéraction qui sera ajouté .
 *\param const int & id : representera l'identifiant de l'intéraction pour lui ajouter la tache .
 */

bool TodoBDD::AjoutTodo(const int & id,Todo & inter)
{
    if(dbOuvert==true)
    {
        QSqlQuery query("SELECT * from TODO ");
        //Insertion de la requete
        query.prepare("INSERT INTO TODO(id_interaction,datetodo,contenu) "
                      "VALUES(:n, :m, :p)"); //insertion des données
        //remplissage de valeur
        query.bindValue(":n",QString::number(id));
        query.bindValue(":m", QString::fromStdString(inter.getDateTodo().fromDateString()));
        query.bindValue(":p",QString::fromStdString(inter.getContenuTodo()));

        if(!query.exec())
        {
            qDebug()<<"insertion todo non effectue";
            return false;
        }
       qDebug()<<"ajout todo effectue";

    }
    return true;
}

/*!
 *\fn  TodoBDD::bddAjoutTodo(int &i , Todo & inter)
 *\brief Ajout d'une tache
 *Slot pour ajouter une tache pour une intéraction ,  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param Todo & inter: representera la tache qui sera ajouté .
 *\param const int & id : representera l'identifiant de l'intéraction .
 * On appel la fonction AjoutTodo dans le slot pour lui donner les parametres du slot .
 */

void TodoBDD::bddAjoutTodo(int &i , Todo & inter)
{
    AjoutTodo(i,inter);
}

/*!
 *\fn TodoBDD::ListeTodoContact(const int & id,std::list<Todo> &li)const
 *\brief Affichage des taches d'une intéraction
 *L'affichage des taches d'une intéraction en utilisant la requete qui selectionne toutes les taches
 *d'une Intéraction dans la base de donnée en triant la liste à la fin par l'appel de sort (c++) .
 *\param std::list<Todo> &li: la liste des taches .
 *\param const int & id : representera l'identifiant de l'intéraction pour lui afficher ses taches .
 */
void TodoBDD::ListeTodoContact(const int & id,std::list<Todo> &li)const
{
    li.clear();
    if(dbOuvert==true)
        {
            QSqlQuery query;
            query.prepare("SELECT TODO.id_todo ,TODO.id_interaction,TODO.datetodo,TODO.contenu "
                          "FROM TODO,INTERACTION,CONTACT WHERE "
                          "TODO.id_interaction=INTERACTION.id_interaction and "
                          "INTERACTION.id_contact=CONTACT.id_contact and "
                          "CONTACT.id_contact=:n");
            query.bindValue(":n",QString::number(id));
            query.exec();
            if(!query.exec())
            {
                qDebug()<<"liste  Todo non ressortie";
            }
            else {
                qDebug()<<"requete  todo reussie";
                while(query.next())
                {
                    Todo inter;
                    QString r=query.value(0).toString();
                         inter.setIdtodo(r.toInt());

                           r=query.value(1).toString();

                           inter.setId_interaction(r.toInt());
                           r=query.value(2).toString();

                           inter.setDateTodo(inter.getDateTodo().toDateString(r.toStdString()));
                           r=query.value(3).toString();

                           inter.setContenuTodo(r.toStdString());

                           li.push_back(inter);

                }
                li.sort();
            }

    }
}

/*!
 *\fn  TodoBDD::bddListeTodoContact(int & id, std::list<Todo> & li)
 *\brief Afficher les taches d'une intéraction .
 *Slot pour affiche les taches d'une intéraction ,  c'est ce slot qu'on appelera dans le main pour le lier avec la fonction
 *correspondante à la fenetre principale .
 *\param std::list<Todo> & li:la liste des taches .
 *\param int & id : representera l'identifiant de l'intéraction .
 * On appel la fonction ListTodoContact dans le slot pour lui donner les parametres du slot .
 */

void TodoBDD::bddListeTodoContact(int & id, std::list<Todo> & li)
{
    ListeTodoContact(id,li);
}


/*!
 *\fn TodoBDD::ListeALLContact(std::list<Todo> & li) const
 *\brief Affichage toutes les taches de toutes les intéractions de tous les contacts .
 *On affiche toutes les taches en selectionnant toute la table TODO et on l'affiche .
 *\param std::list<Interaction> & li : la liste des todos  .
 */

void TodoBDD::ListeALLContact(std::list<Todo> & li) const
{
    li.clear();
    if(dbOuvert==true)
        {

          QSqlQuery  query("SELECT TODO.id_todo ,TODO.id_interaction,TODO.datetodo,TODO.contenu FROM TODO,INTERACTION,CONTACT WHERE "
                           "TODO.id_interaction=INTERACTION.id_interaction and "
                           "INTERACTION.id_contact=CONTACT.id_contact");
/*cette requete permet de récuperer toutes les taches de toutes les intéractions \n de tous les contacts dans la base de donnée.*/

            if(!query.exec())
            {
                qDebug()<<"liste  Todo ALL non ressortie";
            }
            else {
                qDebug()<<"requete  todo ALL reussie";
                while(query.next())
                {
                    Todo inter;
                    QString r=query.value(0).toString();
                         inter.setIdtodo(r.toInt());

                           r=query.value(1).toString();

                           inter.setId_interaction(r.toInt());
                           r=query.value(2).toString();

                           inter.setDateTodo(inter.getDateTodo().toDateString(r.toStdString()));
                           r=query.value(3).toString();

                           inter.setContenuTodo(r.toStdString());

                           li.push_back(inter);


                }
                li.sort(); //on trie la liste des taches par la date de création  .
            }

    }
}

/*!
 *\fn TodoBDD::bddListeALLContact(std::list<Todo> & li)
 *\brief Slot afficher toutes les taches
 *Slot pour afficher toutes les taches  de toutes les intéractions,  c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param std::list<Todo> & li: c'est la liste qu'on met dans le paramètre de la  fonction ListeALLContact pour
 * nous afficher toutes ses taches
 */
void TodoBDD::bddListeALLContact(std::list<Todo> & li)
{
    ListeALLContact(li);
}

/*!
 *\fn  TodoBDD::RechercheTodoCont(const int &id,QString & date1 ,QString & date2,std::list<Todo> & li) const
 *\brief Rechercher les taches entre deux dates pour un contact
 *c'est cette fonction qui nous permet de rechercher des taches entre deux dates pour un contact selectionné .
 *On rentrera l'intervalle à rechercher
 *on selectionnera dans la comboBox le contact
 *on appuyera sur le bouton rechercher .
 *on n'affiche rien si les todos n'existent pas entre ces dates  pour le contact
 *si oui on affiche toutes les taches entre ces dates  en triant les dates avec sort() par date de création .
 *\param int & id: l'identifiant du contact pour le quel on fera la recherche .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Todo> & li :la liste des taches .
 */
void TodoBDD::RechercheTodoCont(const int &id,QString & date1 ,QString & date2,std::list<Todo> & li) const
{
    li.clear();
    Date d;

    Date d1=d.toDateString(date1.toStdString());
    Date d2=d.toDateString(date2.toStdString());

        if(dbOuvert==true)
        {
            QSqlQuery query;
            query.prepare("SELECT TODO.id_todo ,TODO.id_interaction,TODO.datetodo,TODO.contenu FROM TODO,INTERACTION,CONTACT WHERE "
                          "TODO.id_interaction=INTERACTION.id_interaction and "
                          "INTERACTION.id_contact=CONTACT.id_contact and "
                          "CONTACT.id_contact=:n");
            query.bindValue(":n",QString::number(id));
            query.exec();


            if(!query.exec())
            {
                qDebug()<<"probleme niveau recherche contact entre 2 date";
            }
            else
                {
                qDebug()<<"commençons la  recherche de todo du contact";

                while(query.next())
                {
                      QString r=query.value(2).toString();
                    Date dc=d.toDateString(r.toStdString());
                    if(d1<dc && dc<d2 )
                    {
                        Todo inter;
                        r=query.value(0).toString();
                             inter.setIdtodo(r.toInt());

                               r=query.value(1).toString();

                               inter.setId_interaction(r.toInt());

                               inter.setDateTodo(dc);
                               r=query.value(3).toString();

                               inter.setContenuTodo(r.toStdString());


                              li.push_back(inter);//on insert la tache dans la liste
                     }


                }
                 li.sort();//on trie la liste par date de création
            }

    }
}
/*!
 *\fn TodoBDD::bddRechercheTodoCont(int &id,QString & date1 ,QString & date2,std::list<Todo> & li)
 *\brief Slot pour rechercher les taches d'un contact .
 *Slot pour afficher les taches  d'un contact entre deux dates,  c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param int & id: l'identifiant du contact pour le quel on fera la recherche  qui se trouvera dans notre comboBox .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Todo> & li :la liste des taches .
 */
void TodoBDD::bddRechercheTodoCont(int &id,QString & date1 ,QString & date2,std::list<Todo> & li)
{
    RechercheTodoCont(id,date1,date2,li);
}

/*!
 *\fn  TodoBDD::RechercheALLTodoCont(QString & date1 ,QString & date2,std::list<Todo> & li)const
 *\brief Rechercher les taches de tous les contacts entre deux dates
 *c'est cette fonction qui nous permet de rechercher des taches entre deux dates .
 *On rentrera l'intervalle à rechercher en Selectionnant la table:
 *on n'affiche rien si les taches n'existent pas entre ces dates
 *si oui on affiche toutes les taches entre ces dates  en triant les dates avec sort() par date de création .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param sstd::list<Todo> & li :liste des taches .
 */
void TodoBDD::RechercheALLTodoCont(QString & date1 ,QString & date2,std::list<Todo> & li)const
{
    li.clear();
    Date d;

    Date d1=d.toDateString(date1.toStdString());
    Date d2=d.toDateString(date2.toStdString());

        if(dbOuvert==true)
        {

           QSqlQuery  query("SELECT TODO.id_todo ,TODO.id_interaction,TODO.datetodo,TODO.contenu FROM TODO,INTERACTION,CONTACT WHERE "
                            "TODO.id_interaction=INTERACTION.id_interaction and "
                            "INTERACTION.id_contact=CONTACT.id_contact");

            if(!query.exec())
            {
                qDebug()<<"probleme niveau recherche ALLcontact entre 2 date";
            }
            else
                {
                qDebug()<<"commençons la  recherche de todo ALL contact";

                while(query.next())
                {
                      QString r=query.value(2).toString();
                    Date dc=d.toDateString(r.toStdString());
                    if(d1<dc && dc<d2 )
                    {
                        Todo inter;
                        r=query.value(0).toString();
                             inter.setIdtodo(r.toInt());

                               r=query.value(1).toString();

                               inter.setId_interaction(r.toInt());

                               inter.setDateTodo(dc);
                               r=query.value(3).toString();

                               inter.setContenuTodo(r.toStdString());


                              li.push_back(inter); //ajout dans la liste des taches le Todo .
                     }


                }
      li.sort();//trier la liste des taches
            }

    }
}

/*!
 *\fn TodoBDD::bddRechercheALLTodoCont(QString & date1 ,QString & date2,std::list<Todo> & li)
 *\brief Slot pour rechercher les taches de tous les contacts .
 *Slot pour rechercher les taches des contacts entre deux dates,c'est ce slot qu'on appelera dans le main pour le lier  à sa fonction
 *correspondante dans la fenetre principale .
 *\param QString & date1 : la date qui represente le premier intervalle .
 *\param QString & date2 : la date qui represente le premier intervalle .
 *\param std::list<Todo> & li :la liste des taches .
 */
void TodoBDD::bddRechercheALLTodoCont(QString & date1 ,QString & date2,std::list<Todo> & li)
{
    RechercheALLTodoCont(date1,date2,li);
}

/*!
 *\fn InteractionBDD::isOpen(bool &b)
 *\brief Teste on affectera b à b
 *\param bool & b : le booléan en paramètre .
 */
void TodoBDD::isOpen(bool &b)
{
    isDBopen(b);
}

/*!
 *\fn ContactBDD::closeDb()
 *\brief fermer la base
 * On teste si le boolean est à true on ferme la base
 */

void TodoBDD::closeDb()
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

void TodoBDD::isDBopen(bool &b)
{
    dbOuvert=b;
}

