#include "mainwindow.h"
#include<QLabel>
#include<QLineEdit>
#include<QApplication>
#include<QScreen>
#include<QGridLayout>
#include<QToolButton>
#include<stdio.h>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *sifre=new QWidget(this);

    QSize screenSize = qApp->screens()[0]->size();
    boy=screenSize.height()/153.6;
    en=boy*1.1;
    int e=en;
    int b=boy;
    this->setFixedSize(boy*50,en*37);
    int x = (screenSize.width() - this->width())/2;
    int y = (screenSize.height() - this->height()) / 2;
    this->move(x, y);
   // this->setStyleSheet("background-color: #dfdfdf;");
    auto appIcon = QIcon(":/icons/password.svg");
    this->setWindowIcon(appIcon);
    sifre->setFixedSize(boy*50,en*37);
    //sifre->setStyleSheet("background-color: #df00ff;");
    /********************************************************/
    QString username;
    ///username = qgetenv("USER"); // get the user name in Linux
    username = qgetenv("HOME"); // get the home directory in Linux
    username=username.split("/")[2];
    if(username.isEmpty()) {
        username = qgetenv("USERNAME"); // get the name in Windows
    }
    /********************************************************/
    int font=boy*3;
    QLabel *userLabel=new QLabel(sifre);
    userLabel->setText("Kullanıcı Adı:  "+username);
    userLabel->setStyleSheet("color: #0000ac;font-size:"+QString::number(font)+"px");
    userLabel->setFixedSize(boy*40,en*5);

    QLabel *statusLabel=new QLabel(sifre);
   // statusLabel->setText("Kullanıcı Adı");
    statusLabel->setStyleSheet("color:#ac0000;");
    statusLabel->setFixedSize(boy*40,en*5);

    QLabel *passwordLabel=new QLabel(sifre);
    passwordLabel->setText("Yeni Şifre");
    //passwordLabel->setStyleSheet("background-color: #acacac");
    passwordLabel->setFixedSize(boy*20,en*5);

    QLabel *newPasswordLabel=new QLabel(sifre);
    newPasswordLabel->setText("Yeni Şifre Onay");
   // newPasswordLabel->setStyleSheet("background-color: #acacac");
    newPasswordLabel->setFixedSize(boy*20,en*5);

    QLineEdit *passwordLineEdit=new QLineEdit(sifre);
    passwordLineEdit->setFixedSize(boy*20,en*5);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    QLineEdit *newPasswordLineEdit=new QLineEdit(sifre);
    newPasswordLineEdit->setFixedSize(boy*20,en*5);
    newPasswordLineEdit->setEchoMode(QLineEdit::Password);


    QToolButton *passwordChangeButton= new QToolButton(sifre);
    passwordChangeButton->setFixedSize(QSize(boy*40,boy*10));
    passwordChangeButton->setIconSize(QSize(boy*40,boy*5));
    passwordChangeButton->setStyleSheet("Text-align:center");
    passwordChangeButton->setIcon(QIcon(":/icons/password.svg"));
    passwordChangeButton->setAutoRaise(true);
    passwordChangeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // powerOnButton->setFont(f2);
    passwordChangeButton->setText("Şifre Değiştir");

    connect(passwordChangeButton, &QToolButton::clicked, [=]() {
        if (passwordLineEdit->text().length()==0||newPasswordLineEdit->text().length()==0)
        {
            statusLabel->setStyleSheet("color:#ac0000;");

            statusLabel->setText("Yeni şife veya onay şifresi girilmemiş!");
            return;
        }

        if (passwordLineEdit->text()!=newPasswordLineEdit->text())
        {            statusLabel->setStyleSheet("color:#ac0000;");

            statusLabel->setText("Yeni şife veya onay şifresi farklı!");
            return;
        }

        if (passwordLineEdit->text()==newPasswordLineEdit->text())
        {
            statusLabel->setStyleSheet("color:#00ac00;");

            statusLabel->setText("Şifre Başarıyla Değiştirildi..");

            //setuid(0);
            //qapp->setSetuidAllowed(true);
            ///usr/share/passwordyetki user newpassword
            QString kmt="/usr/share/sifredegistir/passwordyetki "+username+" "+passwordLineEdit->text();
           // qDebug()<<kmt;
            system(kmt.toStdString().c_str());
            QString kmt1="touch /home/"+username+"/.config/np";
           // qDebug()<<kmt1;
            system(kmt1.toStdString().c_str());

        }
    });


    auto layout = new QGridLayout(sifre);
    layout->setContentsMargins(0,boy, 0,boy);
   // layout->setVerticalSpacing(5);
    // layout->setHorizontalSpacing(5);
    //layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(userLabel,1,1,1,2,Qt::AlignCenter);
    layout->addWidget(statusLabel, 2,1,1,2,Qt::AlignCenter);

    layout->addWidget(passwordLabel, 3,1,1,1);
    layout->addWidget(passwordLineEdit, 3,2,1,1);

    layout->addWidget(newPasswordLabel, 4,1,1,1);
    layout->addWidget(newPasswordLineEdit, 4,2,1,1);

    layout->addWidget(passwordChangeButton, 5,1,1,2,Qt::AlignCenter);

setLayout(layout);

}

MainWindow::~MainWindow()
{

}
