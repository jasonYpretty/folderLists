#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen> //屏幕头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap pixmap(":/new/icon/src/loading.jpg"); // 1，传图片
    QSplashScreen splash(pixmap);//装载图
    splash.show();//显示图
    for(long index = 0; index < 600000000; index++);//显示延时

    w.show();

    splash.finish(&w);

    return a.exec();
}
