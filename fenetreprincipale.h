#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
/*!
*\file FenetrePrincipale.h
*\author BARRY Thierno Oumar & DIALLO Iliassou
*
*/

#include <QMainWindow>
#include "contact.h"
#include <contactbdd.h>
#include <interactionbdd.h>
#include "Interaction.h"
#include "Todo.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QTimeEdit>
#include <QTimer>
#include <QDateEdit>
#include <QFormLayout>
#include <QObject>
#include <QDialog>
#include <QComboBox>
#include <QMessageBox>
#include <list>
#include <QDebug>
#include <QString>
#include <QDate>
#include <string>
#include <QTextDocument>
#include <QRegularExpression>
#include <QStringList>
#include <QTextBlock>
#include <QJsonDocument>
#include <QIODevice>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>





QT_BEGIN_NAMESPACE
namespace Ui { class FenetrePrincipale; }
QT_END_NAMESPACE
/*!
*\class FenetrePrincipale : public QObjet
*\brief Classe qui gère la fenetre principale .
* La classe herite d'une QMainWindow,elle est l'une des plus importante pour
* notre projet car elle permet de faire la déclaration des boites de
* dialogues ,des slots,des signaux pour bien gérer l'interconnections entre les classes
* et les bases de données .
*/


class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

private:
    Ui::FenetrePrincipale *ui;/*!< déclaration de l'interface utilisateur*/
    /*!
    *\brief Déclaration des boites de Dialogues .
    */

    QDialog *dialog;/*!< déclaration de la boite de dialogue pour la partie créer un contact */
    QDialog *dialog1;/*!< déclaration de la boite de dialogue pour la partie Modification d'un contact*/
    QDialog *dialog2;/*!< déclaration de la boite de dialogue pour la partie supprimer un contact  */
    QDialog *dialog3;/*!< déclaration de la boite de dialogue pour la partie rechercher un contact */
    QDialog *dialogInteraction;/*!< déclaration de la boite de dialogue pour la partie ajouter une interaction */
    QDialog *dialogList;/*!< déclaration de la boite de dialogue pour la partie afficher la liste des interactions d'un contact */
    QDialog *dialogIdeuxDates;/*!< déclaration de la boite de dialogue pour afficher des intéractions entre 2 dates . */
    QDialog *dialogRC;/*!< déclaration de la boite de dialogue pour afficher les intéractions d'un contact entre 2 dates . */
    QDialog *dialogTaches;/*!< déclaration de la boite de dialogue pour afficher l'ajaout d'une taches. */
    QDialog *dialogRechercheT;/*!< déclaration de la boite de dialogue pour faire la recherche des taches d'un contact . */
    QDialog *dialogALL;/*!< déclaration de la boite de dialogue pour faire la recherche des taches de tous les contacts entre deux dates */

    /*!
    *\brief Déclaration des labels pour la boite de dialogue créer un contact .
    */
    QLabel *Nom; /*!< déclaration d'un pointeur Nom de type Qlabel pour la création d'un contact */
    QLabel *Prenom; /*!< déclaration d'un pointeur Prenom de type Qlabel pour la création d'un contact */
    QLabel *Photo; /*!< déclaration d'un pointeur Photo de type Qlabel pour la création d'un contact */
    QLabel *Entreprise; /*!< déclaration d'un pointeur Entreprise de type Qlabel pour la création d'un contact */
    QLabel *Email; /*!< déclaration d'un pointeur Email de type Qlabel pour la création d'un contact */
    QLabel *Telephone; /*!< déclaration d'un pointeur Telephone de type Qlabel pour la création d'un contact */
    QLabel *NomR;/*!< déclaration d'un QLabel */
    QLabel *debut;/*!< déclaration d'un QLabel */
    QLabel *fin;/*!< déclaration d'un QLabel */
    QLabel *Nom1;/*!< déclaration d'un pointeur Nom de type Qlabel pour la Modification d'un contact */
    QLabel *Prenom1;/*!< déclaration d'un pointeur Prenom de type Qlabel pour la Modification d'un contact */
    QLabel *Photo1;/*!< déclaration d'un pointeur photo de type Qlabel pour la Modification d'un contact */
    QLabel *Entreprise1;/*!< déclaration d'un pointeur Entreprise de type Qlabel pour la Modification d'un contact */
    QLabel *Email1;/*!< déclaration d'un pointeur Email de type Qlabel pour la Modification d'un contact */
    QLabel *Telephone1;/*!< déclaration d'un pointeur Telephone de type Qlabel pour la Modification d'un contact */
    QLabel *Nomcombo;/*!< déclaration d'un pointeur nom de la comboBox de type Qlabel pour la Modification d'un contact */
    QLabel *ImageInsere;/*!< déclaration d'un pointeur nom de l'image  de type Qlabel lors  la création d'un contact */
    QLabel *ImageInsere2;/*!< déclaration d'un pointeur nom de l'image  de type Qlabel lors  la modification d'un contact */
    QLabel *commentaire; /*!< déclaration d'un pointeur commentaire de type Qlabel lors  l'ajout d'une intéraction */
    QLabel *NomcomboList;/*!< décalration du QLabel pour la comboBox */
    QLabel *lheure;/*!< décalration du QLabel pour la comboBox */

     QLabel *nomContact;/*!< décalration du QLabel pour le contact à supprimer */
      QLineEdit *nomContacts;/*!< décalration du QLabel pour le contact à son nom */

      QLabel *intertext;/*!< décalration du QLabel pour le contact à une interaction */
       QLineEdit *interactiontext;/*!< décalration du QLabel pour le contact à son nom */

       QLabel *intertexts;/*!< décalration du QLabel pour le contact à liste d'interaction */
        QLineEdit *interactiontexts;/*!< décalration du QLabel pour le contact à son nom */

        QLabel *intertextsc;/*!< décalration du QLabel pour le contact entre 2 date de son interaction */
         QLineEdit *interactiontextsc;/*!< décalration du QLabel pour le contact à son nom */

    /*!
    *\brief Déclaration des champs et les dates  .
    */
    QLineEdit *n; /*!< déclaration d'un pointeur n de type QlineEdit pour la saisie de texte pour le nom */
    QLineEdit *p; /*!< déclaration d'un pointeur p de type QlineEdit pour la saisie de texte pour le prenom */
    QLineEdit *en;/*!< déclaration d'un pointeur en de type QlineEdit pour la saisie de texte pour l'entreprise */
    QLineEdit *em;/*!< déclaration d'un pointeur em de type QlineEdit pour la saisie de texte pour l'email */
    QLineEdit *tel;/*!< déclaration d'un pointeur tel de type QlineEdit pour la saisie de texte pour telephone */
    QLineEdit *ph;/*!< déclaration d'un pointeur ph de type QlineEdit pour l'insertion du chemin pour la photo */
    QLineEdit *n1;/*!< déclaration d'un pointeur n1 de type QlineEdit pour la saisie de texte pour le nom */
    QLineEdit *p1;/*!< déclaration d'un pointeur p1 de type QlineEdit pour la saisie de texte pour le prenom */
    QLineEdit *en1;/*!< déclaration d'un pointeur en1 de type QlineEdit pour la saisie de texte pour l'Entreprise */
    QLineEdit *em1;/*!< déclaration d'un pointeur em1 de type QlineEdit pour la saisie de texte pour l'email */
    QLineEdit *tel1;/*!< déclaration d'un pointeur tel1 de type QlineEdit pour la saisie de texte pour telephone */
    QLineEdit *ph1;/*!< déclaration d'un pointeur ph1 de type QlineEdit pour l'insertion du chemin pour la photo */
    QLineEdit *nR;/*!< déclaration d'un pointeur nR de type QlineEdit pour l'insertion du texte */
    QDateEdit *date1;/*!< déclaration d'un pointeur date1 de type QDateEdit pour l'insertion de la date 1 */
    QDateEdit *date2;/*!< déclaration d'un pointeur date2 de type QDateEdit pour l'insertion de la date 2 */
    QLineEdit *cInteraction; /*!< déclaration d'un pointeur cInteraction de type QlineEdit pour l'insertion d'un contenu */
    QDateEdit *dateAjout;/*!< déclaration d'un pointeur dateAjout de type QDateEdit pour l'insertion d'une date */
    QDateEdit *dateDebutI;/*!< déclaration d'un pointeur dateDebutI de type QDateEdit pour l'insertion d'une date */
    QDateEdit *dateFinI;/*!< déclaration d'un pointeur dateFinI de type QDateEdit pour l'insertion d'une date */
    QDateEdit *date1RC;/*!< déclaration d'un pointeur date1RC de type QDateEdit pour l'insertion d'une date */
    QDateEdit *date2RC;/*!< déclaration d'un pointeur date2RC de type QDateEdit pour l'insertion d'une date */
    QTimer *ltime;/*!< déclaration d'un pointeur ltime de type QTimer qui va gerer une heure /mois/date  */
    QDateEdit *dateDebutTaches;/*!< déclaration d'un pointeur dateDebutTaches de type QDateEdit pour l'insertion d'une date */
    QDateEdit *dateFinTaches;/*!< déclaration d'un pointeur dateFinTaches de type QDateEdit pour l'insertion d'une date */
    QDateEdit *dateDebutALL;/*!< déclaration d'un pointeur dateDebutALL de type QDateEdit pour l'insertion d'une date */
    QDateEdit *dateFinALL;/*!< déclaration d'un pointeur dateFinALL de type QDateEdit pour l'insertion d'une date */
    QTextEdit *editTaches;/*!< déclaration d'un pointeur editTaches de type QTextEdit pour une insertion */

    /*!
    *\brief Déclaration de la ComboBox ou la liste déroulante .
    */

    QComboBox *comboBox; /*!< déclaration de la comboBox pour gérer la liste déroulante */
    QComboBox *comboInteraction;/*!< déclaration de la comboInteraction pour gérer la liste déroulante */
    QComboBox *comboList; /*!< déclaration de la comboList pour gérer la liste déroulante */
    QComboBox *combo;/*!< déclaration de la combo pour gérer la liste déroulante */
    QComboBox *comboRecherche;/*!< déclaration de la comboRecherche pour gérer la liste déroulante */
    QComboBox *comboTache;/*!< déclaration de la comboTache pour gérer la liste déroulante */
    QComboBox *comboTachesRecherche;/*!< déclaration de la comboTachesRecherche pour gérer la liste déroulante */

    /*!
    *\brief Declaration des dimensions .
    *
    * La déclaration des dimension Horizontale et Verticale  pour les Qdialoque afin de bien aligner nos widgets .
    *
    */
    QVBoxLayout *vAligne1;
    QVBoxLayout *vAligne2;
    QVBoxLayout *vAligne3;
    QHBoxLayout *aligneH;
    QVBoxLayout *vAligne11;
    QVBoxLayout *vAligne22;
    QVBoxLayout *vAligne33;
    QHBoxLayout *aligneHH;
    QVBoxLayout *vAligneR;
    QVBoxLayout *vAligneR2;
    QHBoxLayout *hAlignH;
    QVBoxLayout *vAligne1I;
    QVBoxLayout *vAligne2I;
    QVBoxLayout *vAligne3I;
    QHBoxLayout *hAligneI;
    QVBoxLayout *vAligneList1;
    QVBoxLayout *vAligneList2 ;
    QHBoxLayout *hAligneList;
    QVBoxLayout *vAligne1Id;
    QVBoxLayout *vAligne2Id;
    QHBoxLayout *hAligneId ;
    QVBoxLayout *vAligneRRC;
    QVBoxLayout *vAligneR2RC;
    QHBoxLayout *hAlignHRC;
    QVBoxLayout *vAligneTaches;
    QHBoxLayout *hAligne1Taches;
    QHBoxLayout *hAligne2Taches;
    QHBoxLayout *hAligne3Taches;
    QVBoxLayout *vAligne1TachesR;
    QVBoxLayout *vAligne2TachesR;
    QHBoxLayout *hAligneTachesR;
    QVBoxLayout *vAligne1ALL;
    QVBoxLayout *vAligne2ALL;
    QHBoxLayout *hAligneALL;
    QHBoxLayout *hAligne1I;
    QHBoxLayout *hAligne2I;
    QHBoxLayout *hAligne4I;
    QVBoxLayout *vAligneI;

    /*!
    *\brief Déclaration des boutons .
    */
    QPushButton *Bvalider; /*!< Bouton valider */
    QPushButton *Bannuler; /*!< Bouton annuler qui permet de fermer la boite de dialogue*/
    QPushButton *Bvalider1;/*!< Bouton valider pour la liste d'intéraction */
    QPushButton *Bannuler1;/*!< Bouton annuler qui permet de fermer la boite de dialogue */
    QPushButton *BRechercher; /*!< Bouton Rechercher */
    QPushButton *BannulerR;/*!< Bouton annuler qui permet de fermer la boite de dialogue */
    QPushButton *Bsupprimer;/*!< Bouton Supprimer .*/
    QPushButton *BPhotoContact;/*!< bouton pour ajouter la photo lors de la création d'un contact */
    QPushButton *BPhotoModifContact;/*!< bouton pour ajouter la photo lors de la modification d'un contact */
    QPushButton *BajoutInteraction;/*!< bouton ajouter pour une interaction */
    QPushButton *BannulerInteraction;/*!< Bouton annuler qui permet de fermer la boite de dialogue */
    QPushButton *BvaliderListI;/*!< Bouton valider pour la liste d'intéraction */
    QPushButton *BannulerListI;/*!< Bouton annuler qui permet de fermer la boite de dialogue */
    QPushButton *BrechercheIdate;/*!< Bouton pour rechercher des interactions entre deux dates */
    QPushButton *BannulerIdate;/*!< Bouton annuler qui permet de fermer la boite de dialogue */
    QPushButton *BRechercherRC;/*!< Bouton pour rechercher des interactions entre deux dates pour un contact */
    QPushButton *BannulerRC;/*!< Bouton annuler qui permet de fermer la boite de dialogue .*/
    QPushButton *BajoutTaches;/*!< Bouton pour ajouter une taches .*/
    QPushButton *BannulerTaches;/*!< Bouton annuler qui permet de fermer la boite de dialogue .*/
    QPushButton *BrechercherTaches;/*!< Bouton rechercher les taches d'un contact . */
    QPushButton *BannulerTachesR;/*!< Bouton annuler qui permet de fermer la boite de dialogue . */
    QPushButton *BrechercherALL;/*!< Bouton rechercher des taches pour tous les contacts entre deux dates . */
    QPushButton *BannulerALL;/*!< Bouton annuler qui permet de fermer la boite de dialogue . */

