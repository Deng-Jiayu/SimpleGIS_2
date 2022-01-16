#pragma once

#include "openfileplugin_global.h"
#include "../mainAPP/plugin.h"
#include <QToolBar>

class OPENFILEPLUGIN_EXPORT OpenFilePlugin:public MainInterface,public ToolBarPlugin
{
public:
    OpenFilePlugin();

    virtual QString name() { return "OPEN FILE PLUGIN"; }
    virtual QString type() { return "ToolBarPlugin"; }
    virtual QString information() { return "NO NO"; }

    virtual QToolBar* getToolBar() {
        QToolBar* pt = new QToolBar;
        pt->addAction(QStringLiteral("´ò¿ª"));
        return pt;
    }

    virtual MenuPlugin* getMenuPlugin() { return NULL; }

    virtual ToolBarPlugin* getToolBarPlugin() { return this; }

};
