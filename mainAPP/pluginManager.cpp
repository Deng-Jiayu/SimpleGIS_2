#include "pluginManager.h"
#include <QDir>
#include <Windows.h>
#include <QDebug>

PluginManager::PluginManager() {}

PluginManager::~PluginManager() {}

void PluginManager::loadPlugins(QString subPath) {
	QDir plgPathDir = QString(subPath);
	qDebug() << "PluginManager::loadPlugins(QString subPath) subPath = " << subPath;
	if (!plgPathDir.exists()) {
		return;
	}
	QStringList filters;
	filters << QString("*.dll");
	plgPathDir.setFilter(QDir::Files | QDir::NoSymLinks);	// 设置类型过滤器，只为文件格式
	plgPathDir.setNameFilters(filters);						// 设置文件名称过滤器，只为filters格式
	int dirCount = plgPathDir.count();
	if (dirCount <= 0)
		return;
	QStringList stringList;
	QString absPath = plgPathDir.absolutePath();
	for (int i = 0; i < dirCount; i++) {
		QString filName = absPath + "/" + plgPathDir[i];
		qDebug() << filName;
		loadPlugin(filName);
	}
}

typedef MainInterface* (*InitType)();

void PluginManager::loadPlugin(QString plgPath) {
	HMODULE m = LoadLibraryA(plgPath.toStdString().c_str());

	if (m == NULL)return;

	void* addr = GetProcAddress(m, "Init");

	InitType f = (InitType)addr;
	MainInterface* iface = f();

	plgs[iface->name()] = iface;		// 加入到map中
}