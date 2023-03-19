/*!
 *\file Date.h
 *\author BARRY Thierno & Diallo Iliassou
 */

#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <ostream>
#include <string>

/*!
*\class Date
*\brief la classe reprensentant la  Date
* La classe date nous permet de definir la date courante et les differentes
* utilisations que nous auront a faire.
*/

class Date
{

private:
 struct tm  * date; /*!< une structure tm  qui nous permet de gerer la date  */
 int jour; /*!< un attribut de type int qui nous permet de gerer le jour  */
 int mois;  /*!< un attribut de type int qui permet de gerer le mois . */
 int annee;  /*!< un attribut de type int qui permet de gerer l'annee . */
public :
/*!
 *\brief Constructeur
 * Constructeur de la classe Date
 */
 Date();

/*!
 * \brief constructeur
 * \param const int & : initialise le jour d'une date .
 * \param const int & : initialise le mois d'une date .
 * \param const int & : initialis l'année d'une date .
 */
    Date(const int &,const int & ,const int &);

    /*!
     *\brief Accesseurs
     *\brief methode pour recuperer le jour de la structure tm ;
     */

    /*!
     *\brief Recupère le jour dans la structure tm
     *\return  le jour de la structure tm ;
     */
    int getJourtm() const;
     /*!
      *\brief Recupère le mois dans la structure tm
      *\return  le mois de la structure tm ;
      */
    int getMoistm() const;
    /*!
     *\brief Recupère l'année dans la structure tm
     *\return  l'année de la structure tm ;
     */
    int getAnneetm() const;
/*!
 *\brief Recupère le jour pour la date;
 * \return le jour de la date
 */
    int getJour() const;
    /*!
     *\brief Recupère le mois pour la date ;
     * \return le mois de la date
     */
     int getMois() const;
     /*!
      *\brief Recupère l'année pour la date ;
      * \return l'année de la date
      */
    int getAnnee() const;

    /*!
     *\brief modifier le jour de la date
     *\param const int & :le jour à modifier
     */
    void setJour(const int &);
    /*!
     *\brief modifier le mois de la date
     *\param const int & :la date à modifier
     */
    void setMois(const int &);
    /*!
     *\brief modifier l'année de la date
     *\param const int & :l'année à modifier
     */
    void setAnnee(const int &);


/*!
 *\brief methode pour remplir la date
 * La méthode fromDate qui recoit en parametre le jour ,mois,annee afin definir
 * une date en se referant de la date du jour avec la stucture date et enfin on affectera
 * aux attributs respectivement getJourtm(),getMoistm(),getAnneetm.
 * \param const int &: pour gérer le jour .
 * \param const int&: pour gérer le mois .
 * \param const int&: pour gérer l'année.
 */
void fromDate(const int&,const int&,const int&);
/*!
 *\brief Conversion
 * La méthode convertie la date en string .
 */
std::string  fromDateString() const;

/*!
 *\brief Conversion
 * La méthode convertie le string  en type date .
 *\param const std::string & : pour gérer la chaine de caractère  .
 */
Date toDateString(const std::string &  ) const;

/*!
 *\brief comparaison de date
 *La  Methode pour comparer une date courante et une date entré en parametre
 *\param const Date& une date en parametre pour qu'on puisse la comparer à la
 *date courante
 */

bool operator<(const Date &) const;

/*!
 *\brief L'affichage d'une date
 *Afficher une date a cette forme par exemple le 01/01/2021 .
 *\param std::ostream &:  il nous permetra de faire un affichage .
 *\param const Date &: il nous permet d'afficher une date càd jour mois année .
 */

friend std::ostream& operator <<(std:: ostream&, const Date&);
};

#endif // DATE_H
