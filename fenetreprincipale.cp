#include "fenetreprincipale.h"
#include "fenetreprincipale.h"
FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle (tr("Caibinet Médical"));
    resize(680,480);
    FenetreAccueille ();
    CreateFenetreConnexion ();
    CreateDocWidget();
    CreateAction ();
    CreateMenu ();
    CreateBaroutils ();
    CreateSousfentres ();
  // qApp->setStyleSheet ("QLineEdit {background-color : gray}");

}
 // Destructeur

FenetrePrincipale::~FenetrePrincipale()
{
}

//Fenetre d'accueille

void FenetrePrincipale::FenetreAccueille(){
    FenAccueille = new QGraphicsView();
    //imgenAcc = new QLabel;
    //imgenAcc->setPixmap (QPixmap("ff.jpg"));
    //FenAccueille->setCentralWidget (imgenAcc);
    iteme= new QGraphicsPixmapItem;
    iteme->setPixmap(QPixmap("ff.jpg").scaled (1250,650));

    scene= new QGraphicsScene();
    FenAccueille->setScene (scene);
    scene->addItem(iteme);

    FenAccueille->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    FenAccueille->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    iteme->setTransformOriginPoint(50,50);
}

//QPushButton *FenetrePrincipale::getBtnSecretaire() const
//{
//    return btnSecretaire;
//}
//
//void FenetrePrincipale::setBtnSecretaire(QPushButton *newBtnSecretaire)
//{
//    btnSecretaire = newBtnSecretaire;
//}

// Slot pour quitter l'appli

void FenetrePrincipale::OnExit(){
    int Answer = QMessageBox::question (this,tr("Quitter"),tr("Voulez vous vraiment quitter?"),QMessageBox::Yes | QMessageBox::No);
    if (Answer==QMessageBox::Yes){
        qApp->quit ();
    }
}

// Slot pour afficher la fenetre Medecin

void FenetrePrincipale::showFenMedecin(){
    if (Fenetrecentrale->currentWidget () != FenMedecin){
        Fenetrecentrale->setCurrentWidget (FenMedecin);
    }
}

// Slot pour afficher la fenetre Secrétaire

void FenetrePrincipale::showFenSecretaire(){
    if (Fenetrecentrale->currentWidget () != FenSecretaire){
        Fenetrecentrale->setCurrentWidget (FenSecretaire);
    }
}

// Slot pour afficher la fenetre de connexion

void FenetrePrincipale::ShowFenConnextion(){
    if (Fenetrecentrale->currentWidget () != FenConnextion){
        Fenetrecentrale->setCurrentWidget (FenConnextion);
    }
}

// Slot pour afficher la fenetre d'accueille

void FenetrePrincipale::showFenAccueille(){
    if (Fenetrecentrale->currentWidget () != FenAccueille){
        Fenetrecentrale->setCurrentWidget (FenAccueille);
    }
}

// Méthode de Création des actions

void FenetrePrincipale::CreateAction(){
    // Action quitter dans le menuFichier
    aQuitter = new QAction(tr("Quitter"));
    aQuitter->setIcon (QIcon("aquitter.png"));
    aQuitter->setToolTip (tr("Ctrl+Q pour quitter"));
    aQuitter->setShortcut (QKeySequence("Ctrl+Q"));
    connect (aQuitter, &QAction::triggered, this, &FenetrePrincipale::OnExit);

    // Action accueille dans le menuBar
    aAccueille = new QAction();
    aAccueille->setIcon (QIcon("images.png"));
    aAccueille->setToolTip (tr("Accueille"));
    connect (aAccueille,&QAction::triggered,this,&FenetrePrincipale::showFenAccueille);
    // Action Parametre
    aParametre = new QAction();
    aParametre->setIcon (QIcon("parametre.jpeg"));
    aParametre->setToolTip (tr("Parametre"));

    //Action calculatrice

    aCalculette = new QAction();
    aCalculette->setIcon (QIcon("calcul.jpeg"));
    aCalculette->setText (tr("Calculatrice"));
    aCalculette->setToolTip (tr("Cliquez pour calculer"));

    // Action Internet

    aInternet = new QAction();
    aInternet->setIcon (QIcon("net.jpeg"));
    aInternet->setText (tr("Internet"));
    aInternet->setToolTip (tr("Cliquez pour vous connecter"));

    // Action Bloc notes

    aBlocNote = new QAction();
    aBlocNote->setIcon (QIcon("note.jpeg"));
    aBlocNote->setText (tr("Bloc note"));
    aBlocNote->setToolTip (tr("Cliquez pour editer un texte"));

    // Action login

    alogin = new QAction();
    alogin->setIcon (QIcon("alogin.jpg"));
    alogin->setToolTip (tr("Fenetre connexion"));

    connect (alogin,&QAction::triggered,this,&FenetrePrincipale::ShowFenConnextion);
}

// Methode de création de Menu

