#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMouseEvent>
#include <QQueue>

#include "Tree/Graphics/GraphicsLinkCutTree.h"
#include "Tree/Node.h"
#include "Helpers/Sequance.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
               class Frame; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void showEvent(QShowEvent *) override;

    void mousePressEvent(QMouseEvent *e) override;

    void on_pushButtonMakeStepClicked();

    void on_horizontalSliderAnimationSpeedValueChanged(int value);

    void on_pushButtonResetClicked();


    void on_pushButtonExposeClicked();

    void on_pushButtonCutClicked();

    void on_pushButtonLinkClicked();

    void on_pushButtonEndOperationClicked();

private:
    Ui::MainWindow *ui_base;
    Ui::Frame *ui_main;


    GraphicsLinkCutTree graphics_tree;
    LinkCutTree * tree;
    QQueue<GraphicsSolidNodeItem*> selected_nodes;

    void init();
};
#endif // MAINWINDOW_H
