#ifndef SEARCHFRAME_H
#define SEARCHFRAME_H

#include <QFrame>

namespace Ui {
    class SearchFrame;
}

class SearchFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SearchFrame(QString title, QString content, QString id,QWidget *parent = 0);
    ~SearchFrame();

private:
    Ui::SearchFrame *ui;
    QString _id;

public slots:
    void openURL();
};

#endif // SEARCHFRAME_H
