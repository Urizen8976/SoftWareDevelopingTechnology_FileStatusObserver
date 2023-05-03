#include <QCoreApplication>
#include <Classes/FileStatusObserver.h>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    FileStatusObserver watcher;

    QString absoluteFileWayFirstPart = "D:/Timur/Qt_2/QT_Labs/SoftWareDevTech_FileStatusObserver_NoSingleton/TestFiles/TestFile"; //Формируем 1-ую часть пути к файлу
    QString absoluteFileWaySecondPart = ".txt";  // Формируем 3-юю (и последнюю) часть пути к файлу
    QString fullAbsoluteFileWay;
    QString number;
    for (int testFileNimber = 0; testFileNimber < 3; testFileNimber++) {
        number = QString::number(testFileNimber);  // Формируем 2-ую часть пути к файлу
        fullAbsoluteFileWay = absoluteFileWayFirstPart + number + absoluteFileWaySecondPart;  // Сформировали полный абсолютный путь к файлу
        watcher.addNewFile(fullAbsoluteFileWay);  /* Добавляем 3 файла для наблюдения
        и выведем начальное состояние всех файлов*/
    }

    cout << endl;
    watcher.addNewFile("D:/Timur/Qt_2/QT_Labs/SoftWareDevTech_FileStatusObserver_NoSingleton/TestFiles/TestFile2.txt");
    cout << endl;

    QTimer timer {};
    timer.setInterval(100);
    QObject::connect (&timer, &QTimer::timeout, &watcher, &FileStatusObserver::checkChangesSlot);
    timer.start();

    return app.exec();  // QApplication входит в цикл событий (eventloop).
    //Когда приложение Qt запущено, события генерируются и отправляются виджетам приложения.
}
