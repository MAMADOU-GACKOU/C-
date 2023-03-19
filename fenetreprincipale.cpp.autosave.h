/*!
*\file fenetreprincipale.cpp
*\author BARRY Thierno Oumar & DIALLO Iliassou
*\version 0.1
*/

#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"
#include <QFileDialog>

/*!
 *\brief implémentation du constructeur avec paramètre .
 *Ce constructeur hérite d'une QMainWindox et un interface user ui .
 */

FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FenetrePrincipale)
{

    ui->setupUi(this);

    combo=new QComboBox(); /*!< ComboBox pour la liste déroulante pour la création d'un contact */

    comboBox=new QComboBox();/*!< comboBox qu'on utillise pour la modification d'un contact */

    comboInteraction=new QComboBox();/*!< comboBox qu'on utillise pour la liste des interactions */

    comboList=new QComboBox();/*!< comboBox qu'on utillise pour la liste des interactions */

    comboRecherche=new QComboBox(); /*!< comboBox qu'on utillise pour la recherche des interactions */

    comboTache=new QComboBox(); /*!< comboBox qu'on utillise pour la recherche des interactions */

    comboTachesRecherche=new QComboBox(); /*!< la comboBox pour la recherches des taches d'un contact . */

    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir Inserer ou créer un contact  .
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionCreerContact" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à la création d'un contact .
     */

    //connect( ui->actionCr_er_un_contact,SIGNAL(clicked()),this,SLOT(CreerUnContact()));
    connect( ui->actionCr_er_un_contact,SIGNAL(triggered()),this,SLOT(CreerUnContact()));

    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir supprimer un contact  .
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionSupprimer_un_contact" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à la suppression d'un contact .
     */
    //connect( ui->actionSupprimer_un_contact,SIGNAL(clicked()),this,SLOT(SupprimerContact()));
    connect( ui->actionSupprimer_un_contact,SIGNAL(triggered()),this,SLOT(SupprimerContact()));
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir Modifier un contact .
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionModifier_un_contact" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à la modification d'un contact .
     */
    //connect( ui->actionModifier_un_contact,SIGNAL(clicked()),this,SLOT(ModifierContact()));
    connect( ui->actionModifier_un_contact,SIGNAL(triggered()),this,SLOT(ModifierContact()));
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir chercher un Contactn.
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionchercher_un_contact" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à la recherche d'un contact .
     */
    //connect( ui->actionchercher_un_contact,SIGNAL(clicked()),this,SLOT(chercherContact()));
    connect( ui->actionchercher_un_contact,SIGNAL(triggered()),this,SLOT(chercherContact()));
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir Ajouter une interaction.
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionAjouter_une_int_raction" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à l'ajout d'une intéraction .
     */
    //connect( ui->actionAjouter_une_int_raction,SIGNAL(clicked()),this,SLOT(AjoutInteraction()));
    connect( ui->actionAjouter_une_int_raction,SIGNAL(triggered()),this,SLOT(AjoutInteraction()));
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir afficher une interaction.
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionListes_d_int_raction" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à l'affichage d'une intéraction .
     */
    //connect( ui->actionListes_d_int_raction,SIGNAL(clicked()),this,SLOT(ListeInteraction()));
    connect( ui->actionListes_d_int_raction,SIGNAL(triggered()),this,SLOT(ListeInteraction()));
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir ajouter une tache.
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionAjouter_des_taches" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond ajouter une tache .
     */
    //connect( ui->actionAjouter_des_taches,SIGNAL(clicked()),this,SLOT(AjoutTaches()));
    connect( ui->actionAjouter_des_taches,SIGNAL(triggered()),this,SLOT(AjoutTaches()));


    /*!
     *\brief Connection liée à l'affichage du nombre total de contacts dans la base de donnée .
     */
    //connect( ui->BNombrecontact,SIGNAL(clicked()),this,SLOT(TotalContact(int & )));
   // connect( ui->BNombrecontact,SIGNAL(triggered()),this,SLOT(TotalContact(int &)));

    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir recherche  une interaction
     * entre deux dates.
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionInteraction_entre_deux_dates" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond rechercher l'intéraction entre deux dates .
     */
    //connect( ui->actionInteraction_entre_deux_dates,SIGNAL(clicked()),this,SLOT(InteractionsEntre2Date()));
    connect( ui->actionInteraction_entre_deux_dates,SIGNAL(triggered()),this,SLOT(InteractionsEntre2Date()));

    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir afficher les taches entre deux dates
     *pour un contact
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionCollecteDesTaches" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à l'affichage des taches entre les deux dates entrée.
     */
    //connect( ui->actionCollecteDesTaches,SIGNAL(clicked()),this,SLOT(AfficheTachesIntervalle()));
    connect( ui->actionCollecteDesTaches,SIGNAL(triggered()),this,SLOT(AfficheTachesIntervalle()));

    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir rechercher des intéractions entre deux dates
     *pour un contact
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionInteraction_d_un_contact_entre_deux_dates"
     * avec le signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à l'affichage des intéractions trouvés entre les deux dates entrée pour un contact .
     */
    //connect( ui->actionInteraction_d_un_contact_entre_deux_dates,SIGNAL(clicked()),this,SLOT(RechercheInteractionContact()));
    connect( ui->actionInteraction_d_un_contact_entre_deux_dates,SIGNAL(triggered()),this,SLOT(RechercheInteractionContact()));    
    /*!
     *\brief Connection liée à la création de la boite de dialogue pour pouvoir afficher la liste de toutes les  taches
     *de tous les contacts entre deux dates
     *on a connecté l'action du sous menu du UI(interface user)  appelé "actionCollecteDesTaches" avec le
     *signal triggered() au slot pour nous afficher la boite de dialogue qui
     *correspond à l'affichage des taches de tous les contacts entre les deux dates entrée.
     */
    //connect( ui->actionTaches_pour_tous_les_contacts,SIGNAL(clicked()),this,SLOT(AfficheTachesContact()));
    connect( ui->actionTaches_pour_tous_les_contacts,SIGNAL(triggered()),this,SLOT(AfficheTachesContact()));

    /*!
     *\brief Affichage d'un contact
     *Lors du clic sur le bouton affichageListeContact sur la fenetre principale ce bouton nous affiche
     *tous les contacts présent dans la base de donnée .
     *on a pris le bouton ui->BAfficher on lui a mis un signal clicked() et on lui à lié à la fonction
     *Affichage() qui nous permet d'afficher tous les contacts présent dans la base sur la partie
     *dedié à l'affichage des contacts .
     */
    connect(ui->BAfficher,SIGNAL(clicked()),this,SLOT(Affichage()));


    //connect(ui->jsontest,SIGNAL(triggered()),this,SLOT(returnJSON(QJsonDocument &)));



    /*!
     *\brief Affichage d'une intéractiodn
     *Lors du clic sur le bouton affichageListeIntéraction sur la fenetre principale ce bouton nous affiche
     *toutes les intéractions présentes dans la base de donnée .
     *on a pris le bouton ui->BAffichetousInteraction on lui a mis un signal clicked() et on lui à lié à la fonction
     *AfficheToutesLesInteractions() qui nous permettra d'afficher toutes les intéractions présentes dans la base
     *sur la partie dedié à l'affichage des intéractions .
     */
    connect(ui->BAffichetousInteraction,SIGNAL(clicked()),this,SLOT(AfficheToutesLesInteractions()));

    /*!
     *\brief Affichage d'une Tache "Todo"
     *Lors du clic sur le bouton affichageListeTodo sur la fenetre principale ce bouton nous affiche
     *toutes les taches présentes dans la base de donnée .
     *on a pris le bouton ui->boutontodo on lui a mis un signal clicked() et on lui à lié à la fonction
     *ListeTodos() qui nous permettra d'afficher toutes les intéractions présentes dans la base sur la
     *partie dedié à l'affichage des taches .
     */
    connect(ui->boutontodo,SIGNAL(clicked()),this,SLOT(ListeTodos()));

    /*!
     *\brief Affichage du sous menu à propos
     *Dans cette partie on a essayé de dire de façon breve ce qu'on a fait et réussi
     */
   //connect(ui->actionApropos,SIGNAL(clicked()),this,SLOT(Apropos()));
    connect( ui->actionApropos,SIGNAL(triggered()),this,SLOT(Apropos()));

    /*!
     *\brief Affichage de l'heure dès l'éxecution du programme
     *Dans cette partie on a essayé d'afficher l'heur courante en bas à gauche pour donner un peu
     *la vivacité à notre application .
     */
    ltime=new QTimer(this);//Déclaration de ltime on l'initialise à this .
    connect(ltime,SIGNAL(timeout()),this,SLOT(demarrerHeure()));
    ltime->start(1000);//à chaque 1000 milliseconde la seconde s'incrémente .

}


