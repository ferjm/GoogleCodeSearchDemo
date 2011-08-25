#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtgdata/qtgdatacodesearchclient.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QtgdataCodeSearchClient *_client;

public slots:
    void search();
    void onSearch(CodeSearchFeed*);
};

#endif // MAINWINDOW_H
