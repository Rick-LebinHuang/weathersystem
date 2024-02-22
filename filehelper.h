#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <QString>
#include <QFile>
// header of filehelper
class FileHelper
{
public:
    FileHelper();
    static QString readAllTxt(const QString &filePath);
};

#endif // FILEHELPER_H
