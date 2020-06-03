#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>

namespace Ui {
class StartScene;
}

class StartScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartScene(QWidget *parent = 0);
    ~StartScene();

private:
    void SceneInit();

    void AttributeSet();
    void ToolBarBuild();
    void StartButtonBuild();
    void SoundsSet();

    Ui::StartScene *ui;
};

#endif // STARTSCENE_H
