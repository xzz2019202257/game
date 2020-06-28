#include "music.h"
#include <QMediaPlayer>

music::music()
{
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/image/game.mp3"));
    startSound->setVolume(50);
    QMediaPlayer *gameSound = new QMediaPlayer;//创建播放器
    gameSound->play();//音乐播放
    //gameSound->stop();//音乐暂停
}
