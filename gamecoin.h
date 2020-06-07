#ifndef GAMECOIN_H
#define GAMECOIN_H

#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QDebug>

class GameCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit GameCoin(QString img, QWidget *parent = nullptr);

    void CoinInit(bool flag);

    bool isfront = true;
    bool isforbidden = false;
signals:

public slots:
    void BeingFlip();
    void CoinFlip();

private:
    int img_min = 1;
    int img_max = 8;

    QTimer* timer;
};

#endif // GAMECOIN_H
