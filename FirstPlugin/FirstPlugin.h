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
        QMenu* pt = new QMenu(QStringLiteral("�ļ�"));

        pt->addAction(QStringLiteral("�½�"));
        pt->addAction(QStringLiteral("��"));
        pt->addAction(QStringLiteral("�ر�"));

        return pt;
    }

    virtual MenuPlugin* getMenuPlugin() { return this; }

    virtual ToolBarPlugin* getToolBarPlugin() { return NULL; }

};
