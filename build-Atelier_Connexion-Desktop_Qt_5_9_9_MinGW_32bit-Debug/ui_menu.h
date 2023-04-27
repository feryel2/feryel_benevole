/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *gestionVol;
    QPushButton *gestionBillet;
    QPushButton *logout;
    QPushButton *gestionBenevole;
    QPushButton *gestionPasager;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(631, 493);
        gestionVol = new QPushButton(Menu);
        gestionVol->setObjectName(QStringLiteral("gestionVol"));
        gestionVol->setGeometry(QRect(210, 233, 319, 28));
        gestionBillet = new QPushButton(Menu);
        gestionBillet->setObjectName(QStringLiteral("gestionBillet"));
        gestionBillet->setGeometry(QRect(210, 286, 319, 28));
        logout = new QPushButton(Menu);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(100, 60, 101, 23));
        gestionBenevole = new QPushButton(Menu);
        gestionBenevole->setObjectName(QStringLiteral("gestionBenevole"));
        gestionBenevole->setGeometry(QRect(210, 127, 319, 28));
        gestionPasager = new QPushButton(Menu);
        gestionPasager->setObjectName(QStringLiteral("gestionPasager"));
        gestionPasager->setGeometry(QRect(210, 180, 319, 28));

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", Q_NULLPTR));
        gestionVol->setText(QApplication::translate("Menu", "GESTION Donateurs", Q_NULLPTR));
        gestionBillet->setText(QApplication::translate("Menu", "GESTION Don", Q_NULLPTR));
        logout->setText(QApplication::translate("Menu", "LOGOUT", Q_NULLPTR));
        gestionBenevole->setText(QApplication::translate("Menu", "GESTION BENEVOLE", Q_NULLPTR));
        gestionPasager->setText(QApplication::translate("Menu", "GESTION Mamans", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
