#include "project.h"
 Project::Project()
 {
     XMLFileElements.insert(std::pair<QString,QString>("root","Project"));
 }

 void Project::setName(QString name)
 {
     XMLFileElements.insert(std::pair<QString,QString>("name",name));
 }

std::map<QString,QString> Project::getXMLFileElements()
{
    return XMLFileElements;
}
