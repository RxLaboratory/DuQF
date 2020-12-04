#ifndef TESTCUSTOMWIDGETS_H
#define TESTCUSTOMWIDGETS_H

#include "ui_testcustomwidgets.h"

#include "duqf-widgets/sliderspinbox.h"
#include "duqf-widgets/progressslider.h"

class TestCustomWidgets : public QWidget, private Ui::TestCustomWidgets
{
    Q_OBJECT

public:
    explicit TestCustomWidgets(QWidget *parent = nullptr);
};

#endif // TESTCUSTOMWIDGETS_H
