#include "welcome.h"
#include "ui_welcome.h"
#include "mywidget.h"
#include <QDebug>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    mw = new MyWidget();
}

Welcome::~Welcome()
{
    delete ui;
    delete mw;
}

void Welcome::on_runBtn_clicked()
{
    //显示第一个界面
    MyWidget* mw = new MyWidget();
    mw->show();

    //mw->show();

    qDebug() << "代码跑到该处了";

    //隐藏欢迎界面
    this->hide();
}
