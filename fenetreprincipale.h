#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H


#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
//#include <QtWidgets>

// Classes pour bases de données

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QSqlError>

// Les Classes de mon appli

#include "fentresecretaire.h"
#include "fenetremedecin.h"

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();
  //  QPushButton *getBtnSecretaire() const;
  //  void setBtnSecretaire(QPushButton *newBtnSecretaire);

public slots :
    void OnExit();
    void showFenMedecin();
    void showFenSecretaire();
    void ShowFenConnextion();
    void showFenAccueille();
    void Deconnexion();
    void Decocher();
    void showTabGP();
    void showTabGrv();
    void showTabOrd();
    void showTabCer();
    void showTabInf();
public :
    void CreateMenu();
    void CreateAction();
    void CreateDatabase();
    void CreateBaroutils();
    void CreateFenetreConnexion();
    void CreateSousfentres();
    void CreateDocWidget();
    void FenetreAccueille();
private :

    // Fentre de connexion

    QWidget *FenConnextion;
    QLineEdit *login, *passWrd;
    QPushButton *connexion;
    QFormLayout *Fl;
    QVBoxLayout *Vl;
    QLabel *status;
    QCheckBox *showPass;
    QLabel *imlogin;
    QStackedWidget *Fenetrecentrale;

    // Pour la barre à outils

    QToolBar *BarOutils;

    // Action

    QAction *aQuitter;
    QAction *aAccueille;
    QAction *aParametre;
    QAction *aCalculette;
    QAction *aInternet;
    QAction *aBlocNote;
    QAction *alogin;

    // Pour le Menu

     QMenu *menuFichier;
     QMenu *menuParamettre;
     QMenu *menuAide;
     QMenu *menuEdition;
     QMenu *menuOutils;

     // Les autres Classes

     FentreSecretaire *FenSecretaire;
     FenetreMedecin *FenMedecin;

     // Pour la base de données

     QSqlDatabase database;
     QSqlQuery *querry;

     // Pour le Docwidget

     QDockWidget *docFen;
     QWidget *w;
     QVBoxLayout *vlmed;
     QVBoxLayout *VLG;
     QVBoxLayout *vlsec;
     QVBoxLayout *vlcon;
     QPushButton *btnMedecin;
     QPushButton *btnSecretaire;
     QPushButton *btnConnexion;
     QPushButton *btnOrd;
     QPushButton *btnInf;
     QPushButton *btnDem;
     QPushButton *btnCer;
     QPushButton *btnlettre;
     QPushButton *btnGp;
     QPushButton *btnGrv;
     QPushButton *btnGc;
     // Fentre d'accueille

     QGraphicsView *FenAccueille;
     QLabel *imgenAcc;
     QGraphicsPixmapItem *iteme;
     QGraphicsScene *scene;

};
#endif // FENETREPRINCIPALE_H
