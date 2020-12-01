#include "appearancesettingswidget.h"

AppearanceSettingsWidget::AppearanceSettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    _freezeUI = true;

    // Load settings
    settings.beginGroup("appearance");

    int toolButtonStyle = settings.value("toolButtonStyle", 2).toInt();
    toolsComboBox->setCurrentIndex(toolButtonStyle);

    int style = settings.value("style", 0).toInt();
    styleComboBox->setCurrentIndex(style);

    _freezeUI = false;
}

void AppearanceSettingsWidget::on_toolsComboBox_currentIndexChanged(int index)
{
    if (_freezeUI) return;

    Qt::ToolButtonStyle style = Qt::ToolButtonTextUnderIcon;
    if (index == 0) style = Qt::ToolButtonIconOnly;
    else if (index == 1) style = Qt::ToolButtonTextOnly;
    else if (index == 2) style = Qt::ToolButtonTextUnderIcon;
    else if (index == 3) style = Qt::ToolButtonTextBesideIcon;

    settings.setValue("toolButtonStyle", index);

    DuUI::setToolButtonStyle(style);
}


void AppearanceSettingsWidget::on_styleComboBox_currentIndexChanged(int index)
{
    if (_freezeUI) return;

    QString style = ":/styles/default";
    if (index == 1) style = "";
    else if(index == 2)
    {
        QString cssFileName = QFileDialog::getOpenFileName(this,"Open a stylesheet file","","CSS (*.css);;Text files (*.txt);;All files (*.*)");
        QFile checkFile(cssFileName);
        if (checkFile.exists())
        {
            style = cssFileName;
        }
        else style = settings.value("cssFile",style).toString();
    }

    settings.setValue("style", index);
    settings.setValue("cssFile", style);

    DuUI::updateCSS(style);
}
