#ifndef FILESTATUSOBSERVER_H
#define FILESTATUSOBSERVER_H


#include <Classes/FileStatus.h>
#include <QList>
#include <QObject>
#include <QTime>


class FileStatusObserver : public QObject
{
private:
    // Некоторые данные класса:
    Q_OBJECT /* Пишем макрос Q_OBJECT в начале декл-ии, т.к. все классы с сигналами и слотами, должны это делать и происходить от QObject.*/
    QList<FileStatus> filesVector;  // Вектор со статистикой файлов

    // Внутренние методы класса:
    void checkExistChangesByPosition(int position);  // Просмотр изменения состояния
    void checkSizeChangesByPosition(int position);  // Просмотр изменения размера
    void changeFileStatus(int position, const FileStatus &FileStatus);  // Замена данных по позиции
    void checkExistChanges();  // Проверка всех файлов по состоянию
    void checkSizeChanges();  // Проверка всех файлов по размеру

public:
    FileStatusObserver();  // Конструктор по умолчанию класса

    // Методы для доступа и работы с внутренними данными и методами класса:
    bool addNewFile(const QString &filePath);  // Добавление нового файла для отслеживания, принимает путь к файлу
    bool deleteFile(const QString &filePath);

signals:
    void existenceSignal(QString fileName, bool isExist);  // Сигнал передает имя и состояние
    void alreadyAddedSignal(QString fileName);  // Сигнал о повторном добавлении старого файла передает имя и состояние
    void alreadyDeletedSignal(QString fileName);
    void sizeSignal(QString fileName, qint64 size);  // Сигнал передает имя и размер

public slots:
    void checkChangesSlot();  // Проверка всех файлов
};


#endif // FILESTATUSOBSERVER_H
