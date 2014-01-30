/********************************************************************************
** Form generated from reading UI file 'symbollistdialog.ui'
**
** Created: Sat Nov 30 14:37:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLLISTDIALOG_H
#define UI_SYMBOLLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SymbolListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QLabel *label;
    QPlainTextEdit *txtSymbols;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SymbolListDialog)
    {
        if (SymbolListDialog->objectName().isEmpty())
            SymbolListDialog->setObjectName(QString::fromUtf8("SymbolListDialog"));
        SymbolListDialog->resize(656, 390);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SymbolListDialog->setWindowIcon(icon);
        SymbolListDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(SymbolListDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTitle = new QLabel(SymbolListDialog);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitle);

        label = new QLabel(SymbolListDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        txtSymbols = new QPlainTextEdit(SymbolListDialog);
        txtSymbols->setObjectName(QString::fromUtf8("txtSymbols"));

        verticalLayout->addWidget(txtSymbols);

        buttonBox = new QDialogButtonBox(SymbolListDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SymbolListDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SymbolListDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SymbolListDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SymbolListDialog);
    } // setupUi

    void retranslateUi(QDialog *SymbolListDialog)
    {
        SymbolListDialog->setWindowTitle(QApplication::translate("SymbolListDialog", "Stock Symbols", 0, QApplication::UnicodeUTF8));
        lblTitle->setText(QApplication::translate("SymbolListDialog", "HXN Symbols", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SymbolListDialog", "Enter sysmbols separated by commas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SymbolListDialog: public Ui_SymbolListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLLISTDIALOG_H
