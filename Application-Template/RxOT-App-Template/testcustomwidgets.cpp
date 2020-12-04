#include "testcustomwidgets.h"

TestCustomWidgets::TestCustomWidgets(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    ProgressSlider *ps = new ProgressSlider();
    ps->setFormat("Value: %v");
    formLayout->addRow(new QLabel("Progress Slider"), ps);
    SliderSpinBox *sp = new SliderSpinBox();
    sp->setPrefix("Width: ");
    sp->setSuffix("cm");
    formLayout->addRow(new QLabel("Slider Spin Box"), sp);
}
