#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <QMap>
#include <QVector>

typedef QMap<int, QVector<QVector<int>>> GameConfig;
extern GameConfig config;

#endif // GAMECONFIG_H
