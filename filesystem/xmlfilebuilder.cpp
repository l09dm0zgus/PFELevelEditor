#include "xmlfilebuilder.h"

XMLFileBuilder::XMLFileBuilder()
{

}
void XMLFileBuilder::writeXMLFile(QString XMLFilePath, const std::map<QString, QString> &XMLData)
{
    std::map<QString,QString>::const_iterator it = XMLData.find("root");
    if(it != XMLData.end())
    {
        xml::XMLDocument document;
        xml::XMLNode *node = document.NewElement("Project");
        document.InsertFirstChild(node);
        for(const auto &XMLProperty : XMLData)
        {
            if(XMLProperty.first == "root")
            {
                continue;
            }
            xml::XMLElement *element=document.NewElement(XMLProperty.first.toStdString().c_str());
            element->SetText(XMLProperty.second.toStdString().c_str());
            node->InsertEndChild(element);
        }
        xml::XMLError result = document.SaveFile(XMLFilePath.toStdString().c_str());
        XMLCheckResult(result);
    }
    else
    {
        QMessageBox::warning(nullptr,"Error!!!","Invalid XML data!!!");
    }

}
