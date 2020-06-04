#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QLabel>

#include "widgetbutton.h"

namespace Ui {
class StartScene;
}

class StartScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartScene(QWidget *parent = 0);
    ~StartScene();

    virtual void paintEvent(QPaintEvent *ev);
private:
    void SceneInit();

    void AttributeSet();
    void MenuBarBuild();
    void WidgetsBuild();
    void SoundsSet();

    Ui::StartScene *ui;
};

#endif // STARTSCENE_H
