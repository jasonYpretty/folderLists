#include "readlog.h"
#include "ui_readlog.h"
#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
//add
#include <QByteArray>
#include <QCryptographicHash>
#include <QFile>
#include <QDebug>
#include <string>
#include <QString>
using namespace std;


readlog::readlog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readlog)
{
    ui->setupUi(this);

    ui->groupBox_set->hide();
   // layout()->setSizeConstraint(QLayout::SetFixedSize);  //程序异常结束
}

readlog::~readlog()
{
    delete ui;
}

void readlog::on_pushButton_set_clicked()
{
    if(ui->groupBox_set->isVisible()){
        ui->groupBox_set->hide();
        ui->pushButton_set->setText("👇详细设置");
    } else{
        ui->groupBox_set->show();
        ui->pushButton_set->setText("(*￣▽￣*)");
    }
}

void readlog::on_pushButton_close_clicked()
{
    this->close();
}

void readlog::on_pushButton_clicked()
{
    QString folder_Path = QFileDialog::getExistingDirectory(this,"请选择文件夹路径...","./");
    ui->textBrowser_folder->setText(folder_Path);
}

void readlog::on_pushButton_reload_clicked()
{
    exit(1);
}


void readlog::on_textBrowser_folder_anchorClicked(const QUrl &arg1)
{

}
