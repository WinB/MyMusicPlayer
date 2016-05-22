#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"

MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyMusicPlayer)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    player->setPlaylist(this->playlist);

    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_btn_play_clicked()));
    connect(ui->playTimeSlider, SIGNAL(sliderMoved(int)), this, SLOT(on_playTimeSlider_valueChanged(int)));

}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
    delete this->player;
    delete this->playlist;
}


void MyMusicPlayer::on_btn_add_clicked()
{

    QStringList names = QFileDialog::getOpenFileNames(this,"open files","C:/Users/WinB/Desktop","mp3(*.mp3)");
       if(!names.isEmpty())
       {
           ui->listWidget->addItems(names);
           qDebug("aa");
           this->playlist->clear();
           foreach (const QString &fileName, names) {
                       QMediaContent media = QMediaContent(QUrl::fromLocalFile(fileName));
                       this->playlist->addMedia(media);
                   }
             this->playlist->setCurrentIndex(0);
       }
       qDebug()<<names;
}
void MyMusicPlayer::on_btn_play_clicked()
{
    if(!(this->player->state()==QMediaPlayer::PausedState))
    {

        QString name = ui->listWidget->currentItem()->text();
        player->setMedia(QUrl::fromLocalFile(name));
    }
    player->play();


}

void MyMusicPlayer::on_btn_pause_clicked()
{
    this->player->pause();
}

void MyMusicPlayer::on_btn_prev_clicked()
{
    QMediaPlaylist *currentPlayList=playlist;
    currentPlayList->previous();

}

void MyMusicPlayer::on_btn_next_clicked()
{
    this->player->playlist()->next();
}



void MyMusicPlayer::on_playTimeSlider_valueChanged(int value)
{
    float percent = (value * 1.0) / this->ui->playTimeSlider->maximum();
    int64_t pos = this->player->duration() * percent;
    this->player->setPosition(pos);
}

void MyMusicPlayer::playProgressUpdate()
{
    int64_t pos = this->player->position();
    int64_t duration = this->player->duration();
    int value = 100 * (1.0*pos)/duration;
    this->ui->playTimeSlider->setValue(value);
}

void MyMusicPlayer::on_volume_valueChanged(int value)
{
    this->player->setVolume(value);
}
