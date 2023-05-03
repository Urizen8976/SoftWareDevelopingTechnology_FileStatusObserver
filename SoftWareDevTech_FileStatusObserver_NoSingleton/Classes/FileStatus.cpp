#include "FileStatus.h"


FileStatus::FileStatus(const QString &file) {
    QFileInfo fileInfo(file);  // Конструктор создает новый QFileInfo , который предоставляет информацию о данном файле.
        // Файл также может включать абсолютный или относительный путь .
    filePath = fileInfo.absoluteFilePath();   // Возвращает абсолютный путь к файлу. Это не включает имя файла.м
    fileExistence = fileInfo.exists();  // Возвращает true, если файл существует; в противном случае возвращает ложь.
        // Если файл  -  символическая ссылка на несуществующий файл, возвращается значение false.
    fileSize = fileInfo.size();  // Возвращает размер файла в байтах. Если файл не существует или не может быть извлечен, возвращается 0.
}

bool FileStatus::isExists() {
    return fileExistence;
}

QString FileStatus::getFilePath() {
    return filePath;
}

qint64 FileStatus::getFileSize() {
    return fileSize;
}

bool FileStatus::operator==(const FileStatus &fileStatus) const{
    return fileStatus.filePath == filePath && fileStatus.fileSize == fileSize && fileStatus.fileExistence == fileExistence;
}

FileStatus& FileStatus::operator =(const FileStatus &fileStatus) {
    filePath = fileStatus.filePath;
    fileExistence = fileStatus.fileExistence;
    fileSize = fileStatus.fileSize;
    return *this;
}

FileStatus::FileStatus(const FileStatus &fileStatus) {
    filePath = fileStatus.filePath;
    fileExistence = fileStatus.fileExistence;
    fileSize = fileStatus.fileSize;
}
