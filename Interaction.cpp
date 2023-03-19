/*!
*\file Interaction.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "Interaction.h"

/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param const Date &date : elle remplacera la date courante .
 *\param const std::string  &visite: elle remplacera le contenu courant .
 */
Interaction::Interaction(const Date &date,const std::string  &visite):rdv(date),contenu(visite)
{

}

/*!
 *\brief implémentation du constructeur par défaut .
 */
Interaction::Interaction():rdv(),contenu("")
{
}

/*!
 *\brief accesseur "id_contact"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'identifiant d'un contact .
 */

int Interaction::getIdContact() const
{
    return idContact;
}

/*!
 *\brief implémentation du mutateur "id_contact"
 *\param  l'entier const int & value, il remplacera l'identifiant du contact courant .
 */

void Interaction::setIdContact(const int & value)
{
    idContact = value;
}

/*!
 *\brief accesseur "id_interaction"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'identifiant d'une intéraction .
 */

int Interaction::getIdInteraction() const
{
    return idInteraction;
}
/*!
 *\brief implémentation du mutateur "id_interaction"
 *\param  l'entier const int & value, il remplacera l'identifiant  de l'intéraction courante .
 */
void Interaction::setIdInteraction(const int & value)
{
    idInteraction = value;
}

/*!
 *\brief accesseur "Contenu"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au contenu d'une intéraction .
 */

std::string Interaction::getContenu() const
{
    return contenu;
}
/*!
 *\brief implémentation du mutateur "Contenu"
 *\param  l'entier const int & value, il remplacera le Contenu  de l'intéraction courante .
 */
void Interaction::setContenu(const std::string  & cont)
{
  contenu=cont;
}

/*!
 *\brief accesseur " rdv "
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à la date d'une intéraction .
 */

Date Interaction::getRDV() const
{
    return rdv;
}

/*!
 *\brief implémentation du mutateur "Contenu"
 *\param  const Date & date: elle remplacera la date de l'intéraction courante .
 */
void Interaction::setRDV(const Date & date)
{
    rdv=date;
}

/*!
 *\brief test de comparaison entre 2 dates
 *\param const Interaction &i1 : la date à comparer avec la date courante
 *\return un booléen VRAI si égalité
 *\return un booléen FAUX si non égalité
 */
bool Interaction::operator<(const Interaction &i1) const
{
    if(this->getRDV()<i1.getRDV())
    {
      return true;
    }
    return false;
}

/*!
 *\brief Affichage de l'intéraction .
 *\param std:: ostream &o :la bibliothèque ostream qui permet l'affichage
 *\param const Interaction& action:l'intéraction à afficher.
 *\return o : pour l'affichage  de l'intéraction càd sa date et son contenu .
 */

 std:: ostream& operator <<(std:: ostream & o, const Interaction& action)
{

  o<<"rdv le "<<action.getRDV()<<" Aperçu: "<<action.getContenu();

  return o;
}

