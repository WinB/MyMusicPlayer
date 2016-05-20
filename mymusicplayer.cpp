#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"

MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyMusicPlayer)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
}

void MyMusicPlayer::on_btn_add_clicked()
{
    QStringList names = QFileDialog::getOpenFileNames(this,"open files","C:/Users/WinB/Desktop","mp3(*.mp3)");
       if(!names.isEmpty())
           ui->listWidget->addItems(names);
}
void MyMusicPlayer::on_btn_play_clicked()
{
    QString name = ui->listWidget->currentItem()->text();
    player->setMedia(QUrl::fromLocalFile(name));
    player->play();
}

void MyMusicPlayer::on_btn_pause_clicked()
{
    player->pause();
}
