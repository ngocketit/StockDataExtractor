/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Sat Nov 30 14:37:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *txtCodes;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QDateEdit *updateDate;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *btnExtract;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnExtractHNX;
    QPushButton *btnExtractHOSE;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnHNXList;
    QPushButton *btnHOSEList;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnCopyStats;
    QPushButton *btnCopyDetails;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *chkVertical;
    QRadioButton *chkHorizontal;
    QLabel *label_3;
    QLabel *lblOutput;
    QTabWidget *resultTab;
    QWidget *tab;
    QWidget *tab_2;
    QWebView *webView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbProgress;
    QProgressBar *progressBar;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1060, 656);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setSizeGripEnabled(true);
        verticalLayout_6 = new QVBoxLayout(Dialog);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        txtCodes = new QLineEdit(Dialog);
        txtCodes->setObjectName(QString::fromUtf8("txtCodes"));

        verticalLayout_2->addWidget(txtCodes);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        updateDate = new QDateEdit(Dialog);
        updateDate->setObjectName(QString::fromUtf8("updateDate"));
        updateDate->setMinimumSize(QSize(150, 0));
        updateDate->setCalendarPopup(true);

        verticalLayout->addWidget(updateDate);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        btnExtract = new QPushButton(Dialog);
        btnExtract->setObjectName(QString::fromUtf8("btnExtract"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnExtract->sizePolicy().hasHeightForWidth());
        btnExtract->setSizePolicy(sizePolicy);
        btnExtract->setMinimumSize(QSize(0, 0));
        btnExtract->setFont(font1);

        verticalLayout_3->addWidget(btnExtract);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::HLine);
        label_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnExtractHNX = new QPushButton(Dialog);
        btnExtractHNX->setObjectName(QString::fromUtf8("btnExtractHNX"));
        btnExtractHNX->setMinimumSize(QSize(111, 0));
        btnExtractHNX->setFont(font1);
        btnExtractHNX->setStyleSheet(QString::fromUtf8("background-color: #31869a;\n"
"color: white;"));

        horizontalLayout_3->addWidget(btnExtractHNX);

        btnExtractHOSE = new QPushButton(Dialog);
        btnExtractHOSE->setObjectName(QString::fromUtf8("btnExtractHOSE"));
        btnExtractHOSE->setMinimumSize(QSize(111, 0));
        btnExtractHOSE->setFont(font1);
        btnExtractHOSE->setStyleSheet(QString::fromUtf8("background-color: #00af50;\n"
"color: white;"));

        horizontalLayout_3->addWidget(btnExtractHOSE);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnHNXList = new QPushButton(Dialog);
        btnHNXList->setObjectName(QString::fromUtf8("btnHNXList"));
        btnHNXList->setMinimumSize(QSize(111, 0));
        btnHNXList->setFont(font1);
        btnHNXList->setStyleSheet(QString::fromUtf8(""));
        btnHNXList->setAutoDefault(true);
        btnHNXList->setFlat(false);

        horizontalLayout_4->addWidget(btnHNXList);

        btnHOSEList = new QPushButton(Dialog);
        btnHOSEList->setObjectName(QString::fromUtf8("btnHOSEList"));
        btnHOSEList->setMinimumSize(QSize(111, 0));
        btnHOSEList->setFont(font1);
        btnHOSEList->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(btnHOSEList);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(558, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnCopyStats = new QPushButton(Dialog);
        btnCopyStats->setObjectName(QString::fromUtf8("btnCopyStats"));
        btnCopyStats->setMinimumSize(QSize(111, 0));
        btnCopyStats->setFont(font1);
        btnCopyStats->setStyleSheet(QString::fromUtf8(""));
        btnCopyStats->setAutoDefault(true);
        btnCopyStats->setFlat(false);

        horizontalLayout_5->addWidget(btnCopyStats);

        btnCopyDetails = new QPushButton(Dialog);
        btnCopyDetails->setObjectName(QString::fromUtf8("btnCopyDetails"));
        btnCopyDetails->setMinimumSize(QSize(111, 0));
        btnCopyDetails->setFont(font1);
        btnCopyDetails->setStyleSheet(QString::fromUtf8(""));
        btnCopyDetails->setAutoDefault(true);
        btnCopyDetails->setFlat(false);

        horizontalLayout_5->addWidget(btnCopyDetails);


        verticalLayout_5->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(227, 0));
        groupBox->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(groupBox);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        chkVertical = new QRadioButton(groupBox);
        chkVertical->setObjectName(QString::fromUtf8("chkVertical"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        chkVertical->setFont(font2);
        chkVertical->setChecked(true);

        horizontalLayout_7->addWidget(chkVertical);

        chkHorizontal = new QRadioButton(groupBox);
        chkHorizontal->setObjectName(QString::fromUtf8("chkHorizontal"));
        chkHorizontal->setFont(font2);

        horizontalLayout_7->addWidget(chkHorizontal);


        verticalLayout_5->addWidget(groupBox);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_6);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::HLine);
        label_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(label_3);

        lblOutput = new QLabel(Dialog);
        lblOutput->setObjectName(QString::fromUtf8("lblOutput"));
        lblOutput->setFont(font1);

        verticalLayout_6->addWidget(lblOutput);

        resultTab = new QTabWidget(Dialog);
        resultTab->setObjectName(QString::fromUtf8("resultTab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        resultTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        resultTab->addTab(tab_2, QString());

        verticalLayout_6->addWidget(resultTab);

        webView = new QWebView(Dialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        verticalLayout_6->addWidget(webView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbProgress = new QLabel(Dialog);
        lbProgress->setObjectName(QString::fromUtf8("lbProgress"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        lbProgress->setFont(font3);

        horizontalLayout_2->addWidget(lbProgress);

        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);

        horizontalLayout_2->addWidget(progressBar);


        verticalLayout_6->addLayout(horizontalLayout_2);

        label->raise();
        label_2->raise();
        lblOutput->raise();
        webView->raise();
        label_4->raise();
        resultTab->raise();
        btnExtractHNX->raise();
        btnExtractHOSE->raise();
        btnHNXList->raise();
        btnHOSEList->raise();
        label_3->raise();
        btnCopyDetails->raise();
        btnCopyStats->raise();
        groupBox->raise();
        label_5->raise();

        retranslateUi(Dialog);

        resultTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Data Extractor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Stock data extractor", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Stock symbols (separated by commas)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Update date", 0, QApplication::UnicodeUTF8));
        updateDate->setDisplayFormat(QApplication::translate("Dialog", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        btnExtract->setText(QApplication::translate("Dialog", "GO!", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        btnExtractHNX->setText(QApplication::translate("Dialog", "Extract All HNX", 0, QApplication::UnicodeUTF8));
        btnExtractHOSE->setText(QApplication::translate("Dialog", "Extract All HOSE", 0, QApplication::UnicodeUTF8));
        btnHNXList->setText(QApplication::translate("Dialog", "HNX List", 0, QApplication::UnicodeUTF8));
        btnHOSEList->setText(QApplication::translate("Dialog", "HOSE List", 0, QApplication::UnicodeUTF8));
        btnCopyStats->setText(QApplication::translate("Dialog", "Copy All Stats", 0, QApplication::UnicodeUTF8));
        btnCopyDetails->setText(QApplication::translate("Dialog", "Copy All Details", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        chkVertical->setText(QApplication::translate("Dialog", "Vertical format", 0, QApplication::UnicodeUTF8));
        chkHorizontal->setText(QApplication::translate("Dialog", "Horizontal format", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        lblOutput->setText(QApplication::translate("Dialog", "Output Data", 0, QApplication::UnicodeUTF8));
        resultTab->setTabText(resultTab->indexOf(tab), QApplication::translate("Dialog", "Tab 1", 0, QApplication::UnicodeUTF8));
        resultTab->setTabText(resultTab->indexOf(tab_2), QApplication::translate("Dialog", "Tab 2", 0, QApplication::UnicodeUTF8));
        lbProgress->setText(QApplication::translate("Dialog", "Processing KLS...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
