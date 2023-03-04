#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QFileDialog>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    connect(ui->ytdlLocationButton, SIGNAL(clicked(bool)), this, SLOT(setYTLocation()));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::setYTLocation()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select yt-dl file", QDir::currentPath(), "All files (*)");

    if (fileName.length() > 0) {
        ui->ytdlLocationLineEdit->setText(fileName);
    }
}
