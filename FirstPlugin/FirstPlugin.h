#pragma once

#include "firstplugin_global.h"
#include "../mainAPP/plugin.h"
#include <QMenu>

class FIRSTPLUGIN_EXPORT FirstPlugin :public MainInterface, public MenuPlugin
{
public:
    FirstPlugin();

    virtual QString name() { return "TEST FIRST PLUGIN"; }
    virtual QString type() { return "MenuPlugin"; }
    virtual QString information() { return "SILLY BOY"; }

    virtual QMenu* GetMenu() {
        QMenu* pt = new QMenu(QStringLiteral("文件"));

        pt->addAction(QStringLiteral("新建"));
        pt->addAction(QStringLiteral("打开"));
        pt->addAction(QStringLiteral("关闭"));

        return pt;
    }

    virtual MenuPlugin* getMenuPlugin() { return this; }

    virtual ToolBarPlugin* getToolBarPlugin() { return NULL; }

};
