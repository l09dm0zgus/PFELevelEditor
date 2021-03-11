#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeWidgetItem>
#include <QProgressDialog>
#include "newproject.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_foldersView_clicked(const QModelIndex &index);

    void on_actionNew_Project_triggered();

    void on_actionOpen_Project_triggered();
    void addImageFiles();
    void add3DModelsFiles();
    void addAudioFiles();
    void openFoldersViewContextMenu(const QPoint& position);
    void openSceneTreeContextMenu(const QPoint& position);
    void addModelToScene();
    void addSpriteToScene();
    void addLightToScene();

    void on_sceneTree_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QFileSystemModel  *fileModel;
    QString currentProjectPath;
    void createProject();
    void openProject();
    void clearObjectProperties();
    void showProjectFiles(QString projectLocation);
    void loadContextMenus();
    void copyFilesInProject(QString fileType);
};
#endif // MAINWINDOW_H
