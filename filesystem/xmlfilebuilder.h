#ifndef XMLFILEBUILDER_H
#define XMLFILEBUILDER_H
#include "libs/tinyxml2.h"
#include<QString>
#include<map>
#include <QMessageBox>
namespace xml = tinyxml2;
#ifndef XMLCheckResult
    #define XMLCheckResult(result) if (result != xml::XML_SUCCESS) {   QMessageBox::warning(nullptr,"Error!!!","Failed creating project"+QString(result)); }
#endif

class XMLFileBuilder
{
public:
    XMLFileBuilder();
    void writeXMLFile(QString XMLFilePath, std::map<QString,QString> const &XMLData);
};

#endif // XMLFILEBUILDER_H
