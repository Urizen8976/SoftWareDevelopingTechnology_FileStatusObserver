#include "Slots.h"
#include <iostream>


using namespace std;


void Slots::existChangesSlot(QString fileName, bool isExist) {
    if (isExist) {
        wcout << L"File: " << fileName.toStdWString() << L" - exists"<< endl;
    } else {
        wcout << L"File: " << fileName.toStdWString() << L" - does not exist"<< endl;
    }
}

void Slots::alreadyAddedChangesSlot(QString fileName) {
    wcout << L"File: " << fileName.toStdWString() << L" - already added"<< endl;
}

void Slots::alreadyDeletedChangesSlot(QString fileName) {
    wcout << L"File: " << fileName.toStdWString() << L" - already deleted"<< endl;
}


void Slots::sizeChangesSlot(QString fileName, qint64 size) {
    wcout << L"File: " << fileName.toStdWString() << L" has size: "<< size << L" bites"<< endl;
}

void Slots::existenceAndSizeChangesSlot(QString fileName, bool isExist, qint64 size) {
    if (isExist) {
        wcout << L"File: " << fileName.toStdWString() << L" - exists and"
              << L" has size: "<< size << L" bites"<< endl;
    } else {
        wcout << L"File: " << fileName.toStdWString() << L" - does not exist" << endl;
    }
}
