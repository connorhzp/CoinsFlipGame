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

void WidgetButton::ZoomUp(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation ->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y() +10,this->width(),this->height()));
    //Set the animation of widget
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void WidgetButton::ZoomDown(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation ->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y() +10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //Set the animation of widget
    animation->setEasingCurve(QEasingCurve::InBounce);

    animation->start();
}

void WidgetButton::mousePressEvent(QMouseEvent *e){
    if (focus_img != ""){
        QPixmap pix(focus_img);
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize(width(), height()));
    }

    return QPushButton::mousePressEvent(e);
}

void WidgetButton::mouseReleaseEvent(QMouseEvent *e){
    if (focus_img != ""){
        QPixmap pix(normal_img);
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize(width(), height()));
    }

    //Written by mistake: QPushButton::mousePressEvent(e)  cannot trigget the WigdetButton::clicked
    return QPushButton::mouseReleaseEvent(e);
}

void WidgetButton::ButtonBounce(){
    ZoomUp();
    ZoomDown();
}

