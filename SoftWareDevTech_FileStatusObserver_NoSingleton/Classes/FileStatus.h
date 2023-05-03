#ifndef FILESTATUS_H
#define FILESTATUS_H


#include <QFileInfo>
#include <QString>


class FileStatus
{
private:
    QString filePath;  // Абсолютный путь до файла
    qint64 fileSize;  // Размер файла в байтах
    bool fileExistence;  // Состояние файла: 1 - существует, 0 - не существует
public:
    // Конструкторы:
    FileStatus() = default;  // Конструктор по умолчанию указанный явно
    FileStatus(const QString &filePath);  // Конструктор с параметром пути к файлу
    FileStatus(const FileStatus& fileStatus);  // конструктор копирования

    // Геттеры:
    bool isExists();  // Геттер для fileExistence
    QString getFilePath();  // Геттер для filePath
    qint64 getFileSize();  // Геттер для fileSize

    // Перегрузки:
    bool operator==(const FileStatus &fileStatus) const;  // перегрузка оператора сравнения
    FileStatus &operator =(const FileStatus &fileStatus);  // перегрузка оператора присваивания
};


#endif // FILESTATUS_H
