#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

class MyWidget;

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


private:
    Ui::Welcome *ui;
    MyWidget *mw;
};

#endif // WELCOME_H
