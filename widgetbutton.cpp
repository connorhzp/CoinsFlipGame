#include "widgetbutton.h"

WidgetButton::WidgetButton(QString normal_img, QString focus_img, QWidget *parent)
    : QPushButton(parent), normal_img(normal_img), focus_img(focus_img)
{
    QPixmap pix(normal_img);

    //set button size
    setFixedSize(pix.width(), pix.height());
    //set border style
    setStyleSheet("QPushButton{border:0px;}");
    //set button icon
    setIcon(pix);
    //set icon size
    setIconSize(QSize(width(), height()));
}
