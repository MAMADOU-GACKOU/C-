#ifndef CONTACT_H
#define CONTACT_H

/*!
*\file contact.h
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "Date.h"
#include <string>
#include <ostream>

/*!
*\class Contact
*\brief classe répresentant un contact
*
* La classe permet de créer un contact ,de modifier un contact,de supprimer un contact .
*/
class Contact
{

private:
    int id_contact=0; /*!< attribut pour l'identifiant d'un contact */
    std::string nom; /*!< attribut pour le nom d'un contact */
    std::string prenom; /*!< attribut pour le prenom d'un contact */
    std::string entreprise; /*!< attribut pour l'entreprise d'un contact */
    std::string mail;/*!< attribut pour le mail d'un contact */
    std::string telephone;/*!< attribut pour le telephone d'un contact */
    std::string URIphoto;/*!< attribut pour la photo d'un contact */
    Date dateDecreation; /*!< attribut pour la date de création  d'un contact */

public:
  /*!
   *\brief Constructeur
   *
   *Contructeur de la classe Contact
   *
   */
  Contact();
  /*!
  *\brief  Constructeur
  *
  * Constructeur avec paramètre de la classe contact
  *
  *\param const std::string &: initialise le nom  d'un contact
  *\param const std::string &: initialise le Prenom  d'un contact
  *\param const std::string &: initialise l'entreprise  d'un contact
  *\param const std::Email &: initalise de l'email d'un contact
  *\param const std::string &: initialise le numero de telephone d'un contact
  *\param const std::string &: initialise la photo sous forme de chaine de caractere
  */

  Contact(const std::string &,const std::string &,const std::string &,
            const std::string &,const std::string &,const std::string &);



    /*!
     *\brief Getteurs et setteurs
     *\Les fonctions getteurs et setteurs .
     */

    /*!
     *\brief Recupère l'identifiant d'un contact
     *\return l'identifiant  d'un contact
     */
    int getId_contact() const;

    /*!
     *\brief Recupère le nom d'un contact
     *\return le nom  d'un contact
     */
    std::string getNom() const;
   /*!
    *\brief Recupère le prenom d'un contact
    *\return le prenom  d'un contact
    */
    std::string getPrenom() const;
   /*!
    *\brief Recupère l'Entreprise d'un contact
    *\return l'Entreprise  d'un contact
    */
    std::string getEntreprise() const;
    /*!
    *\brief Recupère le telephone d'un contact
    *\return le Telephone  d'un contact
    */
    std::string getTelephone() const;
    /*!
    *\brief Recupère la photo d'un contact
    *\return la photo  d'un contact
    */
    std::string getURIPhoto() const;
    /*!
    *\brief Recupère l'email d'un contact
    *\return le Mail  d'un contact
    */
    std::string getMail()  const;
    /*!
    *\brief Recupère la date de création d'un contact
    *\return la Date  de creation
    */
    Date getDateDecreation() const;

    /*!
      *\brief modifier le nom d'un contact
      *\param const std::string &: le nom à modifier
      */
    void setNom(const std::string &);
    /*!
    *\brief modifier le prenom d'un contact
    *\param const std::string &: le prenom à modifier
    */
    void setPrenom(const std::string &);
    /*!
    *\brief modifier l'entreprise d'un contact
    *\param const std::string &: l'entreprise à modifier
    */
    void setEntreprise(const std::string&);
    /*!
    *\brief modifier la photo d'un contact
    *\param const std::string &: la photo à modifier
    */
    void setURIPhoto(const std::string&);
    /*!
    *\brief modifier le telephone d'un contact
    *\param const std::string &: le telephone à modifier
    */
    void setTelephone(const std::string &);
    /*!
    *\brief modifier le mail d'un contact
    *\param const std::string &: le mail à modifier
    */
    void setMail(const std::string &);
    /*!
    *\brief modifier la date de création d'un contact
    *\param const Date &: la date à modifier
    */
    void setDateDecreation(const Date &);
    /*!
    *\brief modifier l'identifiant d'un contact
    *\param const int &: l'identifiant à modifier
    */
    void setId_contact(const int &);
    /*!
    *\brief   Operateur egal
    * Permet de comparer deux contacts
    * \param  const Contact & :le contact à comparer
    *
    */

    bool operator==(const Contact &)const;
    /*!
    *\brief  operateur inferieur .
    * Permet de comparer deux dates .
    * \param  const Contact & :la date du contact à comparer avec la date du contact courant .
    *
    */
    bool operator<(const Contact &) const;

    /*!
    *\brief pour l'affichage  des propriete d'un  contact
    *
    *\param  const Contact & :le contact à afficher
    * param  std:: ostream& : permet de faire l'affichage
    */
    friend std::ostream& operator <<(std:: ostream&,const Contact&);

};

#endif // CONTACT_H

