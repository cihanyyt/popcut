#include "popcut.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    popCut w;

    w.show();



    return a.exec();
}
