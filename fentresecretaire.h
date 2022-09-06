#ifndef FENTRESECRETAIRE_H
#define FENTRESECRETAIRE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class FentreSecretaire : public QWidget
{
public:
    FentreSecretaire();

public slots :
    void showTabGP();
    void showTabGrv();
private :
    void CreateFormPatient();
    void CreateTablePatient();
    void CreateFormRv();
    void CreateTableRv();
private :

    // Pour tout l'interface

    QTabWidget *Onglets;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;

    QWidget *W1;
    QWidget *W2;

    // Pour la table de données

    QSplitter *spliter;
    QTableView *view;
    QStandardItemModel *model;
    QVBoxLayout *Vlayoutpage1;
    QVBoxLayout *VlayoutGeneral;
    QVBoxLayout *vlayoutTable;
    QHBoxLayout *hlTable;

    // Pour le formulaire de Gestion des patients

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

    // Pour le formulaire  de Gestion de Rendez vous

    QLineEdit *patient;
    QSpinBox *NFichePatient;
    QLineEdit *Daterv;
    QLineEdit *Heurerv;
    QTextEdit *commentaire;
    QPushButton *add;
    QFormLayout *FLayout;

    QTableView *viewrv;
    QStandardItemModel *modelrv;
    QHBoxLayout *hlTablerv;
    QVBoxLayout *vlayouteTablerv;
    QPushButton *onUpdaterv;

    QSplitter *spliterrv;
    QWidget *W1rv;
    QWidget *W2rv;

    QVBoxLayout *vlayoutpage2;

    // Base de données

    QSqlDatabase database;
    QSqlQuery *query;

};

#endif // FENTRESECRETAIRE_H
