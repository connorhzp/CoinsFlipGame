#include "selectscene.h"

SelectScene::SelectScene(QWidget *parent) : Scene(parent)
{
    SceneInit();
}

void SelectScene::AttributeSet(){
    setFixedSize(400, 600);
    setWindowTitle("Coins Flip Game");

    //Only make sence for window
    setWindowIcon(QIcon(":/res/Coin0001.png"));
}

void SelectScene::MenuBarBuild(){
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

void SelectScene::WidgetsBuild(){
    //back button:
    WidgetButton *back_button = new WidgetButton(":/pictures/res/BackButton.png", ":/pictures/res/BackButtonSelected.png", this);
    back_button -> move(width() - back_button->width(), height() - back_button->height());
    connect(back_button, &WidgetButton::clicked, [=]{
        back_sound -> play();
        QTimer::singleShot(500, this, [=]{
            emit BacktoStartScene();
        });
    });

    //new play scene
    PlayScene *play_scene = new PlayScene(this);
    connect(play_scene, &PlayScene::BacktoSelectScene, [=]{
        play_scene -> hide();
        //keep the position the same
        this -> setGeometry(play_scene -> geometry());
        this -> show();
    });

    //game level buttons:
    for (int i =0; i <20; i++){
        WidgetButton *level_button = new WidgetButton(":/pictures/res/LevelIcon.png", "", this);
        level_button -> move(35 + (i %5) *70, 150 + (i /5) *70);

        QLabel *label = new QLabel(QString::number(i +1), this);
        label -> setFixedSize(level_button -> width(), level_button -> height());
        label -> move(35 + (i %5) *70, 150 + (i /5) *70);

        //Set text alignment
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //Set control penetration
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);

        connect(level_button, &WidgetButton::clicked, [=]{
            select_sound -> play();
            QTimer::singleShot(200, this, [=]{
                this -> hide();
                play_scene -> LevelSet(i +1);
                //keep the position the same
                play_scene -> setGeometry(this -> geometry());
                play_scene -> show();
            });
        });
    }
}

void SelectScene::SoundsSet(){
    select_sound = new QSound(":/sounds/res/TapButtonSound.wav", this);
    back_sound = new QSound(":/sounds/res/BackButtonSound.wav", this);
}

void SelectScene::paintEvent(QPaintEvent *ev){
    //background scene
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);

    //add title
    pix.load(":/pictures/res/Title.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
}
