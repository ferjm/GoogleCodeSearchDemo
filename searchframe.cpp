#include "searchframe.h"
#include "ui_searchframe.h"
#include <QDesktopServices>
#include <QUrl>

SearchFrame::SearchFrame(QString title, QString content, QString id,QWidget *parent):
    QFrame(parent),
    ui(new Ui::SearchFrame)
{
    ui->setupUi(this);
    ui->contentPlainText->setHtml(content);
    ui->titleLabel->setText(title);

    ui->idLabel->setText(id);
    this->_id = id;

    connect(ui->linkButton,SIGNAL(clicked()),this,SLOT(openURL()));
}

SearchFrame::~SearchFrame()
{
    delete ui;
}

void SearchFrame::openURL()
{
    QDesktopServices::openUrl(QUrl(this->_id));
}
