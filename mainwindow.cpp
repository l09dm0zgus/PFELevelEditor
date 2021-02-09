#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileModel;
}


void MainWindow::on_foldersView_clicked(const QModelIndex &index)
{
    QString patch = fileModel->fileInfo(index).absoluteFilePath();
    ui->foldersView->setRootIndex(fileModel->setRootPath(patch));
}

void MainWindow::on_actionNew_Project_triggered()
{
   createProject();
}

void MainWindow::on_actionOpen_Project_triggered()
{
   openProject();
}
void MainWindow::createProject()
{
    NewProject newProject;
    newProject.setModal(true);
    newProject.exec();
}
void MainWindow::openProject()
{
    QString projectFile =  QFileDialog::getOpenFileName(this,tr("Open Project"),HOME_DIRECTORY , tr("XML files (*.xml)"));
    QDir directory = QFileInfo(projectFile).absoluteDir();
    directory.absolutePath();
    fileModel  = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs|QDir::Files);
    ui->foldersView->setModel(fileModel);
    ui->foldersView->setRootIndex(fileModel->setRootPath(directory.absolutePath()));
}
