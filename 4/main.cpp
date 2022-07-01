#include <iostream>
#include <QString>
#include <QCryptographicHash>
#include <string>

int main()
{
    QString blah;
    std::string startString = "ckczppom";
    int counter = 0;
    do{
        counter++;
        blah = QString(QCryptographicHash::hash((startString + std::to_string(counter)),QCryptographicHash::Md5).toHex());
    }
    while(blah.toStdString().rfind("000000", 0) == std::string::npos);


    std::cout<<startString << "-" << blah.toStdString() << "-" << counter << std::endl;

    return EXIT_SUCCESS;
}
