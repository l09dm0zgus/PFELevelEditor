#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QFileDialog>
#include "filesystem/project.h"
#include "filesystem/xmlfilebuilder.h"
#include "utils/utils.h"
namespace Ui {
class NewProject;
}

class NewProject : public QDialog
{
    Q_OBJECT

public:
    explicit NewProject(QWidget *parent = nullptr);
    ~NewProject();
    QString getProjectLocation();
private slots:
    void on_fileLocation_clicked();
    void acceptOpeningFile();
    void rejectOpeningFile();
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    QString projectLocation;
    Ui::NewProject *ui;

};

#endif // NEWPROJECT_H
