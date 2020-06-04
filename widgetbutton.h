#ifndef WIDGETBUTTON_H
#define WIDGETBUTTON_H

#include <QPushButton>
#include <QString>

class WidgetButton : public QPushButton
{
    Q_OBJECT
public:
    WidgetButton(QString normal_img, QString focus_img = "", QWidget *parent = nullptr);

signals:

public slots:

private:
    QString normal_img;
    QString focus_img;
};

#endif // WIDGETBUTTON_H
