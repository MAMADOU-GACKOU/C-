/*!
*\file Date.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/
#include "Date.h"

/*!
 *\brief implémentation du constructeur par défaut .
 */
Date::Date()
{
  time_t n=time(0);

  date=localtime(&n);

  this->setJour(getJourtm());
  this->setMois(getMoistm());
  this->setAnnee(getAnneetm());
}

/*!
 *\brief implémentation du constructeur avec paramètre en faisant appel à la methode fromDate().
 *\param const int &a: elle remplacera l'année courante .
 *\param const int &m : elle remplacera le mois courant .
 *\param const int &j : elle remplacera le jour courant .
 */
Date::Date(const int &a,const int & m,const int &j)
{

  fromDate(j,m,a);

}

/*!
 *\brief accesseur de la structure "Jour"
 *pas de paramètre, fonction const
 *\return le jour en utilisant la structure .
 */

int Date::getJourtm() const
{
  return date->tm_mday;
}
/*!
 *\brief accesseur  de la structure "Mois"
 *pas de paramètre, fonction const
 *\return le mois en utilisant la structure .
 */

int Date::getMoistm() const
{
  return date->tm_mon+1;
}

/*!
 *\brief accesseur de la structure "Année"
 *pas de paramètre, fonction const
 *\return l'année en utilisant la structure .
 */
int Date::getAnneetm() const
{
  return date->tm_year+1900;
}

/*!
 *\brief accesseur "Jour"
 *pas de paramètre, fonction const
 *\return le jour .
 */

int Date::getJour() const
{
  return jour;
}
/*!
 *\brief accesseur "Mois"
 *pas de paramètre, fonction const
 *\return le Mois .
 */

int Date::getMois() const
{
  return mois;
}
/*!
 *\brief accesseur "Année"
 *pas de paramètre, fonction const
 *\return l'année .
 */

int Date::getAnnee() const
{
 return annee;
}

/*!
 *\brief implémentation du mutateur "Jour" en faisant appel à fromDate() .
 *\param  const int &j : il remplacera le jour courant .
 */
void Date::setJour(const int &j)
{

  fromDate(j,getMoistm(),getAnneetm());

}

/*!
 *\brief implémentation du mutateur "Mois" en faisant appel à fromDate() .
 *\param  const int &m : il remplacera le Mois courant .
 */
void Date::setMois(const int &m)
{
  fromDate(getJourtm(),m,getAnneetm());

}
/*!
 *\brief implémentation du mutateur "Année" en faisant appel à fromDate() .
 *\param  const int &a : il remplacera l'année courante .
 */
void Date::setAnnee(const int & a)
{
  fromDate(getJourtm(),getMoistm(),a);

}

/*!
 *\brief methode pour remplir la date
 * La méthode fromDate qui recoit en parametre le jour ,mois,annee afin definir
 * une date en se referant de la date du jour avec la stucture date et enfin on affectera
 * aux attributs respectivement getJourtm(),getMoistm(),getAnneetm.
 * \param const int &J: pour gérer le jour .
 * \param const int &M: pour gérer le mois .
 * \param const int &A: pour gérer l'année.
 */

void Date::fromDate(const int &J,const int &M,const int &A)
{
  time_t tim=time(NULL); //on initialise la structure
  struct tm * tem=localtime(&tim);//on met dans tem la date courrante
  tem->tm_mday=J;//on met dans tem le jour passé en parametre
  tem->tm_mon=M-1;

  tem->tm_year=A-1900;

  tim=mktime(tem);

  date=localtime(&tim);

  this->annee = getAnneetm();//on récupère l'année .
  this->mois = getMoistm();//on récupère le mois .
  this->jour = getJourtm();//on récupère le jour .
}

/*!
 *\brief Conversion
 *La méthode qui convertie la date en string .
 *pas de paramètre, fonction const
 *\return std::to_string(getAnnee())+"-"+momois+"-"+mojour : après avoir converti en string la date on l'a retourne sous ce format ( jj-mm-aaaa ) ;
 */
std::string  Date::fromDateString() const
{
    std::string momois=std::to_string(getMois());
    std::string mojour=std::to_string(getJour());
    if(getMois()<10)
    {
        momois="0"+std::to_string(getMois());
    }
    if(getJour()<10)
    {
        mojour="0"+std::to_string(getJour());
    }

return std::to_string(getAnnee())+"-"+momois+"-"+mojour;
}

/*!
 *\brief Conversion
 *La méthode qui convertie le String en type date en utilisant la fonction substr pour découper
 *les chaines et aussion a utilisé stoi pour convertir la date en int.
 *\param const std::string &dat :  la date à convertir .
 *\return d : on retourne la date convertie pour pouvoir l'insérer dans la base normalement .
 */

Date Date::toDateString(const std::string &dat  ) const
{

  std::string dat1=dat.substr(0,4);
  std::string dat2=dat.substr(5,2);
  std::string dat3=dat.substr(8,2);
  int a=std::stoi(dat1);
  int m=std::stoi(dat2);
  int j=std::stoi(dat3);
   Date d(a,m,j);
return    d;
}

/*!
 *\brief test de comparaison entre 2 dates
 *\param const Date &da: la date à comparer avec la date courante
 *\return un booléen VRAI si égalité
 *\return un booléen FAUX si non égalité
 */

bool Date::operator<(const Date &da) const
{
    if(this->getAnnee()<da.getAnnee())
        {  return true;}
    else if(this->getAnnee()==da.getAnnee()&&this->getMois()<da.getMois())
         {  return true;}
   else if(this->getAnnee()==da.getAnnee()&&this->getMois()==da.getMois()&&this->getJour()<da.getJour())
              {  return true;}
    else
          {   return false;}
}

/*!
 *\brief Affichage d'une date
 *\param std:: ostream &os :la bibliothèque ostream
 *\param const Date &temp :la date à afficher sous ce format jj-mm-aaaa .
 *\return os : pour l'affichage  d'une date .
 */
std::ostream& operator <<(std:: ostream &os, const Date &temp)
{
  os<<temp.getAnnee()<<"-"<<temp.getMois()<<"-"<<temp.getJour()<<"";
  return os;
}
