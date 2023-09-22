//#include "mywidget.h"
#include "welcome.h"
#include <QApplication>
//程序入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//qt框架
//    MyWidget w;//创建界面对象
//    w.show();//调用  继承自  QWidget 的show展示界面。
    //创建一个  Welcome的对象
    Welcome welcome;
    //调用继承自 QWidget的show()显示
    welcome.show();

    return a.exec();  // 阻塞，开启循环监听 ， 监听事件
}
