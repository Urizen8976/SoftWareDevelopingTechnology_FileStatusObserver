#ifndef SLOTS_H
#define SLOTS_H


#include <QString>
#include <QObject>


class Slots : public QObject  // Все классы с сигналами и слотами, должны быть потомками (прямо или косвенно) QObject
{
    Q_OBJECT
public slots:
    static void existChangesSlot(QString fileName, bool isExist);  // Метод статичны для возможности вызова их без создания экзепляра класса
    static void sizeChangesSlot(QString fileName, qint64 size);
    static void alreadyAddedChangesSlot(QString fileName);
    static void alreadyDeletedChangesSlot(QString fileName);
};


#endif // SLOTS_H
