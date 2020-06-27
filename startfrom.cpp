#include "startfrom.h"
#include "ui_startfrom.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMediaPlayer>
#include<music.h>
#include<QMediaPlaylist>
StartFrom::StartFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartFrom)
{
    this->setFixedSize(1040,640);
    ui->setupUi(this);

    setWindowTitle("Begin");

    QMediaPlaylist *list= new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/image/game.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setPlaylist(list);
    startSound->play();




    //关卡按钮点击 第一关
    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        //点击按钮进入关卡
        MainWindow *mainwindow = new MainWindow(0);

        mainwindow->show(); //关卡显示
    });

    //第二关
    connect(ui->pushButton_2, &QPushButton::clicked, [=]()
    {
        MainWindow *mainwindow = new MainWindow(1);
        mainwindow->show(); //关卡显示
    });

    //第三关
    connect(ui->pushButton_3, &QPushButton::clicked, [=]()
    {
        MainWindow *mainwindow = new MainWindow(2);
        mainwindow->show(); //关卡显示
    });

}

void StartFrom::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/image/back.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}

StartFrom::~StartFrom()
{
    delete ui;
}
