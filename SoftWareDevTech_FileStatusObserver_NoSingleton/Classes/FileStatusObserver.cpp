#include "FileStatusObserver.h"
#include <QVector>
#include <Classes/FileStatus.h>
#include <Classes/Slots.h>


FileStatusObserver::FileStatusObserver() {
    connect(this, &FileStatusObserver::existenceSignal, this, &Slots::existChangesSlot); // Соед-ие сигнала и слота объекта
    connect(this, &FileStatusObserver::sizeSignal, this, &Slots::sizeChangesSlot); // Запись на основе указателей
    connect(this, &FileStatusObserver::alreadyAddedSignal, this, &Slots::alreadyAddedChangesSlot); // Соед-ие сигнала и слота объекта
    connect(this, &FileStatusObserver::alreadyDeletedSignal, this, &Slots::alreadyDeletedChangesSlot); // Соед-ие сигнала и слота объекта
}

bool FileStatusObserver::addNewFile(const QString &filePath) {
    FileStatus newFile(filePath);  // создание временного файла для проверки
    if(filesVector.contains(newFile))  // проверка наличия старого файла в списке
    {
        emit alreadyAddedSignal(newFile.getFilePath());
        return false;
    }
    filesVector.push_back(newFile);  // добавление файла при его отсутствии в списке
    emit existenceSignal(newFile.getFilePath(), newFile.isExists()); // излучение сигнала при добавлении
    emit sizeSignal(newFile.getFilePath(), newFile.getFileSize()); // излучение сигнала при добавлении
    return true;
}

bool FileStatusObserver::deleteFile(const QString &filePath) {
    FileStatus newFile(filePath);  // временный файл для проверки на наличие файла в списке
    if(filesVector.contains(newFile))
    {
        filesVector.removeOne(newFile);  // Удаляет 1-ый newFile в списке и возвращает true/false в случае успеха/неуспеха;
        return true;
    }
    emit alreadyDeletedSignal(newFile.getFilePath());
    return false;
}

void FileStatusObserver::changeFileStatus(int position, const FileStatus &fileStatus) {
    filesVector[position] = fileStatus;
}

void FileStatusObserver::checkChangesSlot() {
    checkExistChanges();
    checkSizeChanges();
}

void FileStatusObserver::checkExistChanges() {  // is used by checkChanges()
    // Идет по всему вектору и вызывает функцию проверки изменений
    for (int i = 0; i < filesVector.count(); i++) {
        checkExistChangesByPosition(i);
    }
}

void FileStatusObserver::checkSizeChanges() {  // is used by checkChanges()
    // Идет по всему вектору и вызывает функцию проверки изменений
    for (int i = 0; i < filesVector.count(); i++) {
        checkSizeChangesByPosition(i);
    }
}

void FileStatusObserver::checkExistChangesByPosition(int position) {  // used by checkExistChanges() (checkExistChanges() is used by checkChanges())
    /*FileStatus savedStatus = filesVector[position];
    FileStatus currentStatus(savedStatus.getFilePath());
    bool isChanged = (savedStatus.isExists() != currentStatus.isExists());*/ // Для проверки изменения сравним имеющийся экземпляр со созданным по тому же пути

    FileStatus currentStatus(filesVector[position].getFilePath());
    bool isChanged = (filesVector[position].isExists() != currentStatus.isExists());

    if (isChanged) {  // Если файл изменен, то перезапишем его в вектор наблюдения
        changeFileStatus(position, currentStatus);
        emit existenceSignal(currentStatus.getFilePath(), currentStatus.isExists());
    }
}

void FileStatusObserver::checkSizeChangesByPosition(int position) {  // is used by checkSizeChanges() (checkSizeChanges() is used by checkChanges())
    /*FileStatus savedStatus = filesVector[position];
    FileStatus currentStatus(savedStatus.getFilePath());
    bool isChanged = (savedStatus.getFileSize() != currentStatus.getFileSize());*/  // Проверка изменения имеющегося экземпляра

    FileStatus currentStatus(filesVector[position].getFilePath());
    bool isChanged = (filesVector[position].getFileSize() != currentStatus.getFileSize());

    if (isChanged) {  // Если файл изменен, то перезапишем его в вектор наблюдения
        changeFileStatus(position, currentStatus);
        emit sizeSignal(currentStatus.getFilePath(), currentStatus.getFileSize());
    }
}
