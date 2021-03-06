#ifndef LISTEECHOUESFRAME_H
#define LISTEECHOUESFRAME_H

#include <QFrame>
#include "candidature_manager.h"
namespace Ui {
class ListeEchouesFrame;
}

class ListeEchouesFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ListeEchouesFrame(QWidget *parent = 0);
    ~ListeEchouesFrame();

private slots:
    void on_click_impression();

private:
    Ui::ListeEchouesFrame *ui;
};

#endif // LISTEECHOUESFRAME_H