public:
    ContactBDD bd;
    InteractionBDD inBDD;
    /*!
     *\brief Constructeur
     *Constructeur de la classe FenetrePrincipale
     *\param *parent = nullptr: par defaut
     */
    FenetrePrincipale(QWidget *parent = nullptr);
    /*!
     * \brief Destructeur
     * Le Destructeur de la classe FenetrePrincipale càd la fonction qui libère la memoire utilisé .
     */
    ~FenetrePrincipale();


private slots:

    /*!
    *\brief Les fonctions slot pour créer les boites de dialogues .
    */

    /*!
     *\brief CreerUnContact .
     *la fonction qu'on appellera pour la création de la boite dialogue pour créer un contact
     */
    void CreerUnContact();
    /*!
     *\brief SupprimerContact .
     *la fonction qu'on appellera pour la création de la boite dialogue pour supprimer un contact .
     */
    void SupprimerContact();
   void  RemplirSup(const QString  &  );
    /*!
     *\brief ModifierContact .
     *la fonction qu'on appellera pour la création de la boite dialogue  pour modifier un contact .
     */
    void ModifierContact();
    /*!
     *\brief chercherContact .
     *la fonction qu'on appellera pour la création de la boite dialogue  pour rechercher un contact .
     */

     void Remplir(const QString  & );
    void chercherContact();
    /*!
     *\brief AjoutInteraction .
     *la fonction qu'on appellera pour la création de la boite dialogue  pour ajouter une intéraction .
     */
    void AjoutInteraction();
   void  RemplirSupInter(const QString  & );
    /*!
     *\brief AjoutTaches .
     *la fonction qu'on appellera pour la création de la boite dialogue  pour ajouter une taches(Todo)  .
     */
   // void AjoutTaches();
    /*!
     *\brief ListeInteraction .
     *la fonction qu'on appellera pour la création de la boite dialogue  pour lister les intéractions .
     */
    void ListeInteraction();
    void  RemplirSupInters(const QString  & );
    /*!
     *\brief InteractionsEntre2Date .
     *la fonction qui  nous permettra  de créer de la boite dialogue afin de  rechercher des interactions entre deux dates .
     */
    void InteractionsEntre2Date();
    /*!
     *\brief RechercheInteractionContact .
     *la fonction qui nous permettra  de créer de la boite dialogue pour afficher une intéraction pour un contact selectionné .
     */
    void RechercheInteractionContact();
    void  RemplirSupIntersc(const QString  & );

    /*!
     *\brief AfficheTachesIntervalle .
     *la fonction qui nous permettra  de créer de la boite dialogue pour afficher les taches entre deux dates .
     */
    void AfficheTachesIntervalle();
    /*!
     *\brief AfficheTachesContact .
     *la fonction qui nous permettra  de créer de la boite dialogue pour afficher les Todo de tous les contacts .
     */
    void AfficheTachesContact();


   // void on_jsontest_clicked();

