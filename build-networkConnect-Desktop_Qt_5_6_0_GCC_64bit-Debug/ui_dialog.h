/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *wired_tab;
    QFrame *manualFrame;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *IPAddress;
    QLineEdit *netMask;
    QLineEdit *gateway;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *dnsPrimary;
    QLineEdit *dnsSecondary;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectPushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *configurationCombo;
    QFrame *automaticFrame;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *DHCPHostname;
    QLineEdit *nameServerAuto;
    QWidget *wireless_tab;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *connectWireless;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(466, 468);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        wired_tab = new QWidget();
        wired_tab->setObjectName(QStringLiteral("wired_tab"));
        manualFrame = new QFrame(wired_tab);
        manualFrame->setObjectName(QStringLiteral("manualFrame"));
        manualFrame->setGeometry(QRect(10, 50, 421, 291));
        manualFrame->setFrameShape(QFrame::StyledPanel);
        manualFrame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(manualFrame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(manualFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        IPAddress = new QLineEdit(groupBox);
        IPAddress->setObjectName(QStringLiteral("IPAddress"));

        verticalLayout->addWidget(IPAddress);

        netMask = new QLineEdit(groupBox);
        netMask->setObjectName(QStringLiteral("netMask"));

        verticalLayout->addWidget(netMask);

        gateway = new QLineEdit(groupBox);
        gateway->setObjectName(QStringLiteral("gateway"));

        verticalLayout->addWidget(gateway);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(manualFrame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dnsPrimary = new QLineEdit(groupBox_2);
        dnsPrimary->setObjectName(QStringLiteral("dnsPrimary"));

        verticalLayout_3->addWidget(dnsPrimary);

        dnsSecondary = new QLineEdit(groupBox_2);
        dnsSecondary->setObjectName(QStringLiteral("dnsSecondary"));

        verticalLayout_3->addWidget(dnsSecondary);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        layoutWidget = new QWidget(wired_tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 360, 421, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        connectPushButton = new QPushButton(layoutWidget);
        connectPushButton->setObjectName(QStringLiteral("connectPushButton"));

        horizontalLayout_4->addWidget(connectPushButton);

        layoutWidget1 = new QWidget(wired_tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 421, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        configurationCombo = new QComboBox(layoutWidget1);
        configurationCombo->setObjectName(QStringLiteral("configurationCombo"));
        configurationCombo->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(configurationCombo);

        automaticFrame = new QFrame(wired_tab);
        automaticFrame->setObjectName(QStringLiteral("automaticFrame"));
        automaticFrame->setGeometry(QRect(10, 356, 421, 241));
        automaticFrame->setFrameShape(QFrame::StyledPanel);
        automaticFrame->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(automaticFrame);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 401, 64));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_6->addWidget(label_7);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        DHCPHostname = new QLineEdit(layoutWidget2);
        DHCPHostname->setObjectName(QStringLiteral("DHCPHostname"));

        verticalLayout_5->addWidget(DHCPHostname);

        nameServerAuto = new QLineEdit(layoutWidget2);
        nameServerAuto->setObjectName(QStringLiteral("nameServerAuto"));

        verticalLayout_5->addWidget(nameServerAuto);


        horizontalLayout_5->addLayout(verticalLayout_5);

        tabWidget->addTab(wired_tab, QString());
        wireless_tab = new QWidget();
        wireless_tab->setObjectName(QStringLiteral("wireless_tab"));
        treeWidget = new QTreeWidget(wireless_tab);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 10, 421, 351));
        layoutWidget3 = new QWidget(wireless_tab);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 370, 421, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        connectWireless = new QPushButton(layoutWidget3);
        connectWireless->setObjectName(QStringLiteral("connectWireless"));

        horizontalLayout_6->addWidget(connectWireless);

        tabWidget->addTab(wireless_tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Address", 0));
        label_2->setText(QApplication::translate("Dialog", "IP Address", 0));
        label_3->setText(QApplication::translate("Dialog", "Net Mask", 0));
        label_4->setText(QApplication::translate("Dialog", "Gateway", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Name Servers", 0));
        label_5->setText(QApplication::translate("Dialog", "DNS Primary", 0));
        label_6->setText(QApplication::translate("Dialog", "DNS Secondary", 0));
        connectPushButton->setText(QApplication::translate("Dialog", "Connect", 0));
        label->setText(QApplication::translate("Dialog", "Configuration", 0));
        configurationCombo->clear();
        configurationCombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Manual", 0)
         << QApplication::translate("Dialog", "Automatic", 0)
        );
        label_7->setText(QApplication::translate("Dialog", "DHCP Hostname", 0));
        label_8->setText(QApplication::translate("Dialog", "Name Servers", 0));
        tabWidget->setTabText(tabWidget->indexOf(wired_tab), QApplication::translate("Dialog", "Wired", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Dialog", "Available Network", 0));
        connectWireless->setText(QApplication::translate("Dialog", "Connect", 0));
        tabWidget->setTabText(tabWidget->indexOf(wireless_tab), QApplication::translate("Dialog", "Wireless", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
