#ifndef READLOG_H
#define READLOG_H

#include <QWidget>

namespace Ui {
class readlog;
}

class readlog : public QWidget
{
    Q_OBJECT

public:
    explicit readlog(QWidget *parent = 0);
    ~readlog();

private slots:
    void on_pushButton_set_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_reload_clicked();

    void on_pushButton_clicked();

    void on_textBrowser_folder_anchorClicked(const QUrl &arg1);

private:
    Ui::readlog *ui;
};

#endif // READLOG_H
