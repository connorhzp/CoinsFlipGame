#include "startscene.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartScene)
{
    ui->setupUi(this);

    SceneInit();
}

StartScene::~StartScene()
{
    delete ui;
}

void StartScene::SceneInit(){
    AttributeSet();
    MenuBarBuild();
    WidgetsBuild();
    SoundsSet();
}

void StartScene::AttributeSet(){
    setFixedSize(400, 600);
    setWindowTitle("Coins Flip Game");

    //Only make sence for window
    setWindowIcon(QIcon(":/res/Coin0001.png"));
}

void StartScene::MenuBarBuild(){
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

void StartScene::WidgetsBuild(){
    WidgetButton *start_button = new WidgetButton(":/pictures/res/MenuSceneStartButton.png", "", this);
    start_button -> move(width() * 0.5 - start_button->width() * 0.5, height() * 0.7);
}

void StartScene::SoundsSet(){

}

void StartScene::paintEvent(QPaintEvent *ev){
    //background scene
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pictures/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);

    //add title
    pix.load(":/pictures/res/Title.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
}