/*!
 *\brief implémentation du destructeur .
 *A la fin de l'éxecution on à libéré la mémoire.
 *
 */
FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

/*!
 *\fn FenetrePrincipale::CreerUnContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servit à créer un contact c'est à dire :
 *Elle est constituée de la declaration d'une boite de dialogue ,tout ce qui concerne un contact
 *(nom,prenom,tel etc..),les champs de textes ,les boutons necessaires et les dispositions qu'on
 *a utilisés afin de bien positionner les labels,champs,boutons  .
 *
 */
/****************Ouverture d'une boite de dialogue et création d'un contact*****/
void FenetrePrincipale::CreerUnContact()
{
    dialog=new QDialog(this);
    dialog->setWindowTitle(tr("Créer un contact "));
    dialog->resize(400,10);
    dialog->setModal(true);

    //nom
    Nom=new QLabel("Nom");
    //nom
    ImageInsere=new QLabel("Ma Photo");
    //Prenom
    Prenom=new QLabel(" Prenom ");
    //photo
    Photo=new QLabel("Ajouter une Photo ");
    //Entreprise
    Entreprise=new QLabel(" Entreprise ");
    //Email
    Email=new QLabel(" Email ");
    //Date
    Telephone = new QLabel(" Telephone ");

    /*champs de textes*/
    n=new QLineEdit();
    p=new QLineEdit();
    ph=new QLineEdit();
    en=new QLineEdit();
    em=new QLineEdit();
    tel=new QLineEdit();

    /****Dimension****/
    vAligne1=new QVBoxLayout();
    vAligne2=new QVBoxLayout();
    vAligne3=new QVBoxLayout();
    aligneH=new QHBoxLayout();

    Bvalider= new QPushButton("Valider");
    Bannuler= new QPushButton("Annuler");
    BPhotoContact= new QPushButton("Parcourir");
    vAligne1->addWidget(Nom);
    vAligne1->addWidget(Prenom);
    vAligne1->addWidget(Entreprise);
    vAligne1->addWidget(Email);
    vAligne1->addWidget(Telephone);
    vAligne1->addWidget(Photo);
    vAligne1->addWidget(Bannuler);
    aligneH->addLayout(vAligne1); //ajout vAligne1 en dimension horizontale

    vAligne2->addWidget(n);
    vAligne2->addWidget(p);
    vAligne2->addWidget(en);
    vAligne2->addWidget(em);
    vAligne2->addWidget(tel);
    vAligne2->addWidget(BPhotoContact);
    vAligne2->addWidget(Bvalider);
    aligneH->addLayout(vAligne2); //ajout vAligne2 en dimension horizontale


    vAligne3->addWidget(ImageInsere);
    aligneH->addLayout(vAligne3);//ajout vAligne1 en dimension horizontale



    dialog->setLayout(aligneH); //activer la dimension de la dialogue
    dialog->show(); //affichage de la dialogue


connect(Bvalider,SIGNAL(clicked()),this,SLOT(CreationContact()));/*!< connection du bouton valider de l'application au slot CreationContact*/
connect(BPhotoContact,SIGNAL(clicked()),this,SLOT(afficherPhoto()));/*!< connection du bouton BPhotoContact de l'application pour parcourir la photo à ajouter*/
connect(Bannuler,SIGNAL(clicked()),this,SLOT(BoutonAnnulerContact()));/*!< la connection pour le bouton annuler pour fermet la fenetre */
}

/*!
 *\fn FenetrePrincipale::CreationContact()
 *\brief Slot pour la Creation d'un contact
 *on créer un contact c on test si tous les champs sont pas remplis sinon on affiche le messange d'erreur
 *Si Oui on récupère les textes saisies sur les champs avec la photo récupéré on l'envoie par le signal pour
 *qu'enfin qu'il soit connecté avec la base de donnée .
 *On aura au final un contact inséré dans la base de donnée
 */
void FenetrePrincipale::CreationContact()
{

Contact  c;
        if(n->text()!=NULL && p->text()!=NULL && en->text()!=NULL && em->text()!=NULL && tel->text()!=NULL)
        {
            c.setNom(n->text().toStdString());
            c.setPrenom(p->text().toStdString());
            c.setEntreprise(en->text().toStdString());
            c.setMail(em->text().toStdString());
            c.setTelephone(tel->text().toStdString());
            c.setURIPhoto(ph->text().toStdString());
            emit sigInsert(c);  /*!< signal qu'on envoie vers le main qu'on recupera afin de faire les connections avec la BD*/

            std::list<Contact> lp;
            ui->afficherTexte->clear();//Pour raffraichir l'affichage sur la base de donnée
            lp.clear();
            emit sigGetContactList(lp);/*!< signal qu'on envoie vers le main qu'on recupera afin de faire les connections avec la BD*/

            QMessageBox::information(this,"Création d'un contact "," Contact créé avec succés !!!!" );
            comboInteraction->clear();//Raffraichier la combo lors de la création d'un contact
            comboTachesRecherche->clear();//Raffraichier la combo lors de la création d'un contact
            comboRecherche->clear();//raffraichir la combo lors de la création d'un contact .
            combo->clear();//raffraichir la combo
            comboList->clear();//raffraichir la combo
            comboBox->clear();//raffraichir la combo

            dialog->close();
        }

        else
        {
           QMessageBox::warning(this,"Création d'un contact "," Remplissez toutes les cases  !!!" );


        }


}
/*!
 *\fn FenetrePrincipale::BoutonAnnulerContact()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::BoutonAnnulerContact()
{
    dialog->close();
}

/*!
 *\fn FFenetrePrincipale::afficherPhoto()
 *\brief AfficherPhoto
 *Ce slot qui nous permet de parcourir le chemin pour aller là chercher et ajouter son chemin sur le champs
 *de texte dedié afin de l'insérer dans la BD .
 */
void FenetrePrincipale::afficherPhoto()
{
    int w = ImageInsere->width();
    int h = ImageInsere->height();

    QString dir = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier "),QString(),
                                               "Images (*.png *.gif *.jpg *.jpeg *.bmp)");
    ImageInsere->setPixmap(QPixmap(dir).scaled(w,h,Qt::KeepAspectRatio));
    ph->setText(dir);

}

/*!
 *\fn FenetrePrincipale::ModifierContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servit à Modifier un contact c'est à dire :
 *Elle est constituée de la declaration d'une boite de dialogue ,tout ce qui concerne un contact
 *(nom,prenom,tel etc..),une comboBox pour choisier le contact à modifier les champs de textes ,les boutons
 *necessaires et les dispositions qu'on a utilisé afin de bien positionner les labels,champs,boutons normalement.
 *
 */
void FenetrePrincipale::ModifierContact()
{
    dialog1=new QDialog();
    dialog1->setWindowTitle(tr("Modifier Contact"));
    dialog1->resize(400,10);
    dialog1->setModal(true);

    //nom combo
    Nomcombo=new QLabel("Liste contact ");
    //nom
    Nom1=new QLabel("Nom");
    //Prenom
    Prenom1=new QLabel(" Prenom ");
    //photo
    Photo1=new QLabel(" Ajouter une Photo ");
    //nom
    ImageInsere2=new QLabel("MA PHOTO");
    //Entreprise
    Entreprise1=new QLabel(" Entreprise ");
    //Email
    Email1=new QLabel(" Email ");
    //Date
    Telephone1 = new QLabel(" Telephone ");
    //les champs de texte
    n1=new QLineEdit();
    p1=new QLineEdit();
    ph1=new QLineEdit();
    en1=new QLineEdit();
    em1=new QLineEdit();
    tel1=new QLineEdit();
    /*****bouton valider et annuler****/
    Bvalider1= new QPushButton("Valider");
    Bannuler1= new QPushButton("Annuler");
    BPhotoModifContact= new QPushButton("Parcourir");
    /***** disposition**********/
    vAligne11=new QVBoxLayout();
    vAligne22=new QVBoxLayout();
    vAligne33=new QVBoxLayout();
    aligneHH=new QHBoxLayout();


/****création et ajout des widget***********/
    vAligne11->addWidget(Nomcombo);
    vAligne11->addWidget(Nom1);
    vAligne11->addWidget(Prenom1);
    vAligne11->addWidget(Entreprise1);
    vAligne11->addWidget(Email1);
    vAligne11->addWidget(Telephone1);
    vAligne11->addWidget(Photo1);
    vAligne11->addWidget(Bannuler1);
    aligneHH->addLayout(vAligne11);

    vAligne22->addWidget(combo);
    vAligne22->addWidget(n1);
    vAligne22->addWidget(p1);
    vAligne22->addWidget(en1);
    vAligne22->addWidget(em1);
    vAligne22->addWidget(tel1);
    vAligne22->addWidget(BPhotoModifContact);
    vAligne22->addWidget(Bvalider1);
    aligneHH->addLayout(vAligne22);

    vAligne33->addWidget(ImageInsere2);
    aligneHH->addLayout(vAligne33);


    dialog1->setLayout(aligneHH);
    dialog1->show();

    connect(Bvalider1,SIGNAL(clicked()),this,SLOT(AfficheModContact())); /*!< connection du bouton valider1 de l'application au slot AfficheModContact*/
    connect(BPhotoModifContact,SIGNAL(clicked()),this,SLOT(afficherPhoto1())); /*!< connection du bouton BPhotoModifContact de l'application pour parcourir la photo à Modifier*/
    connect(Bannuler1,SIGNAL(clicked()),this,SLOT(BoutonAnnulerModification()));/*!< la connection pour le bouton annuler pour fermet la fenetre */
}


