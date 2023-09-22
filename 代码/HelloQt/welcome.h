#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

//前向声明
class MyWidget;
class QPushButton;

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_runBtn_clicked();


    void on_layoutBtn_clicked();

    void on_openBtn_clicked();

private:
    Ui::Welcome *ui;
    MyWidget *mw;
    QPushButton *closeBtn;
};

#endif // WELCOME_H
