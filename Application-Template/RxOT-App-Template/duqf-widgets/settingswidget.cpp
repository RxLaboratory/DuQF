#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    AppearanceSettingsWidget *appearanceWidget = new AppearanceSettingsWidget();
    appearanceLayout->addWidget(appearanceWidget);
}

void SettingsWidget::on_mainList_currentRowChanged(int currentRow)
{
    mainStackWidget->setCurrentIndex(currentRow);
}
