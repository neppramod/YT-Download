#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    process = new QProcess();

    // Connect Settings Menu Option to SettingsWindow
    connect(ui->actionSettings, SIGNAL(triggered(bool)), this, SLOT(showSettings()));

    // Connect Download Button and Download Menu Option to downloadStart() method
    connect(ui->downloadButton, SIGNAL(clicked(bool)), this, SLOT(downloadStart()));
    connect(ui->actionDownload, SIGNAL(triggered(bool)), this, SLOT(downloadStart()));

    // Connect Clear Button and Clear Menu Option to uriText clear()
    connect(ui->clearButton, SIGNAL(clicked(bool)), ui->uriTextEdit, SLOT(clear()));
    connect(ui->actionClear, SIGNAL(triggered(bool)), ui->uriTextEdit, SLOT(clear()));

    // Process
    connect (process, SIGNAL(readyReadStandardOutput()), this, SLOT(readyRead()));
    connect (process, SIGNAL(finished (int, QProcess::ExitStatus)), this, SLOT(finished()));

    stdoutTxt = new QString();

    ui->uriTextEdit->setText("https://www.youtube.com/watch?v=A09_2yy5f2o");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: showSettings()
{

}

void MainWindow::downloadStart()
{

    QString fileName = getFilename();
    qDebug() << "FileName: " << fileName;

    /*
    // Get filename without random bits
    if (fileName != nullptr && fileName.length() > 0) {
        int lastIndexOfBracket = fileName.lastIndexOf("[");
        if (lastIndexOfBracket > 0) {
            fileName.resize(lastIndexOfBracket-1);
        }
        qDebug() << "FileName2: " << fileName;
    }
    */


    QString uri = ui->uriTextEdit->toPlainText();
    QString command = "/home/deck/.local/bin/yt-dlp -o '%(title)s.%(ext)s' " + uri;

    process->start("/bin/sh", QStringList()<< QString("-c") << command);
    process->waitForFinished(-1);
   // qDebug() << *stdoutTxt;


    //QString cmd1 = "/home/deck/.local/bin/yt-dlp -x --audio-format mp3 https://www.youtube.com/watch?v=A09_2yy5f2o";
    //process->start("/bin/sh", QStringList()<< QString("-c") << cmd1);
}

QString MainWindow::getFilename()
{
    QString uri = ui->uriTextEdit->toPlainText();
    //QString command =  "/home/deck/.local/bin/yt-dlp --print filename " + uri;
    QString command = "/home/deck/.local/bin/yt-dlp --print filename -o '%%(title)s.%%(ext)s' " + uri;
    qDebug() << "Uri: " << uri;

    clearStdoutTxt();
    process->start("/bin/sh", QStringList()<< QString("-c") << command);
    process->waitForFinished(-1);

    QString fileName(stdoutTxt->trimmed());
    clearStdoutTxt();
    return fileName;
}

void MainWindow::clearStdoutTxt()
{
    stdoutTxt->clear();
}


void MainWindow::finished()
{
    //qDebug() << "Finished\n";
}

void MainWindow::readyRead()
{
    if (!process)
        return;

      QString str = process->readAllStandardOutput();
      qDebug() << str;
      stdoutTxt->append(str);
}
