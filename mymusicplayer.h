#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QFileDialog>


namespace Ui {
class MyMusicPlayer;
}

class MyMusicPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit MyMusicPlayer(QWidget *parent = 0);
    ~MyMusicPlayer();

private slots:
    void on_btn_add_clicked();

    void on_btn_play_clicked();

    void on_btn_pause_clicked();

private:
    Ui::MyMusicPlayer *ui;
    QMediaPlayer *player;

};

#endif // MYMUSICPLAYER_H