/*!
 *\fn FenetrePrincipale::AfficheModContact()
 *\brief Slot pour la modification d'un contact
 *on créer un contact c2 on test si tous les champs sont pas remplis sinon on affiche le message d'erreur
 *Si Oui on selectionne le contact à modifier et ensuite on récupère les textes saisies sur les champs avec
 *la photo récupéré on l'envoie par le signal pour qu'enfin qu'il soit connecté avec la base de donnée .
 *On aura au final un contact modifié dans la base de donnée
 */

void FenetrePrincipale::AfficheModContact()
{



    Contact  c2;
    if(n1->text()!=NULL && p1->text()!=NULL && en1->text()!=NULL && em1->text()!=NULL && tel1->text()!=NULL)
         {
            ui->afficherTexte->clear();
            c2.setNom(n1->text().toStdString());
            c2.setPrenom(p1->text().toStdString());
            c2.setEntreprise(en1->text().toStdString());
            c2.setMail(em1->text().toStdString());
            c2.setTelephone(tel1->text().toStdString());
            c2.setURIPhoto(ph1->text().toStdString());

            QString t=combo->currentText();
            int  c=t.toInt();
            emit sigModifier(c,c2);
            std::list<Contact> lp;
            lp.clear();
            emit sigGetContactList(lp);
            combo->clear();
            comboInteraction->clear();
            comboBox->clear();

            QString texte;
            QString vu;
            vu+="idContact \t | ";
            vu+=" Nom \t | ";
            vu+=" Prenom \t | ";
            vu+="Entreprise \t | ";
            vu+=" Email \t | ";
            vu+=" Photo \t | ";
            vu+=" Telephone \t | ";
            vu+=" Date \n\n";
            ui->afficherTexte->insertPlainText(vu);
            for(auto &p:lp)
           {
            texte+=QString::number(p.getId_contact())+ "\t";
            texte+=QString::fromStdString(p.getNom())+ "\t";
            texte+=QString::fromStdString(p.getPrenom())+ "\t";
            texte+=QString::fromStdString(p.getEntreprise())+ "\t";
            texte+=QString::fromStdString(p.getMail())+ "\t";
            texte+=QString::fromStdString(p.getURIPhoto())+ "\t";
            texte+=QString::fromStdString(p.getTelephone())+ "\t";
            texte+=QString::fromStdString(p.getDateDecreation().fromDateString())+ "\n";
            combo->addItem(QString::number(p.getId_contact()));

            comboBox->addItem(QString::number(p.getId_contact()));
            comboInteraction->addItem(QString::number(p.getId_contact()));


            }

            ui->afficherTexte->insertPlainText(texte);
             dialog1->close();
        }
    else

      {
            QMessageBox::warning(this,"Modification d'un contact "," Remplissez toutes les cases  !!!" );

       }


}
/*!
 *\fn FenetrePrincipale::BoutonAnnulerModification()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::BoutonAnnulerModification()
{
    dialog1->close();
}

/*!
*\fn FFenetrePrincipale::afficherPhoto1()
*\brief AfficherPhoto
*Ce slot qui nous permet de parcourir le chemin pour aller chercher la photo et ajouter son chemin sur le champs
*de texte dedié afin de l'insérer dans la BD .
*/
void FenetrePrincipale::afficherPhoto1()
{
    int w = ImageInsere2->width();
    int h = ImageInsere2->height();

    QString photo = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier "),QString(),
                                               "Images (*.png *.gif *.jpg *.jpeg *.bmp)");
    ImageInsere2->setPixmap(QPixmap(photo).scaled(w,h,Qt::KeepAspectRatio));
    ph1->setText(photo);
}

/*!
 *\fn FenetrePrincipale::chercherContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servit à chercher un contact par son nom :
 *Elle est constituée de la declaration d'une boite de dialogue ,tout ce qui concerne un contact
 *(nom,prenom,tel etc..),les champs de textes ,les boutons necessaires et les dispositions qu'on
 *a utilisés afin de bien positionner les labels,champs,boutons  .
 *
 */
void FenetrePrincipale::chercherContact()
{
    dialog3=new QDialog(this);
    dialog3->setWindowTitle(tr("Rechercher un contact "));
    dialog3->setModal(true);


    //nom
    NomR=new QLabel(" Nom");
    //label date debut
    debut=new QLabel("Date début");
    //label date fin
    fin=new QLabel("Date de fin ");

    //champs de texte
     nR=new QLineEdit();
     date1= new QDateEdit();
     date2= new QDateEdit();

    /****Dimension****/
    vAligneR=new QVBoxLayout();
    vAligneR2=new QVBoxLayout();
    hAlignH=new QHBoxLayout();

    //Bouton
    BRechercher= new QPushButton("Rechercher");
    Bannuler= new QPushButton("Annuler");
    vAligneR->addWidget(NomR);
    vAligneR->addWidget(debut);
    vAligneR->addWidget(fin);
    vAligneR->addWidget(Bannuler);
    hAlignH->addLayout(vAligneR);


    vAligneR2->addWidget(nR);
    vAligneR2->addWidget(date1);
    vAligneR2->addWidget(date2);
    vAligneR2->addWidget(BRechercher);
    hAlignH->addLayout(vAligneR2);

    dialog3->setLayout(hAlignH);

    dialog3->show();

    connect(BRechercher,SIGNAL(clicked()),this,SLOT(RechercheUnContact())); /*!< connection du bouton BRechercher de l'application au slot RechercheUnContact*/
    connect(Bannuler,SIGNAL(clicked()),this,SLOT(BoutonAnnulerRechercher())); /*!< la connection pour le bouton annuler pour fermet la fenetre */

}

/*!
 *\fn FenetrePrincipale::RechercheUnContact()
 *\brief Slot pour la Recherche d'un contact
 *on déclare une liste de contact,on test si le nom saisie existes entre les deux dates entrés par l'utilisateur:
 *Sinon on affiche  un message d'erreur
 *Si Oui on récupère les texte saisie et les deux dates on envoie avec le signal  vers la base de donnée pour rechercher pour
 *qu'enfin qu'il soit connecté avec la base de donnée .
 *On aura au final recherché un nom entre deux dates s'il existe dans la base de donnée .
 */

