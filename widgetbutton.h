#ifndef WIDGETBUTTON_H
#define WIDGETBUTTON_H

#include <QPushButton>
#include <QString>
#include <QPropertyAnimation>

class WidgetButton : public QPushButton
{
    Q_OBJECT
public:
    WidgetButton(QString normal_img, QString focus_img = "", QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
    void ButtonBounce();

private:
    void ZoomUp();
    void ZoomDown();

    QString normal_img;
    QString focus_img;
};

#endif // WIDGETBUTTON_H
