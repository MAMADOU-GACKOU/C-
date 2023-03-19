/*!
*\file Todo.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "Todo.h"

/*!
 *\brief implémentation du constructeur par défaut .
 */

Todo::Todo():date(),contenuTodo("")
{

}

/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param const Date &date : elle remplacera la date courante  du todo.
 *\param const std::string  &contenu: elle remplacera la tache courante .
 */
Todo::Todo(const Date &dater,const std::string &contenu):date(dater),contenuTodo(contenu)
{

}

/*!
 *\brief accesseur "id_interaction"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'identifiant d'une intéraction .
 */

int Todo::getId_interaction() const
{
    return id_interaction;
}

/*!
 *\brief implémentation du mutateur "id_interaction"
 *\param  l'entier const int & value, il remplacera l'identifiant  de l'intéraction courante .
 */

void Todo::setId_interaction(const int& value)
{
    id_interaction = value;
}

/*!
 *\brief accesseur "idTodo"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'identifiant d'une tache .
 */
int Todo::getIdtodo() const
{
    return idtodo;
}

/*!
 *\brief implémentation du mutateur "idTodo"
 *\param  l'entier const int & value, il remplacera l'identifiant  de la tache courante .
 */
void Todo::setIdtodo(const int & value)
{
    idtodo = value;
}


/*!
 *\brief accesseur " date "
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à la date d'une tache .
 */

Date Todo::getDateTodo() const
{

  return date;
}
/*!
 *\brief implémentation du mutateur "date"
 *\param  const Date & date: elle remplacera la date de la tache courante .
 */
 void Todo::setDateTodo(const Date &dater)
 {
    date=dater;
 }
/*!
 *\brief accesseur "ContenuTodo"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au contenuTodo d'une Tache .
 */
std::string Todo::getContenuTodo() const
{
  return contenuTodo;
}
/*!
 *\brief implémentation du mutateur "ContenuTodo"
 *\param  l'entier const int & value, il remplacera le Contenu  de la tache courante .
 */
void Todo::setContenuTodo(const std::string &contient)
{
  contenuTodo=contient;

}


/*!
 *\brief test de comparaison entre 2 dates
 *\param const Todo &to : la date à comparer avec la date courante .
 *\return un booléen VRAI si égalité
 *\return un booléen FAUX si non égalité
 */

bool Todo::operator<(const Todo &to) const
{
  if(this->getDateTodo()<to.getDateTodo())
  {
    return true;
  }
  return false;
}

/*!
 *\brief Affichage de la tache  .
 *\param std:: ostream &os :la bibliothèque ostream qui permet l'affichage .
 *\param const Todo &todo:la tache à afficher.
 *\return os : pour l'affichage  de la tache càd sa date et son contenu .
 */
 std::ostream& operator<<(std::ostream &os,const Todo &todo)
 {
   os<<"@todo "<<todo.getContenuTodo()<<" @date "<<todo.getDateTodo()<<"";
   return os;
 }
