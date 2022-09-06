#include "fenetremedecin.h"

FenetreMedecin::FenetreMedecin(): QWidget ()
{
    VLgeneral = new QVBoxLayout(this); // Layout général contenant le Qtab

    // Construction de l'onglet

    onglet = new QTabWidget();
    onglet->setTabShape (QTabWidget::Triangular);
    onglet->setCursor (Qt::PointingHandCursor);

    // Construction des pages

    page1 = new QWidget();
    page2 = new QWidget();
    page3 = new QWidget();
    page4 = new QWidget();
    page5 = new QWidget();
    page6 = new QWidget();
    page7 = new QWidget();
    page8 = new QWidget();
    page9 = new QWidget();

    onglet->addTab (page1,tr("Ordonnace Médicale"));
    onglet->addTab (page2,tr("Certifica Médicaux"));
    onglet->addTab (page3,tr("information Médicale"));
    onglet->addTab (page4,tr("Lettre aux confrères"));
    onglet->addTab (page5,tr("Demande APCI"));
    onglet->addTab (page6,tr("Gestion de Médicament"));
    onglet->addTab (page7,tr("Gestion de CNAM"));
    onglet->addTab (page8,tr("Gestion de patient"));
    onglet->addTab (page9,tr("Carte Médecin"));

    VLgeneral->addWidget (onglet);
    ordonance ();
    certificat ();
    infomed ();
    CreateFormPatient ();
    CreateTablePatient ();

}

void FenetreMedecin::ordonance(){
    Gra = new QGraphicsView();
    item = new QGraphicsPixmapItem;
    item ->setPixmap(QPixmap("ord.jpg"));

    scene= new QGraphicsScene();
    Gra->setScene (scene);
    scene->addItem(item);

    QPushButton *b = new QPushButton("Imprimer");
    b->setStyleSheet ("background-color : blue");
    QHBoxLayout *lh = new QHBoxLayout();
    lh->setAlignment (Qt::AlignHCenter);
    lh->addWidget (b);

    Gra->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Gra->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    item->setTransformOriginPoint(50,50);

    Vlpage1 = new QVBoxLayout();
    Vlpage1->addWidget (Gra);
    page1->setLayout (Vlpage1);
}

void FenetreMedecin::certificat()
{
    split = new QSplitter();
    Wsplit1 = new QWidget();
    Wsplit2 = new QWidget();

    split->addWidget (Wsplit1);
    split->addWidget (Wsplit2);

    vLayout = new QVBoxLayout();
    vLayout->addWidget (split);

    Gra2 = new QGraphicsView();
    item2= new QGraphicsPixmapItem;
    item2->setPixmap(QPixmap("cer1.jpg"));

    scene2= new QGraphicsScene();
    Gra2->setScene (scene2);
    scene2->addItem(item2);

    Gra2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Gra2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    item2->setTransformOriginPoint(50,50);

    QPushButton *btn = new QPushButton("Imprimer");
    btn->setStyleSheet ("background-color : blue");
    QHBoxLayout *lH = new QHBoxLayout();
    lH->setAlignment (Qt::AlignHCenter);
    lH->addWidget (btn);


    VlspliW1 = new QVBoxLayout();
    VlspliW1->addWidget (Gra2);
    VlspliW1->addLayout (lH);
    Wsplit1->setLayout (VlspliW1);


    Gra3 = new QGraphicsView();
    item3= new QGraphicsPixmapItem;
    item3->setPixmap(QPixmap("cer2.png"));

    scene3 = new QGraphicsScene();
    Gra3->setScene (scene3);
    scene3->addItem(item3);

    Gra3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Gra3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    item3->setTransformOriginPoint(50,50);

    QPushButton *bt2 = new QPushButton("Imprimer");
    bt2->setStyleSheet ("background-color : blue");
    QHBoxLayout *lh = new QHBoxLayout();
    lh->setAlignment (Qt::AlignHCenter);
    lh->addWidget (bt2);

    VlspliW2 = new QVBoxLayout();
    VlspliW2->addWidget (Gra3);
    VlspliW2->addLayout (lh);
    Wsplit2->setLayout (VlspliW2);

    Vlpage2 = new QVBoxLayout();

    Vlpage2->addWidget (split);

    page2->setLayout (Vlpage2);


}

void FenetreMedecin::infomed()
{
    Gra4 = new QGraphicsView();
    item4= new QGraphicsPixmapItem;
    item4->setPixmap(QPixmap("infomed.jpg"));

    scene4 = new QGraphicsScene();
    Gra4->setScene (scene4);
    scene4->addItem(item4);

    Gra4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Gra4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    item4->setTransformOriginPoint(50,50);
    VlInfo = new QVBoxLayout();
    VlInfo->addWidget (Gra4);
    page3->setLayout (VlInfo);
}


void FenetreMedecin::showTabord(){
    onglet->setCurrentWidget (page1);
}

void FenetreMedecin::showTabCer(){
    onglet->setCurrentWidget (page2);
}

void FenetreMedecin::showTabInf(){
    onglet->setCurrentWidget (page3);
}


void FenetreMedecin::CreateFormPatient(){

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


    spliter = new QSplitter();
    w1 = new QWidget();
    w2 = new QWidget();

    spliter->addWidget (w1);
    spliter->addWidget (w2);

    w1->setLayout (Flayout);
    w1->setFixedWidth (350);
}

void FenetreMedecin::CreateTablePatient(){

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
    vlayoutTable = new QVBoxLayout();
    vlayoutTable->addWidget (view);
    vlayoutTable->addLayout (hlTable);
    w2->setLayout (vlayoutTable);

    Vlayoutpage8 = new QVBoxLayout();
    Vlayoutpage8->addWidget (spliter);
    page8->setLayout (Vlayoutpage8);
}
