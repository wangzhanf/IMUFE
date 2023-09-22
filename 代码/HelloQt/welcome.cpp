#include "welcome.h"
#include "ui_welcome.h"
#include "mywidget.h"
#include <QDebug>
#include <QPushButton>
#include <QScreen>
#include "layoutform.h"
#include <QFileDialog>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    mw = new MyWidget();

    //通过代码添加组件
    QPushButton* myBtn = new QPushButton(tr("演示按钮"));//按钮会作为独立窗口展示，手工释放对象
    myBtn->setParent(this);//设置父对象， myBtn作为  welcome的子部件展示，自动随welcome销毁而销毁【对象树】
    myBtn->show();

    //定制当前界面以及按钮,
    QScreen* screen = QGuiApplication::primaryScreen();//静态成员static【类成员】调用
    qDebug() << screen->geometry().width();
    int w = 800;
    int h = 600;

    this->setGeometry((screen->geometry().width()-w)/2,
                      (screen->geometry().height()-h)/2,
                      w,h);
    this->setWindowTitle(tr("欢迎界面"));
    this->setFixedSize(w,h);
    myBtn->setGeometry(QRect(10,480,200,100));//匿名对象写法
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

void Welcome::on_layoutBtn_clicked()
{
    layoutForm* lf = new layoutForm();
    lf->show();
}

void Welcome::on_openBtn_clicked()
{
    //打开文件对话框   QFileDialog
    QString filename = QFileDialog::getOpenFileName(this,tr("打开图片"),"c:/",tr("图片格式 (*.png *.jpg *.bmp)"));
    qDebug() << filename;


}
