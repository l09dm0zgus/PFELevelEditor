#include "newproject.h"
#include "ui_newproject.h"
NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
}

NewProject::~NewProject()
{
    delete ui;
}

void NewProject::on_fileLocation_clicked()
{
    QFileDialog dialog(this);
    ui->projectLocationEdit->setPlaceholderText(dialog.getExistingDirectory(this, tr("Open Directory"),HOME_DIRECTORY,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
}
