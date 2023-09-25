#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFontDialog>
#include <QMessageBox>
#include "volform.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //修饰按钮
    ui->fontBtn->setText(tr("点击更换字体"));
    ui->fontBtn->setGeometry(200,200,180,80);
    //点击按钮

    //显示音量控制条
    VolForm* vf = new VolForm(this);


}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_fontBtn_clicked()
{
    //QFontDialog   已封装好的组件， 调用
    bool flag = false;
    QFont myfont = QFontDialog::getFont(&flag,QFont("宋体"),this,tr("请选择按钮字体"));
    //利用返回值做业务处理
    if(flag){
        ui->fontBtn->setFont(myfont);
    }else{
        QMessageBox::information(this,tr("用户提示"),tr("您未选择任何字体"));
    }
}
