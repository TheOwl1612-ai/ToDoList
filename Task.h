#ifndef TASK_H
#define TASK_H
#define NONE 0
#define LOW 1
#define MEDIUM 2
#define HIGH 3
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Task : public QListWidgetItem{
private:
    QVariant priority = NONE;
public:
    Task(QVariant label, QVariant priority);
};

#endif // TASK_H
