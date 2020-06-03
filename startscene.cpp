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
    ToolBarBuild();
    StartButtonBuild();
    SoundsSet();
}

void StartScene::AttributeSet(){
    setFixedSize(400, 600);

    //Only make sence for window
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    setWindowTitle("Coins Flip Game");
}

void StartScene::ToolBarBuild(){
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

}

void StartScene::StartButtonBuild(){

}

void StartScene::SoundsSet(){

}
