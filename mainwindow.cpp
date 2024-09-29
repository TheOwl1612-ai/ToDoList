#include <Task.h>
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_TaskAdd_clicked()
{
    QVariant label = ui->line_TaskLabelEdit->text();
    QVariant priority = ui->cBox_TaskCategoriesEdit->currentIndex();
    createTask(label,priority);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Delete){
        deleteTask();
    }
    else if (event->key() == Qt::Key_Return){
        createTask(ui->line_TaskLabelEdit->text(),ui->cBox_TaskCategoriesEdit->currentData());
    }
}

void MainWindow::createTask(QVariant label, QVariant priority)
{
    if (label == "") return;

    QListWidgetItem* item = new Task(label,priority);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setCheckState(Qt::Unchecked);
    switch (priority.toInt()){
    case NONE:
        ui->list_unCategorized->addItem(item);
        break;
    case LOW:
        ui->list_LowTasks->addItem(item);
        break;
    case MEDIUM:
        ui->list_MediumTasks->addItem(item);
        break;
    case HIGH:
        ui->list_HighTasks->addItem(item);
        break;
    }

    ui->line_TaskLabelEdit->clear();
    ui->line_TaskLabelEdit->setFocus();
}

void MainWindow::deleteTask()
{
    QListWidgetItem* item1 = ui->list_unCategorized->currentItem();
    QListWidgetItem* item2 = ui->list_LowTasks->currentItem();
    QListWidgetItem* item3 = ui->list_HighTasks->currentItem();
    QListWidgetItem* item4 = ui->list_MediumTasks->currentItem();

    QListWidgetItem* itemToBeDeleted = item1 ? item1 : (item2 ? item2 : (item3 ? item3 : item4));
    delete itemToBeDeleted;
}
