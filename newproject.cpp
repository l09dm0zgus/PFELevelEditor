#include "newproject.h"
#include "ui_newproject.h"
NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

NewProject::~NewProject()
{
    delete ui;
}
void NewProject::acceptOpeningFile()
{
    projectLocation =  ui->projectLocationEdit->placeholderText();
    Project project;
    project.setName(ui->projectNameEdit->toPlainText());
    XMLFileBuilder projectXMLFile;
    projectXMLFile.writeXMLFile(projectLocation+"/"+ui->projectNameEdit->toPlainText()+".pfeproj",project.getXMLFileElements());
}
void NewProject::rejectOpeningFile()
{
    projectLocation = "";
}
void NewProject::on_fileLocation_clicked()
{
    QFileDialog dialog(this);
    ui->projectLocationEdit->setPlaceholderText(dialog.getExistingDirectory(this, tr("Open Directory"),HOME_DIRECTORY,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
}


QString  NewProject::getProjectLocation()
{
    return projectLocation;
}

void NewProject::on_buttonBox_accepted()
{
    acceptOpeningFile();
    this->close();
}

void NewProject::on_buttonBox_rejected()
{
    rejectOpeningFile();
    this->close();
}
