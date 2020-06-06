#include "gamecoin.h"

GameCoin::GameCoin(QString img, QWidget *parent) : QPushButton(parent), isfront(true), timer(new QTimer(this))
{
    QPixmap pix(img);

    //set button size
    setFixedSize(pix.width(), pix.height());
    //set border style
    setStyleSheet("QPushButton{border:0px;}");
    //set button icon
    setIcon(pix);
    //set icon size
    setIconSize(QSize(width(), height()));


    connect(timer, &QTimer::timeout, this, &GameCoin::BeingFlip);
}

void GameCoin::CoinInit(bool flag){

    isfront = flag;
    if (flag){
        QPixmap pix(":/pictures/res/Coin0001.png");
        setIcon(pix);
    }
    else{
        QPixmap pix(":/pictures/res/Coin0008.png");
        setIcon(pix);
    }

}

void GameCoin::BeingFlip(){
    //Turn negative
    if (isfront){
        QPixmap pix(QString(":/pictures/res/Coin000%1.png").arg(img_min++));
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize(width(), height()));

        if (img_max < img_min){
            img_min =1;
            isfront = false;
            timer -> stop();
        }
    }
    //Turn positive
    else{
        QPixmap pix(QString(":/pictures/res/Coin000%1.png").arg(img_max--));
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize(width(), height()));

        if (img_max < img_min){
            img_max =8;
            isfront = true;
            timer -> stop();
        }
    }
}

void GameCoin::CoinFlip(){
    timer -> start(30);
}
