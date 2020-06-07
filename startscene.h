#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "scene.h"
#include "widgetbutton.h"
#include "selectscene.h"

namespace Ui {
class StartScene;
}

class StartScene : public Scene
{
    Q_OBJECT

public:
    explicit StartScene(QWidget *parent = 0);
    ~StartScene();

    virtual void paintEvent(QPaintEvent *ev);
private:

    virtual void AttributeSet() override;
    virtual void MenuBarBuild() override;
    virtual void WidgetsBuild() override;
    virtual void SoundsSet() override;

    SelectScene *select_scene = nullptr;
    QSound *sound = nullptr;


    Ui::StartScene *ui;
};

#endif // STARTSCENE_H
