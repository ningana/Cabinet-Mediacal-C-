#include "fentresecretaire.h"

FentreSecretaire::FentreSecretaire() : QWidget ()
{
    VlayoutGeneral = new QVBoxLayout(this); // Layout generale contenant le QTab
    Onglets = new QTabWidget();
    Onglets->setCursor (Qt::PointingHandCursor);
    Onglets->setTabShape (QTabWidget::Triangular);

    VlayoutGeneral->addWidget (Onglets);
    // Construction des widgets pages à ajouter dans le QTabWidget
    page1 = new QWidget();
    page2 = new QWidget();
    page3 = new QWidget();
    // Appel de la Methode de creation de formulaire et de la Table
    CreateFormPatient ();
    CreateTablePatient();
    // Layout qui contiendra le spliter
    Vlayoutpage1 = new QVBoxLayout();
    // Layout contenant la table de donnée
    vlayoutTable = new QVBoxLayout();
    vlayoutTable->addWidget (view);
    vlayoutTable->addLayout (hlTable);
    // Les deux widgets composant le spliter
    W1 = new QWidget(); W1->setLayout (Flayout);// Contient le formulaire
    W1->setFixedWidth (350);
    W2 = new QWidget(); W2->setLayout (vlayoutTable);// Contiendra la table de base de données
    // Le spliter
    spliter = new QSplitter();
    spliter->addWidget (W1);
    spliter->addWidget (W2);

    Vlayoutpage1->addWidget (spliter);
    page1->setLayout (Vlayoutpage1);

    Onglets->addTab (page1,tr("Gestion de patient"));
    Onglets->addTab (page2,tr("Gestion rendez vous"));
    Onglets->addTab (page3,tr("Gestion de comptabilité"));

    CreateFormRv ();
    CreateTableRv ();

    spliterrv = new QSplitter();
    W1rv = new QWidget(); W1rv->setLayout (FLayout);

    W1rv->setFixedWidth (700);

    W2rv = new QWidget(); W2rv->setLayout (vlayouteTablerv);

    spliterrv->addWidget (W1rv);
    spliterrv->addWidget (W2rv);

    vlayoutpage2->addWidget (spliterrv);

    page2->setLayout (vlayoutpage2);
}

void FentreSecretaire::CreateFormPatient(){

    Flayout    =    new QFormLayout();
    firstName  =    new QLineEdit();
    lastName   =    new QLineEdit();
    Numtel     =    new QLineEdit();
    addresse   =    new QLineEdit();
    youngName  =    new QLineEdit();
    lastName   =    new QLineEdit();
    sexe       =    new QLineEdit();
    DCreation  =    new QLineEdit();
    DCreation->setText ("0/0/0");
    DNaissance =    new QLineEdit();
    DNaissance->setText ("0/0/0");
    Nfiche     =    new QSpinBox();
    CIN        =    new QSpinBox();
    profession =    new QLineEdit();
    description=    new QTextEdit();
    onAdd = new QPushButton(tr("Ajouter"));
    onAdd->setStyleSheet ("background-color : blue");

    Flayout->addRow (tr("Fiche N° : "),Nfiche);
    Flayout->addRow (tr("Date de creation : "),DCreation);
    Flayout->addRow (tr("CIN : "),CIN);
    Flayout->addRow (tr("Nom : "),firstName);
    Flayout->addRow (tr("Prenom : "),lastName);
    Flayout->addRow (tr("Sexe"),sexe);
    Flayout->addRow (tr("Néé le : "),DNaissance);
    Flayout->addRow (tr("Adresse : "),addresse);
    Flayout->addRow (tr("Nom jeunesse : "),youngName);
    Flayout->addRow (tr("Profession"),profession);
    Flayout->addRow (tr("Téléphone"),Numtel);
    Flayout->addRow (tr("Description"),description);

    hlformulaire = new QHBoxLayout();
    hlformulaire->addWidget (onAdd);
    hlformulaire->setAlignment (Qt::AlignHCenter);
    Flayout->addRow (hlformulaire);
}

void FentreSecretaire::CreateTablePatient(){

    view = new QTableView();
    model = new QStandardItemModel;
    hlTable = new QHBoxLayout();

    view->setModel (model);


    QStringList head;
    head<<tr("idFIche")<<tr("DateCréation")<<tr("nom")<<tr("prenom")<<tr("sexe")<<
          tr("DateNaissance")<<tr("addersse")<<tr("NomJeunesse")<<tr("Profession")<<tr("tel")<<tr("Description");

    model->setHorizontalHeaderLabels (head);

    onUpdate = new QPushButton(tr("Mis à jour"));
    onUpdate->setStyleSheet ("background-color : blue");

    //connect(onUpdate,SIGNAL (clicked()),this,SLOT (Update(database)));
    hlTable->addWidget (onUpdate);
    hlTable->setAlignment (Qt::AlignHCenter);
}