void FenetrePrincipale::RechercheUnContact()
{
    std::list<Contact> lp;
    ui->afficherTexte->clear();//Pour raffraichir l'affichage sur la base de donnée
    QString date01="";
    QString date02="";
    QString sep="-";

    QString tr=date1->text();
    date01=(((date01.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    tr=date2->text();
    date02=(((date02.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    tr=nR->text();
    emit sigRechercheUnContact(tr,date01,date02,lp);

    QString texte;
    QString vu;
    vu+="idContact \t | ";
    vu+=" Nom \t | ";
    vu+=" Prenom \t | ";
    vu+="Entreprise \t | ";
    vu+=" Email \t | ";
    vu+=" Photo \t | ";
    vu+=" Telephone \t | ";
    vu+=" Date \n\n";
    ui->afficherTexte->insertPlainText(vu);
    for(auto &p:lp)
    {
        texte+=QString::number(p.getId_contact())+ "\t";
        texte+=QString::fromStdString(p.getNom())+ "\t";
        texte+=QString::fromStdString(p.getPrenom())+ "\t";
        texte+=QString::fromStdString(p.getEntreprise())+ "\t";
        texte+=QString::fromStdString(p.getMail())+ "\t";
        texte+=QString::fromStdString(p.getURIPhoto())+ "\t";
        texte+=QString::fromStdString(p.getTelephone())+ "\t";
        texte+=QString::fromStdString(p.getDateDecreation().fromDateString())+ "\n";
    }

  ui->afficherTexte->insertPlainText(texte);
  dialog3->close();
}

/*!
 *\fn FenetrePrincipale::BoutonAnnulerRechercher()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */

void FenetrePrincipale::BoutonAnnulerRechercher()
{
    dialog3->close();
}

/*!
 *\fn FenetrePrincipale::SupprimerContact()
 *\brief Création d'une Boite de dialogue
 *elle comportera juste une comboBox pour avoir la liste des contacts pour enfin choisir le quel
 *on veut supprimer et le bouton supprimer et annuler .
 */

void FenetrePrincipale::SupprimerContact()
{
    dialog2=new QDialog(this);
    dialog2->setWindowTitle(tr("Suppression Contact"));
    dialog2->setModal(true);



     //Bouton Supprimer
     Bsupprimer= new QPushButton("Supprimer");
     QPushButton *Bannuler= new QPushButton("Annuler");

    /****Dimension****/
    QVBoxLayout *vAligne1=new QVBoxLayout();
    QVBoxLayout *vAligne2=new QVBoxLayout();
    QHBoxLayout *hAligne=new QHBoxLayout();
    //nom
    QLabel *Ncontact=new QLabel(" Liste Contact ");

    vAligne1->addWidget(Ncontact);
    vAligne1->addWidget(Bannuler);
    hAligne->addLayout(vAligne1);

    vAligne2->addWidget(comboBox);
    vAligne2->addWidget(Bsupprimer);

    hAligne->addLayout(vAligne2);

    dialog2->setLayout(hAligne);
    dialog2->show();

    connect(Bsupprimer,SIGNAL(clicked()),this,SLOT(suppressionContact()));
    connect(Bannuler,SIGNAL(clicked()),this,SLOT(BoutonAnnulerSupprimer()));
}
/*!
 *\fn FenetrePrincipale::SuppressionContact()
 *\brief Slot pour la suppression d'un contact
 *un contact a une ou plusieurs intéraction et une ou plusieurs taches donc c'est dans la base de donnée qu'on
 *a géré avec l'utilisation de ON CASCADE et ON pragma .
 *Lors de l'ouverture de cette boite de dialogue on selectionne juste le contact et on le supprime .
 */

void FenetrePrincipale::suppressionContact()
{
        ui->afficherTexte->clear();
        QString t=comboBox->currentText();

        if(t!=NULL)
          {
            int  c=t.toInt();
            qDebug()<<" "+ QString::number(c);
            emit sigSupprimer(c);
            std::list<Contact> lp;
            lp.clear();
            emit sigGetContactList(lp);
            comboBox->clear();
            combo->clear();
            comboInteraction->clear();
            comboList->clear();
            comboRecherche->clear();
            comboTachesRecherche->clear();
            comboTache->clear();
            QString vu;
            vu+="idContact \t | ";
            vu+=" Nom \t | ";
            vu+=" Prenom \t | ";
            vu+="Entreprise \t | ";
            vu+=" Email \t | ";
            vu+=" Photo \t | ";
            vu+=" Telephone \t | ";
            vu+=" Date \n\n";
            ui->afficherTexte->insertPlainText(vu);

            QString texte;
            for(auto &p:lp)
           {
            texte+=QString::number(p.getId_contact())+ "\t";
            texte+=QString::fromStdString(p.getNom())+ "\t";
            texte+=QString::fromStdString(p.getPrenom())+ "\t";
            texte+=QString::fromStdString(p.getEntreprise())+ "\t";
            texte+=QString::fromStdString(p.getMail())+ "\t";
            texte+=QString::fromStdString(p.getURIPhoto())+ "\t";
            texte+=QString::fromStdString(p.getTelephone())+ "\t";
            texte+=QString::fromStdString(p.getDateDecreation().fromDateString())+ "\n";
            //Actualiser les comboBoxs
            comboBox->addItem(QString::number(p.getId_contact()));
            combo->addItem(QString::number(p.getId_contact()));
            comboInteraction->addItem(QString::number(p.getId_contact()));
            comboList->addItem(QString::number(p.getId_contact()));
            comboRecherche->addItem(QString::number(p.getId_contact()));
            comboTachesRecherche->addItem(QString::number(p.getId_contact()));
            comboTache->addItem(QString::number(p.getId_contact()));
           }
            ui->afficherTexte->insertPlainText(texte);
            AfficheToutesLesInteractions();/*!< appel de la fonction pour actualiser l'affichage de toutes les intéractions aprés suppression .*/
            ListeTodos();/*!< appel de la fonction pour actualiser l'affichage des listes de taches à faire aprés suppression*/
          }
        else
          {
            QMessageBox::warning(this,"Suppression Contact","Impossible de faire la suppression sans\n"
                                      "voir la liste des contacts ");
          }
        dialog2->close();

}

/*!
 *\fn FenetrePrincipale::BoutonAnnulerSupprimer()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::BoutonAnnulerSupprimer()
{
    dialog2->close();
}

/*!
 *\fn FenetrePrincipale::TotalContact(int & tot)
 *\brief Nombre de contacts
 *Ce slot qui nous permet de nous afficher sur la fenetre principale le nombre total de contact dans la base sur un label  .
 */
void FenetrePrincipale::TotalContact(int & tot)
{
    QString texte="Le nombre total de contact est "+QString::number(tot)+"\n";
    ui->BNombrecontact->setText(texte);

}


/*!
 *\fn FenetrePrincipale::AjoutInteraction()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servit à ajouter une intéraction :
 *Elle est constituée de la declaration d'une boite de dialogue ,tout ce qui concerne une interaction
 *(Date et contenu),le champs de texte pour le contenu,les boutons necessaires et les dispositions qu'on
 *a utilisés afin de bien positionner les labels,le champ,les boutons  .
 *
 */

void FenetrePrincipale::AjoutInteraction()
{
    dialogInteraction=new QDialog(this);
    dialogInteraction->setWindowTitle(tr("Ajout Intéraction "));
    dialogInteraction->resize(300,1);
    dialogInteraction->setModal(true);


    //Prenom
    commentaire=new QLabel("Commentaire");
    cInteraction=new QLineEdit();

    QLabel *NomContact=new QLabel("Listes Contact ");
    QLabel *NomDate=new QLabel("Date ");
    dateAjout=new QDateEdit();

    BajoutInteraction= new QPushButton("Ajout Interaction");
    BannulerInteraction= new QPushButton("Annuler");


    /****Dimension****/
    vAligne1I=new QVBoxLayout(this);
    vAligne2I=new QVBoxLayout(this);
    hAligneI=new QHBoxLayout();

    vAligne1I->addWidget(NomContact);
    vAligne1I->addWidget(NomDate);
    vAligne1I->addWidget(commentaire);
    vAligne1I->addWidget(BannulerInteraction);

    hAligneI->addLayout(vAligne1I);

    vAligne2I->addWidget(comboInteraction);
    vAligne2I->addWidget(dateAjout);
    vAligne2I->addWidget(cInteraction);
    vAligne2I->addWidget(BajoutInteraction);

    hAligneI->addLayout(vAligne2I);

    dialogInteraction->setLayout(hAligneI);
    dialogInteraction->show();

    connect(BajoutInteraction,SIGNAL(clicked()),this,SLOT(AjoutUneInteraction()));/*!< connection du bouton BajoutInteraction de l'application au slot AjoutUneInteraction*/
    connect(BannulerInteraction,SIGNAL(clicked()),this,SLOT(AnnulerInteraction()));/*!< la connection pour le bouton annuler pour fermet la fenetre */

}

/*!
 *\fn FenetrePrincipale::AjoutUneInteraction()
 *\brief Slot pour l'ajout d'une intéraction
 *on test si la comboBox est null on envoir un message d'erreur .
 *si elle contient la liste des contacts : on entre la date et le contenu pour l'intéraction du contact
 *qu'on a choisi et on récupère la date et le contenu saisis on l'envoie par le signal "emit" pour
 *qu'enfin qu'il soit connecté avec la base de donnée .
 *On aura au final une intéraction ajouté avec sa date et contenu
 */

void FenetrePrincipale::AjoutUneInteraction()
{

    Interaction interaction;
    QString t=comboInteraction->currentText();
    QString date1="";
    QString sep="-";
    QString tr=dateAjout->text();
    date1=(((date1.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    if(cInteraction->text()!=NULL && t!=NULL)
              {
                int  c=t.toInt();
                interaction.setContenu(cInteraction->text().toStdString());
                interaction.setRDV(interaction.getRDV().toDateString(date1.toStdString()));
                interaction.setIdContact(c);
                emit  sigAjoutInteraction(c,interaction);

                QMessageBox msgBox;
                msgBox.setText("L'intéraction  a été ajouté avec succés sur le  contact qui a pour identifiant "
                               +QString::number(interaction.getIdContact()));
                msgBox.exec();
              }
    else
              {
                QMessageBox::warning(this,"Ajouter une intéraction ","Impossible d'ajouter une intéraction sans voir la liste des contacts \n"
                                          "ou sans entrer un contenu \n"
                                          "veuillez afficher les contacts sur la fenetre principale avant ." );
              }
    comboTache->clear();
    ui->textEditIntraction->clear();
    dialogInteraction->close();


}

/*!
 *\fn FenetrePrincipale::BoutonAnnulerIntéraction()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::AnnulerInteraction()
{
  dialogInteraction->close();
}

/*!
 *\fn FenetrePrincipale::ListeInteraction()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servi à lister les intéractions  d'un contact
 *Elle est constituée de la declaration d'une boite de dialogue ,un combobox pour la liste des contacts à lister ,
 *le bouton annuler et valider .
 */
void FenetrePrincipale::ListeInteraction()
{
    dialogList=new QDialog(this);
    dialogList->setWindowTitle(tr("Liste des Interactions "));
    dialogList->setModal(true);

    vAligneList1=new QVBoxLayout(this);
    vAligneList2=new QVBoxLayout(this);
    hAligneList=new QHBoxLayout();

    //Bouton
    BvaliderListI= new QPushButton("valider");
    BannulerListI= new QPushButton("Annuler");
    NomcomboList=new QLabel(" Liste des Conctact ");

    vAligneList1->addWidget(NomcomboList);
    vAligneList1->addWidget(BannulerListI);
    hAligneList->addLayout(vAligneList1);

    vAligneList2->addWidget(comboList);
    vAligneList2->addWidget(BvaliderListI);
    hAligneList->addLayout(vAligneList2);

    dialogList->setLayout(hAligneList);
    dialogList->show();

    connect(BvaliderListI,SIGNAL(clicked()),this,SLOT(ListeInteractionContact()));/*!< connection du bouton BvaliderListI de l'application au slot ListeInteractionContact*/
    connect(BannulerListI,SIGNAL(clicked()),this,SLOT(AnnulerListeInteraction()));/*!< la connection pour le bouton annuler pour fermet la fenetre */

}

/*!
 *\fn FenetrePrincipale::ListeInteractionContact()
 *\brief Slot pour l'affichage des intéractions d'un contact
 *Dans cette partie on testera si la combobox est null on affiche un message d'erreur
 *sinon on choisi le contact et on affiche toutes ses intéractions
 */
void FenetrePrincipale::ListeInteractionContact()
{

    ui->textEditIntraction->clear();
    QString t=comboList->currentText();
        int  c=t.toInt();

   if(t!=NULL)
    {
        std::list<Interaction> li;
        li.clear();
        emit sigListeInteraction(c,li);
         QString texte;

         QString inter;
         inter+="idInteract |   ";
         inter+="idContact  |   ";
         inter+="dateInter  |\t  ";
         inter+=" Contenu \n\n";
         ui->textEditIntraction->insertPlainText(inter);
        for(auto &p:li)
        {
            texte+=QString::number(p.getIdInteraction())+ "\t";
            texte+=QString::number(p.getIdContact())+"\t";
            texte+=QString::fromStdString(p.getRDV().fromDateString())+ "\t";
            texte+=QString::fromStdString(p.getContenu())+"\n";
        }
        ui->textEditIntraction->insertPlainText(texte); /*!< insertion de l'affichage sur le textEdit dedié .*/
              }
    else
      {
        QMessageBox::warning(this,"Liste intéractions","Impossible d'afficher les intéractions d'un contact sans connaitre le contact ! \n"
                                       "veuillez afficher la liste des contacts sur la fenetre principale avant");
      }

     dialogList->close();

}

/*!
 *\fn FenetrePrincipale::BoutonAnnulerListeInteraction()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::AnnulerListeInteraction()
{
    dialogList->close();
}

/*!
 *\fn FenetrePrincipale::AfficheToutesLesInteractions()
 *\brief Affichage des interactions
 *Lors du clic sur le bouton afficher listes interactions c'est grace à ce slot
 *qu'on voit l'affichage des intéraction en se réactualisant à chaque ajout,suppression ou modification sur
 *tout ce qui concerne les intéractions .
 */
void FenetrePrincipale::AfficheToutesLesInteractions()
{
    ui->textEditIntraction->clear();
    std::list<Interaction> li;
    li.clear();
    comboTache->clear();
    sigListeInteractionALL(li);
    QString texte;
    QString inter;
    inter+="idInteract |   ";
    inter+="idContact  |   ";
    inter+="dateInter  |\t  ";
    inter+=" Contenu \n\n";
    ui->textEditIntraction->insertPlainText(inter);
    for(auto &p:li)
    {
        texte+=QString::number(p.getIdInteraction())+ " \t| ";
        texte+=QString::number(p.getIdContact())+" \t| ";
        texte+=QString::fromStdString(p.getRDV().fromDateString())+ " \t| ";
        texte+=QString::fromStdString(p.getContenu())+" \t \n";
        comboTache->addItem(QString::number(p.getIdInteraction()));

    }
    ui->textEditIntraction->insertPlainText(texte);
}

/*!
 *\fn FenetrePrincipale::InteractionsEntre2Date()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a créé la boite de dialogue qui nous sert à Rechercher des intéractions entre deux dates.
 *La boite de dialogue  est constituée de la déclaration d'une boite de dialogue,d'une comboBox pour voir toute la liste
 *des contacts,et les dates debut et fin d'intervalle ,du bouton rechercher et annuler.
 */

void FenetrePrincipale::InteractionsEntre2Date()
{
    dialogIdeuxDates=new QDialog(this);
    dialogIdeuxDates->setWindowTitle(tr("Intéraction entre deux Dates "));
    dialogIdeuxDates->resize(400,10);
    dialogIdeuxDates->setModal(true);

    //Bouton
    BrechercheIdate=new QPushButton("Rechercher");
    BannulerIdate=new QPushButton("Annuler");

    //nom et date deubt
    QLabel *NomdateDebut=new QLabel("Date debut ");
    dateDebutI=new QDateEdit();

    //nom et date fin
    QLabel *NomdateFin=new QLabel("Date Fin ",this);
    dateFinI=new QDateEdit();

    vAligne1Id=new QVBoxLayout(this);
    vAligne2Id=new QVBoxLayout(this);
    hAligneId=new QHBoxLayout();

    vAligne1Id->addWidget(NomdateDebut);
    vAligne1Id->addWidget(NomdateFin);
    vAligne1Id->addWidget(BannulerIdate);
    hAligneId->addLayout(vAligne1Id);

    vAligne2Id->addWidget(dateDebutI);
    vAligne2Id->addWidget(dateFinI);
    vAligne2Id->addWidget(BrechercheIdate);
    hAligneId->addLayout(vAligne2Id);
    dialogIdeuxDates->setLayout(hAligneId);

    dialogIdeuxDates->show();

    connect(BrechercheIdate,SIGNAL(clicked()),this,SLOT(RechercherInteractionEntreDeuxDates()));/*!< connection du bouton BrechercheIdate de l'application au slot RechercherInteractionEntreDeuxDates*/
    connect(BannulerIdate,SIGNAL(clicked()),this,SLOT(AnnulerInteractionEntreDeuxDates()));/*!< la connection pour le bouton annuler pour fermet la fenetre */

}

/*!
 *\fn FenetrePrincipale::RechercherInteractionEntreDeuxDates()
 *\brief Slot pour la Rechercher des intéraction entre deux dates .
 *On converti et on decoupe les deux dates dans ce slot pour l'adapter à la BD tout en recuperant les dates saisies par l'utilisateur,
 *On aura au final des intéractions de la table qui se trouve dans cet intervalle des deux dates saisies .
 */
void FenetrePrincipale::RechercherInteractionEntreDeuxDates()
{
    std::list<Interaction> li;
    ui->textEditIntraction->clear();//Pour raffraichir l'affichage sur la base de donnée
    QString date1="";
    QString date2="";
    QString sep="-";

    QString tr=dateDebutI->text();
    date1=(((date1.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    tr=dateFinI->text();
    date2=(((date2.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    sigRechercheInteraction(date1,date2,li);

    QString texte;
    QString inter;
    inter+="idInteract |   ";
    inter+="idContact  |   ";
    inter+="dateInter  |\t  ";
    inter+=" Contenu \n\n";
    ui->textEditIntraction->insertPlainText(inter);
    for(auto &p:li)
    {
       texte+=QString::number(p.getIdInteraction())+ "\t";
       texte+=QString::number(p.getIdContact())+"\t";
       texte+=QString::fromStdString(p.getRDV().fromDateString())+ "\t";
       texte+=QString::fromStdString(p.getContenu())+"\n";
    }
    ui->textEditIntraction->insertPlainText(texte);/*!< insertion de l'affichage sur le textEdit dedié .*/
    dialogIdeuxDates->close();

}
/*!
 *\fn FenetrePrincipale::AnnulerInteractionEntreDeuxDates()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */

void FenetrePrincipale::AnnulerInteractionEntreDeuxDates()
{
    dialogIdeuxDates->close();
}

/*!
 *\fn FenetrePrincipale::RechercheInteractionContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a créé la boite de dialogue qui nous sert à Rechercher des intéractions entre deux dates
 *pour un contact .
 *La boite de dialogue  est constituée de la déclaration d'une boite de dialogue,d'une comboBox pour voir toute la liste
 *des contacts,et les dates debut et fin d'intervalle ,du bouton rechercher et annuler.
 */
void FenetrePrincipale::RechercheInteractionContact()
{
    dialogRC=new QDialog(this);
    dialogRC->setWindowTitle(tr("Rechercher interaction contact entre deux dates "));
    dialogRC->setModal(true);


    //nom
    QLabel *NContact=new QLabel("Liste contact");
    //label date debut
    QLabel *debutRC=new QLabel("Date début");
    //label date fin
    QLabel *finRC=new QLabel("Date de fin ");

    //champs de texte
     date1RC= new QDateEdit();
     date2RC= new QDateEdit();

    /****Dimension****/
    vAligneRRC=new QVBoxLayout();
    vAligneR2RC=new QVBoxLayout();
    hAlignHRC=new QHBoxLayout();

    //Bouton
    BRechercherRC= new QPushButton("Rechercher");
    BannulerRC= new QPushButton("Annuler");

    vAligneRRC->addWidget(NContact);
    vAligneRRC->addWidget(debutRC);
    vAligneRRC->addWidget(finRC);
    vAligneRRC->addWidget(BannulerRC);
    hAlignHRC->addLayout(vAligneRRC);


    vAligneR2RC->addWidget(comboRecherche);
    vAligneR2RC->addWidget(date1RC);
    vAligneR2RC->addWidget(date2RC);
    vAligneR2RC->addWidget(BRechercherRC);
    hAlignHRC->addLayout(vAligneR2RC);

    dialogRC->setLayout(hAlignHRC);

    dialogRC->show();

    connect(BRechercherRC,SIGNAL(clicked()),this,SLOT(FindContact()));/*!< connection du bouton BRechercherRC de l'application au slot FindContact*/
    connect(BannulerRC,SIGNAL(clicked()),this,SLOT(CancelContact()));/*!< la connection pour le bouton annuler pour fermet la fenetre */
}

/*!
 *\fn FenetrePrincipale::FindContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a créé la boite de dialogue qui nous sert à Rechercher des intéractions entre deux dates
 *pour un contact .
 *La boite de dialogue  est constituée de la déclaration d'une boite de dialogue,d'une comboBox pour voir toute la liste
 *des contacts,et les dates debut et fin d'intervalle ,du bouton rechercher et annuler.
 */
void FenetrePrincipale::FindContact()
{
    std::list<Interaction> li;
    ui->textEditIntraction->clear();

    QString date1="";
    QString date2="";
    QString sep="-";
    QString tr=date1RC->text();
    date1=(((date1.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

    tr=date2RC->text();
    date2=(((date2.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));
    QString t=comboRecherche->currentText();
    int  c=t.toInt();

    sigRechercheInteractionCont(c ,date1 ,date2 ,li);
    comboRecherche->clear();
    QString texte;
    QString inter;
    inter+="idInteract |   ";
    inter+="idContact  |   ";
    inter+="dateInter  |\t  ";
    inter+=" Contenu \n\n";
    ui->textEditIntraction->insertPlainText(inter);
    for(auto &p:li)
   {
      texte+=QString::number(p.getIdInteraction())+ "  |  ";
      texte+=QString::number(p.getIdContact())+"  |  ";
      texte+=QString::fromStdString(p.getRDV().fromDateString())+ "  |  ";
      texte+=QString::fromStdString(p.getContenu())+"\n";
   }
   ui->textEditIntraction->insertPlainText(texte);
   dialogRC->close();
}
/*!
 *\fn FenetrePrincipale::CancelContact()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */

void FenetrePrincipale::CancelContact()
{
    dialogRC->close();
}

/*!
 *\fn FenetrePrincipale::AjoutTaches()
 *\brief Slot pour l'ajout d'une tache
 *c'est dans cette fonction on a crée la boite de dialogue qui nous à servit à ajouter une tache pour une intéraction :
 *Elle est constituée de la declaration d'une boite de dialogue ,d'une liste d'intéraction ,d'un espace de saisie de texte "textEdit"
 *les boutons ajouts et annuler .
 */
void FenetrePrincipale::AjoutTaches()
{
    dialogTaches=new QDialog(this);
    dialogTaches->setWindowTitle(tr("Ajout d'une Tache"));
    dialogTaches->setModal(true);


    /****Dimension****/
    vAligneTaches=new QVBoxLayout(this);
    hAligne1Taches=new QHBoxLayout();
    hAligne2Taches=new QHBoxLayout();
    hAligne3Taches=new QHBoxLayout();
    //Bouton
    BajoutTaches= new QPushButton("Ajout",this);
    BannulerTaches= new QPushButton("Annuler",this);
    QLabel *NomcomboTache=new QLabel(" Liste des Intéractions ");
    //champ de texte
    editTaches=new QTextEdit();

    hAligne1Taches->addWidget(NomcomboTache);
    hAligne1Taches->addWidget(comboTache);
    vAligneTaches->addLayout(hAligne1Taches);

    hAligne2Taches->addWidget(editTaches);
    vAligneTaches->addLayout(hAligne2Taches);

    hAligne3Taches->addWidget(BannulerTaches);
    hAligne3Taches->addWidget(BajoutTaches);
    vAligneTaches->addLayout(hAligne3Taches);


    dialogTaches->setLayout(vAligneTaches);
    dialogTaches->show();

    connect(BajoutTaches,SIGNAL(clicked()),this,SLOT(AjoutTodoContact()));/*!< connection du bouton BajoutTaches de l'application au slot AjoutTodoContact */
    connect(BannulerTaches,SIGNAL(clicked()),this,SLOT(AnnulerTodoContact()));/*!< la connection pour le bouton annuler pour fermet la fenetre */


}

/*!
 *\fn FenetrePrincipale::AjoutTodoContact()
 *\brief Slot pour l'ajout  de la tache
 *on test si la combobox est null on affiche un message d'erreur
 *Sinon :on decoupe le tag @todo ou @date et on insère que les textes après le @todo et les dates qui son
 *ecrites au format jj/mm/aaaa devant le @date a fin de bien faire le tag .
 *On aura au final ajouter des taches dans la base de donnée
 */


void FenetrePrincipale::AjoutTodoContact()
{
   QString t=comboTache->currentText();


    if(t!=NULL)
     {
        QTextDocument * qdoc=editTaches->document();
        QTextCursor c(qdoc);
         QTextDocument::FindFlag  fcs=(QTextDocument::FindFlag) 0;

         QStringList ltodos;
         while(!c.isNull())
         {
             QRegularExpression qreg("^@todo .*$");
             c=qdoc->find(qreg, c.position(),fcs);
             if(!c.isNull())
             {
                 QTextBlock qtb = c.block ();
                 ltodos.append(qtb.text());
             }

         }

         int position;
         QString contenu;
          int  ci=t.toInt();
         for(auto& s:ltodos)
         {
             Todo in;

             in.setId_interaction(ci);
             position=s.toStdString().find("@date");
             if(position>0)
             {
                    QString date=s.mid(position+6,s.size());
                    std::string tmp(date.toStdString());
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
                     QString date1="";
                     QString sep="-";
                     date=QString::fromStdString(tmp);
                     date1=(((date1.append(date.mid(6,4)).append(sep)).append(date.mid(3,2)).append(sep)).append(date.mid(0,2)));
                      contenu=s.mid(6,position-6);
                     in.setContenuTodo(contenu.toStdString());
                     in.setDateTodo(in.getDateTodo().toDateString(date1.toStdString()));

             }
             else
             {
                   contenu=s.mid(6,s.size());
                  contenu+= " à faire maintenant";

                     in.setContenuTodo(contenu.toStdString());

             }
             emit  sigAjoutTodo(ci,in);
         }
         QMessageBox::information(this,"Ajout d'une tache ","Tache ajouté avec succés \n");

   }
    else
    {
        QMessageBox::warning(this,"Ajout d'une tache ","mpossible d'ajouter une tache \n"
                                     " veuillez afficher la liste des interactions ");

    }

       ui->textEditTodo->clear();
       dialogTaches->close();
}
/*!
 *\fn FenetrePrincipale::AnnulerTodoContact()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::AnnulerTodoContact()
{
    dialogTaches->close();
}


/*!
 *\fn FenetrePrincipale::ListeTodos()
 *\brief Affichage des taches
 *Lors du clic sur le bouton afficher listes todo c'est grace à ce slot
 *qu'on voit l'affichage des taches en se réactualisant à chaque ajout,suppression ou modification sur
 *tout ce qui concerne le TODO .
 */
void FenetrePrincipale::ListeTodos()
{

        std::list<Todo> li;
        li.clear();
        emit  sigListeALLContact(li);
        ui->textEditTodo->clear();
        QString texte;
        QString daTeInverse;//variable qui inverse la valeur
        int position;
        QString Tach;
        Tach+="idTodo    | ";
        Tach+="idIntera  | ";
        Tach+=" ContenuTodo | ";
        Tach+="  dateTodo\n\n";
        ui->textEditTodo->insertPlainText(Tach);
        for(auto &p:li)
         {
            position=p.getContenuTodo().find("à faire maintenant");/*!< verifier si la tache est urgente ou pas avec la fonction find */
            daTeInverse=QString::fromStdString(p.getDateTodo().fromDateString());
            texte+=QString::number(p.getIdtodo())+ "\t";
            texte+=QString::number(p.getId_interaction())+"\t";

        if(position>0)
         {
            texte+=" @todo "+QString::fromStdString(p.getContenuTodo())+"\n"; /*!< pour pouvoir faire le tag avec @todo*/
         }
        else{
                //recuperer la  date du todo en chaine de caractere
             QString date="";
             QString sep="/";
             date=(((date.append(daTeInverse.mid(8,2)).append(sep)).append(daTeInverse.mid(5,2)).append(sep)).append(daTeInverse.mid(0,4)));/*!< Inversion de la date de jj/mm/aaaa vers aaaa-mm-jj afin de pouvoir l'insérer dans la base */
             texte+=" @todo "+QString::fromStdString(p.getContenuTodo())+" @date "+date+"\n";/*!< pour pouvoir faire le tag avec @date*/

        }

    }
    ui->textEditTodo->insertPlainText(texte); /*!< insertion de l'affichage sur le textEdit dedié .*/

}


/*!
 *\fn FenetrePrincipale::AfficheTachesIntervalle()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a créé la boite de dialogue qui nous sert à afficher les taches des intéractions entre deux dates .
 *La boite de dialogue  est constituée de la déclaration d'une boite de dialogue,d'une comboBox pour voir toute la liste
 *des intéractions ,et les dates debut et fin d'intervalle ,du bouton BrechercherTaches et annuler.
 */

void FenetrePrincipale::AfficheTachesIntervalle()
{
    dialogRechercheT=new QDialog(this);
    dialogRechercheT->setWindowTitle(tr("Listes des taches d'un contact entre deux Dates "));
    dialogRechercheT->resize(400,1);
    dialogRechercheT->setModal(true);

    //Bouton
    BrechercherTaches= new QPushButton("Recherche taches");
    BannulerTachesR= new QPushButton("Annuler");

    //nom et date deubt
    QLabel *NomdateDebut=new QLabel("Date debut ");
    dateDebutTaches=new QDateEdit();

    QLabel *NomcomboBoxTaches=new QLabel("Choisir un contact ");


    //nom et date fin
    QLabel *NomdateFin=new QLabel("Date Fin ");
    dateFinTaches=new QDateEdit();


    vAligne1TachesR=new QVBoxLayout();
    vAligne2TachesR=new QVBoxLayout();
    hAligneTachesR=new QHBoxLayout();

    vAligne1TachesR->addWidget(NomcomboBoxTaches);
    vAligne1TachesR->addWidget(NomdateDebut);
    vAligne1TachesR->addWidget(NomdateFin);
    vAligne1TachesR->addWidget(BannulerTachesR);
    hAligneTachesR->addLayout(vAligne1TachesR);

    vAligne2TachesR->addWidget(comboTachesRecherche);
    vAligne2TachesR->addWidget(dateDebutTaches);
    vAligne2TachesR->addWidget(dateFinTaches);
    vAligne2TachesR->addWidget(BrechercherTaches);
    hAligneTachesR->addLayout(vAligne2TachesR);


    dialogRechercheT->setLayout(hAligneTachesR);

    dialogRechercheT->show();

    connect(BrechercherTaches,SIGNAL(clicked()),this,SLOT(RechercheTodoCont()));/*!< connection du bouton BrechercherTaches de l'application au slot RechercheTodoCont*/
    connect(BannulerTachesR,SIGNAL(clicked()),this,SLOT(BoutonAnnulerRechercherT()));/*!< la connection pour le bouton annuler pour fermet la fenetre */
}

/*!
 *\fn FenetrePrincipale::RechercheTodoCont()
 *\brief Slot pour la Rechercher des taches d'un contact entre deux dates .
 *on test si la combobox est nulle on affiche un message d'erreur
 *Sinon:
 *On converti et on decoupe les deux dates dans ce slot pour l'adapter à la BD tout en recuperant les dates saisies par l'utilisateur,
 *On aura au final des taches de la BD pour les contacts se trouvant dans cet intervalle des deux dates saisies .
 */
void FenetrePrincipale::RechercheTodoCont()
{
    ui->textEditTodo->clear();
    comboTachesRecherche->clear();
    QString date1="";
    QString date2="";
    QString sep="-";
    QString t=comboTachesRecherche->currentText();
    int  c=t.toInt();

    if(t!=NULL)
       {

            QString tr=dateDebutTaches->text();
            date1=(((date1.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));
            tr=dateFinTaches->text();
            date2=(((date2.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));
            std::list<Todo> lt;
            lt.clear();
            emit sigRechercheTodoCont(c , date1 , date2 , lt);
            QString texte;
            QString Tach;
            Tach+="idTodo    | ";
            Tach+="idIntera  | ";
            Tach+=" ContenuTodo | ";
            Tach+="  dateTodo\n\n";
            ui->textEditTodo->insertPlainText(Tach);
            for(auto &p:lt)
            {
                texte+=QString::number(p.getIdtodo())+ "\t";
                texte+=QString::number(p.getId_interaction())+"\t";
                texte+=QString::fromStdString(p.getDateTodo().fromDateString())+ "\t";
                texte+=QString::fromStdString(p.getContenuTodo())+"\n";

            }

            ui->textEditTodo->insertPlainText(texte); /*!< insertion de l'affichage sur le textEdit dedié .*/

       }

   else
       {
            QMessageBox::warning(this,"Interaction entre deux dates ",
            "Impossible de faire la récherche sans voir la liste des contacts");
       }

    dialogRechercheT->close();
}
/*!
 *\fn FenetrePrincipale::BoutonAnnulerRechercherT()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::BoutonAnnulerRechercherT()
{
    dialogRechercheT->close();
}

/*!
 *\fn FenetrePrincipale::AfficheTachesContact()
 *\brief Création d'une Boite de dialogue
 *c'est dans cette fonction on a créé la boite de dialogue qui nous sert à afficher toutes les taches de toutes les intéractions entre deux dates .
 *La boite de dialogue  est constituée de la déclaration d'une boite de dialogue, les dates debut et fin d'intervalle ,du bouton BrechercherTaches et annuler.
 */

void FenetrePrincipale::AfficheTachesContact()
{

    dialogALL=new QDialog(this);
    dialogALL->setWindowTitle(tr("Listes des taches de tous les contacts entre deux dates "));
    dialogALL->resize(450,1);
    dialogALL->setModal(true);

    //Bouton
    BrechercherALL= new QPushButton("Recherche");
    BannulerALL= new QPushButton("Annuler");

    //nom et date deubt
    QLabel *NomdateDebutALL=new QLabel("Date debut ");
    dateDebutALL=new QDateEdit();


    //nom et date fin
    QLabel *NomdateFinALL=new QLabel("Date Fin ");
    dateFinALL=new QDateEdit();


    vAligne1ALL=new QVBoxLayout();
    vAligne2ALL=new QVBoxLayout();
    hAligneALL=new QHBoxLayout();


    vAligne1ALL->addWidget(NomdateDebutALL);
    vAligne1ALL->addWidget(NomdateFinALL);
    vAligne1ALL->addWidget(BannulerALL);
    hAligneALL->addLayout(vAligne1ALL);

    vAligne2ALL->addWidget(dateDebutALL);
    vAligne2ALL->addWidget(dateFinALL);
    vAligne2ALL->addWidget(BrechercherALL);
    hAligneALL->addLayout(vAligne2ALL);


    dialogALL->setLayout(hAligneALL);

    dialogALL->show();

    connect(BrechercherALL,SIGNAL(clicked()),this,SLOT(RechercheALLTodoCont())); /*!< connection du bouton BrechercherALL de l'application au slot RechercheALLTodoCont*/
    connect(BannulerALL,SIGNAL(clicked()),this,SLOT(AnnulerALL()));/*!< la connection pour le bouton annuler pour fermet la fenetre */



}

/*!
*\fn  FenetrePrincipale::RechercheALLTodoCont()
*\brief Slot pour la Rechercher des taches de tous les contacts entre deux dates .
*On converti et on decoupe les deux dates dans ce slot pour l'adapter à la BD tout en recuperant les dates saisies par l'utilisateur,
*On aura au final des taches de la BD pour  tous les contacts se trouvant dans cet intervalle des deux dates saisies .
*/

void FenetrePrincipale::RechercheALLTodoCont()
{
    std::list<Todo> li;
    li.clear();
    ui->textEditTodo->clear();
    QString date1="";
    QString date2="";
    QString sep="-";

   QString tr=dateDebutALL->text();
   date1=(((date1.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

   tr=dateFinALL->text();
   date2=(((date2.append(tr.mid(6,4)).append(sep)).append(tr.mid(3,2)).append(sep)).append(tr.mid(0,2)));

   emit  sigRechercheALLTodoCont( date1,date2,li);
   QString texte;
   QString Tach;
   Tach+="idTodo    | ";
   Tach+="idIntera  | ";
   Tach+=" ContenuTodo | ";
   Tach+="  dateTodo\n\n";
   ui->textEditTodo->insertPlainText(Tach); /*!< insertion de l'affichage sur le textEdit dedié .*/

   for(auto &p:li)
     {

      texte+=QString::number(p.getIdtodo())+ "\t";
      texte+=QString::number(p.getId_interaction())+"\t";
      texte+=QString::fromStdString(p.getDateTodo().fromDateString())+ "\t";
      texte+=QString::fromStdString(p.getContenuTodo())+"\n";

  }
  ui->textEditTodo->insertPlainText(texte); /*!< insertion de l'affichage sur le textEdit dedié .*/
  dialogALL->close();

}
/*!
 *\fn FenetrePrincipale::AnnulerALL()
 *\brief Annuler
 *Ce slot qui nous permet de faire la fermeture de la boite de dialogue lors du clic sur le bouton annuler quand il est ouvert .
 */
void FenetrePrincipale::AnnulerALL()
{
    dialogALL->close();
}



/*!
 *\fn FenetrePrincipale::Affichage()
 *\brief Affichage Contact
 *Lors du clic sur le bouton afficher listes contact c'est grace à ce slot
 *qu'on voit l'affichage des contact en se réactualisant à chaque ajout,suppression ou modification sur
 *tout ce qui concerne le contact .
 */
void FenetrePrincipale::Affichage()
{
    std::list<Contact> lp;
    ui->afficherTexte->clear();//raffraichier le textEdit
    combo->clear();//raffraichir la combo
    comboBox->clear();//raffraichir la combo
    comboInteraction->clear();//raffraichir la combo
    comboList->clear();//raffraichir la combo
    comboRecherche->clear();//raffraichir la combo
    comboTache->clear();//raffraichir la combo
    comboTachesRecherche->clear();//Raffraichier la combo pour la recherche d'une tache d'un contact .



    emit sigGetContactList(lp);//envoi du signal qu'on liera dans le main avec la BD

    QString texte;

    QString vu;
    vu+="idContact \t | ";
    vu+=" Nom \t | ";
    vu+=" Prenom \t | ";
    vu+="Entreprise \t | ";
    vu+=" Email \t | ";
    vu+=" Photo \t | ";
    vu+=" Telephone \t | ";
    vu+=" Date \n\n";
    ui->afficherTexte->insertPlainText(vu);
    for(auto &p:lp)
    {   texte+=QString::number(p.getId_contact())+ " \t";
        texte+=QString::fromStdString(p.getNom())+ " \t";
        texte+=QString::fromStdString(p.getPrenom())+ " \t";
        texte+=QString::fromStdString(p.getEntreprise())+ " \t";
        texte+=QString::fromStdString(p.getMail())+ " \t";
        texte+=QString::fromStdString(p.getURIPhoto())+ " \t";
        texte+=QString::fromStdString(p.getTelephone())+ " \t";
        texte+=QString::fromStdString(p.getDateDecreation().fromDateString())+ "\n";

        //actualiser les comboBoxs dans l'application
        combo->addItem(QString::number(p.getId_contact())+" "+QString::fromStdString(p.getNom())); //ajout de l'identifant du contact sur la combo à chaque appel de ce slot
        //combo->addItems(QStringList()<<QString::fromStdString(p.getNom())<< QString::number(p.getId_contact())) ;
        //combo->addItem(QString::fromStdString(p.getNom()));
        comboBox->addItem(QString::number(p.getId_contact()));
        comboList->addItem(QString::number(p.getId_contact()));
        comboRecherche->addItem(QString::number(p.getId_contact()));
        comboInteraction->addItem(QString::number(p.getId_contact()));
        comboTachesRecherche->addItem(QString::number(p.getId_contact()));


    }

    ui->afficherTexte->insertPlainText(texte);//insertion sur le textedit le QString afin de faire l'affichage
}

/*!
 *\fn FenetrePrincipale::Apropos()
 *\brief About
 *C'est dans ce slots on a dit de manière brève ce que notre application fait
 *et qui l'a fait et c'est qui le professeur .
 */

void FenetrePrincipale::Apropos()
{

   QMessageBox::information(this, "Apropos de notre Projet CDAA",
                            " On a developpé cette applilcation QT (c++) en faisant \n"
                            "  dialoguer l'application et une base de donnée SQL .\n"
                            " Ce projet est fait  par  \n"
                            " DIALLO Iliassou \n"
                            "&\n"
                            " BARRY thierno Oumar \n"
                            "du Groupe BR !\n\n"
                            "Professeur: Monsieur Raffin Romain .");

}
/*!
 *\fn FenetrePrincipale::demarrerHeure()
 *\brief Affichage de l'heure lors de l'éxécution de notre programme
 *Slot pour afficher l'heure courrante dès qu'on lance notre application
 */


void FenetrePrincipale::demarrerHeure()
{
    QTime timeValue;
    timeValue=QTime::currentTime();
    QString format=" H:m:s";
    ui->Lheure->setText(timeValue.toString(format));

}

/*
void FenetrePrincipale::returnJSON(QJsonDocument &document)
{
    QByteArray bytes=document.toJson( QJsonDocument::Indented );
    QFile file("Agenda.json ");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ))
     {
        QTextStream iStream(&file);
        iStream.setCodec("utf-8");
        iStream << bytes ;
        file.close();

        QMessageBox msgBox;
        msgBox.setText("le fichier a bien ete crée ");
        msgBox.exec();

      }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Erreur ");
        msgBox.exec();
    }
}











void FenetrePrincipale::on_jsontest_clicked()
{
    emit sqlToJson();
}

*/
