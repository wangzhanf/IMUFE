#ifndef VOLFORM_H
#define VOLFORM_H

#include <QWidget>

namespace Ui {
class VolForm;
}

class VolForm : public QWidget
{
    Q_OBJECT

public:
    explicit VolForm(QWidget *parent = nullptr);
    ~VolForm();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::VolForm *ui;
};

#endif // VOLFORM_H
