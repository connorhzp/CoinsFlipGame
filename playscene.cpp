#include "playscene.h"

PlayScene::PlayScene(QWidget *parent) : Scene(parent), level_str(nullptr), win_button(nullptr)
{
    SceneInit();
}

void PlayScene::AttributeSet(){
    setFixedSize(400, 600);
    setWindowTitle("Coins Flip Game");

    //Only make sence for window
    setWindowIcon(QIcon(":/res/Coin0001.png"));
}

void PlayScene::MenuBarBuild(){
    //add menubar
    QMenuBar *menu_bar = menuBar();
    setMenuBar(menu_bar);

    //add menus
    QMenu *control_menu = new QMenu("control", menu_bar);
    QMenu *options_menu = new QMenu("options", menu_bar);
    menu_bar -> addMenu(control_menu);
    menu_bar -> addMenu(options_menu);

    //add actions in each menu
    QAction *restart_action = new QAction("restart");
    QAction *close_action = new QAction("close");
    QAction *expend_action = new QAction("expend");
    control_menu -> addAction(restart_action);
    control_menu -> addAction(close_action);
    options_menu -> addAction(expend_action);

    connect(close_action, &QAction::triggered, this, &QMainWindow::close);
}

void PlayScene::WidgetsBuild(){
    //back button:
    WidgetButton *back_button = new WidgetButton(":/pictures/res/BackButton.png", ":/pictures/res/BackButtonSelected.png", this);
    back_button -> move(width() - back_button->width(), height() - back_button->height());
    connect(back_button, &WidgetButton::clicked, [=]{
        QTimer::singleShot(500, this, [=]{
            emit BacktoSelectScene();
        });
    });

    //level string:
    QFont font;
    font.setPointSize(16);
    level_str = new QLabel(this);
    level_str -> setFont(font);
    level_str -> setGeometry(20, height() -50, 200, 50);

    //win sign:
    win_button = new WidgetButton(":/pictures/res/LevelCompletedDialogBg.png", "", this);
    connect(win_button, &WidgetButton::clicked, [=](){
        win_button -> ButtonBounce();
        QTimer::singleShot(500, this, [=](){
            this -> LevelSet(cur_level +1);
        });
    });

    //coins back ground:
    for (int i=0; i < 4; i++){
        for (int j =0; j < 4; j++){
            QLabel *coin_background = new QLabel(this);
            coin_background -> setGeometry(100 + (i %4) *50, 200 + (j %4) *50, 50, 50);
            coin_background -> setPixmap(QPixmap(":/pictures/res/BoardNode.png"));

            GameCoin *coin = new GameCoin(":/pictures/res/Coin0001.png", this);
            coin -> move(102 + (i %4) *50, 202 + (j %4) *50);

            connect(coin, &GameCoin::clicked, [=](){
                coin -> CoinFlip();
                coins_flag[i][j] = !coins_flag[i][j];

                QTimer::singleShot(300, this, [=]{
                    if (i +1 < 4){
                        coins[i +1][j] -> CoinFlip();
                        coins_flag[i +1][j] = !coins_flag[i +1][j];
                    }
                    if (i -1 >= 0){
                        coins[i -1][j] -> CoinFlip();
                        coins_flag[i -1][j] = !coins_flag[i -1][j];
                    }
                    if (j +1 < 4){
                        coins[i][j +1] -> CoinFlip();
                        coins_flag[i][j +1] = !coins_flag[i][j +1];
                    }
                    if (j -1 >= 0){
                        coins[i][j -1] -> CoinFlip();
                        coins_flag[i][j -1] = !coins_flag[i][j -1];
                    }

                    //judge win or not
                    bool iswin = true;
                    for (int i =0; i <4; i++){
                        for (int j =0; j <4; j++){
                            if (coins_flag[i][j] == false){
                                iswin = false;
                                break;
                            }
                        }
                    }
                    if (iswin){
                        QPropertyAnimation * animation = new QPropertyAnimation(win_button, "geometry", this);
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(win_button->x(), win_button->y(), win_button->width(), win_button->height()));
                        animation->setEndValue(QRect(win_button->x(), win_button->y() + 200, win_button->width(), win_button->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });

            });

            coins[i][j] = coin;
        }
    }
}

void PlayScene::SoundsSet(){

}

void PlayScene::LevelSet(int level){
    cur_level = level;
    //reset win label
    win_button -> move((width() - win_button->width()) * 0.5,  -win_button->height());
    // level show:
    level_str -> setText(QString("Now %1 level").arg(level));
    // coins init:
    for (int i =0; i < 4; i++){
        for (int j =0; j < 4; j++){
            coins[i][j] -> CoinInit(config[level][i][j]);
            coins_flag[i][j] = config[level][i][j];
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *ev){
    //background scene
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);

    //add title
    pix.load(":/pictures/res/Title.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
}
