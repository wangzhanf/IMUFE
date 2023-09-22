#ifndef MYWIDGET_H
#define MYWIDGET_H
//头文件守卫， 防止头文件被多次包含

#include <QWidget>

//命名空间， 实现不同包管理机制
namespace Ui {
    class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT
    //Qt的核心宏，  Qt特性都由  Q_OBJECT提供，  属性系统，信号和槽 ， 必须在第1行
public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;//ui界面对象，在构造函数初始化，在析构函数释放
};

#endif // MYWIDGET_H
