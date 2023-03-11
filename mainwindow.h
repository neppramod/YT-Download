#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    QString *stdoutTxt;

    QString getFilename();
    void clearStdoutTxt();

private slots:
    void showSettings();
    void downloadStart();
    void finished();
    void readyRead();
};

#endif // MAINWINDOW_H
