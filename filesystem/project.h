#ifndef PROJECT_H
#define PROJECT_H
#include<QString>
#include<map>
class Project
{
    public:
        Project();
        void setName(QString name);
        std::map<QString,QString> getXMLFileElements();
    private:
        std::map<QString,QString> XMLFileElements;
};

#endif // PROJECT_H
