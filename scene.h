#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QString>
#include <QFont>
#include <QSound>
#include <QPropertyAnimation>


class Scene : public QMainWindow
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

    virtual void SceneInit();
private:
    virtual void AttributeSet() = 0;
    virtual void MenuBarBuild() = 0;
    virtual void WidgetsBuild() = 0;
    virtual void SoundsSet() = 0;
signals:

public slots:
};

#endif // SCENE_H