public slots:

    /*!
     *\brief Les slot pour tout ce qui concerne le CONTACT
     *Les slots qu'on liera aux boites de dialogues concernant un Contact
     */

    /*!
     *\brief Slot Affichage .
     *Slot lié à l'affichage des contacts
     */
     void Affichage();
     /*!
      *\brief Slot Apropos .
      *slot lié à l'affichage de about
      */
     void Apropos();
     /*!
      *\brief Slot demarrerHeure .
      *slot lié à l'affichage de l'heure
      */
     void demarrerHeure();
     /*!
      *\brief Slot pour la Creation d'un Contact .
      *Slot lié à la création d'un contact .
      */
     void CreationContact();
     /*!
      *\brief Slot Bouton pour Annuler le Contact .
      *Slot lié à la fermeture de la boite de dialogue lors de la création d'un contact  .
      */
     void BoutonAnnulerContact();
     /*!
      *\brief Slot afficher une Photo .
      *Slot lié à l'affichage de la photo lors dé la création d'un contact .
      */
     void afficherPhoto();
     /*!
      *\brief Slot AfficheModContact  .
      *slot lié à l'affichage lié à la Modification d'un contact
      */
     void AfficheModContact();
     /*!
      *\brief Slot Bouton pour BoutonAnnulerModification.
      *Slot lié à la fermeture de la boite de dialogue lors de la modification d'un contact  .
      */
     void BoutonAnnulerModification();
     /*!
      *\brief Slot afficher une Photo .
      *Slot lié à l'affichage de la photo lors dé la création d'un contact .
      */


     void  afficherPhoto1();
     /*!
      *\brief Slot RechercheUnContact .
      *Slot lié à slot lié pour la recherche d'un contact.
      */
     void RechercheUnContact();
     /*!
      *\brief Slot Bouton pour BoutonAnnulerRechercher .
      *Slot lié à la fermeture de la boite de dialogue lors de la recherche d'un contact  .
      */
     void BoutonAnnulerRechercher();
     /*!
      *\brief Slot suppressionContact .
      *slot lié pour la suppression d'un contact .
      */
     void suppressionContact();
     /*!
      *\brief Slot Bouton pour BoutonAnnulerSupprimer .
      *Slot lié à la fermeture de la boite de dialogue lors de la suppression d'un contact  .
      */
     void BoutonAnnulerSupprimer();
     /*!
      *\brief Slot TotalContact .
      *le slot qu'on appellera pour retourner le nombre total des contacts .
      * \param int &: retourne le nombre total des contacts
      */
     void TotalContact(int &);




     /*!
      *\brief Les slots pour tout ce qui concerne l'INTÉRACTION
      *Les slots qu'on liera aux boites de dialogues  concernant une intéraction
      */

     /*!
      *\brief Slot AjoutUneInteraction .
      *Slot lié à l'ajout d'une interaction pour un contact
      */
     void AjoutUneInteraction();
     /*!
      *\brief Slot Bouton pour AnnulerInteraction .
      *Slot lié à la fermeture de la boite de dialogue lors de l'ajout d'une intéraction .
      */
     void AnnulerInteraction();
     /*!
      *\brief Slot ListeInteractionContact .
      *Slot lié à l'affichage des interactions pour un contact choisi
      */
     void ListeInteractionContact();
     /*!
      *\brief Slot Bouton pour AnnulerListeInteraction .
      *Slot lié au Bouton annuler pour fermer la boite de dialogue
      */
     void AnnulerListeInteraction();
     /*!
      *\brief Slot AfficheToutesLesInteractions .
      *Slot lié pour afiicher les intéractions
      */
     void AfficheToutesLesInteractions();
     /*!
      *\brief Slot RechercherInteractionEntreDeuxDates  .
      *Slot lié pour réchercher une interaction entre deux dates
      */
     void RechercherInteractionEntreDeuxDates();
     /*!
      *\brief Slot Bouton pour AnnulerInteractionEntreDeuxDates .
      *Slot lié au Bouton annuler pour fermer la boite de dialogue
      */
     void AnnulerInteractionEntreDeuxDates();
     /*!
      *\brief Slot FindContact  .
      *slot lié pour Rechercher les interactions d'un contact entre deux dates
      */
     void FindContact();
     /*!
      *\brief Slot Bouton pour CancelContact .
      *Slot lié au Bouton annuler pour fermer la boite de dialogue
      */
     void CancelContact();




     /*!
      *\brief Les slots pour tout ce qui concerne les TODO
      *Les slots qu'on liera aux boites de dialogues  concernant les Taches
      */


     /*!
      *\brief Slot AjoutTodoContact .
      *Slot lié à l'ajout d'une tache pour une intéraction d'un contact
      */
   //  void  AjoutTodoContact();
     /*!
      *\brief Slot Bouton pour AnnulerTodoContact .
      *Slot lié à la fermeture de la boite de dialogue lors de l'ajout d'une Tache .
      */
    // void AnnulerTodoContact();
     /*!
      *\brief Slot AjoutTodoContact .
      *Slot lié à l'affichage de toutes les taches des contacts lors du clic sur le bouton afficher toutes les taches .
      */
     void ListeTodos();
     /*!
      *\brief Slot RechercheTodoCont .
      *Slot lié à la collecte des taches pour un contact .
      */
     void RechercheTodoCont();
     /*!
      *\brief Slot Bouton pour BoutonAnnulerRechercherT .
      *Slot lié à la fermeture de la boite de dialogue lors de la recherche d'une Tache .
      */
     void BoutonAnnulerRechercherT();
     /*!
      *\brief Slot RechercheTodoCont .
      *Slot lié à la recherche des taches pour tous les contact entre deux dates
      */
     void RechercheALLTodoCont( );
     /*!
      *\brief Slot Bouton pour AnnulerALL .
      *Slot lié à la fermeture de la boite de dialogue lors de la recherche des taches pour les contacts entre deux dates .
      */
     void AnnulerALL();
     /*!
      *\brief Slot lié au Json pour un contact  .
      *c'est cette fonction qui nous permettra d'exporter les fichiers json d'un contact .
      */
     void JsonContact();
     /*!
      *\brief Slot lié au Json pour une intéraction  .
      *c'est cette fonction qui nous permettra d'exporter les fichiers json d'une intéraction.
      */
     void JsonInteraction();



