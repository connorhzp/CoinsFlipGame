#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "scene.h"
#include "widgetbutton.h"
#include "gamecoin.h"
#include "gameconfig.h"

class PlayScene : public Scene
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);

    void LevelSet(int level);

    virtual void paintEvent(QPaintEvent *ev);
private:

    virtual void AttributeSet() override;
    virtual void MenuBarBuild() override;
    virtual void WidgetsBuild() override;
    virtual void SoundsSet() override;
signals:
    void BacktoSelectScene();
public slots:

private:
    QLabel *level_str = nullptr;
    WidgetButton *win_button = nullptr;
    QSound *next_sound = nullptr;
    QSound *back_sound = nullptr;
    QSound *flip_sound = nullptr;
    QSound *win_sound = nullptr;

    unsigned char cur_level;
    bool coins_flag[4][4];
    GameCoin* coins[4][4];
};

#endif // PLAYSCENE_H