void FenetrePrincipale::CreateMenu(){
    menuFichier = new QMenu();
    menuEdition = new QMenu();
    menuOutils = new QMenu();
    menuAide = new QMenu();

    menuFichier = menuBar ()->addMenu (tr("&Fichier"));
    menuEdition = menuBar ()->addMenu (tr("&Edition"));
    menuOutils = menuBar ()->addMenu (tr("&Outils"));
    menuAide = menuBar ()->addMenu (tr("&Aide"));

    // Ajout des actions dans Outils

    menuOutils->addAction (aCalculette);
    menuOutils->addAction (aInternet);
    menuOutils->addAction (aBlocNote);

    // AJout dans Fichier

    menuFichier->addAction (aQuitter);

}

// Méthode de Création de la barre d'outils

void FenetrePrincipale::CreateBaroutils(){
    BarOutils= new QToolBar();
    BarOutils->setStyleSheet ("background-color : blue");
    BarOutils = addToolBar ("BarOutils");
    BarOutils->addAction (aAccueille);
    BarOutils->addAction (aParametre);
    BarOutils->addAction (alogin);

    //BarOutils->addSeparator ();
    //QLabel *logo = new QLabel();
    //logo->setPixmap (QPixmap("logo.png"));
    //BarOutils->addWidget (logo);

    status = new QLabel();
    status->setFont (QFont("",13));
    status->setText (tr("<h4>Déconnecter</h4>"));
    statusBar ()->addWidget (status);
}

// Méthode de création de la base de donnée

void FenetrePrincipale::CreateDatabase(){
    database.QSqlDatabase::addDatabase ("QMYSQL");

    database.setUserName (login->text ());
    database.setPassword (passWrd->text ());
    database.setDatabaseName ("Cabinet");

    if (!database.open ()){
        QMessageBox::critical (this,tr("Error"),database.lastError ().text ());
    }else{
        QMessageBox::information (this,"",tr("Connecté"));
        status->setText ("<h4>Connecté</h4>");
        connexion->setText (tr("Connecté"));
        connect (connexion,&QPushButton::clicked,this, &FenetrePrincipale::Deconnexion);
    }

}

// Méthode de création de la fenetre de connexion

void FenetrePrincipale::CreateFenetreConnexion(){
    FenConnextion = new QWidget();
    login = new QLineEdit();
    passWrd = new QLineEdit();
    connexion = new QPushButton(tr("Connexion"));

    // le bouton connexion en bleu

    connexion->setStyleSheet ("background-color : blue");

    showPass = new QCheckBox();
    // Connexion du showpass au slot Decocher qui va rendre le mot de passe user visible
    connect(showPass,&QCheckBox::stateChanged,this,&FenetrePrincipale::Decocher);
    imlogin = new QLabel;
    imlogin->setPixmap (QPixmap("alogin.jpg").scaled (185, 180)); // Le scaled me permet de redimentionner l'image

    Fl = new QFormLayout();
    Fl->addRow (tr("User"),login);
    Fl->addRow (tr("Mot de passe"),passWrd);
    Fl->addRow (tr("Afficher Mot de passe"),showPass);

    passWrd->setEchoMode (QLineEdit::Password);
    Fl->addRow (connexion);
    Fl->setAlignment (Qt::AlignCenter);

    // J'appel la methode setAlignment pour aligner

    Fl->setAlignment (connexion, Qt::AlignHCenter);
    Fl->setAlignment (login, Qt::AlignHCenter);
    Fl->setAlignment (passWrd, Qt::AlignHCenter);

    Vl = new QVBoxLayout();
    Vl->addWidget (imlogin, 0, Qt::AlignHCenter);
    Vl->addLayout (Fl);
    Vl->setAlignment (Qt::AlignCenter);
    FenConnextion->setLayout (Vl);
    connect(connexion,&QPushButton::clicked,this,&FenetrePrincipale::CreateDatabase);


}

// Méthode de création des sous fenetre, dont leur ajout dans le Qstacked widget

void FenetrePrincipale::CreateSousfentres(){
    Fenetrecentrale = new QStackedWidget();

    FenMedecin = new FenetreMedecin();
    FenSecretaire = new FentreSecretaire();

    Fenetrecentrale->addWidget (FenMedecin);
    Fenetrecentrale->addWidget (FenSecretaire);
    Fenetrecentrale->addWidget (FenConnextion);
    Fenetrecentrale->addWidget (FenAccueille);
    Fenetrecentrale->setCurrentWidget (FenAccueille);

    this->setCentralWidget (Fenetrecentrale);

}

