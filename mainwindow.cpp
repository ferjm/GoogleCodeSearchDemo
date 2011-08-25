#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtgdata/qtgdataoauthdata.h"
#include "searchframe.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buscarButton,SIGNAL(clicked()),this,SLOT(search()));
    OAuthData *auth = new OAuthData();
    auth->setConsumerKey("anonymous");
    auth->setConsumerSecret("anonymous");
    auth->setToken("");
    auth->setTokenSecret("");
    this->_client = new QtgdataCodeSearchClient(auth);
    connect(this->_client, SIGNAL(codeSearchFeedRetrieved(CodeSearchFeed*)),this,SLOT(onSearch(CodeSearchFeed*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search()
{
    QString code = ui->codeEdit->text();
    if(!code.isEmpty())
    {
        QStringList list;
        list.append(code);
        this->_client->query(list);
    }
}

void MainWindow::onSearch(CodeSearchFeed *feed)
{
    ui->tableWidget->hide();
    if(ui->tableWidget->rowCount() > 0)
    {
        for(int i=0; i<ui->tableWidget->rowCount(); i++)
        {
            ui->tableWidget->cellWidget(i,0)->deleteLater();
            ui->tableWidget->removeCellWidget(i,0);
            ui->tableWidget->removeRow(i);
        }
        ui->tableWidget->removeColumn(0);
        ui->tableWidget->insertColumn(0);
    }
    ui->tableWidget->setColumnWidth(0,761);
    for(int i=0; i < (feed->entries.size()); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setRowHeight(i,140);
        SearchFrame *f = new SearchFrame(feed->entries.at(i)->title,
                                         QString(feed->entries.at(i)->content.content),
                                         feed->entries.at(i)->id,
                                         this);

        ui->tableWidget->setCellWidget(i,0,f);
    }
    ui->tableWidget->show();
}
