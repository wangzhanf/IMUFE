#include "volform.h"
#include "ui_volform.h"
#include <QDebug>

VolForm::VolForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VolForm)
{
    ui->setupUi(this);

    //信号和槽    第2种方式
    //connect(信号发送者，信号，信号接收者，槽函数)
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->label,SLOT(setNum(int)));

    //信号和槽    第3种方式，  Qt5开始的函数指针方式
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    //信号和槽    第4种方式，   存在函数重载时需要使用函数显式指针处理  setNum(int)   setNum(double)
    void (QLabel::*sni)(int) = &QLabel::setNum;
    void (QLabel::*snd)(double) = &QLabel::setNum;
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->label,sni);

    void(QSpinBox::*sbi)(int)= &QSpinBox::valueChanged;
    connect(ui->spinBox,sbi,ui->horizontalSlider,&QSlider::setValue);

    //信号和槽  第5种方式   lambda表达式方式，函数式编程【逻辑类似回调】
    //自定义槽函数的方式
    //connect(ui->horizontalSlider,&QSlider::valueChanged,this,&VolForm::callBack);
    connect(ui->horizontalSlider,&QSlider::valueChanged,this,[=](int currVal){
                //[]   设定允许访问的空间， = 代表外围函数的可视空间
                //()    形参列表
                //int val = ui->horizontalSlider->value();
                if(currVal == 0){
                    ui->label->setText("静音");
                }else if(currVal >=75){
                    ui->label->setText("音量过高");
                }else{
                    ui->label->setNum(currVal);
                }
            });


}

//自定义槽函数
void VolForm::callBack()
{
    int val = ui->horizontalSlider->value();
    if(val == 0){
        ui->label->setText("静音");
    }else if(val >=75){
        ui->label->setText("音量过高");
    }else{
        ui->label->setNum(val);
    }
}

//自定义槽函数
void VolForm::mySlot(QString title,int num)
{
    qDebug() << "title" << title ;
    qDebug() << "num" << num ;
    QString content = QString("你需要%1,%2").arg(num).arg(title);
    ui->label->setText(content);
}

VolForm::~VolForm()
{
    delete ui;
}

//信号和槽   第1种方式
void VolForm::on_horizontalSlider_valueChanged(int value)
{
    //ui->spinBox->setValue(value);
    //判断逻辑可以写在这里，  伪码表示
   // ui->spinbox.setvalue((Math.Round(value)));

}
