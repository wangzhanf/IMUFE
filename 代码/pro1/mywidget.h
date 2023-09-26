#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_fontBtn_clicked();

private:
    Ui::MyWidget *ui;

signals:
    void mySig(QString title,int num);//声明了一个信号，带有2个参数
};

#endif // MYWIDGET_H
