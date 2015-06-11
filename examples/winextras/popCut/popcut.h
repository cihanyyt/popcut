#ifndef POPCUT_H
#define POPCUT_H

#include <QMainWindow>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>

namespace Ui {
class popCut;
}

class popCut : public QMainWindow
{
    Q_OBJECT

public:
    explicit popCut(QWidget *parent = 0);
    ~popCut();

private:
    Ui::popCut *ui;


protected:
    void dropEvent(QDropEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);
};

#endif // POPCUT_H
