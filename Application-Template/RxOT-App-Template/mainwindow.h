#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "duqf-app/app-version.h"
#include "duqf-app/app-style.h"
#include "duqf-widgets/toolbarspacer.h"

#include <QMouseEvent>
#include <QLabel>
#include <QToolButton>
#include <QMenu>
#include <QDesktopServices>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int argc, char *argv[], QWidget *parent = nullptr);

public slots:
    void duqf_maximize(bool max);
    void duqf_maximize();
    void duqf_bugReport();
    void duqf_forum();
    void duqf_chat();
    void duqf_doc();

private:
    // ========= RxOT UI ==============
    /**
     * @brief initUi Called once to build the default RxOT UI
     */
    void duqf_initUi();
    /**
     * @brief Is the tool bar currently clicked or not
     */
    bool duqf_toolBarClicked;
    /**
     * @brief Drag position
     * Used for drag n drop feature
     */
    QPoint duqf_dragPosition;
    QToolButton *duqf_maximizeButton;

protected:
    bool eventFilter(QObject *obj, QEvent *event);

};
#endif // MAINWINDOW_H
