#include "mywidget.h"
#include "ui_mywidget.h"  //由  xxx.ui文件通过  moc  编译的结果， 在编译后目录中存在

//构造函数的定义，    通过  初始化列表方式    父对象和成员进行初始化操作
MyWidget::MyWidget(QWidget *parent):QWidget(parent),ui(new Ui::MyWidget)
{
    ui->setupUi(this);//设置ui绑定
}

MyWidget::~MyWidget()
{
    delete ui;//释放ui
}
