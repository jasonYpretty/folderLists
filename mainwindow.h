#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readlog.h"
#include "more.h"
#include "calendar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showScrollText(QString text);


private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_creatL_clicked();

    void on_action_calendar_triggered();

    void on_actionabout_triggered();

    void writeLog();

    void on_action_help_triggered();

    void on_pushButton_readL_clicked();

    void on_toolButton_clicked();


private:
    Ui::MainWindow *ui;

    readlog readL;
    more mor;
    calendar calE;


};


#endif // MAINWINDOW_H
