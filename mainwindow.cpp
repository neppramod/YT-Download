#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize SettingsWindow
    settingsWindow = new SettingsWindow(nullptr);

    // Connect Settings Menu Option to SettingsWindow
    connect(ui->actionSettings, SIGNAL(triggered(bool)), this, SLOT(showSettings()));

    // Connect Download Button and Download Menu Option to downloadStart() method
    connect(ui->downloadButton, SIGNAL(clicked(bool)), this, SLOT(downloadStart()));
    connect(ui->actionDownload, SIGNAL(triggered(bool)), this, SLOT(downloadStart()));

    // Connect Clear Button and Clear Menu Option to uriText clear()
    connect(ui->clearButton, SIGNAL(clicked(bool)), ui->uriTextEdit, SLOT(clear()));
    connect(ui->actionClear, SIGNAL(triggered(bool)), ui->uriTextEdit, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: showSettings()
{
    settingsWindow->show();
}

void MainWindow::downloadStart()
{
    qDebug() << "Download Started";
}
