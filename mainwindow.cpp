#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settingsWindow = new SettingsWindow(nullptr);

    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(showSettings()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: showSettings()
{
    settingsWindow->show();
}
