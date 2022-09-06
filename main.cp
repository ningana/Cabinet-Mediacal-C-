#include "fenetreprincipale.h"

#include <QApplication>
//#include <QTranslator>
//#include <QLocale>
//#include <QLibraryInfo>

int main(int argc, char *argv[])
{

   // Q_INIT_RESOURCE (ressource);
    QApplication a(argc, argv);
   // QString locale = QLocale::system().name().section('_', 0, 0);
   // QTranslator translator;
   // translator.load(QString("qt_") + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
   // a.installTranslator(&translator)
    FenetrePrincipale w; w.showMaximized ();
    return a.exec();
}
