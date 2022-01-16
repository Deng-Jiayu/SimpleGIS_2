#pragma once

#include "helpplugin_global.h"
#include "../mainAPP/plugin.h"

#include <QMenu>

class HELPPLUGIN_EXPORT HelpPlugin :public MainInterface, public MenuPlugin
{
public:
    HelpPlugin();

    virtual QString name() { return "Help Plugin"; }
    virtual QString type() { return "MenuPlugin"; }
    virtual QString information() { return "NO information"; }

    virtual QMenu* GetMenu() {
        QMenu* pt = new QMenu(QStringLiteral("帮助"));

        pt->addAction(QStringLiteral("检查更新"));
        pt->addAction(QStringLiteral("插件管理"));
        pt->addAction(QStringLiteral("关于"));

        return pt;
    }

    virtual MenuPlugin* getMenuPlugin() {
        return this;
    }

    virtual ToolBarPlugin* getToolBarPlugin() { return NULL; }
};
