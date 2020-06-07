#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include "scene.h"
#include "widgetbutton.h"
#include "playscene.h"

class SelectScene : public Scene
{
    Q_OBJECT
public:
    explicit SelectScene(QWidget *parent = nullptr);

    virtual void paintEvent(QPaintEvent *ev);
private:

    virtual void AttributeSet() override;
    virtual void MenuBarBuild() override;
    virtual void WidgetsBuild() override;
    virtual void SoundsSet() override;

signals:
    void BacktoStartScene();
public slots:

private:
    QSound *select_sound = nullptr;
    QSound *back_sound = nullptr;
};

#endif // SELECTSCENE_H
