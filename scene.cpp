#include "scene.h"

Scene::Scene(QWidget *parent) : QMainWindow(parent)
{

}

void Scene::SceneInit(){

    AttributeSet();

    MenuBarBuild();

    WidgetsBuild();

    SoundsSet();
}
