#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QFileDialog>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    // FixMe (selectionChanged())
    connect(ui->ytdlLocationLineEdit, SIGNAL(selectionChanged()), this, SLOT(setYTLocation()));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::setYTLocation()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select yt-dl file", QDir::currentPath(), "All files (*)");
    ui->ytdlLocationLineEdit->setText(fileName);
}
