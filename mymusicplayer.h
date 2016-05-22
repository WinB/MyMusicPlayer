#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QMediaMetaData>



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

    void on_btn_prev_clicked();

    void on_btn_next_clicked();

    void on_volume_valueChanged(int value);

    void on_playTimeSlider_valueChanged(int value);

    void playProgressUpdate();
private:
    Ui::MyMusicPlayer *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    qint64 value;

};

#endif // MYMUSICPLAYER_H