//void FentreSecretaire::Update(QSqlDatabase database){
//
//    QSqlQuery query = QSqlQuery(database);
//    if (query.exec ("SELECT * FROM Patient;"))
//    {
//        model = new QStandardItemModel();
//        QStringList head;
//        head<<tr("idFIche")<<tr("DateCréation")<<tr("nom")<<tr("prenom")<<tr("sexe")<<
//              tr("DateNaissance")<<tr("addersse")<<tr("NomJeunesse")<<tr("Profession")<<tr("tel")<<tr("Description");
//        model->setHorizontalHeaderLabels (head);
//
//        while(query.next ())
//        {
//            QList<QStandardItem*> lsItem;
//
//
//            QString Nfiche = query.value ("idFiche").toString ();
//            QString firstName = query.value ("nom").toString ();
//            QString lastName = query.value ("prenom").toString ();
//            QString sexe = query.value ("sexe").toString ();
//            QString DNaissance = query.value ("DateNaissance").toString ();
//            QString DCreation = query.value ("DateCreation").toString ();
//            QString profession = query.value ("profession").toString ();
//            QString Numtel = query.value ("tel").toString ();
//            QString description = query.value ("Description").toString ();
//            QString addresse = query.value ("addresse").toString ();
//
//
//            lsItem<<new QStandardItem(Nfiche);
//            lsItem<<new QStandardItem(firstName);
//            lsItem<<new QStandardItem(lastName);
//            lsItem<<new QStandardItem(sexe);
//            lsItem<<new QStandardItem(DNaissance);
//            lsItem<<new QStandardItem(DCreation);
//            lsItem<<new QStandardItem(profession);
//            lsItem<<new QStandardItem(Numtel);
//            lsItem<<new QStandardItem(description);
//            lsItem<<new QStandardItem(addresse);
//
//
//            model->appendRow (lsItem);
//        }
//        view->setModel (model);
//    }
//    else
//        QMessageBox::critical (this, "Error", "Erreur d'execution"+ query.lastError ().text ());
//}

//void FentreSecretaire::onAdd(QSqlDatabase database){
//    QSqlQuery query = QSqlQuery(database);
//    query.prepare ("INSERT INTO Patient(DateCreation,nom,prenom,sexe,DateNaissance,addresse,NomJeunesse,Profession,tel,Description) "
//                   "VALUES (:Dcreation, :firstName, :lastName, :sexe, :DNaissance, :addresse, :youngName, :profession, :Numtel, : description"");");
//
//    query.bindValue (":nom",firstName->text ());
//    query.bindValue (":prenom",lastName->text ());
//    query.bindValue (":sexe",sexe->text ());
//    query.bindValue (":DateNaissance",DNaissance->text());
//    query.bindValue (":DateCréation",DCreation->text ());
//    query.bindValue (":addresse",addresse->text ());
//    query.bindValue (":tel",Numtel->text ());
//    query.bindValue (":description",description->toPlainText ());
//    query.bindValue (":NomJeunesse",youngName->text ());
//    query.bindValue (":Description",description->toPlainText());
//
//    if (!query.exec ()){
//        QMessageBox::critical (this,"query error",query.lastError ().text ());
//    }else
//        QMessageBox::information (this,"","Ajouter");
//}

void FentreSecretaire::CreateFormRv(){

    FLayout = new QFormLayout();
    patient = new QLineEdit();
    NFichePatient = new QSpinBox();
    Daterv = new QLineEdit();
    Heurerv = new QLineEdit();
    commentaire = new QTextEdit();
    add = new QPushButton(tr("Ajouter"));
    add->setStyleSheet ("background-color : blue");

    QHBoxLayout *hLFormRvBouton = new QHBoxLayout();
    hLFormRvBouton->addWidget (add);
    hLFormRvBouton->setAlignment (Qt::AlignHCenter);

    FLayout->addRow (tr("patient : "),patient);
    FLayout->addRow (tr("NFichePtient : "),NFichePatient);
    FLayout->addRow (tr("Date"),Daterv);
    FLayout->addRow (tr("Heure"),Heurerv);
    FLayout->addRow (tr("commentaire"),commentaire);
    FLayout->addRow (hLFormRvBouton);
}

void FentreSecretaire::CreateTableRv(){
    viewrv = new QTableView();
    modelrv = new QStandardItemModel;
    hlTablerv = new QHBoxLayout();
    vlayouteTablerv = new QVBoxLayout();
    vlayoutpage2 = new QVBoxLayout();
    // Boutton de mis a jour
    onUpdaterv = new QPushButton(tr("Mis à jour"));
    onUpdaterv->setStyleSheet ("background-color : blue");

    hlTablerv->addWidget (onUpdaterv);
    hlTablerv->setAlignment (Qt::AlignHCenter);

    viewrv->setModel (modelrv);


    QStringList headrv;
    headrv<<tr("patient")<<tr("idFiche")<<tr("date")<<tr("heure")<<tr("commentaire");

    modelrv->setHorizontalHeaderLabels (headrv);

    vlayouteTablerv->addWidget (viewrv);
    vlayouteTablerv->addLayout (hlTablerv);
}

void FentreSecretaire::showTabGP(){
    Onglets->setCurrentWidget (page1);
}

void FentreSecretaire::showTabGrv()
{
    Onglets->setCurrentWidget (page2);
}
