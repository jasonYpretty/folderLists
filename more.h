#ifndef MORE_H
#define MORE_H

#include <QDialog>

namespace Ui {
class more;
}

class more : public QDialog
{
    Q_OBJECT

public:
    explicit more(QWidget *parent = 0);
    ~more();

private slots:
    void on_pushButton_reload_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::more *ui;    
};

#endif // MORE_H
