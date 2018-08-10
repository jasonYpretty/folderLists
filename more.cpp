#include "more.h"
#include "ui_more.h"
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QFile>
#include <QDebug>
#include <string>
#include "QMessageBox"
#include "QFileDialog"
using namespace std;
//md5
QByteArray getFileMd5(QString filePath)
{
    QFile localFile(filePath);

    if (!localFile.open(QFile::ReadOnly))
    {
        qDebug() << "file open error.";
        return 0;
    }

    QCryptographicHash ch(QCryptographicHash::Md5);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = localFile.size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = localFile.read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
    }

    localFile.close();
    QByteArray md5 = ch.result();
    return md5;
}
//end of md5 ↑

more::more(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::more)
{
    ui->setupUi(this);
}

more::~more()
{
    delete ui;
}

void more::on_pushButton_reload_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
        //定义文件对话框标题
        fileDialog->setWindowTitle(tr("打开图片"));
        //设置文件过滤器
        //fileDialog->setNameFilter(tr("Log文件(*.log *.txt)"));
        //设置可以选择多个文件
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        //设置视图模式
        fileDialog->setViewMode(QFileDialog::Detail);
        //打印所有选择的文件的路径
        QStringList fileNames;
        if(fileDialog->exec())
        {
            fileNames = fileDialog->selectedFiles();
        }
        //以上是打开文件程序段
        for(auto tmp:fileNames){
            qDebug()<<tmp<<endl;
            QFile theFile(tmp);
            theFile.open(QIODevice::ReadOnly);
            QByteArray ba = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Md5);
            theFile.close();
            string a = ba.toHex().constData();
            qDebug() << ba.toHex().constData();
            ui->textBrowser_md5->setText((a).c_str());
        }

}

void more::on_pushButton_close_clicked()
{
     this->close();
}
