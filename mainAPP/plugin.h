#pragma once
#include <QString>

class QMenu;
class QToolBar;
class MenuPlugin;
class ToolBarPlugin;

class MainInterface {
public:
	virtual ~MainInterface() {}
	virtual QString name() = 0;
	virtual QString type() = 0;
	virtual QString information() = 0;
	
	virtual MenuPlugin* getMenuPlugin() = 0;
	virtual ToolBarPlugin* getToolBarPlugin() = 0;
};

class MenuPlugin {
public:
	virtual QMenu* GetMenu() = 0;
};

class ToolBarPlugin {
public:
	virtual QToolBar* getToolBar() = 0;
};