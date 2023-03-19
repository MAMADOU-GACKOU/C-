/*!
*\file main.cpp
*\brief Application Qt.
*\author BARRY Thierno Oumar & DIALLO Iliassou
*
*/

#include "fenetreprincipale.h"
#include <contactbdd.h>
#include <todobdd.h>
#include <interactionbdd.h>
#include <QApplication>

/*!
*\class main
*\brief La classe main
* La classe qui est la plus importante car elle permet de faire la connection de la fenetre principale
* à la base de donnée et aussi elle nous permet d'afficher les interfaces .
* \param int argc : l'entier en parametre .
* \param char *argv[] : la chaine de caractère en paramètre .
*
*/

int main(int argc, char *argv[])
{
        QApplication a(argc, argv); /*!< Initialisation de a avec les parametres argc et argv */
        FenetrePrincipale w; /*!< déclaration de w de type fenetre principale qui est une classe */
        ContactBDD c; /*!< déclaration de c de type ContactBDD qui est une classe qui represente la base de donnée d'un contact */
        InteractionBDD interact; /*!< déclaration de interact de type InteractionBDD qui est une classe qui represente la base de donnée d'une intéraction  */
        TodoBDD taches; /*!< déclaration de taches de type TodoBDD qui est une classe qui represente la base de donnée d'un Todo */


         /*!
          *\brief Les connections pour tout ce qui concerne le Contact
          *Les connections (signaux) qu'on liera à la fonction correspondante dans labas de données  concernant un contact  .
          */

        /*!
         *\brief connection lié à l'affichage d'un contact
         *La connection du signal de  l'application principale
         *à la base de donnée correspondante à l'affichage d'un contact dans la base .
         */
        QObject::connect(&w,SIGNAL(sigGetContactList(std::list<Contact>&)),&c,SLOT( bddListeContact(std::list<Contact> &)));
        /*!
         *\brief connection lié à creer un contact
         *La connection du signal de  l'application principale
         *à la base de donnée correspondante à la création d'un d'un contact dans la base.
         */
        QObject::connect(&w,SIGNAL(sigInsert( Contact &)),&c,SLOT( bbdNouveauContact(Contact &)));
        /*!
         *\brief connection lié à la modification d'un contact
         *La connection du signal de  l'application principale
         *à la base de donnée correspondante à la modification d'un contact dans la base .
         */
        QObject::connect(&w,SIGNAL(sigModifier( int & , Contact &)),&c,SLOT( bddModifContact( int & , Contact &)));
        /*!
         *\brief connection lié à la suppression d'un contact
         *La connection du signal de  l'application principale
         *à la base de donnée correspondante à la suppression d'un contact dans la base .
         */
        QObject::connect(&w,SIGNAL(sigSupprimer( int &)),&c,SLOT( bddSupprimeContact( int  & )));
        /*!
         *\brief connection lié à la Recherche un contact
         *La connection du signal de  l'application principale
         *à la base de donnée correspondante à la recherche d'un contact dans la base .
         */
        QObject::connect(&w,SIGNAL(sigRechercheUnContact(QString &  ,QString & ,QString & ,std::list<Contact> & )),
                                    &c,SLOT(bddRechercherContact(QString &,QString & ,QString & ,std::list<Contact>&)));
        /*!
         *\brief connection lié au Nombre de contact
         *La connection du signal de l'application principale
         *à la base de donnée correspondante au  Nombre total de contact dans la base .
         */
        QObject::connect(&c,SIGNAL(nombreTotalContact( int &  )),&w,SLOT(TotalContact(int &)));


        /*!
         *\brief Les connections pour tout ce qui concernant une Intéraction
         *Les connections (signaux) qu'on liera à la fonction correspondante dans labas de données  concernant une intéraction .
         */

        /*!
         *\brief connection lié à l'Ajout d'une intéraction
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'ajout d'une intéraction dans la base .
         */
        QObject::connect(&w,SIGNAL(sigAjoutInteraction(int &,Interaction &)),
                               &interact,SLOT(bddAjoutInteraction(int &,Interaction &)));
        /*!
         *\brief connection lié à l'Affichage d'une intéraction
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'affichage d'une intéraction d'un contact dans la base .
         */
        QObject::connect(&w,SIGNAL(sigListeInteraction(int &,std::list<Interaction> &)),
                               &interact,SLOT( bddListeInteraction(int &,std::list<Interaction> &)));
        /*!
         *\brief connection lié à l'Affichage toutes les intérations des contacts
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'affichage de toutes les intérations des contacts dans la base .
         */
        QObject::connect(&w,SIGNAL(sigListeInteractionALL(std::list<Interaction> &)),
                               &interact,SLOT( bddListeInteractionALL(std::list<Interaction> &)));
        /*!
         *\brief connection lié à l'affichage des interactions entre deux dates
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'affichage des interactions de tous les contacts entre deux dates dans la base .
         */
        QObject::connect(&w,SIGNAL( sigRechercheInteraction(QString &,QString &,std::list<Interaction> &)),
                                     &interact,SLOT( bddRechercheInteraction(QString &,QString &,std::list<Interaction> &)));
        /*!
         *\brief connection lié à la recherche d'une intéraction d'un contact
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à la recherche des interactions pour un contact entre deux dates dans la base .
         */
        QObject::connect(&w,SIGNAL( sigRechercheInteractionCont(int & , QString & , QString & , std::list<Interaction> &)),
                               &interact,SLOT( bddRechercheInteractionCont(int & , QString & , QString & , std::list<Interaction> &)));



        /*!
         *\brief Les connections pour tout ce qui concernant un Todo
         *Les connections (signaux) qu'on liera à la fonction correspondante dans labas de données  concernant les taches .
         */

        /*!
         *\brief connection lié  ajouter une tache "todo"
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'ajout d'une tache dans la base .
         */
        QObject::connect(&w,SIGNAL(sigAjoutTodo(int &,Todo &)),&taches,SLOT(bddAjoutTodo(int &,Todo &)));
        /*!
         *\brief connection lié  à l'affichage des taches pour tous les contacts .
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à l'affichage des taches pour tous les contacts dans la base .
         */
        QObject::connect(&w,SIGNAL(sigListeALLContact(std::list<Todo> &)),&taches,SLOT(bddListeALLContact(std::list<Todo> &)));
        /*!
         *\brief connection lié  à la recherche d'une tache entre deux dates pour un contact.
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à  la recherche d'une tache entre deux dates pour un contact entre deux dates dans la base .
         */
        QObject::connect(&w,SIGNAL( sigRechercheTodoCont(int & , QString & , QString & , std::list<Todo> &)),
                                       &taches,SLOT( bddRechercheTodoCont(int & , QString & , QString & , std::list<Todo> &)));
        /*!
         *\brief connection lié  à la recherche des taches entre deux dates .
         *La connection du signal de l'application principale
         *à la base de donnée correspondante à la recherche des taches entre deux dates pour tous les contacts dans la base .
         */
        QObject::connect(&w,SIGNAL( sigRechercheALLTodoCont( QString & , QString & , std::list<Todo> &)),
                                         &taches,SLOT( bddRechercheALLTodoCont( QString & , QString & , std::list<Todo> &)));


        w.show(); /*!< w etant de type FenetrePrincipale et on l'affiche en faisant appel à la fonction show() . */
        /*!
         *\brief Execution de l'application .
         *\return  a.exec() : on exécute l'application .
         */
        return a.exec();

}
