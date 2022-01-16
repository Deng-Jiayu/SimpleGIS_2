#pragma once
#include "plugin.h"
#include <map>

class PluginManager {
public:
	PluginManager();
	~PluginManager();

	void loadPlugins(QString subPath);

private:
	void loadPlugin(QString plgPath);

public:
	std::map<QString, MainInterface*> plgs;
};