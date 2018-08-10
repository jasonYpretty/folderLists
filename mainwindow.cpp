#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
//add
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
string getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y%m%d-%H%M%S",localtime(&timep) );
    return tmp;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());  //不让窗口大小变化
    setWindowOpacity(0.9);                        //透明度分十级

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    exit(1);
}

void MainWindow::on_pushButton_creatL_clicked()
{
   QMessageBox msg(QMessageBox::Warning,"提示","是否生成当前文件夹索引列表？");
   msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
   msg.setButtonText (QMessageBox::Ok,QString("确 定"));
   msg.setButtonText (QMessageBox::Cancel,QString("取 消"));
   if(msg.exec() == QMessageBox::Ok){
       writeLog();
   }
}

void MainWindow::writeLog()
{
    string   time = getTime();
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(".");
    mkdir("A =folderLOG");
    ofstream outfile((".\\A =folderLOG\\flistsLog="+time+".txt").c_str(), ios::app);
    while((ptr = readdir(dir)) != NULL)
    {
        #ifdef _WIN32
             //printf("d_name: %s\n", ptr->d_name);
        outfile << ptr->d_name<<endl;
        #endif
     }
    outfile.close();
    closedir(dir);

    qDebug() << (time+"writeLog").c_str();
}

void MainWindow::on_actionabout_triggered()
{
    QMessageBox::about(this, tr("About folderLists"),
             tr("<h1> folderLists 2018</h1>"

             "<p><h4>Release 0.1</h4>"
             "<p>Copyright ©2019 jasonYpretty.All rights reserved."
             "<p>by jasonYpretty"
             "<p>😋 https://github.com/jasonYpretty"
                ));

}

void MainWindow::on_action_help_triggered()
{
    QMessageBox::about(this, tr("Help"),
             tr("<h1> Help </h1>"
             "<p><h4>生成 文件Log</h4>"
             "<p>于程序目录下文件夹‘A =folderLOG’生成Log文件，格式为  AfileLog=YYYYMMDD-hhmmss"
             "<p><h4>读取Log 及 设置</h4>"
             "<p>读取功能用于比较“文件变更”情况，可设置是否导出至txt文件或是显示与置顶对话框中"

                ));
}

void MainWindow::on_pushButton_readL_clicked()
{
    readL.show();

}

void MainWindow::on_toolButton_clicked()
{
    mor.show();
}

void MainWindow::on_action_calendar_triggered()
{
    calE.show();
}
