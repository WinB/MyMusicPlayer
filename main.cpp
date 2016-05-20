#include "mymusicplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMusicPlayer w;
    w.show();

    return a.exec();
}
