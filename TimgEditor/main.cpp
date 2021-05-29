#include "timgeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimgEditor w;
    w.show();
    return a.exec();
}
