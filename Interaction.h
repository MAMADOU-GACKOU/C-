#ifndef INTERACTION_H
#define INTERACTION_H

/*!
*file Interaction.h
*\author BARRY Thierno & DIALLO Iliassou
*/

#include <ostream>
#include <string>
#include "Date.h"

/*!
*\class Interaction
*\brief La classe permet de gerer une interaction  suivant son contenu et sa date de creation
*/

class Interaction
{
  /*!
   *@brief  permet d'indiquer une date de rendez-vous
   *@brief Le  commentaire
   *
   */

private:

  Date  rdv; /*!< attribut de type date qui gère la date */
  std::string contenu;/*!< attribut de type string qui gère le contenu dans l'intéraction */
  int idContact=0;/*!< attribut de type int qui gère l'identififiant d'un contact */
  int idInteraction=0;/*!< attribut de type int qui gère l'identififiant d'une intéraction */
public :
/*!
*\brief Constructeur
*
*Contructeur de la classe Interaction
*/
  Interaction();
  /*!
  *\brief  constructeur avec 2 parametres
  *\param Date: definition d'une date  de rendez-vous
  *\param string: commentaire du rendez-vous
  */
  Interaction(const Date&,const std::string&);


  /*!
  *\brief Les getteurs et mutateurs
  * Les fonction getteurs et mutateurs
  */

  /*!
   *\brief Recupère le contenu d'une intéraction
   *\return le contenu  d'une interaction
   */
  std::string getContenu()const;
  /*!
   *\brief Recupère l'identifiant d'un Contact
   *\return l'identifiant  d'un Contact
   */
    int getIdContact() const;
    /*!
     *\brief Recupère l'identifiant d'une Interaction
     *\return l'identifiant  d'une intéraction .
     */
      int getIdInteraction() const;
  /*!
   *\brief Recupère la date d'une intéraction
   *\return la date  d'une interaction
   */
  Date getRDV()const;
  /*!
    *\brief modifier la Date d'une interaction
    *\param const Date &: la date qu'on utilisera pour faire la modification .
    */
  void setRDV(const Date &);
  /*!
   *\brief modifier l'id d'un Contact
   *\param const int & : le string qu'on utilisera pour faire la modification de l'id du contact .
   */
  void setIdContact(const int &);
  /*!
   *\brief modifier l'id d'une interaction
   *\param const int & : le string qu'on utilisera pour faire la modification de l'id de l'intéraction .
   */

  void setIdInteraction(const int &);
   /*!
    *\brief modifier le contenu d'une interaction
    *\param const std:: string &: le string qu'on utilisera pour faire la modification .
    */
  void setContenu(const std:: string &);
      /*!
      *\brief comparaison
      * La comparaison de l'Interaction courant à l'intéraction en paramètre
      *\param const Interaction & : l'interaction passé en paramètre pour la comparaison .
      */
  bool operator<(const Interaction &) const;
  /*!
   *\brief L'affichage d'une Intéraction
   *\param std::ostream &:  il nous permetra de faire l'affichage .
   *\param const Intéraction &: il nous permet d'afficher une interaction càd le rdv et contenu .
   */
  friend std:: ostream& operator <<(std:: ostream &, const Interaction
&);



};

#endif // INTERACTION_H
