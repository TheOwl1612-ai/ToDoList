#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_TaskAdd_clicked();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    void createTask(QVariant label, QVariant priority);
    void deleteTask();
};
#endif // MAINWINDOW_H
