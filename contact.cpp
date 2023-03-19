/*!
*\file contact.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "contact.h"
#include "contact.h"

/*!
 *\brief implémentation du constructeur par défaut .
 */
Contact::Contact():nom(""),prenom(""),entreprise(""),mail(""),telephone(""),URIphoto(""),dateDecreation()
{
}

/*!
 *\brief implémentation du constructeur avec paramètre .
 *\param const std::string &n : elle remplacera le nom courant .
 *\param const std::string &p : elle remplacera le prenom courant .
 *\param const std::string &e : elle remplacera l'entreprise courante .
 *\param const std::string &em : elle remplacera l'email courant .
 *\param const std::string &t : elle remplacera le telephone courant .
 *\param const std::string &photo :  elle remplacera la photo courante .
 */

Contact::Contact(const std::string &n,const std::string &p,const std::string &e,
    const std::string & em,const std::string &t,const std::string &photo):nom(n),prenom(p),entreprise(e),mail(em),telephone(t),URIphoto(photo)
    {
    }


/*!
 *\brief accesseur "id_contact"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'identifiant d'un contact .
 */

int Contact::getId_contact() const
{
    return id_contact;
}

/*!
 *\brief implémentation du mutateur "id_contact"
 *\param  l'entier const int & value, il remplacera l'identifian courant .
 */
void Contact::setId_contact(const int & value)
{
    id_contact = value;
}

/*!
 *\brief accesseur "Nom"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au nom d'un contact .
 */
std::string Contact::getNom() const
{
    return nom;
}

/*!
 *\brief implémentation du mutateur "Nom"
 *\param  std::string (const): il remplacera le nom courant  .
 */
void Contact::setNom(const std::string &n)
{

    nom=n;
}

/*!
 *\brief accesseur "Prenom"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au Prenom d'un contact .
 */

std::string Contact::getPrenom() const
{
    return prenom;
}

/*!
 *\brief implémentation du mutateur "prenom"
 *\param  std::string &p : il remplacera le prenom courant  .
 */
void Contact::setPrenom(const std::string &p)
{

   prenom=p;
}
/*!
 *\brief accesseur "Entreprise"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'Entreprise d'un contact .
 */
std::string Contact::getEntreprise() const
{
    return entreprise;
}
/*!
 *\brief implémentation du mutateur "Entreprise"
 *\param  std::string &e : il remplacera l'Entreprise courant  .
 */

void Contact::setEntreprise(const std::string &e)
{

   entreprise=e;
}

/*!
 *\brief accesseur "Telephone"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au Telephone d'un contact .
 */

std::string Contact::getTelephone() const
{

    return telephone;
}
/*!
 *\brief implémentation du mutateur "Telephone"
 *\param  std::string &t : il remplacera le telephone courant  .
 */

void Contact::setTelephone(const std::string &t)
{
   telephone=t;
}

/*!
 *\brief accesseur "URIPhoto"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond à l'URIPhoto d'un contact .
 */

std::string Contact::getURIPhoto() const
{

    return URIphoto;
}

/*!
 *\brief implémentation du mutateur "URIPhoto"
 *\param  std::string &p : il remplacera la photo courante .
 */

void Contact::setURIPhoto(const std::string &p)
{

   URIphoto=p;
}

/*!
 *\brief accesseur "Mail"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond au Mail d'un contact .
 */

std::string Contact::getMail()  const
{

    return mail;
}

/*!
 *\brief implémentation du mutateur "Mail"
 *\param  std::string &m : il remplacera le Mail courant .
 */

void Contact::setMail(const std::string &m)
{
       mail=m;
}

/*!
 *\brief accesseur "DateDecreation"
 *pas de paramètre, fonction const
 *\return le std::string qui correspond a la DateDecreation d'un contact .
 */

Date Contact::getDateDecreation() const
{
    return dateDecreation;

}

/*!
 *\brief implémentation du mutateur "DateDecreation"
 *\param  const Date &de : il remplacera la DateDecreation courante .
 */

void Contact::setDateDecreation(const Date &de)
{
      dateDecreation=de;
}

/*!
 *\brief test d'égalité entre 2 contacts
 *\param const Contact &c1 : le contact à égaliser .
 *\return un booléen VRAI si égalité
 *\return un booléen FAUX si non égalité
 */
bool  Contact::operator==(const Contact &c1) const
{
    if(getNom()==c1.getNom())
        if(getPrenom()==c1.getPrenom())
            if(getEntreprise()==c1.getEntreprise())
                if(getTelephone()==c1.getTelephone())
                    if(getURIPhoto()==c1.getURIPhoto())
                        return true;
    return false;
}

/*!
 *\brief test de comparaison entre 2 dates
 *\param const Contact &da: le contact à comparer entre la date courante
 *\return un booléen VRAI si égalité
 *\return un booléen FAUX si non égalité
 */
bool Contact::operator<(const Contact &da) const
{
    if(this->getDateDecreation()<da.getDateDecreation())
        {  return true;}
    else
          {   return false;}
}

/*!
 *\brief Affichage d'une date
 *\param std:: ostream &o :la bibliothèque ostream
 *\param const Contact &c :le contact à afficher
 *\return o pour l'affichage  d'un contact
 */
std::ostream& operator <<(std:: ostream &o,const Contact &c)
{
  o<<c.getNom()<<"\n";
  o<<c.getPrenom()<<"\n";
  o<<c.getEntreprise()<<"\n";
  o<<c.getMail()<<"\n";
  o<<c.getTelephone()<<"\n";
  o<<c.getURIPhoto()<<"\n";
  o<<c.getDateDecreation().fromDateString()<<"\n";

return o;

}
