#ifndef TODO_H
#define TODO_H

/*!
*\file Todo.h
*\author BARRY Thierno Oumar & DIALLO Iliassou
*
*/

#include "Date.h"
#include <ostream>
#include <string>

/*!
*\class Todo
*\brief  cette classe permet de gerer une tache  suivant son contenu et sa date de creation
*/
class Todo
{

private:
  Date  date;/*!< attribut de type Date pour gérer la date */
  std::string contenuTodo; /*!< attribut de type string pour gérer le contenu de la tache */
  int id_interaction=0;/*!< attribut pour gérer l'id de l'intéraction */
  int idtodo=0; /*!< attribut pour gérer l'id de tache */

public:
  /*!
  *\brief Constructeur
  *
  *Contructeur de la classe Todo
  */
  Todo();
  /*!
  *\brief  constructeur 2 parametre
  *\param const Date& : definition d'une date  de tache a faire
  *\param const std::string&:commentaire d'un contenu de la tache
  **/
  Todo(const Date&,const std::string&);


  /*!
   *\brief Getteurs et setteurs
   *\Les fonctions getteurs et setteurs .
   */

  /*!
   *\brief Recupère la date du Todo
   *\return la date de la tache
   */

  Date getDateTodo() const;

  /*!
  *@brief recupère le contenu de la tache
  *@return le contenu du todo
  */
  std::string getContenuTodo() const;

   /*!
   *\brief Recupère l'identifiant d'une Interaction
   *\return l'identifiant  d'une intéraction .
   */

  int getId_interaction() const;
  /*!
  *@brief recupère le contenu de la tache
  *@return le contenu du todo
  */
  int getIdtodo() const;

  /*!
    *\brief modifier la date de tache
    *\param const Date&: la date à modifier
    */
  void setDateTodo(const Date&);
  /*!
   *\brief modifier l'id du todo
   *\param const int & : l'entier qu'on utilisera pour faire la modification de l'id du todo  .
   */
  void setIdtodo(const int &);
  /*!
   *\brief modifier l'id d'une interaction
   *\param const int & : l'entier qu'on utilisera pour faire la modification de l'id de l'interaction  .
   */
  void setId_interaction(const int& );
  /*!
    *\brief modifier le contenu de tache
    *\param const std::string&: le contenu à modifier
    */
  void setContenuTodo(const std::string&);
  /*!
  *\brief   comparaison de la tache courante suivant
  *\param const Todo &: le parametre à affiher les Todos
  *
  */
  bool operator<(const Todo &) const;
  /*!
   *\brief L'affichage d'un Todo
   *\param std::ostream &:  il nous permetra de faire l'affichage .
   *\param const Todo&: il nous permet d'afficher une tache.
   */
friend std::ostream& operator<<(std::ostream&,const Todo&);



};

#endif // TODO_H
