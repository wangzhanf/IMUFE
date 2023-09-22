#include "mywidget.h"
#include "ui_mywidget.h"  //由  xxx.ui文件通过  moc  编译的结果， 在编译后目录中存在
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScreen>
#include <QDebug>



//构造函数的定义，    通过  初始化列表方式    父对象和成员进行初始化操作
MyWidget::MyWidget(QWidget *parent):QWidget(parent),ui(new Ui::MyWidget)
{
    ui->setupUi(this);//设置ui绑定

    //仿造一个QQ登录页面
    QScreen* screen = QGuiApplication::primaryScreen();
//    qDebug() << screen->geometry().width();
    int w = 400;
    int h = 300;

    this->setGeometry((screen->geometry().width()-w)/2,
                      (screen->geometry().height()-h)/2,
                      w,h);
    this->setWindowTitle(tr("登录QQ"));
    this->setFixedSize(w,h);
    //创建文字提示
    QLabel* accoutLab = new QLabel(tr("QQ号："),this);
    QLabel* passwordLab = new QLabel(tr("密码："),this);
    //创建输入框
    QLineEdit* accoutInput = new QLineEdit(this);
    QLineEdit* passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText(tr("请输入密码"));
    passwordInput->setEchoMode(QLineEdit::Password);
    //创建登录按钮
    QPushButton* loginBtn = new QPushButton(tr("登录"),this);
    //排版布局
    accoutLab->setGeometry(50,50,50,50);
    passwordLab->setGeometry(50,120,50,50);
    accoutInput->setGeometry(120,50,230,50);
    passwordInput->setGeometry(120,120,230,50);
    loginBtn->setGeometry(50,200,300,50);
}

MyWidget::~MyWidget()
{
    delete ui;//释放ui
}
