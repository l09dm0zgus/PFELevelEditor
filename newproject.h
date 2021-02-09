#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QFileDialog>
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

private slots:
    void on_fileLocation_clicked();

private:
    Ui::NewProject *ui;
};

#endif // NEWPROJECT_H