signals:

     /*!
      *\brief Les signaux pour tout ce qui concerne le contact
      *Les signaux qu'on appelera dans les slots pour pouvoir les lier dans le main avec les fonctions correspondantes dans la base de donnée
      */


     /*!
      *\brief signal sigGetContactList .
      *Le signal nous permet d'emetre un signal en envoyant une liste de contact.
      *\param std::list<Contact>& :liste de contact .
      */
    void sigGetContactList(std::list<Contact>&);
    /*!
     *\brief signal sigInsert  .
     *Le signal qui nous permet d'emetre un signal en inserant un contact  .
     *\param Contact & :le contact à envoyer par le signal .
     */
    void sigInsert( Contact &);
    /*!
     *\brief signal sigSupprimer  .
     *Le signal qui nous permet d'emetre un signal en faisant la suppression de l'id du contact  .
     *\param int & :l'identifiant à envoyer par le signal .
     */
    void sigSupprimer( int  &);
    /*!
     *\brief signal sigModifier  .
     *Le signal qui nous permet d'emetre un signal en faisant la modification d'un contact en selectionnant son idcontact  .
     *\param int & :l'identifiant à envoyer par le signal .
     *\param Contact & : le contact à envoyer par le signal .
     */
    void sigModifier( int & , Contact &);
    /*!
     *\brief signal sigRechercheUnContact  .
     *Le signal qui nous permet d'emetre un signal en faisant la recherche en rentrant le nom du contact entre deux dates   .
     *\param QString & :le nom a saisir pour la recherche .
     *\param QString & :le premiere date à saisir pour la recherche.
     *\param QString & :la deuxieme date à saisir pour la recherche.
     *\param std::list<Contact> &: la liste de contact pour la recherche.
     * Tous ces paramètres seront envoyés par le signal  .
     */
    void sigRechercheUnContact(QString & , QString & ,QString & ,std::list<Contact> & );

    /*!
     *\brief Les signaux pour tout ce qui concerne l'intéraction
     *Les signaux qu'on appelera dans les slots pour pouvoir les lier dans le main avec les fonctions correspondantes dans la base de donnée
     */


    /*!
     *\brief signal sigAjoutInteraction .
     *Ce signal nous permet d'ajouter une intéraction pour un contact .
     *\param Interaction & :l'intéraction ajouté
     *\param int & :l'identifiant du contact qui doit recevoir l'intéraction ajouté .
     */

    void sigAjoutInteraction(int &,Interaction &);
    /*!
     *\brief signal sigListeInteraction .
     *Ce signal nous permet d'afficher pour un contact sa liste d'intéraction .
     *\param std::list<Interaction> & :listes d'intéractions
     *\param int & :l'identifiant du contact pour afficher ses intéractions .
     */
    void sigListeInteraction(int &,std::list<Interaction> &);
    /*!
     *\brief signal sigListeInteractionALL .
     *Ce signal nous permet d'afficher toutes les intéractions de tous les contacts .
     *\param std::list<Interaction> & :listes d'intéractions  .
     */

    void sigListeInteractionALL(std::list<Interaction> &);
    /*!
     *\brief signal sigRechercheInteraction .
     *Ce signal nous permet de rechercher dans un intervalle de deux dates toutes les intéractions .
     *\param std::list<Interaction> & :listes d'intéractions
     *\param QString &:la premiere date ou debut de l'intervalle à rechercher .
     *\param QString &:la deuxieme date ou fin de l'intervalle à rechercher .
     */
    void sigRechercheInteraction(QString &,QString &,std::list<Interaction> &);
    /*!
     *\brief signal sigRechercheInteractionCont .
     *Ce signal nous permet de rechercher pour un contact sa liste d'intéraction .
     *\param int & :l'identifiant du contact à rechercher .
     *\param std::list<Interaction> & :listes d'intéractions .
     *\param QString &:la premiere date ou debut de l'intervalle à rechercher .
     *\param QString &:la deuxieme date ou fin de l'intervalle à rechercher  .
     */
    void sigRechercheInteractionCont(int & , QString & , QString & , std::list<Interaction> &);

    /*!
     *\brief Les signaux pour tout ce qui concerne le Todo
     *Les signaux qu'on appelera dans les slots pour pouvoir les lier dans le main avec les fonctions correspondantes dans la base de donnée
     */

    /*!
     *\brief signal sigAjoutInteraction .
     *Ce signal nous permet d'ajouter une tache pour une intéraction .
     *\param Todo & :la tache ajouté
     *\param int & :l'identifiant de l'intéraction qui doit recevoir la tache ajoutée .
     */
    void  sigAjoutTodo(int &,Todo &);

    /*!
     *\brief signal sigListeTodoContact .
     *Ce signal nous permet d'afficher la liste des taches pour un contact .
     *\param int & :l'identifiant du contact  .
     *\param std::list<Todo>&:listes de tache .
     */
    void sigListeTodoContact(int &,std::list<Todo>&);
    /*!
     *\brief signal sigListeALLContact .
     *Ce signal nous permet d'afficher la liste des taches pour tous les  contact .
     *\param std::list<Todo>&:listes de tache .
     */
    void sigListeALLContact(std::list<Todo> &);
    /*!
     *\brief signal sigRechercheTodoCont .
     *Ce signal nous permet de rechercher des taches pour un contact entre deux dates .
     *\param int & :l'identifiant du contact à rechercher .
     *\param std::list<Todo> & :listes des taches .
     *\param QString &:la premiere date ou debut de l'intervalle à rechercher .
     *\param QString &:la deuxieme date ou fin de l'intervalle à rechercher  .
     */
    void sigRechercheTodoCont(int & , QString & , QString & , std::list<Todo> &);
    /*!
     *\brief signal sigRechercheALLTodoCont .
     *Ce signal nous permet de rechercher les taches de tous les contacts entre deux dates .
     *\param std::list<Todo> & :listes des taches .
     *\param QString &:la premiere date ou debut de l'intervalle à rechercher .
     *\param QString &:la deuxieme date ou fin de l'intervalle à rechercher  .
     */
    void sigRechercheALLTodoCont( QString & , QString & , std::list<Todo> &);



};
#endif // FENETREPRINCIPALE_H