void FenetrePrincipale::CreateDocWidget()
{
    docFen = new QDockWidget();
    docFen->setFloating (false);
    docFen->setFixedWidth (100);
    w = new QWidget();
    btnMedecin = new QPushButton(tr("Médecin"));
    btnMedecin->setFont (QFont("",13,QFont::Bold));

    btnSecretaire = new QPushButton(tr("Secrétaire"));
    btnConnexion = new QPushButton(tr("Connexion"));
    btnConnexion->setFont (QFont("",11,QFont::Bold));
    btnSecretaire->setFont (QFont("",13,QFont::Bold));

    btnOrd = new QPushButton(tr("Ordonnace"));
    btnOrd->setStyleSheet ("background-color : red");
    btnCer = new QPushButton(tr("Certificat"));
    btnCer->setStyleSheet ("background-color : red");
    btnInf = new QPushButton(tr("Information"));
    btnInf->setStyleSheet ("background-color : red");
    btnlettre = new QPushButton(tr("Lettre"));
    btnlettre->setStyleSheet ("background-color : red");
    btnGp = new QPushButton(tr("Patient"));
    btnGp->setStyleSheet ("background-color : red");
    btnGrv = new QPushButton(tr("Rendez-vous"));
    btnGrv->setStyleSheet ("background-color : red");
    btnGc = new QPushButton(tr("Comptabilité"));
    btnGc->setStyleSheet ("background-color : red");

    //btnMedecin->setIcon (QIcon("Login.jpg"));

    // Couleur de fond

    btnMedecin->setStyleSheet ("background-color : blue");
    btnSecretaire->setStyleSheet ("background-color : blue");
    btnConnexion->setStyleSheet ("background-color : blue");

    VLG = new QVBoxLayout();
    vlmed = new QVBoxLayout();
    vlsec = new QVBoxLayout();
    vlcon = new QVBoxLayout();

    // Ajout des Widgets dans le layout de medecin

    vlmed->addWidget (btnMedecin);
    vlmed->addWidget (btnOrd);
    vlmed->addWidget (btnCer);
    vlmed->addWidget (btnInf);
    vlmed->addWidget (btnlettre);

    // AJout du bouton de connexion dans le layout de connexion

    vlcon->addWidget (btnConnexion);

    vlsec->addWidget (btnSecretaire);
    vlsec->addWidget (btnGp);
    vlsec->addWidget (btnGrv);
    vlsec->addWidget (btnGc);

    VLG->addLayout (vlmed);
    VLG->addLayout (vlcon);
    VLG->addLayout (vlsec);
    VLG->setSpacing (10);

    w->setLayout (VLG);
    docFen->setWidget (w);

    addDockWidget (Qt::LeftDockWidgetArea,docFen);

    connect(btnMedecin,&QPushButton::clicked, this, &FenetrePrincipale::showFenMedecin);
    connect(btnSecretaire,&QPushButton::clicked, this, &FenetrePrincipale::showFenSecretaire);
    connect(btnConnexion,&QPushButton::clicked, this, &FenetrePrincipale::ShowFenConnextion);


    // Connection des sous boutton

    connect(btnGp,&QPushButton::clicked, this, &FenetrePrincipale::showTabGP);
    connect(btnGrv,&QPushButton::clicked, this, &FenetrePrincipale::showTabGrv);
    connect(btnOrd,&QPushButton::clicked, this, &FenetrePrincipale::showTabOrd);
    connect(btnCer,&QPushButton::clicked, this, &FenetrePrincipale::showTabCer);
    connect(btnInf,&QPushButton::clicked, this, &FenetrePrincipale::showTabInf);
   // connect(btnlettre,&QPushButton::clicked, this, &FenetrePrincipale::showTabLettre);
    //connect(btnConnexion,&QPushButton::clicked, this, &FenetrePrincipale::ShowFenConnextion);
    //connect(btnConnexion,&QPushButton::clicked, this, &FenetrePrincipale::ShowFenConnextion);

}

// Se deconnecter de la base de données

void FenetrePrincipale::Deconnexion(){
    database.close ();
    if (!database.isOpen ()){
        connexion->setText (tr("Connexion"));
        status->setText ("Déconnecté");
    }else{
        QMessageBox::information (this,"",tr("Erreur de déconnexion"));
    }
}

// Visibilitée du mot de passe dans la fenetre de connexion

void FenetrePrincipale::Decocher(){
    if(showPass->isChecked ()){ // si le bouton est coché, on affiche le mot de passe
        passWrd->setEchoMode (QLineEdit::Normal);
    }else{ // sinon on laisse le mot de passe caché
        passWrd->setEchoMode (QLineEdit::Password);
    }
}

void FenetrePrincipale::showTabGP(){
    Fenetrecentrale->setCurrentWidget (FenSecretaire);
    FenSecretaire->showTabGP ();
}

void FenetrePrincipale::showTabGrv()
{
    Fenetrecentrale->setCurrentWidget (FenSecretaire);
    FenSecretaire->showTabGrv ();
}

void FenetrePrincipale::showTabOrd()
{
    Fenetrecentrale->setCurrentWidget (FenMedecin);
    FenMedecin->showTabord ();
}

void FenetrePrincipale::showTabCer()
{
    Fenetrecentrale->setCurrentWidget (FenMedecin);
    FenMedecin->showTabCer ();
}

void FenetrePrincipale::showTabInf()
{
    Fenetrecentrale->setCurrentWidget (FenMedecin);
    FenMedecin->showTabInf ();
}
