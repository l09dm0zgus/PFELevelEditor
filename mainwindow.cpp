#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sceneTree->setColumnCount(1);
    ui->sceneTree->setHeaderLabel("Scene");
    loadContextMenus();
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



void MainWindow::openFoldersViewContextMenu(const QPoint& position)
{
    QPoint  globalPosition = ui->foldersView->mapToGlobal(position);
    QMenu menu;
    menu.addAction("Add Images",this,SLOT(addImageFiles()));
    menu.addAction("Add 3D models",this,SLOT(add3DModelsFiles()));
    menu.addAction("Add Audio",this,SLOT(addAudioFiles()));
    menu.exec(globalPosition);
}
void MainWindow::openSceneTreeContextMenu(const QPoint& position)
{
    QPoint  globalPosition = ui->sceneTree->mapToGlobal(position);
    QMenu menu;
    menu.addAction("Create Sprite",this,SLOT(addSpriteToScene()));
    menu.addAction("Create 3D Model",this,SLOT(addModelToScene()));
    menu.addAction("Create Light",this,SLOT(addLightToScene()));
    menu.exec(globalPosition);
}
void MainWindow::addImageFiles()
{
    qDebug("Adding  image files");
}
void MainWindow::add3DModelsFiles()
{
    qDebug("Adding  models files");
}
void MainWindow::addAudioFiles()
{
    qDebug("Adding  audio files");
}
void MainWindow::addModelToScene()
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->sceneTree);
    item->setText(0,"Model");
    ui->sceneTree->addTopLevelItem(item);
}
void MainWindow::addSpriteToScene()
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->sceneTree);
    item->setText(0,"Sprite");
    ui->sceneTree->addTopLevelItem(item);
}
void MainWindow::addLightToScene()
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->sceneTree);
    item->setText(0,"Light");
    ui->sceneTree->addTopLevelItem(item);
}

void MainWindow::loadContextMenus()
{
    ui->foldersView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->sceneTree->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->foldersView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(openFoldersViewContextMenu(QPoint)));
    connect(ui->sceneTree,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(openSceneTreeContextMenu(QPoint)));
}
void MainWindow::clearObjectProperties()
{
    if (ui->objectProperties->layout() != nullptr )
    {
        QLayoutItem* item;
        while ( ( item = ui->objectProperties->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete ui->objectProperties->layout();
    }
}
void MainWindow::on_sceneTree_itemClicked(QTreeWidgetItem *item, int column)
{
    clearObjectProperties();
    QPushButton* button = new QPushButton("Kek");
    QTextEdit *edit = new QTextEdit();
    connect(button, &QPushButton::clicked,
               [edit,item]() {
                   item->setText(0,edit->toPlainText());
               }
           );
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(button);
    hbox->addWidget(edit);
    ui->objectProperties->setLayout(hbox);
}
