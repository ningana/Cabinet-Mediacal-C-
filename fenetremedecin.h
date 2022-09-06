#ifndef FENETREMEDECIN_H
#define FENETREMEDECIN_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class FenetreMedecin : public QWidget
{
public:
    FenetreMedecin();
    void CreateFormPatient();
    void CreateTablePatient();
public slots :
    void showTabord();
    void showTabCer();
    void showTabInf();
private :
    void ordonance();
    void certificat();
    void infomed();
private :

    // Les pages

    QWidget *page1;
    QWidget *page2;
    QWidget *page3;
    QWidget *page4;
    QWidget *page5;
    QWidget *page6;
    QWidget *page7;
    QWidget *page8;
    QWidget *page9;

    // Bouttons

    QPushButton *btnimprmOrd;
    QPushButton *btnimprmcert;


    // Layout

    QVBoxLayout *VLgeneral;


    // QTab

    QTabWidget *onglet;

    // SPliter et ces enfants

    QSplitter *spliterCert;
    QWidget *W1;
    QWidget *W2;


    // Ordonance médicale

    QGraphicsView *Gra;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QVBoxLayout *Vlpage1;

    // Certificat Medicaux

    QVBoxLayout *Vlpage2;
    QSplitter *split;
    QWidget *Wsplit1, *Wsplit2;
    QVBoxLayout *vLayout;
    QGraphicsView *Gra2;
    QGraphicsView *Gra3;
    QGraphicsPixmapItem *item2;
    QGraphicsPixmapItem *item3;
    QGraphicsScene *scene2;
    QGraphicsScene *scene3;
    QVBoxLayout *VlspliW1;
    QVBoxLayout *VlspliW2;

    // information medicale

    QVBoxLayout *VlInfo;
    QGraphicsView *Gra4;
    QGraphicsPixmapItem *item4;
    QGraphicsScene *scene4;


    //Formulaire

    QFormLayout *Flayout;
    QPushButton *onAdd;
    QPushButton *onUpdate;
    QHBoxLayout *hlformulaire;
    QSpinBox *Nfiche;
    QLineEdit *DCreation;
    QLineEdit *DNaissance;
    QSpinBox *CIN;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *sexe;
    QLineEdit *profession;
    QLineEdit *Numtel;
    QLineEdit *youngName;
    QLineEdit *addresse;
    QTextEdit *description;

    QSplitter *spliter;
    QTableView *view;
    QStandardItemModel *model;
    QVBoxLayout *Vlayoutpage8;
    QVBoxLayout *VlayoutGeneral;
    QVBoxLayout *vlayoutTable;
    QHBoxLayout *hlTable;
    QWidget *w1;
    QWidget *w2;

};

#endif // FENETREMEDECIN_H
