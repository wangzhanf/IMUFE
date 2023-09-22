#ifndef LAYOUTFORM_H
#define LAYOUTFORM_H

#include <QWidget>

namespace Ui {
class layoutForm;
}

class layoutForm : public QWidget
{
    Q_OBJECT

public:
    explicit layoutForm(QWidget *parent = nullptr);
    ~layoutForm();

private:
    Ui::layoutForm *ui;
};

#endif // LAYOUTFORM_H
