#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
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

private:
    Ui::MainWindow *ui;
    QFileSystemModel  *fileModel;
    void createProject();
    void openProject();
};
#endif // MAINWINDOW_H
