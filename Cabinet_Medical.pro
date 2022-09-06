QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fenetremedecin.cp \
    fentresecretaire.cp \
    main.cp \
    fenetreprincipale.cp

HEADERS += \
    fenetremedecin.h \
    fenetreprincipale.h \
    fentresecretaire.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc

DISTFILES += \
    Login.jpg \
    aLogin.png \
    aQuitter.jpeg \
    aaLogin.png \
    aaQuitter.jpeg \
    aalogin.png \
    aide.png \
    alogin.jpg \
    aquitter.png \
    arrierePlan.jpeg \
    blueLogin.jpg \
    calcul.jpeg \
    ff.jpg \
    images.jpeg \
    images.png \
    login.jpg \
    net.jpeg \
    note.jpeg \
    ord.jpg \
    parametre.jpeg \
    pileLivre.jpg \
    slide_1.jpg \
    slide_1.xcf \
    téléchargement.png
